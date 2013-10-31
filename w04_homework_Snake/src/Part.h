//
//  Snake.h
//  w4_homework_Snake
//
//  Created by Mirte Becker on 9/24/13.
//
//

#pragma once
#include "ofMain.h"

class Part{
public:
    Part();
    void draw(ofVec2f target, float size, float i, float catchUpSpeed);
    
    float angle;
    float radius;
    ofPoint pos;
};