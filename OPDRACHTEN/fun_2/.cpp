#include "SoundClass.h"



 void SoundClass::setup()
{
	bass.loadSound("elec_bass.wav");
	bass.setVolume(0.3);
	bass.setLoop(true);

}

 void SoundClass::keyPressed(int key)
 {
	 switch (key)
	 {
	 case ' ': bass.play(); break;
	 case OF_KEY_LEFT : bass.setSpeed(-1.0); break;
	 case OF_KEY_RIGHT: bass.setSpeed(1.0) ; break;
	 case 's': bass.stop(); break;
	 }


 }
