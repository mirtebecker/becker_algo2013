//
//  Particle.h
//  w8_homework_VectorField
//
//  Created by Mirte Becker on 10/18/13.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    Particle();
    
    void setParams(float px, float py, float vx, float vy);
    void addForce(ofVec2f force);
    void addDampingForce();
    void resetForce();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    ofVec2f damping;
    
    void update();
    void draw();
};