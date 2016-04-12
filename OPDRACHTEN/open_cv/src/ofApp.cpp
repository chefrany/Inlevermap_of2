#include "ofApp.h"
#define GRABBER_WIDTH 320
#define GRABBER_HEIGHT 240
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0,0);
	grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT, true);
	rgbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	hsbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	hue.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	sat.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	bright.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	fillterd.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	fillterd_2.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	// extra fillter 

}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	if(grabber.isFrameNew()) {
		rgbImage.setFromPixels(grabber.getPixels().getData()
			                  , GRABBER_WIDTH, GRABBER_HEIGHT);
		rgbImage.mirror(false, true); // hor,ver
		hsbImage = rgbImage;
		hsbImage.convertRgbToHsv();

		hsbImage.convertToGrayscalePlanarImages(hue,sat,bright);
		/////////
		for (int i = 0; i < GRABBER_WIDTH* GRABBER_HEIGHT; i++) {
			if (ofInRange(hue.getPixels()[i], findHue - 5, findHue + 5)) {
				fillterd.getPixels()[i] = 255;
				
			}
			else {
				fillterd.getPixels()[i] =0 ;
			}
		}
		fillterd.flagImageChanged();
		cont.findContours(fillterd,50,GRABBER_WIDTH*GRABBER_HEIGHT/2,1,false);
		// die gooit een contour over de geselecteerde kleur heen.
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::white);
	rgbImage.draw(640, 0);
	hsbImage.draw(0, 0);

	hue.draw(0, 240);
	sat.draw(320, 240);
	bright.draw(640, 240);

	fillterd.draw(0, 480);
	cont.draw(640,0);

	ofSetColor(ofColor::blue, 100);
	ofFill();
	for (int i = 0; i < cont.nBlobs; i++) {
		ofDrawCircle(cont.blobs[i].centroid.x +640,
			cont.blobs[i].centroid.y, 20);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	findHue = hue.getPixels()[y*GRABBER_WIDTH + x];
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
