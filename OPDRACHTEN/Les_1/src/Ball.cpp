#include "Ball.h"
Ball::Ball(){
}
void Ball::setup(){//S
	BoxSize_X = 800; BoxSize_Y = 800; BoxSize_Z = 800; 
	position.x = ofRandom(-BoxSize_X*0.5, BoxSize_X*0.5);
	position.y = ofRandom(-BoxSize_Y*0.5, BoxSize_Y*0.5);
	position.z = ofRandom(-BoxSize_Z*0.5, BoxSize_Z*0.5);

	object_Speed_X = 20; object_Speed_Y = 20; object_Speed_Z = 20;
	speed.x = ofRandom(-object_Speed_X, object_Speed_X);
	speed.y = ofRandom(-object_Speed_Y, object_Speed_Y);
	speed.z = ofRandom(-object_Speed_Z, object_Speed_Z);
	negative_Speed = -1;

	radius_Min = 50; radius_Max = 100;
	radius = ofRandom( radius_Min , radius_Max );
   
	red = 255; green = 255; blue = 255;
	color.set(red , green , blue );
}
void Ball::update(){//U
    if(position.x < -BoxSize_X*0.5  +radius ){
        position.x = -BoxSize_X*0.5 +radius;
        speed.x *= negative_Speed;
		color.set(ofRandom(255), ofRandom(255), ofRandom(255));
   } else if(position.x > BoxSize_X*0.5 -radius){
        position.x = BoxSize_X*0.5      -radius;
        speed.x *= negative_Speed;
    }

    if(position.y < -BoxSize_Y*0.5  +radius){
        position.y = -BoxSize_Y*0.5 +radius;
        speed.y *= negative_Speed;
		radius = ofRandom(radius_Min*0.1 , radius_Max*0.1 );
    } else if(position.y > BoxSize_Y*0.5 -radius){
        position.y = BoxSize_Y*0.5       -radius;
        speed.y *= negative_Speed;
		radius = ofRandom(radius_Min , radius_Max );
    }
	if (position.z < -BoxSize_Z*0.5 +radius) {
		position.z = -BoxSize_Z*0.5 +radius;
		speed.z *= negative_Speed;
		speed.z = ofRandom(-object_Speed_Z , object_Speed_Z);
	}
	else if (position.z > BoxSize_Z*0.5 -radius) {
		position.z = BoxSize_Z*0.5      -radius;
		speed.z *= negative_Speed;
		speed.z = ofRandom(-object_Speed_Z , object_Speed_Z);
	}
	position = position + speed;
}
void Ball::draw(){//D
    ofSetColor(color);
	ofDrawSphere(position, radius);
}
