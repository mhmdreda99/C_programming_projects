#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""

import cv2

cap = cv2.VideoCapture(0)

depth = 60
width = 80

x_centre = 320 # Contour x centre
y_centre = 240 # Contour y centre

current_direction = -1

tracking_x_offset = 40
tracking_y_offset = 40

horizontal_motion = -1
vetical_motion = -1

directions = ["Top", "Right", "Bottom", "Left"]

while(True):
    ret, main_frame = cap.read()
    
    '''
        Slicing the frame ino 4 parts
    '''
    cropped_frame = [
            main_frame [0:depth, x_centre-width:x_centre+width], #Top
            main_frame [y_centre-width:y_centre+width, 639-depth:639], #Right
            main_frame [479-depth:479, x_centre-width:x_centre+width], #Bottom
            main_frame [y_centre-width:y_centre+width, 0:depth] #Left
            ]
    
    '''
        Displaying some lines
    '''
    cv2.line(main_frame, (320,0), (320, 480), (0, 0, 255), 2) #Vertical Line in the middle
    cv2.line(main_frame, (0,240), (640, 240), (0, 0, 255), 2) #Horizontal Line in the middle
    cv2.line(main_frame, (x_centre,0), (x_centre, 480), (0, 240, 0), 2) 
    cv2.line(main_frame, (0,y_centre), (640, y_centre), (0, 240, 0), 2)
    
    
    cv2.imshow("Top",cropped_frame[0])
    cv2.imshow("Right", cropped_frame[1])
    cv2.imshow("Bottom", cropped_frame[2])
    cv2.imshow("Left", cropped_frame[3])
    
    
    '''
        Looking for contours in the 4 cropped sections
    '''
    for x in range(4):        
        gray = cv2.cvtColor(cropped_frame[x], cv2.COLOR_BGR2GRAY)
        blur = cv2.GaussianBlur(gray, (5, 5), 0) 
        ret, thresh = cv2.threshold(blur, 60, 255, cv2.THRESH_BINARY_INV)
        contours, hierarchy = cv2.findContours(thresh, 1 , cv2.CHAIN_APPROX_NONE)

        if len(contours) > 0:
            cv2.drawContours(cropped_frame[x], contours, -1, (0, 100, 0), 2)
            if current_direction == -1:
                current_direction = x
                break   
            
            if current_direction +2 != x and current_direction-2 != x:
                current_direction = x
                #print("Triggered: " + directions[current_direction])
                c = max(contours, key=cv2.contourArea)
                break  
    
    '''
        Changing cropped frames locations 
    '''
    if current_direction == 0: #Top
        vetical_motion = "Up"
        x_centre = 320
        y_centre = 80
        
    elif current_direction == 1: #Right
        horizontal_motion = "Right"
        x_centre = 559
        y_centre = 240
        
    elif current_direction == 2: #Bottom
        vetical_motion = "Down"
        x_centre = 320
        y_centre = 399
        
    elif current_direction == 3: #Left
        horizontal_motion = "Left"
        x_centre = 80
        y_centre = 240
    
    '''
        Correcting robot's side drift 
    '''
    try:
        M = cv2.moments(c)
        COG_x_coordinate = int(M['m10'] /M['m00'])  #take x middle coordinate
        COG_y_coordinate = int(M['m01'] / M['m00'])  #take y middle coordinates
        
        '''
        cv2.line(main_frame, (COG_x_coordinate,0), (COG_x_coordinate, 480), (100, 160, 0), 2) 
        cv2.line(main_frame, (0,COG_y_coordinate), (640, COG_y_coordinate), (100, 160, 0), 2)
        print(COG_x_coordinate, COG_y_coordinate)
        '''
    
        if current_direction == 0 or current_direction == 2: #When in vertical motion
            if COG_x_coordinate > width + tracking_x_offset:
                horizontal_motion = "D_Right"
            elif COG_x_coordinate < width - tracking_x_offset:
                horizontal_motion = "D_Left" 
            else:
                horizontal_motion = "D_on track"
            
        elif current_direction == 1 or current_direction == 3: #When in horizontal motion
            if COG_y_coordinate < depth + tracking_y_offset:
                vetical_motion = "D_Up"
            elif COG_y_coordinate > y_centre - tracking_y_offset:
                vetical_motion = "D_Down"
            else:
                vetical_motion = "D_on track"
    except:
        pass
    
    # printing outcome
    print(vetical_motion, horizontal_motion)
    cv2.imshow("Main_frame", main_frame)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    
# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
    
