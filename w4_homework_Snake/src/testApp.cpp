#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    ofPoint mousePos( mouseX, mouseY );
    mySnake.mousePos = mousePos;
}

//--------------------------------------------------------------
void testApp::draw(){
    mySnake.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == OF_KEY_UP){
        mySnake.parts++;
    }
    
    if(key == OF_KEY_DOWN){
        mySnake.parts--;
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
