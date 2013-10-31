#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    /// using code from the openFrameworks fboTrailsExample
    
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    
    fboUI.allocate(210, 210);
    fbo.allocate(1024, 768);
    
    // we have to clear all the fbos so that we don't see any artefacts
	// the clearing color does not matter here, as the alpha value is 0, that means the fbo is cleared from all colors
	// whenever we want to draw/update something inside the fbo, we have to write that inbetween fbo.begin() and fbo.end()
    
    fboUI.begin();{
        ofClear(255, 0);
    }fboUI.end();
    
    fbo.begin();{
        ofClear(255, 0, 255, 0);
    }fbo.end();
    
}

//--------------------------------------------------------------
void testApp::update(){
    fboUI.begin();{
        //this is where we fade the fbo
        //by drawing a rectangle the size of the fbo with a small alpha value, we can slowly fade the current contents of the fbo.
        ofFill();
        ofSetColor(0, 255);
        ofRect(0, 0, 210, 210);
        
        // draw graphics
        ofNoFill();
        ofSetColor(255, 255, 255);
        
        ofFill();
        ofCircle(ofGetMouseX() % 210, ofGetMouseY(), 8);
    }fboUI.end();
    
    fbo.begin();{
        //this is where we fade the fbo
        //by drawing a rectangle the size of the fbo with a small alpha value, we can slowly fade the current contents of the fbo.
        ofFill();
        ofSetColor(255, 0, 255, 5);
        ofRect(0, 0, 1024, 768);
        
        // draw graphics
        ofNoFill();
        ofSetColor(255, 255, 255);
        
        ofFill();
        ofCircle(ofGetMouseX() % 768, ofGetMouseY(), 8);
    }fbo.end();
}

//--------------------------------------------------------------
void testApp::draw(){
    // drawing fbo's
    fboUI.draw(0,0);
    fbo.draw(0, 0);
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
