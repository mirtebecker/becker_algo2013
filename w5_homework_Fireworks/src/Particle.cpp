//
//  Particle.cpp
//  w5_inclass_SingleParticle
//
//  Created by Mirte Becker on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle(){
    setParams(0, 0, 0, 0);
    damping.set(0.01, 0.01);
    
    target = ofGetElapsedTimef() + ofRandom(1,2);
    
    fill = ofRandom(1, 3);
    shape = ofRandom(1, 4);
    color = ofRandom(1, 5);
    size1 = ofRandom(10, 50);
    size2 = ofRandom(10, 50);
    
    c1 = ofColor(70, 220, 240, ofRandom(80, 255)); //cyan
    c2 = ofColor(245, 50, 125, ofRandom(80, 255)); //magenta
    c3 = ofColor(245, 130, 100, ofRandom(80, 255)); //orange
    c4 = ofColor(115, 130, 240, ofRandom(80, 255)); //purple
    
    //rotateNum = ofRandom(0, 3);
    
    ofSetLineWidth(2);
}

void Particle::setParams(float px, float py, float vx, float vy){
    pos.set(px, py);
    vel.set(vx, vy);
}

void Particle::addForce(ofVec2f force){
    frc += force;
}

void Particle::resetForces(){
    frc.set(0, 0);
}

void Particle::addDampingForce(){
    frc = frc - vel * damping;
}

void Particle::update(){
    vel += frc;
    pos += vel;
    
    
    if(ofGetElapsedTimef() > target){
        cout << "target" << endl;
        pos += vel + sin(ofNoise(pos.x / 5, pos.y / 5) * 5);
    }
    
    //rotate += rotateNum;
}

void Particle::draw(){
    cout << ofGetElapsedTimef() << " | " << target << endl;

    
    ofPushMatrix();{
        
        switch(fill){
            case 1:
                ofFill();
                break;
            case 2:
                ofNoFill();
                break;
        }
        
        switch(shape) {
            case 1:
                ofCircle(pos, size1);
                break;
            case 2:
                ofRect(pos, size1, size2);
                break;
            case 3:
                ofRectRounded(pos.x, pos.y, size1, size2, size1);
                break;
        }
        
        switch(color) {
            case 1:
                ofSetColor(c1);
                break;
            case 2:
                ofSetColor(c2);
                break;
            case 3:
                ofSetColor(c3);
                break;
            case 4:
                ofSetColor(c4);
                break;
        }
        
    }ofPopMatrix();
}