#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    cUp = true;
    sUp = true;
}

//--------------------------------------------------------------
void testApp::update(){
    myRect.xenoToPoint(mouseX, mouseY);
    myRect.degrees++;
    
    if(myRect.cBright > 254){
        cUp = false;
    }
    if(myRect.cBright < 1){
        cUp = true;
    }
    
    if(cUp){
        myRect.cBright++;
    }else {
        myRect.cBright--;
    }
    
    if(myRect.size > 254){
        sUp = false;
    }
    if(myRect.size < 1){
        sUp = true;
    }
    
    if(sUp){
        myRect.size++;
    }else {
        myRect.size--;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor semiTransparent(0, 255*0.9);
    ofSetColor(semiTransparent);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    myRect.draw();
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
