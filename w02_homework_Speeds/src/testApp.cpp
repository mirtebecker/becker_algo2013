#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:
	
	ofSetVerticalSync(true);
	
	// set the "a" and "b" positions of the rectangle
	myRectangle.posa.x = 0;
	myRectangle.posa.y = ofGetWindowHeight()/2;
	myRectangle.posb.x = ofGetWindowWidth();
	myRectangle.posb.y = ofGetWindowHeight()/2;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter
    speed = 0.01f;
}

//--------------------------------------------------------------
void testApp::update(){
	pct += speed;							// increase by a certain amount
	myRectangle.interpolateByPct(pct);		// go between pta and ptb
    
    speedStr = "SPEED "+ofToString(speed);
    pixelsecondStr = "PIXEL/SECOND "+ofToString(speed*ofGetFrameRate());
    kmhourStr = "KM/HOUR "+ofToString((speed*ofGetFrameRate()) * (1/37.795275591) * (1/100000) * (3600)); //this doesn't work yet
}

//--------------------------------------------------------------
void testApp::draw(){    
	myRectangle.draw();
    
    ofDrawBitmapString(ofToString("CLICK TO REFRESH"), 20, 30);
    ofDrawBitmapString(ofToString("KEY UP/DOWN TO CHANGE SPEED"), 20, 50);
    
    ofSetColor(0);
    ofDrawBitmapString(ofToString(speedStr), 20, 70);
    ofDrawBitmapString(ofToString(pixelsecondStr), 20, 90);
    ofDrawBitmapString(ofToString(kmhourStr), 20, 110);
    
    if(speed == 0.03f){
        ofSetColor(255);
        ofDrawBitmapString("Fastest still perceptible speed", 120, 70);
    }
    
    if(speed > 0.08f && speed < 0.09f){ // somehow == doesn't always work for this number
        ofSetColor(255);
        ofDrawBitmapString("Fastest non moving speed", 120, 70);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    if (key == OF_KEY_UP){
        speed += 0.01f;
        pct = 0;
        cout << speed;

    }
    if (key == OF_KEY_DOWN){
        if(speed > 0.01f){
            speed -= 0.01f;
            pct = 0;
            cout << speed;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    pct = 0;
	//myRectangle.posa.x = x;
	//myRectangle.posa.y = y;
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
