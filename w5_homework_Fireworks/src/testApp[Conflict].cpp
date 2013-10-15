#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    pos = ofVec2f(ofRandom(200, 800), ofGetWindowHeight());
    target = ofRandom(20, ofGetWindowHeight()/2);
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    float noise = ofNoise( pos.x * 0.03, pos.y * 0.03);
    pos.y -= 5;
    pos.x -= noise;
    
//    if(pos.y > target){
//        pos.x -= sin(angle) * steps;
//        pos.y -= cos(angle) * steps;
//    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    ofCircle(pos, 1);
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
