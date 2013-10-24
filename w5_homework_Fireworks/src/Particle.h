//
//  Particle.h
//  w5_inclass_SingleParticle
//
//  Created by Mirte Becker on 9/30/13.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    
    Particle();
    
    void update();
    void draw();
    
    void setParams(float px, float py, float vx, float vy);
    void addForce(ofVec2f force);
    void addDampingForce();
    void resetForces();
    
    ofVec2f pos;
    ofVec3f vel;
    ofVec2f frc;
    ofVec2f damping;
    
    float now;
    float target;
    float alpha;
    
    float rotate;
    int rotateNum;
    
    int fill, shape, color, size1, size2;
    ofColor c1, c2, c3, c4;
};
