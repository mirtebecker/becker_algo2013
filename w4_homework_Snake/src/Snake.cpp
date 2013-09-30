//
//  Snake.cpp
//  w4_homework_Snake
//
//  Created by Mirte Becker on 9/24/13.
//
//

#include "Snake.h"

Snake::Snake(){
    catchUpSpeed = 0.005;
    parts = 20;
    radius = 15;
}

void Snake::draw(){
    ofPushMatrix();{
        ofTranslate(pos);
        
        float dx = mousePos.x - pos.x;
        float dy = mousePos.y - pos.y;
        
        angle = atan2(dy, dx);
        
        ofRotate( ofRadToDeg(angle+PI) );
        
        pos.x = catchUpSpeed * mousePos.x + (1-catchUpSpeed) * pos.x;
        pos.y = catchUpSpeed * mousePos.y + (1-catchUpSpeed) * pos.y;
        
        // snake
        ofFill();
        
        for(int i = 0; i < parts; i++){
            float angle = ofGetElapsedTimef()+(360/30)*i;
            float add = radius * sin(angle);
            ofSetColor(255);
            ofCircle(5*i, 0+add, 5);
        }
    }ofPopMatrix();
}