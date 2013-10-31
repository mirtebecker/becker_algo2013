#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(188, 188, 188);
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    
    pos = ofVec2f(ofRandom(200, 800), ofGetWindowHeight());
    target = ofRandom(50, ofGetWindowHeight()/2);
    
    explode = false;
    
    for(int i =0; i < 100; i++){
        addParticle();
    }
}

//--------------------------------------------------------------
void testApp::addParticle(){
    Particle tmp;
    float vx = ofRandom(-4, 4);
    float vy = ofRandom(-4, 4);
    tmp.setParams(300, 300, vx, vy);
    particleList.push_back(tmp);
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i = 0; i < particleList.size(); i++){
        particleList[i].resetForces();
        particleList[i].addForce(ofVec2f(0, 0.01));
        particleList[i].addDampingForce();
        particleList[i].update();
    }

    if(pos.y > target){
        float noise = ofNoise( pos.x * 0.03, pos.y * 0.03);
        pos.y -= 5;
        pos.x -= noise;
    }
    
    if(pos.y < target){
        
        for(int i = 0; i < particleList.size(); i++){
            float circVal = ofRandom(TWO_PI);
            float vx = cos(circVal) * ofRandom(0, 4);
            float vy = sin(circVal) * ofRandom(0, 4);
            
            particleList[i].setParams(pos.x, pos.y, vx, vy);
        }
        
        explode = true;
        cout << explode << endl;
        
        pos = ofVec2f(ofRandom(200, 800), ofGetWindowHeight());
        target = ofRandom(20, ofGetWindowHeight()/2);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackgroundGradient(ofColor(188, 188, 188, 150), ofColor(188, 188, 188, 150), OF_GRADIENT_CIRCULAR);
    
    ofSetColor(245, 50, 125);
    ofFill();
    ofCircle(pos, 3);
    
    if(explode == true){
        for(int i = 0; i < particleList.size(); i++){
            particleList[i].draw();
        }
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
