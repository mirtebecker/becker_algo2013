#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class Rectangle {
    
public:
	
    Rectangle();
	
    void draw();
    void interpolateByPct(float myPct);
    
    ofPoint		pos;
    
    ofPoint		posa;
    ofPoint		posb;
    
    float		pct;	// what pct are we between "a" and "b"
	
	
    
};

#endif // RECTANGLE_H
