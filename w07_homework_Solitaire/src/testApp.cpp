#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(bg);
    
    useMouse = false;
    add = false;
    
    for(int i = 0; i < 1; i++){
        Card queen;
        cardList.push_back(queen);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < cardList.size(); i++){
        cardList[i].update(mouse);

        cout << cardList[i].vel.y << endl;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < cardList.size(); i++){
        cardList[i].draw(useMouse);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'm'){
        if(useMouse == true){
            useMouse = false;
            ofClear(bg);
        }else{
            useMouse = true;
            ofClear(bg);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    mouse.x = x;
    mouse.y = y;
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
