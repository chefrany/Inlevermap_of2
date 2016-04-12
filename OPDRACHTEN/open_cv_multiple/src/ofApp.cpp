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
	image.load("eyes.png");
	haarFinder.setup("haarcascade_eyes.xml");

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
		for (int i = 0; i < GRABBER_WIDTH* GRABBER_HEIGHT; i++) {
			if (ofInRange(hue.getPixels()[i], findHue_2 - 5, findHue_2 + 5)) {
				fillterd_2.getPixels()[i] = 255;

			}
			else {
				fillterd_2.getPixels()[i] = 0;
			}
		}
		fillterd_2.flagImageChanged();
		cont_2.findContours(fillterd_2, 40, GRABBER_WIDTH*GRABBER_HEIGHT / 2, 1, false);
	   
		haarFinder.findHaarObjects(grabber.getPixels(), 50, 50);
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
	cont_2.draw(640, 240);

	ofSetColor(ofColor::blue, 100);
	ofFill();
	for (int i = 0; i < cont.nBlobs; i++) {
		ofDrawCircle(cont.blobs[i].centroid.x +640,
			cont.blobs[i].centroid.y, 20);
	}

	ofSetColor(ofColor::orangeRed, 100);
	ofFill();
	for (int i = 0; i < cont_2.nBlobs; i++) {
		ofDrawCircle(cont_2.blobs[i].centroid.x + 640,
			cont_2.blobs[i].centroid.y, 20);
	}
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

//--------------------------------------------------------------
// De keypressed moet nog even gefixt worden. 
void ofApp::keyPressed(int key ){
	if (key == 'b') {
		findHue = hue.getPixels()[mouseY*GRABBER_WIDTH+ mouseX];
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
	findHue_2 = hue.getPixels()[y*GRABBER_WIDTH + x];
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
