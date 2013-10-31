//
//  Rectangle.h
//  w2_homework_clickAtoB
//
//  Created by Mirte Becker on 9/1/13.
//
//

#pragma once
#include "ofMain.h"

class Rectangle {
public:
    Rectangle();
    
    void draw();
    void xenoToPoint(float catchX, float catchY);

    float catchUpSpeed;
    ofPoint pos;
};