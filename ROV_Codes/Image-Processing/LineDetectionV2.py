import numpy as np
import cv2

img = cv2.VideoCapture(0)
temporary = ""

old_x = None
old_y = None
while(True):

    ret, frame = img.read()
    crop_img = frame#[0:1280, 0:720]     #################################
    gray = cv2.cvtColor(crop_img, cv2.COLOR_BGR2GRAY) #was crop_img instead of frame
    blur = cv2.GaussianBlur(gray, (5, 5), 0) #Gasian blur to remove unneeded stuff from the background
    ret, thresh = cv2.threshold(blur, 60, 255, cv2.THRESH_BINARY_INV) #threshold values https://docs.opencv.org/3.4/d7/d4d/tutorial_py_thresholding.html so we convert image to boolean (white and black pixels)
    contours, hierarchy = cv2.findContours(thresh, 1 , cv2.CHAIN_APPROX_NONE) #https://docs.opencv.org/3.1.0/d4/d73/tutorial_py_contours_begin.html used to join similar pixels together. Need to be proceed on binnary image

    if len(contours) > 0:

        c = max(contours, key=cv2.contourArea)                #https://docs.opencv.org/3.1.0/dd/d49/tutorial_py_contour_features.html

        M = cv2.moments(c)

        center_x = int(M['m10'] /M['m00'])  #take x middle coordinate
        center_y = int(M['m01'] / M['m00'])  #take y middle coordinates

        x, y, w, h = cv2.boundingRect(c)

        cv2.line(crop_img, (center_x , 0), (center_x , 480), (255, 0, 0), 2)  #draw vertical line

        cv2.line(crop_img, (0, center_y), (640, center_y), (255, 0, 0), 2)   #draw horizontal line

        cv2.line(crop_img, (320,0), (320, 480), (0, 0, 255), 2)

        cv2.line(crop_img, (0,240), (640, 240), (0, 0, 255), 2)


        cv2.line(blur, (320,0), (320, 480), (0, 0, 255), 2)

        cv2.line(blur, (0,240), (640, 240), (0, 0, 255), 2)

        cv2.drawContours(crop_img, contours, -1, (0, 255, 0), 2)


        x_offset = 40
        y_offset = 40

        if center_x > 320 + x_offset:
            temp_x = "Right"
        elif center_x < 320 - x_offset:
            temp_x = "Left"
        else:
             #temp_x = "off"
            temp_x = temp_x

        if center_y < 240 + y_offset:
            temp_y = "Up"
        elif center_y > 240 - y_offset:
            temp_y = "Down"
        else:
            temp_y = "off"

        if old_x != None and old_y != None:
            if temp_x != old_x and temp_y != old_y:
                temp_x = old_x     
                temp_y = old_y
            else:                       
                old_x= temp_x
                old_y= temp_y

        print(temp_x, temp_y)

        #print(center_x)
        #print(center_y)
        #print("The Widths is: " + w )
        print()

    else:
        print("I don't see the line")


    cv2.imshow("Image", frame)
    cv2.imshow("Edge",blur)


    #cv2.imshow("Edges", gray)
    if cv2.waitKey(1) & 0xFF == ord('`'):
        break

img.release()
cv2.destroyAllWindows()











