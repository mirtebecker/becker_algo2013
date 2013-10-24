//
//  VectorField.h
//  w8_homework_VectorField
//
//  Created by Mirte Becker on 10/18/13.
//
//

#pragma once
#include "ofMain.h"

class VectorField{
public:
    VectorField();
    
    void setup( int width, int height, int res);
    void update();
    void draw();
    
    ofVec2f getForceAtScreenPos(ofVec2f pos);

    vector <vector<ofVec2f> > flowList; //2d array
    
    int fieldWidth, fieldHeight, fieldRes;
};