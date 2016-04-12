#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFullscreen(true);
	ofSetFrameRate(60);
	soundGroup.setup();
	circleGroup.setup();
	paramGroup.add(circleGroup.circleParameters);
	paramGroup.add(soundGroup.soundParameters);
	gui.setup(paramGroup);
	fftSmooth = new float[8192];
	for (int i = 0; i < 8192; i++) {
		fftSmooth[i] = 0;
	}
	bands = 64;


	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
	fbo.begin();
	ofBackground(ofColor::black);
	fbo.end();

	time = ofGetElapsedTimef();
	


}

//--------------------------------------------------------------
void ofApp::update(){
	ofSoundUpdate();
	float currentTime = ofGetElapsedTimef();
	float elapsedTime = ofClamp(currentTime - time, 0, 0.1); // of clamp is threshold min,maxi 
	time = currentTime;
	float * value = ofSoundGetSpectrum(bands); // 64
	for (int i = 0; i < bands; i++)
	{
		fftSmooth[i] *= 0.95f;
		if (fftSmooth[i] < value[i]) {
			fftSmooth[i] = value[i];
		}
	}
	soundGroup.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofBackgroundGradient(ofColor::salmon, ofColor::aqua);
	
	

	//fadeAmount = 20;

	fbo.begin();
	ofEnableAlphaBlending();
	ofSetColor(ofColor::black, 10);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofDisableAlphaBlending();
	
	ofSetColor(ofColor::black);
	for (int i = 0; i < bands; i++) {
		
		ofCircle(ofGetWidth() / 2, (fftSmooth[i] * 3000) / 2, -(fftSmooth[i] *150 ),100);
	}

	ofSetColor(ofColor::white);
	for (int i = 0; i < bands; i++) {

		ofCircle(ofGetWidth() / 2, (fftSmooth[i] * 1000) / 2, -(fftSmooth[i] * 50 ),10);
	}

	fbo.end();
	ofSetColor(ofColor::white);
	fbo.draw(0, 0);
	//circleGroup.draw();
	gui.draw();
	soundGroup.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	soundGroup.keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
