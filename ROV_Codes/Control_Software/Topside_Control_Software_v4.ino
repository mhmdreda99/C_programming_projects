//Topside Control Software


/*
/////////////   PS2 Controller Button Actions   ////////////
-Movement
  -Forward/Reverse/Turn 
    -Left Motor = Left Analog Stick
    -Right Motor = Right Ananlog Stick
  -Up/Dpwn
    -L1 = Up
    -R1 = Down
-Camera
  -Tilt up = left pad up
  -Tilt down = left pad down
  -Pan left = left pad left
  -Pan right = left pad right
  -Home = L2
-Accessories
    -On/Off
      -1 = Triangle 
      -2 = Circle 
*/
//------------------------------------
#include <PS2X_lib.h>
#include <EasyTransfer.h> 
#include <LiquidCrystal.h>
EasyTransfer Transfer;
LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);

//------------------------------------
float softwareVersion  = 3.1;

//PS2 controller setup----------------
PS2X ps2x;
int error = 0; 
byte type = 0;
byte vibrate = 0;

//variables---------------------------
boolean enable = false;
int neutral = 128;
int verticals = 0;
int LSYVal = 0;
int LSXVal = 0;
int RSYVal = 0;
int RSXVal = 0;
boolean enabled = false;
boolean relay_1 = false;
boolean relay_2 = false;
int motorSpeed = 3;
long servoResetTime = 0;

//BWD---------------------------------
unsigned long lastSend = 0;
unsigned long currentTime;
int sendInterval = 75;
unsigned long previousMillis = 0;
unsigned long interval = 100;
int ledPin = 9;
int ledState = LOW;
int ps2led = 8;


//rs422 com setup---------------------
struct rovData
{
  int motor1;
  int motor2;
  int motor3;
  int relay1;
  int relay2;
  int servo1;
  int servo2;
  boolean homeCamera;
  int motorSpeed;  
}data;

//------------------------------------
void setup()
{
 Serial.begin(57600);
 Transfer.begin(details(data), &Serial);
 error = ps2x.config_gamepad(13,11,10,12, true, true);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
 
 lcd.begin(16, 2);
 lcd.print("Initializing");
 delay(750);
 lcd.clear();
 
 if(error == 0)
 {
   digitalWrite(ps2led, HIGH);
   lcd.setCursor(0, 0);
   lcd.print("PS2 Connected");
   delay(1000);
   lcd.clear();
 } 
 pinMode(ledPin, OUTPUT);
 pinMode(ps2led, OUTPUT);
 lcd.print("ROV Disabled");
}
//------------------------------------
void loop()
{
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval)
    {
      previousMillis = currentMillis;
      if(ledState == LOW)
      {
         ledState = HIGH;
      }
      else
      {
        ledState = LOW;
      }
      digitalWrite(ledPin, ledState);
    }  
  
  if(error == 1) //skip loop if no controller found
  return;  
  if(type == 2)
  { //Guitar Hero Controller
  }
  else
  {   
    readPS2();
  }    
}
//------------------------------------
inline void readPS2()
{
    ps2x.read_gamepad();    
    
    //Enable ROV
    if(ps2x.ButtonPressed(PSB_START) && enabled == false)
    {
      enable = true;
      enabled = true;
      interval = 1000;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROV Enabled");
    }
    else if(ps2x.ButtonPressed(PSB_START) && enabled == true)
    {
      enable = false;
      enabled = false;
      interval = 100;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ROV Disabled");
    }
    
    //Gear Speed Select
    if(ps2x.ButtonPressed(PSB_SELECT) && motorSpeed < 3) //select motor speed 
    {
      motorSpeed++;
      data.motorSpeed++;
      lcd.setCursor(0, 2);
      lcd.print(motorSpeed);
    }
    else if(ps2x.ButtonPressed(PSB_SELECT) && motorSpeed == 3) //select motor speed 
    {
      motorSpeed = 1;
      data.motorSpeed = 1;
    }
    lcd.setCursor(0, 2);
    lcd.print(motorSpeed);
    
    //Camera Pan/Tilt Servos
    //Tilt
    if(ps2x.Button(PSB_PAD_UP))
      data.servo1 = 1;        
    if(ps2x.Button(PSB_PAD_DOWN))
      data.servo1 = 2;
    //Pan  
    if(ps2x.Button(PSB_PAD_LEFT))
      data.servo2 = 1;        
    if(ps2x.Button(PSB_PAD_RIGHT))
      data.servo2 = 2;
    if(ps2x.ButtonReleased(PSB_PAD_UP) || ps2x.ButtonReleased(PSB_PAD_DOWN) || ps2x.ButtonReleased(PSB_PAD_LEFT) || ps2x.ButtonReleased(PSB_PAD_RIGHT))
    {
      data.servo1 = 0;
      data.servo2 = 0;
    }    
    //Camera Reset(Home) 
    if(ps2x.NewButtonState(PSB_PINK))
    {
      data.homeCamera = true;
      servoResetTime = millis();
    }
    else
    {
      if(millis() - servoResetTime > 50)
      {
        data.homeCamera = false;
      }
    }
    
    //Accessories
    if(ps2x.ButtonPressed(PSB_GREEN) && relay_1 == false)
    {
      data.relay1 = 1;
      relay_1 = true;
    }
    else if(ps2x.ButtonPressed(PSB_GREEN) && relay_1 == true)
    {
      data.relay1 = 0;
      relay_1 = false;
    }
    if(ps2x.ButtonPressed(PSB_BLUE) && relay_2 == false)
    {
      data.relay2 = 1;
      relay_2 = true;
    }
    else if(ps2x.ButtonPressed(PSB_BLUE) && relay_2 == true)
    {
      data.relay2 = 0;
      relay_2 = false;
    } 
        
    
    //Verticals (Up/Down)          
    if(ps2x.ButtonPressed(PSB_L1))
      verticals = 1;  
    if(ps2x.ButtonPressed(PSB_R1))
      verticals = 2;
    if(ps2x.ButtonReleased(PSB_R1) || ps2x.ButtonReleased(PSB_L1))
      verticals = 0;
      
    //Left Right stick    
    LSYVal = ps2x.Analog(PSS_LY);
    //LSXVal = ps2x.Analog(PSS_LX);
    RSYVal = ps2x.Analog(PSS_RY);
    //RSXVal = ps2x.Analog(PSS_RX);
    motorCalc();    
 }      
//------------------------------------
inline void motorCalc()
{
    if(LSYVal == 128 && RSYVal == 128 && verticals == 0) //check for neutral
    {
      data.motor1 = neutral;
      data.motor2 = neutral;
      data.motor3 = neutral;
    }
    else
    {
      LSYVal = map(LSYVal, 0, 255, 60, 185); //limit current draw to 2A @ 12v
      data.motor1 = LSYVal;
      RSYVal = map(RSYVal, 0, 255, 60, 185); //limit current draw to 2A @ 12v
      data.motor2 = RSYVal;  
    }
    
    data.motor3 = verticals;
    
    //debug
    /*
    Serial.println(data.motor1);
    Serial.println(data.motor2);
    Serial.println(data.motor3);
    Serial.println("...");  
    */  
    
    currentTime = millis();
    if(currentTime - lastSend > sendInterval)
    {
      lastSend = currentTime;
      if(enable == true)
      {
        Transfer.sendData();
      }
    }
}
//------------------------------------
