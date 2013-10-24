#include "testApp.h"

// Audio visualization code used from the SoundPlayerFFTExample

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
        
    radius = 150;
    points = 8;
    degrees = 0;
    
    float angle = ofDegToRad(360/points);
    for(int i = 0; i < points; i++){
        ofPoint tmp;
        tmp.x = cos(angle*i) * radius;
        tmp.y = sin(angle*i) * radius;
        pos.push_back(tmp);
        
        // getting errors, so doing the math myself...
        // cos(0.7853982*0) * 250 = 250;
        // cos(0.7853982*1) * 250 = 176;
        // cos(0.7853982*2) * 250 = 0;
        // cos(0.7853982*3) * 250 = -176;
        // cos(0.7853982*4) * 250 = -250;
        // cos(0.7853982*5) * 250 = -176;
        // cos(0.7853982*6) * 250 = 0;
        // cos(0.7853982*7) * 250 = 176;
    }
    
    mp3.loadSound("fortknox.mp3");
    mp3.play();
    
    fftSmoothed = new float[8192];
	for (int i = 0; i < 8192; i++){
		fftSmoothed[i] = 0;
	}
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i = 0; i < points; i++){
        pos[i].x += fftSmoothed[1]*i;
        pos[i].y += fftSmoothed[1]*i;
    }
    
    float angle = fftSmoothed[1];
    degrees += radius * sin(angle);
    
	float * val = ofSoundGetSpectrum(points);
	for (int i = 0;i < points; i++){
		fftSmoothed[i] *= 0.96f;
		if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    ofDrawBitmapString("Fort Knox", 500, 580);
    ofBackgroundGradient(ofColor(200, 25), ofColor(237*(fftSmoothed[0]), 20, 90, 25), OF_GRADIENT_CIRCULAR);
    ofTranslate(ofGetWindowSize()/2);
    
    ofSetColor(0);
    ofNoFill();
    
    ofPushMatrix();{
        ofBeginShape();{
            ofRotate(degrees);
            for (int i = 0; i < points; i++){
                ofVertex(pos[i]);
                //string posStr = ofToString(i)+":"+ofToString(pos[i].x)+","+ofToString(pos[i].y);
                //ofDrawBitmapString(posStr, pos[i]-10);
            }
            ofVertex(pos[0]); // close the shape
            
        }ofEndShape();
    }ofPopMatrix();
    
    ofFill();
    
    for(int i = 0; i < points; i++){
        //ofCircle(pos[i].x, pos[i].y, 4);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
