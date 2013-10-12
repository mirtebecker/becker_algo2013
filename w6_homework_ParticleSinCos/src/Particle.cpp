//
//  Particle.cpp
//  w6_homework_ParticleSinCos
//
//  Created by Mirte Becker on 10/11/13.
//
//

#include "Particle.h"

Particle::Particle(){
    pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
}

void Particle::update( float steps, float strength, float size ){
    angle = ofNoise( pos.x / size, pos.y / size ) * strength;
    pos.x += cos(angle) * steps;
    pos.y += sin(angle) * steps;
}

void Particle::draw(){
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 15.0; // from week 4, 08_Perlin_Particles
    ofSetColor(255, noise*10);
    ofCircle(pos, 1);
}