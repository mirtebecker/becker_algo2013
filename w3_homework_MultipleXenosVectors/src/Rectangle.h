//
//  Rectangle.h
//  w3_homework_MultipleXenosVectors
//
//  Created by Mirte Becker on 9/9/13.
//
//

#pragma once
#include "ofMain.h"

class Rectangle {
public:
    Rectangle();
    
    void draw(float b, float a);
    void xenoToPoint(float catchX, float catchY, float catchUpSpeed);
    
    ofVec2f pos;
};

