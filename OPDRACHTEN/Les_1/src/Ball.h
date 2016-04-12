#pragma once

#include "ofMain.h"

class Ball {

public:

    Ball();

    void setup();
    void update();
    void draw();

    // variables
	ofPoint position;
	ofVec3f speed;
	ofColor color;
	int BoxSize_X , BoxSize_Y , BoxSize_Z;    
	int radius, radius_Min, radius_Max;
    int object_Speed_X , object_Speed_Y , object_Speed_Z;
	int negative_Speed;
	int red, green, blue ;

private:

};
