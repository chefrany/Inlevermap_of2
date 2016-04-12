#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 9000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofxOscReceiver receive;
		float oscX = 0.0;
		float oscY = 0.0;
		
};
