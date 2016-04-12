#pragma once

#include "ofMain.h"
#include "ofxopenCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		// werk altijd met de HSB waardes
		ofVideoGrabber grabber;
		ofxCvColorImage rgbImage;
		ofxCvColorImage hsbImage;
		ofxCvGrayscaleImage hue;
		ofxCvGrayscaleImage sat;
		ofxCvGrayscaleImage bright;

		ofxCvGrayscaleImage fillterd;
		ofxCvGrayscaleImage fillterd_2;
		ofxCvContourFinder cont;
		int findHue;
		int findhuie_2;

};
