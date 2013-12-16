//
//  Seed.h
//  wXX_final_ShatterDivision
//
//  Created by Mirte Becker on 12/10/13.
//
//

#pragma once
#include "ofMain.h"

class Seed{
public:
    
    Seed();
    void update(bool bounce);
    void addForce(ofVec2f force);
    void resetForce();
    void drawSeed();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    int c;
};