#pragma once

#include "ofMain.h"
#include "Parameters.h"
#include "Particle.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
  void setup();
  void update();
  void draw();
  ofFbo fbo;
  float time;
  Parameters parameters;
  Particle particle = NULL;
  vector<Particle> particles;
  
  //gui
  bool showGui;
  ofxPanel gui;
  ofxIntSlider hoeveelHeid;
  ofxIntSlider grote;
  ofxIntSlider ghosting;
  ofxColorSlider achtergrond;
  ofxFloatSlider hue_min;
  ofxFloatSlider hue_max;
  ofxFloatSlider birthRate;
 // float birthRate = 1000;


 
};
