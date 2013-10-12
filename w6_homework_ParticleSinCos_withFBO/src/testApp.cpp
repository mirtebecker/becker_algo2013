#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    ofEnableAlphaBlending();
    
    // Particles
    steps = 3;
    strength = 1;
    size = 300;
    
    now = ofGetElapsedTimeMillis();
    target = ofGetElapsedTimeMillis() + ofRandom(1000, 2000);
    
    for(int i = 0; i < 100; i++){
        Particle p;
        particleList.push_back(p);
    }
    
    // UI
    gui = new ofxUICanvas;
    gui->setVisible(false);
    
    fboUI = new ofFbo;
    fbo = new ofFbo;
    
    fboUI->allocate(210, 210, GL_RGBA);
    fbo->allocate(1024, 768, GL_RGBA);
    
    // for a special (memory issue related) surprise, delete the part where the fbo's are cleared:
    fboUI->begin();{
        ofClear(0, 0);
    }fboUI->end();
    
    fbo->begin();{
        ofClear(255, 0, 255, 0);
        //ofClear(0, 0);
    }fbo->end();
    //
    
    fboUI->begin();{
        ofFill();
        ofSetColor(255, 100);
        ofRect(0, 0, 210, 210);
        
        gui->setColorBack(ofColor(255, 100));
        gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255, 100));
        gui->addSlider("Steps", 1, 10, steps);
        gui->addSlider("Strength", 0, 50, strength);
        gui->addSlider("Size", 0, 500, size);
    }fboUI->end();
    
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);
}

//--------------------------------------------------------------
void testApp::exit(){
    delete gui;
    
    // thought this might fix the memory issue, but didn't:
    delete fbo;
    delete fboUI;
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
    
    fbo->begin();{
        ofFill();
        ofSetColor(0, 0);
        ofRect(0, 0, 1024, 768);
        
        for(int i = 0; i < particleList.size(); i++){
            particleList[i].draw();
        }
    }fbo->end();
}

//--------------------------------------------------------------
void testApp::draw(){
    // drawing fbo's
    fboUI->draw(0, 0);
    fbo->draw(0, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'h'){
        gui->toggleVisible();
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
