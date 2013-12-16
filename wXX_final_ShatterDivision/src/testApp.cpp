#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(0);
    
    img.loadImage("picasso.jpg");
    myFlowField.setup(ofGetWindowWidth(), ofGetWindowHeight(), 20);
    
    hideImage = true;
    hideField = true;
    hideSeeds = false;
    bouncing = true;
    
    for(int i = 0; i < 50; i++){
        Seed s;
        seedList.push_back(s);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < seedList.size(); i++){
        seedList[i].addForce(myFlowField.getForceAtScreenPos(seedList[i].pos)*0.000001);
        seedList[i].update(bouncing);
    }
    
    // Porting from Processing code, but not exactly smooth:
    //    for(int x = 0; x < ofGetWindowWidth(); x++){
    //        for(int y = 0; y < ofGetWindowHeight(); y++){
    //            float minDist = ofGetWindowWidth() + ofGetWindowHeight();
    //            int closest = 0;
    //            for(int i = 0; i < seedList.size(); i++){
    //                Seed s = seedList[i];
    //                ofVec2f tmp = ofVec2f(x, y);
    //                float d = tmp.distance(s.pos);
    //                if (d < minDist){
    //                    closest = i;
    //                    minDist = d;
    //                }
    //            }
    //            pixels[y * ofGetWindowWidth() + x] = seedList[closest].c;
    //        }
    //    }
    //    tex.loadData(pixels);
}

//--------------------------------------------------------------
void testApp::draw(){
    //tex.draw(0, 0);
    
    if(!hideImage){
        img.draw(0,0);
    }
    
    if(!hideField){
       myFlowField.draw();
    }
    if(!hideSeeds){
        for(int i = 0; i < seedList.size(); i++){
            seedList[i].drawSeed();
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'i'){
        hideImage = !hideImage;
    }
    if(key == 'f'){
        hideField = !hideField;
    }
    if(key == 's'){
        hideSeeds = !hideSeeds;
    }
    if(key == 'b'){
        bouncing = !bouncing;
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
