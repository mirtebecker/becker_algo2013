//
//  Ball.h
//  w3_homework_BouncingBall3D
//
//  Created by Mirte Becker on 9/10/13.
//
//

#pragma once
#include "ofMain.h"

class Ball{
public:
    Ball();
    
    void update();
    void draw();
    
    float boxSize;
    
    ofPoint pos;
    ofVec3f vel;
};