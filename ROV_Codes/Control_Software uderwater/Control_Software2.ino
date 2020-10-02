//Bottomside ROV Software
//Created 06/30/13 by Nick S.
//Last Modified 11/30/13 1503hrs
//Released into the Public Domain
//Thanks to Bill Porter for his Easy Transfer Serial Library

//-----libraries------------------------
#include <Servo.h>
#include <EasyTransfer.h>
EasyTransfer ET;
//-----rs-422/485 com receiver setup-----
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

//----------define pin variables----------
int motorPin1 = 2; //Left
int motorPin2 = 3; //Right
int motorPin3 = 4; //Verticals
//int motorPin4 = 5;
//int motorPin5 = 6;
//int motorPin6 = 7;
int relayPin1 = A2; //Accessory 1
int relayPin2 = A3; //Accessory 2
boolean relay_1 = false;
boolean relay_2 = false;
int servoPin1 = A0; //Tilt
int servoPin2 = A1; //Pan
int ledPin = 9; //Com status pin

//---------------define value variables-------
int servo1value = 1500;
int servo2value = 1500;
boolean lostCom = false;
int neutral = 1500;
int motorMin = 1000;
int motorMax = 2000;
int ServoNeutral = 90;
Servo Motor1;
Servo Motor2;
Servo Motor3;
//Servo Motor4;
//Servo Motor5;
//Servo Motor6;
Servo Servo1;
Servo Servo2;
int gear = 0;

//--------Com led blink variables-----------
int ledState = LOW;
unsigned long previousMillis = 0;
unsigned long interval = 500;
unsigned long lastComCheck = 0;
unsigned long lastComInterval = 1500;
unsigned long last2 = 0;
unsigned long interval2 = 100;
unsigned long current2;

//-----------------------------------------
void setup()
{
  //start serial communication
  Serial.begin(57600); 
  ET.begin(details(data), &Serial);
  //set I/O state
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
  pinMode(ledPin, OUTPUT);
  //attach servos
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  Servo1.writeMicroseconds(neutral);
  Servo2.writeMicroseconds(neutral);
  //attach ESC's
  Motor1.attach(motorPin1);
  Motor2.attach(motorPin2);
  Motor3.attach(motorPin3);
  //Motor4.attach(motorPin4);
  //Motor5.attach(motorPin5);
  //Motor6.attach(motorPin6);
  Motor1.writeMicroseconds(neutral);
  Motor2.writeMicroseconds(neutral);
  Motor3.writeMicroseconds(neutral);
  //Motor4.writeMicroseconds(neutral);
  //Motor5.writeMicroseconds(neutral);
  //Motor6.writeMicroseconds(neutral);
  data.homeCamera = false;
}

//-------------------------------------
void loop()
{    
  //start com led timing variables
  current2 = millis();
  unsigned long currentMillis = millis();
  //check for incoming serial data
  if(ET.receiveData())
  {
    lastComCheck = millis();
    interval = 1000;
    lostCom = false;
    processData();    
  }   
  //check for a break in communication
  if(millis() - lastComCheck > 1000)
  {
    interval = 100;
    rovSafe(); //set everything to safe values    
  }  
  //set com led blink rate
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
}

//--------------------------------------
inline void rovSafe() //if com is lost or ROV is disabled then set everything to "safe" state
{
    Motor1.writeMicroseconds(neutral);
    Motor2.writeMicroseconds(neutral);
    Motor3.writeMicroseconds(neutral);
    //Motor4.writeMicroseconds(neutral);
    //Motor5.writeMicroseconds(neutral);
    //Motor6.writeMicroseconds(neutral);
    
    Servo1.writeMicroseconds(neutral);
    Servo2.writeMicroseconds(neutral);
    
    digitalWrite(relayPin1, LOW);
    digitalWrite(relayPin2, LOW);
    
}

//------------------------------------------
inline void processData()
{
  //motor1 - left
  if(data.motor1 > 150 || data.motor1 < 110) //if values are not in neutral range
    data.motor1 = map(data.motor1, 0, 255, 1000, 2000); //map values from PS2 range to servo range for good speed control
  else
    data.motor1 = neutral; //if values are in neutral range set output to neutral
  
  //motor2 - right  
  if(data.motor2 > 150 || data.motor2 < 110)
    data.motor2 = map(data.motor2, 0, 255, 1000, 2000);
  else
    data.motor2 = neutral;
  
  //motor3 - verticals  
  if(data.motor3 == 1)
    data.motor3 = 2000;
  else if(data.motor3 == 2)
    data.motor3 = 1000;
  else
    data.motor3 = neutral;
  
  //Servo1  - tilt
  if(data.servo1 == 1)
    servo1value = (servo1value + 3);
  if(data.servo1 == 2)
    servo1value = (servo1value - 3);
  if(data.homeCamera == true)
    servo1value = ServoNeutral;
  Servo1.write(servo1value);
  
  //Servo2  - pan
  if(data.servo2 == 1)
    servo2value = servo2value + 3;
  if(data.servo2 == 2)
    servo2value = servo2value - 3;
  if(data.homeCamera == true)
    servo2value = ServoNeutral;
  Servo2.write(servo2value);

  if(data.relay1 == 1 && relay_1 == false) //relay 1
  {
    digitalWrite(relayPin1, HIGH); //-watchdog loop so that the pin does no flicker
    relay_1 = true;
  }
  else if(data.relay1 == 0)
  {
    digitalWrite(relayPin1, LOW);
    relay_1 = false;
  }
  
  if(data.relay2 == 1 && relay_2 == false) //relay 2
  {
    digitalWrite(relayPin2, HIGH);
    relay_2 = true;
  }
  else if(data.relay2 == 0)
  {
    digitalWrite(relayPin2, LOW);
    relay_2 = false;
  }  
  
  //Gear Speed Select
  if(data.motorSpeed == 1)
  {
    motorMin = 1300;
    motorMax = 1700;
  }
  if(data.motorSpeed == 2)
  {  
    motorMin = 1150;
    motorMax = 1850;
  }
  if(data.motorSpeed == 3)
  {
    motorMin = 1000;
    motorMax = 2000;
  }
   
  //Write motor values to ESC's
  data.motor1 = constrain(data.motor1, motorMin, motorMax);
  data.motor2 = constrain(data.motor2, motorMin, motorMax);
  data.motor3 = constrain(data.motor3, motorMin, motorMax);
  //data.motor1 = constrain(data.motor1, motorMin, motorMax);
  //data.motor1 = constrain(data.motor1, motorMin, motorMax);
  //data.motor1 = constrain(data.motor1, motorMin, motorMax);
  Motor1.writeMicroseconds(data.motor1);
  Motor2.writeMicroseconds(data.motor2);
  Motor3.writeMicroseconds(data.motor3);
  //Motor4.writeMicroseconds(data.motor4);
  //Motor5.writeMicroseconds(data.motor5);
  //Motor6.writeMicroseconds(data.motor6);
}
//---------------------------------------------
