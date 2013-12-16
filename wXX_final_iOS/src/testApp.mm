#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofBackground(0);
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    // init mask fbo's
    walkerMaskFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    walkerMaskFbo.begin();{
        ofClear(0);
    }walkerMaskFbo.end();
    
    photoMaskFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    photoMaskFbo.begin();{
        ofClear(0);
    }photoMaskFbo.end();
    
    invertedMaskFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    invertedMaskFbo.begin();{
        ofClear(0);
    }invertedMaskFbo.end();
    
    noiseMaskFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    noiseMaskFbo.begin();{
        ofClear(0);
    }noiseMaskFbo.end();
    
    // init fbo's
    walkerFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    walkerFbo.begin();{
        ofClear(0);
    }walkerFbo.end();
    
    noiseFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    noiseFbo.begin();{
        ofClear(0);
    }noiseFbo.end();
    
    // ofxSvgExample
	svg.load("shards.svg");
	for (int i = 0; i < svg.getNumPath(); i++){
		ofPath p = svg.getPathAt(i);
		// svg defaults to non zero winding which doesn't look so good as contours
		p.setPolyWindingMode(OF_POLY_WINDING_ODD);
		vector<ofPolyline>& lines = p.getOutline();
		for(int j=0;j<(int)lines.size();j++){
			outlines.push_back(lines[j].getResampledBySpacing(1));
		}
	}
    
    // opencvFaceExample
	finder.setup("haarcascade_frontalface_default.xml");
    grabber.setVerbose(true);
    grabber.setDeviceID(1);
    grabber.setDesiredFrameRate(20);
    grabber.initGrabber(480, 360);
    
    int w = grabber.getWidth();
    int h = grabber.getHeight();
    
    colorCv.allocate(w,h);
    colorCvSmall.allocate(w/4, h/4);
    grayCv.allocate(w/4, h/4);
    
    finder.setNeighbors(1);
    finder.setScaleHaar(1.5);
    
    for(int i = 0; i < 10; i++){
        Walker w;
        walkerList.push_back(w);
    }
    
    // inverted photo
    photoImg.loadImage("photo.jpg");
    ofPixels pixels = photoImg.getPixelsRef();
    ofxCvColorImage tmp;
    tmp.setFromPixels(pixels);
    tmp.invert();
    invertedImg.setFromPixels(tmp.getPixelsRef());
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    walkerFbo.begin();{
        for(int i = 0; i < walkerList.size(); i++){
            walkerList[i].update();
            walkerList[i].draw();
        }
    }walkerFbo.end();
    ofPixels walkerPixels;
    walkerFbo.readToPixels(walkerPixels);
    walkerImg.setFromPixels(walkerPixels);
    
    noiseFbo.begin();{
        for( int x = 0; x < noiseFbo.getWidth(); x+=5){
            for( int y = 0; y < noiseFbo.getHeight(); y+=5){
                ofColor c = ofRandom(255);
                ofSetColor(c);
                ofRect(x, y, 5, 5);
            }
        }
    }noiseFbo.end();
    ofPixels noisePixels;
    noiseFbo.readToPixels(noisePixels);
    noiseImg.setFromPixels(noisePixels);
    
//    // opencvFaceExample, disabled for now to save processing power 
//    grabber.update();
//    colorCv = grabber.getPixels();
//    colorCvSmall.scaleIntoMe(colorCv, CV_INTER_NN);
//    grayCv = colorCvSmall;
//    finder.findHaarObjects(grayCv);
//    faces = finder.blobs;
//    
//	faces = finder.blobs;
//    if(faces.size() != 0){
//        cout << "found " << faces.size() << endl;
//    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // walker mask
    walkerMaskFbo.begin();{
        for(int i = 0; i < outlines.size(); i++){
            vector<ofPoint> shard = outlines[i].getVertices();
            ofSetColor(255);
            ofFill();
            if(i == 9){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
            if(i == 8){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
        }
    }walkerMaskFbo.end();
    ofPixels walkerMaskPixels;
    walkerMaskFbo.readToPixels(walkerMaskPixels);
    walkerMaskImg.setFromPixels(walkerMaskPixels);
    
    // photo mask
    photoMaskFbo.begin();{
        for(int i = 0; i < outlines.size(); i++){
            vector<ofPoint> shard = outlines[i].getVertices();
            ofSetColor(255);
            ofFill();
            if(i == 0){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
            if(i == 10){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
            if(i == 15){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
        }
    }photoMaskFbo.end();
    ofPixels photoMaskPixels;
    photoMaskFbo.readToPixels(photoMaskPixels);
    photoMaskImg.setFromPixels(photoMaskPixels);
    
    // inverted mask
    invertedMaskFbo.begin();{
        for(int i = 0; i < outlines.size(); i++){
            vector<ofPoint> shard = outlines[i].getVertices();
            ofSetColor(255);
            ofFill();
            if(i == 6){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
            if(i == 7){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
            if(i == 21){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
            if(i == 11){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
        }
    }invertedMaskFbo.end();
    ofPixels invertedMaskPixels;
    invertedMaskFbo.readToPixels(invertedMaskPixels);
    invertedMaskImg.setFromPixels(invertedMaskPixels);
    
    // noise mask
    noiseMaskFbo.begin();{
        for(int i = 0; i < outlines.size(); i++){
            vector<ofPoint> shard = outlines[i].getVertices();
            ofSetColor(255);
            ofFill();
            if(i == 12){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
            if(i == 1){
                ofBeginShape();{
                    ofVertices(shard);
                }ofEndShape();
            }
        }
    }noiseMaskFbo.end();
    ofPixels noiseMaskPixels;
    noiseMaskFbo.readToPixels(noiseMaskPixels);
    noiseMaskImg.setFromPixels(noiseMaskPixels);
    
    // ofxImageMask
	walkerDestination = walkerImg;
    walkerDestination.applyMask(walkerMaskImg);
    walkerDestination.draw(0, 0);
    
    photoDestination = photoImg;
    photoDestination.applyMask(photoMaskImg);
    photoDestination.draw(0, 0);
    
    invertedDestination = invertedImg;
    invertedDestination.applyMask(invertedMaskImg);
    invertedDestination.draw(0, 0);
    
    noiseDestination = noiseImg;
    noiseDestination.applyMask(noiseMaskImg);
    noiseDestination.draw(0, 0);
}

//--------------------------------------------------------------
void testApp::exit(){
    
}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs& touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){
    
}

//--------------------------------------------------------------
void testApp::gotFocus(){
    
}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){
    
}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){
    
}

