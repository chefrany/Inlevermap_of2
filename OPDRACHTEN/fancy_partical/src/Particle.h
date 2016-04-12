#pragma once

#include "ofMain.h"
#include "Parameters.h"


class Particle {
 public:
  Particle(Parameters* parameters);

  void setup(float hue_min, float hue_max, float grote );
  void update(float elapsedTime); //
  void draw();

  ofPoint randomPointOnCircle(float maxRadius);

  ofPoint position;
  ofVec3f speed;
  bool isAlive;
  float age;
  float maxAge;
  float size;
  float min;
  float max;



  Parameters* param;
};
