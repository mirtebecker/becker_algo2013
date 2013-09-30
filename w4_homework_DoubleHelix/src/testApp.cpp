#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    
    cam.setAutoDistance(true);
    
    radius = 50;
    
    for(int i = 0; i < 25; i++){
        float angle = i;
        float Helix1x = radius * sin(angle);
        float Helix1y = radius * cos(angle);
        
        ofPoint Helix1tmp;
        Helix1tmp.x = Helix1x;
        Helix1tmp.y = Helix1y;
        Helix1tmp.z += i*10;
        Helix1.push_back(Helix1tmp);
        
        float angle2 = i+180;
        float Helix2x = radius * sin(angle2);
        float Helix2y = radius * cos(angle2);
        
        ofPoint Helix2tmp;
        Helix2tmp.x = Helix2x;
        Helix2tmp.y = Helix2y;
        Helix2tmp.z += i*10;
        Helix2.push_back(Helix2tmp);
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofNode node = cam.getTarget();
    string camPTrgtStr = "Target = "+ofToString(node.getPosition());
    ofSetColor(255);
    ofDrawBitmapString(camPTrgtStr, 20, 25);
    
    float camDis = cam.getDistance();
    string camDisStr = "Distance = "+ofToString(camDis);
    ofSetColor(255);
    ofDrawBitmapString(camDisStr, 20, 45);
    
    ofPoint camPos = cam.getPosition();
    string camPosStr = "Position = "+ofToString(camPos);
    ofSetColor(255);
    ofDrawBitmapString(camPosStr, 20, 65);
    
    
    cam.begin();
    
    ofPushMatrix();{
        ofTranslate(ofGetWindowSize()/2);
        ofNoFill();
        
        ofBeginShape();{
            ofCurveVertex(Helix1[0].x, Helix1[0].y, Helix1[0].z);
            for(int i = 0; i < Helix1.size(); i++){
                ofSetColor(255, 0, 0);
                ofCurveVertex(Helix1[i].x, Helix1[i].y, Helix1[i].z);
                ofCircle(Helix1[i].x, Helix1[i].y, Helix1[i].z, 2);

            }
            ofCurveVertex(Helix1[24].x, Helix1[24].y, Helix1[24].z);

        }ofEndShape();
        
        ofBeginShape();{
            ofCurveVertex(Helix2[0].x, Helix2[0].y, Helix2[0].z);
            for(int i = 0; i < Helix1.size(); i++){
                ofSetColor(0, 0, 255);
                ofCurveVertex(Helix2[i].x, Helix2[i].y, Helix2[i].z);
                ofCircle(Helix2[i].x, Helix2[i].y, Helix2[i].z, 2);
            }
            ofCurveVertex(Helix2[24].x, Helix2[24].y, Helix2[24].z);
            
        }ofEndShape();
        
//        ofSetLineWidth(5);
//        for(int i = 0; i < Helix1.size(); i++){
//            ofSetColor(255);
//            ofLine(Helix1[i].x, Helix1[i].y, Helix1[i].z, Helix2[i].x, Helix2[i].y, Helix2[i].z);
//        }
    
    }ofPopMatrix();
    
    cam.end();
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
