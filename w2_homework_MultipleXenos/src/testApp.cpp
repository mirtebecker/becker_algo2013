#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    myRect1.pos.x = ofRandom(ofGetWindowWidth());
    myRect1.pos.y = ofRandom(ofGetWindowHeight());
    
    myRect2.pos.x = ofRandom(ofGetWindowWidth());;
    myRect1.pos.y = ofRandom(ofGetWindowHeight());
    
    myRect3.pos.x = ofRandom(ofGetWindowWidth());;
    myRect1.pos.y = ofRandom(ofGetWindowHeight());
}

//--------------------------------------------------------------
void testApp::update(){
    myRect1.xenoToPoint(mouseX, mouseY, 0.03);
    myRect2.xenoToPoint(mouseX, mouseY, 0.2);
    myRect3.xenoToPoint(mouseX, mouseY, 0.008);
}

//--------------------------------------------------------------
void testApp::draw(){
    myRect1.draw(255, 0, 0, 255*0.1);
    myRect2.draw(255, 0, 0, 255*0.5);
    myRect3.draw(255, 0, 0, 255*0.9);
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
