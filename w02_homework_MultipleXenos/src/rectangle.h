//
//  Rectangle.h
//  w2_homework_multiplexenos
//
//  Created by Mirte Becker on 9/1/13.
//
//

#pragma once
#include "ofMain.h"

class Rectangle {
public:
    Rectangle();
    
    void draw(float r, float g, float b, float a);
    void xenoToPoint(float catchX, float catchY, float catchUpSpeed);
    
    ofPoint pos;
    float catchUpSpeed;
};