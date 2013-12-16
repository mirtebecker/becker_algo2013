#include "testApp.h"
#include "ofMain.h"

// This needs of_v0.8.0_ios_release to compile.

int main(){
    ofSetupOpenGL(1024,768, OF_FULLSCREEN);			// <-------- setup the GL context
	ofRunApp(new testApp);
}
