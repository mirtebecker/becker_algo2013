//
//  VectorField.cpp
//  w8_homework_VectorField
//
//  Created by Mirte Becker on 10/18/13.
//
//

#include "VectorField.h"

VectorField::VectorField(){
    
}

void VectorField::setup(int width, int height, int res){
    fieldWidth = width;
    fieldHeight = height;
    fieldRes = res;
    
    int cols = fieldWidth / fieldRes;
    int rows = fieldHeight / fieldRes;
    
    for(int y = 0; y < rows; y++){
        vector<ofVec2f> myList;
        
        for(int x  = 0; x < cols; x++){
            ofVec2f dir(ofRandom(-5, 5), ofRandom(-5, 5));
            myList.push_back(dir);
        }
        
        flowList.push_back(myList);
    }
}

ofVec2f VectorField::getForceAtScreenPos(ofVec2f pos){
    float pctX = pos.x / fieldWidth;
    float pctY = pos.y / fieldHeight;
    
    int cols = fieldWidth / fieldRes;
    int rows = fieldHeight / fieldRes;

    int xVal = ofClamp(pctX * cols, 0, cols-1);
    int yVal = ofClamp(pctY * rows, 0, rows-1);
    
    ofVec2f newPos;
    newPos.set(flowList[yVal][xVal]);
    return newPos;
}

void VectorField::update(){
    
}

void VectorField::draw(){
    for(int y = 0; y < flowList.size(); y++){
        for(int x = 0; x < flowList[y].size(); x++){
            ofVec2f tmpPos = ofVec2f(x*fieldRes, y*fieldRes);
            ofLine(tmpPos, tmpPos+flowList[y][x]);
        }
    }
}