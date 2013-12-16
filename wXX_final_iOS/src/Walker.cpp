//
//  Walker.cpp
//  final
//
//  Created by Mirte Becker on 12/13/13.
//
//

#include "Walker.h"

Walker::Walker(){
    pos = ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/2-50);
    r = ofRandom(-10, 10);
    
    steps = ofRandom(1, 5);
    strength = ofRandom(1, 3);
    size = ofRandom(200, 400);
}

void Walker::update(){
    if(ofGetElapsedTimeMillis() > target){
        strength = ofRandom(0, 25);
        now = ofGetElapsedTimeMillis();
        target = ofGetElapsedTimeMillis() + ofRandom(1000, 3000);
    }
    
    angle = ofNoise( pos.x / size, pos.y / size ) * strength;
    pos.x += cos(angle+r) * steps;
    pos.y += sin(angle+r) * steps;
}

void Walker::draw(){
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 15.0; // from week 4, 08_Perlin_Particles
    ofSetColor(255, noise*10);
    ofCircle(pos, 2);
}