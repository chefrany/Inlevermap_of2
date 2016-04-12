#pragma once

#include "ofMain.h"

class Parameters {
public:
	Parameters();

	ofPoint startingPoint;
	float radius = 200;
	float maxSpeed = 100;
	float lifeTime = 2.0;
	float rotate = 5;

	float force = 100;
	float spinning = 100;
	float friction = 0.5;
};