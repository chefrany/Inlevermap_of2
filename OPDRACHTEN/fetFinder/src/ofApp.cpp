#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	image.load("eyes.png");
	grabber.setup(1280, 720, true);
	haarFinder.setup("haarcascade_eyes.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	if (grabber.isFrameNew()) {
		haarFinder.findHaarObjects(grabber.getPixels(), 50, 50);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	grabber.draw(0, 0);
	ofNoFill();
	for (int i = 0; i < haarFinder.blobs.size(); i++) {
		ofRectangle blobBoundingRect = haarFinder.blobs[i].boundingRect;

		if (drawBox) {
			ofDrawRectangle(blobBoundingRect.x, blobBoundingRect.y,
				blobBoundingRect.width, blobBoundingRect.height);
		}
			image.draw(blobBoundingRect.x, blobBoundingRect.y,
				blobBoundingRect.width, blobBoundingRect.height);
		}
	}
// box 2d  ofpoint zit in een blob 

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'b') {
		drawBox = !drawBox;
	}
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
