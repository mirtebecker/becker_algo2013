#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"

#include "ofxOpenCv.h"
#include "ofxSvg.h"
#include "ofxImageMask.h"

#include "Walker.h"

class testApp : public ofxiOSApp{
	
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchDoubleTap(ofTouchEventArgs & touch);
    void touchCancelled(ofTouchEventArgs & touch);
	
    void lostFocus();
    void gotFocus();
    void gotMemoryWarning();
    void deviceOrientationChanged(int newOrientation);

    //ofxSvg
    ofxSVG svg;
    float step;
    vector<ofPolyline> outlines;
    
    //Fbo's
    ofFbo walkerMaskFbo;
    ofFbo photoMaskFbo;
    ofFbo invertedMaskFbo;
    ofFbo noiseMaskFbo;
    
    ofFbo walkerFbo;
    ofFbo noiseFbo;
    
    //ofImageMask
    ofImage walkerMaskImg;
    ofImage photoMaskImg;
    ofImage invertedMaskImg;
    ofImage noiseMaskImg;
    
    ofImage walkerImg;
    ofImage photoImg;
    ofImage invertedImg;
    ofImage noiseImg;
    
    ofxImageMask walkerDestination;
    ofxImageMask photoDestination;
    ofxImageMask invertedDestination;
    ofxImageMask noiseDestination;
    
    //opencvFaceExample
    ofVideoGrabber grabber;
    ofTexture tex;
    unsigned char * pix;
    ofxCvColorImage colorCv;
    ofxCvColorImage colorCvSmall;
    ofxCvGrayscaleImage grayCv;
    ofxCvHaarFinder finder;
    ofImage colorImg;
    vector<ofxCvBlob> faces;
    
    // Walker
    vector<Walker> walkerList;
};
