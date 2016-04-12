#pragma once

#include "ofMain.h"
#include"SoundClass.h"
#include "ShapeClass.h"
#include "ofxGui.h"



class ofApp : public ofBaseApp{

	public:
		void setup() ;
		void update();
		void draw()  ;

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
		
		//SoundClass sound;
	    
		float * fftSmooth;
		float time;
		int bands;

		ofxPanel gui;
		ofParameterGroup paramGroup;
		ShapeClass circleGroup;
		SoundClass soundGroup;

		ofFbo fbo;
		int fadeAmount = 200;
		int fadeAmount_2;// <------
		
		
};
