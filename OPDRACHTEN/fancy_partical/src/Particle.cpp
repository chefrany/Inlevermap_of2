#include "Particle.h"

Particle::Particle(Parameters* parameters) {
  isAlive = false;
  param = parameters;
}

void Particle::setup(float hue_min ,float hue_max, float grote) {


  position = param->startingPoint + randomPointOnCircle(param->radius);

  speed = randomPointOnCircle(param->maxSpeed);
  age = 0;
  maxAge = param->lifeTime;
  isAlive = true;
  size = ofRandom(10);
  min = hue_min;
  max = hue_max;
  size = grote;
  


}


void Particle::update(float elapsedTime) {
	if(!isAlive) return;
	speed.rotate(0, 0, param->rotate * elapsedTime);
	
	ofVec3f acceleration;
	ofVec3f distance = position - param->startingPoint;
	if (ofInRange(distance.length(), 0, param->radius))
	{
		distance.normalize(); // krijg je de richting mee

		acceleration += distance * param->force;
		acceleration.x = -distance.y * param->spinning;
		acceleration.y = -distance.x * param->spinning;

	}
	speed += acceleration * elapsedTime;
	speed *= (1 - param->friction);
	
	position += speed * elapsedTime;
	age += elapsedTime;
	if (age >= maxAge) isAlive = false;
}


void Particle::draw()
{
	
	ofColor color = ofColor::red;
	float hue = ofMap(age, 0, maxAge, min, max);
	color.setHue(hue);
	ofSetColor(color);

	//float size = ofMap(maxAge - age, 0, maxAge, 3, 1);

	ofDrawCircle(position, size );
}


ofPoint Particle::randomPointOnCircle(float maxRadius) {
  ofPoint point;
  float radius = ofRandom(0, maxRadius);
  float angle = ofRandom(0, M_TWO_PI);

  point.x = cos(angle) * radius;
  point.y = sin(angle) * radius;

  return point;
}
