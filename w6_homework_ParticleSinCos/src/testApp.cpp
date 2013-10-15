#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofBackground(122, 0, 38);
    ofEnableAlphaBlending();
    
    // Particles
    steps = 3;
    strength = 1;
    size = 250;
    
    now = ofGetElapsedTimeMillis();
    target = ofGetElapsedTimeMillis() + ofRandom(1000, 2000);
    
    for(int i = 0; i < 100; i++){
        Particle p;
        particleList.push_back(p);
    }
    
    // UI
    gui = new ofxUICanvas;
    
    gui->setColorBack(ofColor(255, 100));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255, 100));
    gui->addSlider("Steps", 1, 10, steps);
    gui->addSlider("Strength", 0, 50, strength);
    gui->addSlider("Size", 0, 500, size);
    
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);
    
}

//--------------------------------------------------------------
void testApp::exit(){
    delete gui;
}

//--------------------------------------------------------------
void testApp::onGuiEvent(ofxUIEventArgs &e){
    if( e.getName() == "Steps" ){
        ofxUISlider *stepsSlider = (ofxUISlider *)e.widget;
        steps = stepsSlider->getScaledValue();
    }
    if( e.getName() == "Strength" ){
        ofxUISlider *strengthSlider = (ofxUISlider *)e.widget;
        strength = strengthSlider->getScaledValue();
    }
    if( e.getName() == "Size" ){
        ofxUISlider *sizeSlider = (ofxUISlider *)e.widget;
        size = sizeSlider->getScaledValue();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < particleList.size(); i++){
        particleList[i].update(steps, strength, size);
    }
    
    if(ofGetElapsedTimeMillis() > target){
        strength = ofRandom(0, 25);
        now = ofGetElapsedTimeMillis();
        target = ofGetElapsedTimeMillis() + ofRandom(1000, 3000);
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackgroundGradient(ofColor(122, 0, 38, 1), ofColor(122, 0, 38, 1), OF_GRADIENT_CIRCULAR);
    
    ofSetColor(0);
    ofFill();
    ofRect(0, 0, 210, 210);
    
    for(int i = 0; i < particleList.size(); i++){
        particleList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'c'){
        ofClear(0);
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
