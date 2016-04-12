#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOsc.h"
#define PORT 9000


class SoundClass
{
public:
	void setup();
	void keyPressed(int key);
	void playPressed();
	void stopPressed();
	void draw();
	void update(); 

	ofSoundPlayer bass_1;
	ofSoundPlayer bass_2;
	ofSoundPlayer vocals_1;
	ofSoundPlayer vocals_2;
	ofSoundPlayer vocals_3;
	ofSoundPlayer vocals_4;
	ofSoundPlayer fx_1;
	ofSoundPlayer fx_2;

	ofxPanel gui;
	// al deze moeten aangepast worden tot de sample naam (voor duidelijkheid)
	// werkt 
	ofxButton play_Bass_1;
	ofxButton stop_Bass_1;

	ofxButton play_Bass_2;
	ofxButton stop_Bass_2;

	ofxButton play_MaleVocal;
	ofxButton stop_MaleVocal;

	ofxButton play_WomanVocal;
	ofxButton stop_WomanVocal;

	ofxButton play_RobotVocal_1;
	ofxButton stop_RobotVocal_1;

	ofxButton play_RobotVocal_2;
	ofxButton stop_RobotVocal_2;

	ofxButton play_Magic;
	ofxButton stop_Magic;

	ofxButton play_Lune;
	ofxButton stop_Lune;

	ofxButton play_Piano;
	ofxButton stop_Piano;
	
	//ofxFloatSlider volume_Piano;
	//ofxFloatSlider speed_Piano;

	// ofxGui aangestuurd 
	ofSoundPlayer sample; 
	ofSoundPlayer samnple_2;

	// test connecting to app.h 

	ofParameterGroup soundParameters; 
	ofParameter<float> volume_Bass_1;
	ofParameter<float> speed_Bass_1;

	ofParameter<float> volume_Bass_2;
	ofParameter<float> speed_Bass_2;

	ofParameter<float> volume_MaleVocal;
	ofParameter<float> speed_MaleVocal;

	ofParameter<float> volume_WomanVocal;
	ofParameter<float> speed_WomanVocal;

	ofParameter<float> volume_RobotVocal_1;
	ofParameter<float> speed_RobotVocal_1;

	ofParameter<float> volume_RobotVocal_2;
	ofParameter<float> speed_RobotVocal_2;

	ofParameter<float> volume_Magic;
	ofParameter<float> speed_Magic;

	ofParameter<float> volume_Lune;
	ofParameter<float> speed_Lune;

	ofParameter<float> volume_Piano;
	ofParameter<float> speed_Piano ;

	ofxOscReceiver receive;

	float v1 = 0.0;
	float v2 = 0.0;
	float v3 = 0.0;
	float v4 = 0.0;
	float v5 = 0.0;
	float v6 = 0.0;
	float v7 = 0.0;
	float v8 = 0.0;
	float v9 = 0.0;

	float s1 = 0.0;
	float s2 = 0.0;
	float s3 = 0.0;
	float s4 = 0.0;
	float s5 = 0.0;
	float s6 = 0.0;
	float s7 = 0.0;
	float s8 = 0.0;
	float s9 = 0.0;

	float play_1 = 0.0;
	float play_2 = 0.0;
	float play_3 = 0.0;
	float play_4 = 0.0;
	float play_5 = 0.0;
	float play_6 = 0.0;
	float play_7 = 0.0;
	float play_8 = 0.0;
	float play_9 = 0.0;

	float stop_1 = 0.0;
	float stop_2 = 0.0;
	float stop_3 = 0.0;
	float stop_4 = 0.0;
	float stop_5 = 0.0;
	float stop_6 = 0.0;
	float stop_7 = 0.0;
	float stop_8 = 0.0;
	float stop_9 = 0.0;
	

};

