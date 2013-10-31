//
//  Particle.h
//  w6_homework_ParticleSinCos
//
//  Created by Mirte Becker on 10/12/13.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    Particle();
    void update( float steps, float strength, float size );
    void draw();
    
    ofVec2f pos;
    float angle;
};