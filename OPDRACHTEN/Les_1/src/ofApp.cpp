#include "ofApp.h"
#include "Ball.h"

//--------------------------------------------------------------
void ofApp::setup() {
	BoxSize_X = 800; 
	BoxSize_Y = 800; 
	BoxSize_Z = 800; 

	ofSetFrameRate(60);
	//ofBackground(0, 0, 0);
	drawGrid = false;
	drawBox = false;
        ball_1.setup();
		ball_2.setup();
		ball_3.setup();
		ball_4.setup();
		ball_5.setup();
		ball_6.setup();
		ball_7.setup();
		ball_8.setup();
		ball_9.setup();
		ball_10.setup();
		light.setPointLight();
		light.setPosition(200, 200, 200);

		light_2.setPointLight();
		light_2.setPosition(400, 400, 400);
		//ball2.setup();
}

//--------------------------------------------------------------
void ofApp::update() {
	ofBackground(mouseX * 0.2, mouseY * 0.2, mouseX *0.2 / mouseY *0.2);
        ball_1.update();
		ball_2.update();
		ball_3.update();
		ball_4.update();
		ball_5.update();
		ball_6.update();
		ball_7.update();
		ball_8.update();
		ball_9.update();
		ball_10.update();
		
		///
		/*
		if (ball_1.position.distance(ball_2.position) < ball_1.radius * 2) {
			ball_1.speed *= -1;
		}

		if (ball_2.position.distance(ball_1.position) < ball_2.radius * 2) {
			ball_2.speed *= -1;
		}  */

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofEnableDepthTest();
	cam.begin();
	light.enable();
	if (drawGrid) ofDrawGrid(200);
	if (drawBox) {

		ofNoFill();
		ofSetColor(ofColor::white);
		ofDrawBox( BoxSize_X , BoxSize_Y , BoxSize_Z );
	}
        ball_1.draw();
		ball_2.draw();
		ball_3.draw();
		ball_4.draw();
		ball_5.draw();
		ball_6.draw();
		ball_7.draw();
		ball_8.draw();
		ball_9.draw();
		ball_10.draw();
		light.disable();
		cam.end();
		ofDisableDepthTest();
		
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'b') {
		drawBox = !drawBox;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
