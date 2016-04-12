#include "ofApp.h"


void ofApp::setup() {
	showGui = true;
	
	gui.setup("parameters");
	gui.add(hoeveelHeid.setup("hoeveelheid", 50, 0, 200));
	gui.add(grote.setup("grote", 10, 0, 100));
	gui.add(birthRate.setup("birthRate", 0, 0, 10000));
	gui.add(achtergrond.setup("achtergrond", ofColor::black, ofColor(0, 0, 0), ofColor::white)); // R,G,B
	gui.add(ghosting.setup("ghosting", 2, 0, 100));
	gui.add(hue_min.setup("hue_min", 10, 0, 360));
	gui.add(hue_max.setup("hue_max", 10, 0, 360));
	ofSetFrameRate(100);
	ofEnableSmoothing();

	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
	fbo.begin();
	ofBackground(ofColor::black);
	fbo.end();

	time = ofGetElapsedTimef();
	

	//particle = Particle(&parameters); 
	
}

void ofApp::update() {

	float currentTime = ofGetElapsedTimef();
	float elapsedTime = ofClamp(currentTime - time, 0, 0.1); // of clamp is threshold min,maxi 
	time = currentTime;
	int i = 0;
	while (i < particles.size()) {
		if (!particles[i].isAlive) {
			particles.erase(particles.begin() + i);

		}
		else {
			i++;
		}
	}

	int newParticles = birthRate *elapsedTime;

	for (int i = 0; i < newParticles; i++) {

		if (particles.size() < hoeveelHeid)
		{
			Particle newParticle(&parameters);
			newParticle.setup(hue_min, hue_max, grote);
			particles.push_back(newParticle);
		}
		for (int i = 0; i < particles.size(); i++) {
			particles[i].update(elapsedTime);
		}
	}
}

void ofApp::draw() {

	ofBackground(achtergrond);
	if (showGui) gui.draw();

	fbo.begin();
	ofEnableAlphaBlending();
	ofSetColor(ofColor::black, ghosting);
	ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
	ofDisableAlphaBlending();



	ofFill();
	for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
	particle.draw();
	//ofClear(0, 0, 0, 0);
	fbo.end();
	ofSetColor(ofColor::white);
	fbo.draw(0, 0);

}
