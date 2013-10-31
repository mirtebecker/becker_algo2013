#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofBackground(255);
    
    bRadius = true;
    radius = 150.0;
    radius2 = 300.0;
    
    degrees = 0.0;
}

//--------------------------------------------------------------
void testApp::update(){
    degrees++;
    
    if(radius > 350){
        bRadius = false;
    }
    if(radius < 100){
        bRadius = true;
    }
    
    if(bRadius){
        radius++;
    }else {
        radius--;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackgroundGradient(ofColor(100, 5, 100, 25), ofColor(0, 25), OF_GRADIENT_CIRCULAR);
    ofTranslate(ofGetWindowSize()/2);
    
    float angle = ofGetElapsedTimef() * 3.5;
    float x = radius * sin(angle);
    float y = radius * cos(angle);
    
    float angle2 = ofGetElapsedTimef() * 0.5;
    float x2 = radius2 * sin(angle2);
    float y2 = radius2 * cos(angle2);
    
    ofPoint tmp;
    tmp.x = x;
    tmp.y = y;
    pointList.push_back(tmp);
    
    if(pointList.size() > 50){
        pointList.erase(pointList.begin());
    }
    
    for(int i = 0; i < pointList.size(); i++){
        ofPushMatrix();{
            ofBeginShape();{
                //ofColor c = ofColor::fromHsb(0, 0, cBright, 50);
                ofSetColor(0, 255*0.1);
                ofNoFill();
                ofRotate(degrees);
                ofRect(pointList[i].x, pointList[i].y, x2, y2);
                //ofCircle(pointList[i].x, pointList[i].y, x2);
                //ofLine(pointList[i].x, pointList[i].y, x2, y2);
                //ofTriangle(pointList[i].x, pointList[i].y, pointList[i].y, pointList[i].y+40, pointList[i].x+90, pointList[i].y+40);
            }ofEndShape();
        }ofPopMatrix();
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
