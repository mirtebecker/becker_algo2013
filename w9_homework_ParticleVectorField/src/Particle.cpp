//
//  Particle.cpp
//  w8_homework_VectorField
//
//  Created by Mirte Becker on 10/18/13.
//
//

#include "Particle.h"

Particle::Particle(){
    //setParams(0, 0, 0, 0);
    damping.set(0.01f);
}

void Particle::setParams(float px, float py, float vx, float vy){
    pos.set(px, py);
    vel.set(vx, vy);
}

void Particle::addForce(ofVec2f force){
    frc += force;
}

void Particle::addDampingForce(){
    frc = frc - (vel*damping);
}

void Particle::resetForce(){
    frc.set(0,0);
}

void Particle::update(){
    vel += frc;
    pos += vel;
}

void Particle::draw(){
    ofCircle(pos, 5);
}