#pragma once

#include "ofMain.h"
#include "Ball.h"

#define MAXBALLS 15

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


	int BoxSize_X;
	int BoxSize_Y;
	int BoxSize_Z;

    Ball ball_1;
	Ball ball_2;
	Ball ball_3;
	Ball ball_4;
	Ball ball_5;
	Ball ball_6;
	Ball ball_7;
	Ball ball_8;
	Ball ball_9;
	Ball ball_10;

	ofLight light;
	ofLight light_2;
	ofEasyCam cam;
	bool drawGrid;
	bool drawBox;

};
