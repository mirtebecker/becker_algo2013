//
//  Snake.h
//  w4_homework_Snake
//
//  Created by Mirte Becker on 9/24/13.
//
//

#pragma once
#include "ofMain.h"

class Snake{
public:
    Snake();
    void draw();
    
    float catchUpSpeed;
    float angle;
    float radius;
    float parts;
    
    ofPoint pos;
    ofPoint mousePos;
    
};