import math
import numpy as np
import cv2

#dictionary of all contours
contours = {}
#array of edges of polygon
approx = []
#scale of the text
scale = 2
#camera
cap = cv2.VideoCapture(0)
print("press q to exit")

# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))

#calculate angle
def angle(pt1,pt2,pt0):
    dx1 = pt1[0][0] - pt0[0][0]
    dy1 = pt1[0][1] - pt0[0][1]
    dx2 = pt2[0][0] - pt0[0][0]
    dy2 = pt2[0][1] - pt0[0][1]
    return float((dx1*dx2 + dy1*dy2))/math.sqrt(float((dx1*dx1 + dy1*dy1))*(dx2*dx2 + dy2*dy2) + 1e-10)

while(cap.isOpened()):
    #Capture frame-by-frame
    ret, frame = cap.read()
    if ret==True:
        triangles = 0
        squares = 0
        lines = 0
        circles = 0
        #grayscale
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        #canny = cv2.Canny(frame,80,240,3)
        blur = cv2.GaussianBlur(gray, (5, 5), 0)
        ret,thresh1 = cv2.threshold(gray,60,250,cv2.THRESH_BINARY)   
        #contours
        canny2, contours, hierarchy = cv2.findContours(skin_ycrcb,cv2.RETR_CCOMP,cv2.CHAIN_APPROX_SIMPLE)
        for cnt in contours:
            #approximate the contour with accuracy proportional to
            #the contour perimeter
            approx = cv2.approxPolyDP(cnt,cv2.arcLength(cnt,True)*0.02,True)
            #Skip small or non-convex objects
            if(abs(cv2.contourArea(cnt))<100 or not(cv2.isContourConvex(approx))):
                continue
            #triangle
            if(len(approx) == 1):
                lines = lines + 1
                x,y,w,h = cv2.boundingRect(cnt)
                cv2.drawContours(frame, [approx], -1, (0,255,0), 3)
                cv2.putText(frame,'Line',(x,y),cv2.FONT_HERSHEY_SIMPLEX,scale,(255,255,255),2,cv2.LINE_AA)
            if(len(approx) == 3):
                triangles = triangles + 1
                x,y,w,h = cv2.boundingRect(cnt)
                cv2.drawContours(frame, [approx], -1, (0,255,0), 3)
                cv2.putText(frame,'TRI',(x,y),cv2.FONT_HERSHEY_SIMPLEX,scale,(255,255,255),2,cv2.LINE_AA)    
            elif(len(approx)>=4 and len(approx)<=6):
                #nb vertices of a polygonal curve
                vtc = len(approx)
                #get cos of all corners
                cos = []
                for j in range(2,vtc+1):
                    cos.append(angle(approx[j%vtc],approx[j-2],approx[j-1]))
                #sort ascending cos
                cos.sort()
                #get lowest and highest
                mincos = cos[0]
                maxcos = cos[-1]

                #Use the degrees obtained above and the number of vertices
                #to determine the shape of the contour
                x,y,w,h = cv2.boundingRect(cnt)
                if(vtc==4):
                    squares = squares + 1
                    cv2.drawContours(frame, [approx], -1, (0,255,0), 3)
                    ar = w/float(h)
                    if (ar >= 0.95 and ar <= 1.05):
                        cv2.putText(frame,'Square',(x,y),cv2.FONT_HERSHEY_SIMPLEX,scale,(255,255,255),2,cv2.LINE_AA)
                    else:
                        cv2.putText(frame,'Rectangle',(x,y),cv2.FONT_HERSHEY_SIMPLEX,scale,(255,255,255),2,cv2.LINE_AA)

                        
                elif(vtc==5):
                    cv2.drawContours(frame, [approx], -1, (0,255,0), 3)
                    cv2.putText(frame,'PENTA',(x,y),cv2.FONT_HERSHEY_SIMPLEX,scale,(255,255,255),2,cv2.LINE_AA)
                elif(vtc==6):
                    cv2.drawContours(frame, [approx], -1, (0,255,0), 3)
                    cv2.putText(frame,'HEXA',(x,y),cv2.FONT_HERSHEY_SIMPLEX,scale,(255,255,255),2,cv2.LINE_AA)
            else:
                #detect and label circle
                area = cv2.contourArea(cnt)
                x,y,w,h = cv2.boundingRect(cnt)
                radius = w/2
                if(abs(1 - (float(w)/h))<=2 and abs(1-(area/(math.pi*radius*radius)))<=0.2):
                    circles += 1
                    cv2.drawContours(frame, [approx], -1, (0,255,0), 3)
                    cv2.putText(frame,'CIRC',(x,y),cv2.FONT_HERSHEY_SIMPLEX,scale,(255,255,255),2,cv2.LINE_AA)

        #Display the resulting frame
        out.write(frame)
        print('Squares : ' + str(squares))
        print('Circles : ' + str(circles))
        print('Triangles : ' + str(triangles))
        print('Lines : ' + str(lines))
        cv2.imshow('frame',frame)
        cv2.imshow('thres1', thresh1)
        key = cv2.waitKey(1)
        if key == 27:
            break

#When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
