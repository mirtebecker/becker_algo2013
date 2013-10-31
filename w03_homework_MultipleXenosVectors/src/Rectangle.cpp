//
//  Rectangle.cpp
//  w3_homework_MultipleXenosVectors
//
//  Created by Mirte Becker on 9/9/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(){
    
}

void Rectangle::draw(float b, float a){
    ofFill();
    ofSetColor(b, a);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(pos, 20, 20);
}

void Rectangle::xenoToPoint(float catchX, float catchY, float catchUpSpeed){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}

