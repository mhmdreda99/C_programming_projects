import cv2
import numpy as np

cap = cv2.VideoCapture(0)

#define the compression code and saving the video output
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('Reda.mp4', fourcc, 20.0, (300, 240))

if (cap.isOpened() == False):
    print('error opening video stream or file')
    
while(cap.isOpened()):
    
    ret, frame = cap.read()
    if ret == True:
        #Display resulting frame
        ret,frame=cap.read()
        gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
        ret,thresh = cv2.threshold(gray,140,255,0)
        image,contours,hie = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
        frame = cv2.drawContours(frame, contours, 3, (0,255,0), 3)
        font = cv2.FONT_HERSHEY_COMPLEX
          
        for cnt in contours:
            approx = cv2.approxPolyDP(cnt, 0.1*cv2.arcLength(cnt, True), True)
            cv2.drawContours(frame, [approx], 0, (0), 5)
            x = approx.ravel()[0]
            y = approx.ravel()[1]
         
            if len(approx) == 3:
                cv2.putText(frame, "Triangle", (x, y), font, 1, (0))
            elif len(approx) == 4:
                cv2.putText(frame, "Rectangle", (x, y), font, 1, (0))
            elif len(approx) == 5:
                cv2.putText(frame, "Pentagon", (x, y), font, 1, (0))
            elif 6 < len(approx) < 15:
                cv2.putText(frame, "Ellipse", (x, y), font, 1, (0))
            else:
                cv2.putText(frame, "Circle", (x, y), font, 1, (0))
        
            cv2.imshow("Frame", frame)    
        #Press Q on keyboard to exit 
        if cv2.waitKey(25) & 0xFF == ord('q'):
            break
    else:
        break
cap.release()
out.release()
cv2.destroyAllWindows()
