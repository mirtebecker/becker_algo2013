//
//  Ball.cpp
//  w3_homework_BouncingBall3D
//
//  Created by Mirte Becker on 9/10/13.
//  Used @cwhitney's inclass code for ofDrawBox and ofDrawSphere.
//
//

#include "Ball.h"

Ball::Ball(){
    boxSize = 200.0;
    
    ofSeedRandom();
    vel.x = ofRandom(0.0, 1.0);
    vel.y = ofRandom(0.0, 1.0);
    vel.z = ofRandom(0.0, 1.0);
    
    pos.x = 0.0;
    pos.y = 0.0;
    pos.z = 0.0;
}

void Ball::update(){
    pos.x += vel.x * 5.0;
    pos.y += vel.y * 5.0;
    pos.z += vel.z * 5.0;
    
    if(pos.x < -boxSize || pos.x > boxSize){
        vel.x *= -1.0;
    }
    if(pos.y < -boxSize || pos.y > boxSize){
        vel.y *= -1.0;
    }
    if(pos.z < -boxSize || pos.z > boxSize){
        vel.z *= -1.0;
    }
}

void Ball::draw(){
    ofTranslate(ofGetWindowSize()/2);
    ofSetColor(0);
    ofNoFill();
    ofDrawBox(0, 0, 0, boxSize*2, boxSize*2, boxSize*2);
    ofDrawSphere(pos.x, pos.y, pos.z, 25);
}

