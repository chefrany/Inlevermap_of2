#include "sound.h"



void sound::setup()
{ 
	number.loadSound("fm_bass.wav");
	number.setVolume(0.3);
	number.setLoop(true);
	

}

void sound::keyPressedd(int key){
	switch (key){
	case' ': number.play(); break;
	case OF_KEY_LEFT: number.setSpeed(-1.0); break;
	case OF_KEY_RIGHT: number.setSpeed(1.0); break; 
	case 's': number.stop(); break; 



	}

}


