//
//  Rectangle.cpp
//  w2_homework_clickAtoB
//
//  Created by Mirte Becker on 9/1/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(){
    catchUpSpeed = 0.03;
}

void Rectangle::draw(){
    ofFill();
    ofSetColor(255, 0, 0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(pos.x, pos.y, 20, 20);
}

void Rectangle::xenoToPoint(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}