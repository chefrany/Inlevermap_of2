#include "SoundClass.h"



void SoundClass::setup()
{
	receive.setup(PORT);

	bass_1.loadSound   ("bass/elec_bass.wav");
	bass_2.loadSound   ("bass/fm_bass.wav");
	vocals_1.loadSound ("vocal/vocal_woman.wav");
	vocals_2.loadSound ("vocal/vocal_men.wav");
	vocals_3.loadSound ("vocal/vocal_robot.wav");
	vocals_4.loadSound ("vocal/vocal_robot_allnight.wav");
	fx_1.loadSound     ("fx/magic_fx.wav");
	fx_2.loadSound     ("fx/lune_fx.wav");
	sample.loadSound   ("fx/piano.wav");
/*
	bass_1.setVolume(0.3);
	bass_2.setVolume(0.3);
	vocals_1.setVolume(0.7);
	vocals_2.setVolume(0.7);
	vocals_3.setVolume(0.7);
	vocals_4.setVolume(0.7);
	fx_1.setVolume(1.0);
	fx_2.setVolume(1.0);
*/
	bass_1.setLoop(true);
	bass_2.setLoop(true);
	vocals_1.setLoop(true);
	vocals_2.setLoop(true);
	vocals_3.setLoop(true);
	vocals_4.setLoop(true);
	fx_1.setLoop(true);
	fx_2.setLoop(true);
	sample.setLoop(true);


	play_Bass_1.addListener(this, &SoundClass::playPressed);
	stop_Bass_1.addListener(this, &SoundClass::stopPressed);

	play_Bass_2.addListener(this, &SoundClass::playPressed);
	stop_Bass_2.addListener(this, &SoundClass::stopPressed);

	play_MaleVocal.addListener(this, &SoundClass::playPressed);
	stop_MaleVocal.addListener(this, &SoundClass::stopPressed);

	play_WomanVocal.addListener(this, &SoundClass::playPressed);
	stop_WomanVocal.addListener(this, &SoundClass::stopPressed);

	play_RobotVocal_1.addListener(this, &SoundClass::playPressed);
	stop_RobotVocal_1.addListener(this, &SoundClass::stopPressed);

	play_RobotVocal_2.addListener(this, &SoundClass::playPressed);
	stop_RobotVocal_2.addListener(this, &SoundClass::stopPressed);

	play_Magic.addListener(this, &SoundClass::playPressed);
	stop_Magic.addListener(this, &SoundClass::stopPressed);

	play_Lune.addListener(this, &SoundClass::playPressed);
	stop_Lune.addListener(this, &SoundClass::stopPressed);

	play_Piano.addListener(this, &SoundClass::playPressed); // linked to gui  play  luisterd naar class
	stop_Piano.addListener(this, &SoundClass::stopPressed); // linked to gui  stop luisterd naar class
	
	gui.setup();
	gui.add(play_Bass_1.setup("Play_Bass_1 "));
	gui.add(stop_Bass_1.setup("Stop_Bass_1 "));

	gui.add(play_Bass_2.setup("Play_Bass_2 "));
	gui.add(stop_Bass_2.setup("Stop_Bass_2 "));

	gui.add(play_MaleVocal.setup("Play_MaleVocal "));
	gui.add(stop_MaleVocal.setup("Stop_MaleVocal "));

	gui.add(play_WomanVocal.setup("Play_WomanVocal "));
	gui.add(stop_WomanVocal.setup("Stop_WomanVocal "));

	gui.add(play_RobotVocal_1.setup("Play_RobotVocal_1 "));
	gui.add(stop_RobotVocal_1.setup("Stop_RobotVocal_1 "));

	gui.add(play_RobotVocal_2.setup("Play_RobotVocal_2 "));
	gui.add(stop_RobotVocal_2.setup("Stop_RobotVocal_2 "));

	gui.add(play_Magic.setup("Play_Magic "));
	gui.add(stop_Magic.setup("Stop_Magic "));

	gui.add(play_Lune.setup("Play_Lune "));
	gui.add(stop_Lune.setup("Stop_Lune "));

	gui.add(play_Piano.setup("Play_Piano "));
	gui.add(stop_Piano.setup("Stop_Piano "));
	//gui.add(volume_Piano.setup("Volume Piano", 1.0, 0.0, 1.0));
	//gui.add(speed_Piano.setup("Speed Piano ", 1.0, -3.0, 3.0));

	soundParameters.setName("soundControlPanel");

	soundParameters.add(volume_Bass_1.set("Volume_Bass_1", 0, 0, 1));
	soundParameters.add(speed_Bass_1.set("speed_Bass_1", 1, -4, 4));

	soundParameters.add(volume_Bass_2.set("Volume_Bass_2", 0, 0, 1));
	soundParameters.add(speed_Bass_2.set("speed_Bass_2", 1, -4, 4));

	soundParameters.add(volume_MaleVocal.set("Volume_MaleVocal", 0, 0, 1));
	soundParameters.add(speed_MaleVocal.set("speed_MaleVocal", 1, -4, 4));

	soundParameters.add(volume_WomanVocal.set("Volume_WomanVocal", 0, 0, 1));
	soundParameters.add(speed_WomanVocal.set("speed_WomanVocal", 1, -4, 4));

	soundParameters.add(volume_RobotVocal_1.set("Volume_RobotVocal_1", 0, 0, 1));
	soundParameters.add(speed_RobotVocal_1.set("speed_RobotVocal_1", 1, -4, 4));

	soundParameters.add(volume_RobotVocal_2.set("Volume_RobotVocal_2", 0, 0, 1));
	soundParameters.add(speed_RobotVocal_2.set("speed_RobotVocal_2", 1, -4, 4));

	soundParameters.add(volume_Magic.set("Volume_Magic", 0, 0, 1));
	soundParameters.add(speed_Magic.set("speed_Magic", 1, -4, 4));

	soundParameters.add(volume_Lune.set("Volume_Lune", 0, 0, 1));
	soundParameters.add(speed_Lune.set("speed_Lune", 1, -4, 4));

	soundParameters.add(volume_Piano.set("Volume_Piano", 0, 0, 1));
	soundParameters.add(speed_Piano.set("speed_Piano" , 1 , -4 , 4));

}

