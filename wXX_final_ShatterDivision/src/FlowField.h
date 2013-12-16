//
//  FlowField.h
//  wXX_final_ShatterDivision
//
//  Created by Mirte Becker on 12/10/13.
//
//

#pragma
#include "ofMain.h"

class FlowField{
public:
    FlowField();
    
    void setup(int width, int height, int res);
    ofVec2f getForceAtScreenPos(ofVec2f pos);
    void useImage();
    void draw();
    
    vector <vector<ofVec2f> > flowList;
    
    int fieldWidth;
    int fieldHeight;
    int fieldRes;
    
    ofImage img;
    
};