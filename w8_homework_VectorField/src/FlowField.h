//
//  FlowField.h
//  w8_homework_VectorField
//
//  Created by Mirte Becker on 10/18/13.
//
//

#pragma
#include "ofMain.h"

class FlowField{
public:
    FlowField();
    
    void setup(int width, int height, int res);
    void update( float fft );
    void draw();
    
    vector <vector<ofVec2f> > flowList;
    
    int fieldWidth;
    int fieldHeight;
    int fieldRes;
    float loadFft;
    
};