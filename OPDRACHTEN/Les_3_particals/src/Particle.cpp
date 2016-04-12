#include "Particle.h"

Particle::Particle(int x, int y) {
  position.set(x, y);
  radius = ofRandom(10,100);
  particalColor.set(ofRandom(255), ofRandom(255), ofRandom(255) , 100);
  resolution = ofRandom( 3 , 12 );
}

void Particle::update() 
{ 
	position += speed; 
}

void Particle::draw() 
{
  ofSetColor(particalColor);
  ofSetCircleResolution(resolution);
  ofDrawCircle(position, radius);
}
