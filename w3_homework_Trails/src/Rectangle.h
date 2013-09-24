//
//  Rectangle.h
//  w3_homework_Trails
//
//  Created by Mirte Becker on 9/9/13.
//
//

#pragma once
#include "ofMain.h"

class Rectangle{
public:
    Rectangle();
    void draw();
    void xenoToPoint(float catchX, float catchY);
    
    float catchUpSpeed;
    ofVec2f pos;
    
    int degrees;
    int cHue;
    int cSat;
    int cBright;
    int cAlpha;
    int size;
};