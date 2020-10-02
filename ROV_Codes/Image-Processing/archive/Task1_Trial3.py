#THIS ALGORITHM FIRST DETECTS THE SHAPE AND THEN THE COLOUR. IT USES THE MEAN VALUE TO 
# TO COMPARE THE RED, GREEN AND BLUE COLOR#
import cv2
import numpy as np
from PIL import Image, ImageEnhance

#cap = cv2.VideoCapture('Test1_UnderwaterT.mp4')
cap = cv2.VideoCapture(0)
cap.set(3,320)
cap.set(4,240)

lower_red=np.array([150,150,0])
upper_red=np.array([180,255,255])

# You can apply filters which literally just blurs the images, thus ignoring any distrurbances
lower_blue=np.array([100,150,0])
upper_blue=np.array([140,255,255])

lower_yellow=np.array([20, 100, 100])
upper_yellow=np.array([30, 255, 255])


#while True:
while(cap.isOpened()):
    red,frame=cap.read() #'_' is a value returned to this function, but we don't care about that value

    if (frame.all()!=None):
        frame=Image.fromarray(frame)
        enhancer = ImageEnhance.Contrast(frame)
    
        factor =  1 #CHANG FOR CONTRAST
        image=enhancer.enhance(factor)
        #frame = np.array(image).reshape((image.height, image.width,3))
        
        enhancer=ImageEnhance.Brightness(image)
        
        factor =  1 #CHANGE FOR BRIGHTNESS
        image=enhancer.enhance(factor)
        frame = np.array(image).reshape((image.height, image.width,3))
        
        enhancer=ImageEnhance.Sharpness(image) 
        factor =  1 #CHANGE FOR SHARPNESS
        image=enhancer.enhance(factor)
        frame = np.array(image).reshape((image.height, image.width,3))
        median_value=cv2.medianBlur(frame,15)
        edges=cv2.Canny(median_value,100,200)
        
        canny2, contours, hierarchy = cv2.findContours(edges,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
    
        for i in range(0,len(contours)):
            #approximate the contour with accuracy proportional to
            #the contour perimeter
            approx = cv2.approxPolyDP(contours[i],cv2.arcLength(contours[i],True)*0.1,True) # CHANGE THIS FACTOR TO APPROXIMATE EDGES 
            #Skip small or non-convex objects
            if(abs(cv2.contourArea(contours[i]))<400 or not(cv2.isContourConvex(approx))):
                continue
    
            #triangle
            if(len(approx)<=3):
                x,y,w,h = cv2.boundingRect(contours[i])
                cv2.rectangle(frame,(x,y),(x+w,y+h),(255,0,0),2)
    #            new_frame=frame[x:x+w,y:y+h]
    #            hsv=cv2.cvtColor(new_frame,cv2.COLOR_BGR2HSV)    
    #            mask=cv2.inRange(hsv,lower_blue,upper_blue)
    #            x,y,w,h = cv2.boundingRect(mask)
                mean_val = cv2.mean(contours[i]) # the means of the blue, green, and red channels, respectively
                if(mean_val[0]>mean_val[1] and (mean_val[0]>mean_val[2])):
                    cv2.putText(frame,'TRI_B',(x,y),cv2.FONT_HERSHEY_SIMPLEX,2,(255,255,255),2,cv2.LINE_AA)
                elif(mean_val[2]>mean_val[1] and (mean_val[2]>mean_val[0])):
                    cv2.putText(frame,'TRI_R',(x,y),cv2.FONT_HERSHEY_SIMPLEX,2,(255,255,255),2,cv2.LINE_AA)
                else:
                    cv2.putText(frame,'TRI_Y',(x,y),cv2.FONT_HERSHEY_SIMPLEX,2,(255,255,255),2,cv2.LINE_AA)

            elif(len(approx)>=4):
                vtc = len(approx)
                x,y,w,h = cv2.boundingRect(contours[i])
                cv2.rectangle(frame,(x,y),(x+w,y+h),(255,0,0),2)
                mean_val = cv2.mean(contours[i]) # the means of the blue, green, and red channels, respectively            
                if((mean_val[0]>mean_val[1]) and (mean_val[0]>mean_val[2])):
                    cv2.putText(frame,'REC_B',(x,y),cv2.FONT_HERSHEY_SIMPLEX,2,(255,255,255),2,cv2.LINE_AA)
                elif((mean_val[2]>mean_val[1]) or (mean_val[2]>mean_val[0])):
                    cv2.putText(frame,'REC_R',(x,y),cv2.FONT_HERSHEY_SIMPLEX,2,(255,255,255),2,cv2.LINE_AA)
                    print('I AM RED')
                else:
                    cv2.putText(frame,'REC_Y',(x,y),cv2.FONT_HERSHEY_SIMPLEX,2,(255,255,255),2,cv2.LINE_AA)
            else:
                print('None')
    
        cv2.imshow('frame',frame)
        cv2.waitKey(1)
        
cv2.destroyAllWindows() 
cv2.VideoCapture(0).release()   
#    