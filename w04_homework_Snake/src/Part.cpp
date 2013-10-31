//
//  Snake.cpp
//  w4_homework_Snake
//
//  Created by Mirte Becker on 9/24/13.
//
//

#include "Part.h"

Part::Part(){
    radius = 15;
}

void Part::draw(ofVec2f target, float size, float i, float catchUpSpeed){
    ofPushMatrix();{
        ofTranslate(pos);
    
        float dx = target.x - pos.x;
        float dy = target.y - pos.y;
        angle = atan2(dy, dx);
        ofRotate(ofRadToDeg(angle));
        
        pos.x = catchUpSpeed * target.x + (1-catchUpSpeed) * pos.x;
        pos.y = catchUpSpeed * target.y + (1-catchUpSpeed) * pos.y;
        
        // Snake
        ofFill();
        
        float angle = ofGetElapsedTimef()+(360/30);
        float add = radius * sin(angle)*i;
        
        ofSetColor(255);
        ofCircle(0, 0+add, size);
    }ofPopMatrix();
}