void SoundClass::keyPressed(int key) {
	switch (key) {
	case 'q': bass_1.play();   break;
	case 'e': bass_2.play();   break;
	case 'a': vocals_1.play(); break;
	case 'd': vocals_2.play(); break;
	case 'g': vocals_3.play(); break;
	case 'j': vocals_4.play(); break;
	case 'z': fx_1.play();     break;
	case 'c': fx_2.play();     break;

	/*case OF_KEY_LEFT:  bass.setSpeed(-1.0) , 
		               vocals.setSpeed(-1.0) ,
	               	   fx.setSpeed(-1.0);  break;
	case OF_KEY_RIGHT: bass.setSpeed(1.0)    , 
		               vocals.setSpeed(1.0)  , 
		               fx.setSpeed(1.0);   break;
    */
	case 'w': bass_1.stop();   break;
	case 'r': bass_2.stop();   break;
	case 's': vocals_1.stop(); break;
	case 'f': vocals_2.stop(); break;
	case 'h': vocals_3.stop(); break;
	case 'k': vocals_4.stop(); break;
	case 'x': fx_1.stop();     break;
	case 'v': fx_2.stop();     break;

	
	}

}

void SoundClass::playPressed() {
	bass_1.play();
	bass_2.play();
	vocals_1.play();
	vocals_2.play();
	vocals_3.play();
	vocals_4.play();
	fx_1.play();
	fx_2.play();
	sample.play();
}

void SoundClass::stopPressed() {
	bass_1.stop();
	bass_2.stop();
	vocals_1.stop();
	vocals_2.stop();
	vocals_3.stop();
	vocals_4.stop();
	fx_1.stop();
	fx_2.stop();
	sample.stop();
}

