//
//  Particle.cpp
//  w10_homework_SquashStretch
//
//  Created by Mirte Becker on 10/30/13.
//
//

#include "Particle.h"

Particle::Particle(){
    damping.set(0.01f);
    width = 50;
    height = 50;
    
    pos.set(ofGetWindowSize()/2);
    vel.set(ofRandom(-1, 1));
}

void Particle::addForce( ofVec2f force ){
    frc += force;
}

void Particle::addDampingForce(){
    frc - frc * (vel - damping);
}

void Particle::resetForce(){
    frc.set(0,0);
}

void Particle::update(){
    if(pos.x > 0 && pos.x < ofGetWindowWidth() && pos.y > 0 && pos.y < ofGetWindowHeight()){
        vel += frc;
        pos += vel;
    }
}

void Particle::draw(){
    ofNoFill();
    ofSetColor(45, 30, 200, 255*0.5);
    ofPushMatrix();{
        ofBeginShape();{
            for (int i = 0; i < 100; i++){
                float add = ofNoise(i/50.0f, offset+ofGetElapsedTimef()*0.15);
                ofVertex( pos.x + (width + height * add) * cos((i/100.0) * TWO_PI),
                          pos.y + (width + height * add) * sin((i/100.0) * TWO_PI));
            }
            float add = ofNoise(0/50.0f, offset+ofGetElapsedTimef()*0.15);
            
            // control point?
            ofVertex( pos.x + (width + height * add) * cos((0/100.0) * TWO_PI),
                      pos.y + (width + height * add) * sin((0/100.0) * TWO_PI));
            
        }ofEndShape();
        
    }ofPopMatrix();
    //ofEllipse(pos, width, height);
}