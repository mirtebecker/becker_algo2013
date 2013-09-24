//
//  Rectangle.cpp
//  w3_homework_Trails
//
//  Created by Mirte Becker on 9/9/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(){
    catchUpSpeed = 0.03;
    degrees = 50;
    cHue = 180;
    cSat = 255;
    cBright = 255;
    cAlpha = 255;
    size = 100;
}

void Rectangle::draw(){
    ofNoFill();
    ofColor c = ofColor::fromHsb(cHue, cSat, cBright, cAlpha*0.5);
    ofSetColor(c);
    ofSetLineWidth(1);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //ofRotate(float degrees, float vecX, float vecY, float vecZ);
    ofRotate(degrees, 1, 0.5, 0);  
    ofRect(pos.x, pos.y, size, size);
}

void Rectangle::xenoToPoint(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}