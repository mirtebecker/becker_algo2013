//
//  FlowField.cpp
//  w8_homework_VectorField
//
//  Created by Mirte Becker on 10/18/13.
//
//

#include "FlowField.h"

FlowField::FlowField(){
    
}

void FlowField::setup(int width, int height, int res){
    fieldWidth = width;
    fieldHeight = height;
    fieldRes = res;
    
//    int cols = fieldWidth / fieldRes;
//    int rows = fieldHeight / fieldRes;
//    
//    for(int y = 0; y < rows; y++){
//        vector<ofVec2f> myList;
//        
//        //using perlin noise
//        for(int x = 0; x < cols; x++){
//            float noise = ofMap( ofNoise(x*0.05, y*0.05), 0, 1, 0, TWO_PI);
//            ofVec2f dir(cos(noise)*10, sin(noise)*10);
//            myList.push_back(dir);
//        }
//        
//        flowList.push_back(myList);
//    }
    
}

void FlowField::update( float fft ){
    float loadFft = fft;
    cout << loadFft << endl;
}

void FlowField::draw(){
    
    int cols = fieldWidth / fieldRes;
    int rows = fieldHeight / fieldRes;
    
    for(int y = 0; y < rows; y++){
        vector<ofVec2f> myList;
        
        //using perlin noise
        for(int x = 0; x < cols; x++){
            float noise = ofMap( ofNoise(x*0.05, y*0.05), 0, 1, 0, TWO_PI);
            ofVec2f dir(cos(noise)*10, sin(noise)*10);
            myList.push_back(dir);
        }
        
        flowList.push_back(myList);
    }
    
    for(int y = 0; y < flowList.size(); y++){
        for(int x = 0; x < flowList[y].size(); x++){
            ofVec2f tmp = ofVec2f(x*fieldRes, y*fieldRes);
            ofLine(tmp, tmp+flowList[y][x]);
        }
    }
}