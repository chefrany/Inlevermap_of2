#include "Spring.h"


Spring::Spring(Particle* firstParticle, Particle* secondParticle) {
  first = firstParticle;
  second = secondParticle;
  length = DEFAULT_LENGTH;

}

void Spring::draw() {
  ofSetColor(ofColor::white);
  ofSetLineWidth(2);
  ofDrawLine(first->position, second->position);
}

void Spring::update() {
  float distance = first->position.distance(second->position);

  ofVec3f acceleration = second->position - first->position;
  acceleration.normalize();
  acceleration *= (distance *(ofRandom(100) *0.001)) / DEFAULT_LENGTH;

  first->speed += acceleration;
  second->speed -= acceleration;
}
