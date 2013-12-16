//
//  Seed.cpp
//  wXX_final_ShatterDivision
//
//  Created by Mirte Becker on 12/10/13.
//
//

#include "Seed.h"

Seed::Seed(){
    pos.set(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    vel.set(ofRandom(-1, 1), ofRandom(-1, 1));
    c = ofRandom(255);
}

void Seed::addForce(ofVec2f force){
    frc += force;
}

void Seed::resetForce(){
    frc.set(0, 0);
}

void Seed::update(bool bounce){
    vel += frc;
    pos += vel;
    
    if(bounce){
        if(pos.x < 0 || pos.x > ofGetWindowWidth()){
            vel.x *= -1;
        }
        if(pos.y < 0 || pos.y > ofGetWindowHeight()){
            vel.y *= -1;
        }
    }
}

void Seed::drawSeed(){
    ofSetColor(255);
    ofFill();
    ofCircle(pos, 5);
}