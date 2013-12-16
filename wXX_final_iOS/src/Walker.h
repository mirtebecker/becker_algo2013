//
//  Walker.h
//  final
//
//  Created by Mirte Becker on 12/13/13.
//
//

#pragma once
#include "ofMain.h"

class Walker{
public:
    Walker();
    void update();
    void draw();
    
    ofVec2f pos;
    float angle;
    float r;
    int now, target;
    float steps, strength, size;
};