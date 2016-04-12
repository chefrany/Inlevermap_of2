#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	receive.setup(PORT);
	ofSetFrameRate(60);

}

//--------------------------------------------------------------
void ofApp::update(){
	while (receive.hasWaitingMessages()) {
		ofxOscMessage m;
		receive.getNextMessage(&m);

		if (m.getAddress() == "vert/x") {
			oscX = m.getArgAsFloat(0);}
		if (m.getAddress() == "hor/y")
			oscY = m.getArgAsFloat(0);}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	ofCircle(oscX *300, oscY *300, 30);
}

