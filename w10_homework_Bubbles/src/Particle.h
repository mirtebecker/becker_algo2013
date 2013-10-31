//
//  Particle.h
//  w10_homework_SquashStretch
//
//  Created by Mirte Becker on 10/30/13.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    
    Particle();
    
    //void setParams(float px, float py, float vx, float vy);
    void addForce( ofVec2f force );
    void addDampingForce();
    void resetForce();
    
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    ofVec2f damping;
    
    float width;
    float height;
    
    float offset;
    
};