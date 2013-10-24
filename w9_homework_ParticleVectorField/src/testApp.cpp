#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofSetVerticalSync(true);
    
    myVF.setup(ofGetWindowWidth(), ofGetWindowHeight(), 20);
        
    for(int i = 0; i < 100; i++){
        Particle tmp;
        particleList.push_back(tmp);
        
        particleList[i].setParams(ofRandomWidth(), ofRandomHeight(), ofRandom(-1, 1), ofRandom(-1, 1));
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < particleList.size();i++){
        particleList[i].resetForce();
        particleList[i].addForce(myVF.getForceAtScreenPos( particleList[i].pos )*0.005);
        particleList[i].addDampingForce();
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0);
    myVF.draw();
    
    ofSetColor(255, 0, 255);
    for(int i = 0; i < particleList.size(); i++){
        particleList[i].draw();
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
