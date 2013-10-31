#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    
    size = 5;
    
    for(int i = 0; i < 5; i++){
        Part p;
        partList.push_back(p);
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < partList.size(); i++){
        ofVec2f targetPos;
        
        if(i == 0){
            targetPos.x = mouseX;
            targetPos.y = mouseY;
            catchUpSpeed = 0.03;
        }else{
            targetPos.x = partList[i-1].pos.x+size;
            targetPos.y = partList[i-1].pos.y+size;
            catchUpSpeed = 0.03;
        }
        
        partList[i].draw(targetPos, size, i, catchUpSpeed);
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
