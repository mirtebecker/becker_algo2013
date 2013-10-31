#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    for(int i = 0; i < 10; i++){
        Rectangle tmpRect;
        rectList.push_back(tmpRect);
        
        float randomAlpha;
        randomAlpha = ofRandom(0,1);
        alphaList.push_back(randomAlpha);
        
        float randomSpeed;
        randomSpeed = ofRandom(0.5,0.2);
        speedList.push_back(randomSpeed);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    mousePos.x = mouseX;
    mousePos.y = mouseY;
    
    for(int i = 0; i < rectList.size(); i++){
        if(i == 0){
            rectList[i].xenoToPoint(mousePos.x, mousePos.y, speedList[i]);
        }else {
            rectList[i].xenoToPoint(rectList[i-1].pos.x, rectList[i-1].pos.y, speedList[i]);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i = 0; i < rectList.size(); i++){
        rectList[i].draw(0, 255*alphaList[i]);
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
