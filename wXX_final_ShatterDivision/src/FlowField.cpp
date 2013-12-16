//
//  FlowField.cpp
//  wXX_final_ShatterDivision
//
//  Created by Mirte Becker on 12/10/13.
//
//

#include "FlowField.h"

FlowField::FlowField(){
    // Pablo Picasso - Girl before a Mirror
    img.loadImage("picasso.jpg");
}

void FlowField::setup(int width, int height, int res){
    fieldWidth = width;
    fieldHeight = height;
    fieldRes = res;
    
    int cols = fieldWidth / fieldRes;
    int rows = fieldHeight / fieldRes;
    
    for(int y = 0; y < rows; y++){
        vector<ofVec2f> myList;
        
        // using brightness of an image for flowfield
        // code from Jennifer Presto
        for(int x = 0; x < cols; x++){
            ofColor tmpColor = img.getColor(x * fieldRes + (fieldRes * 0.5), y * fieldRes + (fieldRes * 0.5));
            
            float brightness = tmpColor.getBrightness();
            float angle = ofMap(brightness, 0, 255, 0, TWO_PI);
            
            ofVec2f dir;
            dir.x = - cos(angle);
            dir.y = - sin(angle);
            
            if (brightness <= 4) {
                dir.x = cos(angle) * -10;
                dir.y = sin(angle) * -10;
            } else {
                dir.x = cos(angle) * 10;
                dir.y = sin(angle) * 10;
            }
            myList.push_back(dir);
        }
        
        flowList.push_back(myList);
    }
}

ofVec2f FlowField:: getForceAtScreenPos(ofVec2f pos){
    float pctX = pos.x / fieldWidth;
    float pctY = pos.y / fieldHeight;
    
    int cols = fieldWidth / fieldRes;
    int rows = fieldHeight / fieldRes;
    
    int xVal = ofClamp( pctX * cols, 0, cols-1 );
    int yVal = ofClamp( pctY * rows, 0, rows-1 );
    
    ofVec2f newPos;
    newPos.set( flowList[yVal][xVal] );
    
    return newPos;
}


void FlowField::draw(){
    for(int y = 0; y < flowList.size(); y++){
        for(int x = 0; x < flowList[y].size(); x++){
            ofVec2f tmp = ofVec2f(x*fieldRes, y*fieldRes);
            ofLine(tmp, tmp+flowList[y][x]);
        }
    }
}