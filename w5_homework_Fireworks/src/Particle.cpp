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
}

void Particle::setParams(float px, float py, float vx, float vy){
    pos.set(px, py);
    vel.set(vx, vy);
    
    now = ofGetElapsedTimef();
    target = ofGetElapsedTimef() + ofRandom(1,2);
    
    alpha = ofRandom(1, 254);
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
}

void Particle::draw(){
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofSetColor(240, 20, 90);
    ofCircle(pos, 2);
    
    ofColor(255, alpha);
    ofCircle(pos, 1);
}