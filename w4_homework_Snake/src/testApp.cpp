#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    
    radius = 15;
    parts = 20;
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofTranslate(ofGetWindowSize()/2);
    ofSetColor(255);
    ofFill();
    
    for(int i = 0; i < parts; i++){
        float angle = ofGetElapsedTimef()*2+(360/(parts*1.5))*i;
        // parts*1.5 doesn't always give good results
        float add = radius * sin(angle);
        ofCircle(pos.x+(10*i), pos.y+add, 10, 10);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == OF_KEY_UP){
        parts++;
    }
    
    if(key == OF_KEY_DOWN){
        parts--;
    }
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