void SoundClass::update() {
	while (receive.hasWaitingMessages()) {
		ofxOscMessage m;
		receive.getNextMessage(&m);

		if (m.getAddress() == "/SPEED/fader1") {
			s1 = m.getArgAsFloat(0);
			speed_Bass_1 = s1;
		}
		if (m.getAddress() == "/SPEED/fader2") {
			s2 = m.getArgAsFloat(0);
			speed_Bass_2 = s2;
		}
		if (m.getAddress() == "/SPEED/fader3") {
			s3 = m.getArgAsFloat(0);
			speed_MaleVocal = s3;
		}
		if (m.getAddress() == "/SPEED/fader4") {
			s4 = m.getArgAsFloat(0);
			speed_WomanVocal = s4;
		}
		if (m.getAddress() == "/SPEED/fader5") {
			s5 = m.getArgAsFloat(0);
			speed_RobotVocal_1 = s5;
		}
		if (m.getAddress() == "/SPEED/fader6") {
			s6 = m.getArgAsFloat(0);
			speed_RobotVocal_2 = s6;
		}
		if (m.getAddress() == "/SPEED/fader7") {
			s7 = m.getArgAsFloat(0);
			speed_Magic = s7;
		}
		if (m.getAddress() == "/SPEED/fader8") {
			s8 = m.getArgAsFloat(0);
			speed_Lune = s8;
		}
		if (m.getAddress() == "/SPEED/fader9") {
			s9 = m.getArgAsFloat(0);
			speed_Piano = s9;
		}
////////////////////////////////////////////////////////
		if (m.getAddress() == "/VOLUME/fader10") {
			v1 = m.getArgAsFloat(0);
			volume_Bass_1 = v1;
		}
		if (m.getAddress() == "/VOLUME/fader11") {
			v2 = m.getArgAsFloat(0);
			volume_Bass_2 = v2;
		}
		if (m.getAddress() == "/VOLUME/fader12") {
			v3 = m.getArgAsFloat(0);
			volume_MaleVocal = v3;
		}
		if (m.getAddress() == "/VOLUME/fader13") {
			v4 = m.getArgAsFloat(0);
			volume_WomanVocal = v4;
		}
		if (m.getAddress() == "/VOLUME/fader14") {
			v5 = m.getArgAsFloat(0);
			volume_RobotVocal_1 = v5;
		}
		if (m.getAddress() == "/VOLUME/fader15") {
			v6 = m.getArgAsFloat(0);
			volume_RobotVocal_2 = v6;
		}
		if (m.getAddress() == "/VOLUME/fader16") {
			v7 = m.getArgAsFloat(0);
			volume_Magic = v7;
		}
		if (m.getAddress() == "/VOLUME/fader17") {
			v8 = m.getArgAsFloat(0);
			volume_Lune = v8;
		}
		if (m.getAddress() == "/VOLUME/fader18") {
			v9 = m.getArgAsFloat(0);
			volume_Piano = v9;
		}
		////////////////////////////////////////////////
		/*if (m.getAddress() == "/3/toggle1") {
			play_1 = m.getArgAsFloat(0);
			play_Bass_1.setup = play_1;
		}*/
		////////// DEZE TESTEN MET DE OSC SIGNAL   
		if (m.getAddress() == "/3/toggle2") {
			play_1 = m.getArgAsFloat(0);
			if (play_1 = 1) {
				bass_2.play();
			}
			else
			{
				bass_2.stop();
			}
		}
	}
}

void SoundClass::draw() {
	gui.draw();
	bass_1.setVolume(volume_Bass_1);
	bass_2.setVolume(volume_Bass_2);
	vocals_1.setVolume(volume_MaleVocal);
	vocals_2.setVolume(volume_WomanVocal);
	vocals_3.setVolume(volume_RobotVocal_1);
	vocals_4.setVolume(volume_RobotVocal_2);
	fx_1.setVolume(volume_Magic);
	fx_2.setVolume(volume_Lune);
	sample.setVolume(volume_Piano);

	bass_1.setSpeed(speed_Bass_1);
	bass_2.setSpeed(speed_Bass_2);
	vocals_1.setSpeed(speed_MaleVocal);
	vocals_2.setSpeed(speed_WomanVocal);
	vocals_3.setSpeed(speed_RobotVocal_1);
	vocals_4.setSpeed(speed_RobotVocal_2);
	fx_1.setSpeed(speed_Magic);
	fx_2.setSpeed(speed_Lune);
    sample.setSpeed(speed_Piano);
	

	

}

