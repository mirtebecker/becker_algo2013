//
//  Rectangle.cpp
//  w2_homework_multiplexenos
//
//  Created by Mirte Becker on 9/1/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(){
}

void Rectangle::draw(float r, float g, float b, float a){
    ofFill();
    ofSetColor(r, g, b, a);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(pos.x, pos.y, 20, 20);
}

void Rectangle::xenoToPoint(float catchX, float catchY, float catchUpSpeed){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}

