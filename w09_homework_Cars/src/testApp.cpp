#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSeedRandom();

    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    pos = ofGetWindowSize() / 2;
    dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );

    ferrari.setParams( pos, ofVec2f(10, -5), 10.0, 0.4 );
    volvo.setParams( pos, ofVec2f(3, -3), 5.0, 0.2 );

    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){

    // 1
    ferrari.seek( dest );
    ferrari.addRepulsionForce(volvo.pos.x, volvo.pos.y, 60, 1);
    ferrari.update();

    
    if( ferrari.pos.distance(dest) < 5){
        dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    }
    
    // 2
    volvo.seek( dest );
    volvo.addRepulsionForce(ferrari.pos.x, ferrari.pos.y, 60, 1);
    volvo.update();
    
    if( volvo.pos.distance(dest) < 5){
        dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // 1
    ofSetColor(255, 0, 0);
    ferrari.draw();

    // 2
    ofSetColor(40, 130, 180);
    volvo.draw();
    
    ofSetColor(255);
    ofCircle( dest, 4 );
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
