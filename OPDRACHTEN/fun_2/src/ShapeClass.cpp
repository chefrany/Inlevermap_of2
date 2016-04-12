#include "ShapeClass.h"



void ShapeClass::setup()
{
	circleParameters.setName("circleControl");
	circleParameters.add(red.set("red", 255, 0, 255));
	circleParameters.add(green.set("green", 255, 0, 255));
	circleParameters.add(blue.set("blue", 255, 0, 255));

	circleParameters.add(posX.set("posX", 500, 0, 1000));
	circleParameters.add(posY.set("posY", 600, 0, 800));
	circleParameters.add(radius.set("radius", 90, 0, 1000));
}

void ShapeClass::draw()
{
	ofSetColor(red, green, blue);
	ofCircle(posX, posY, radius);

}



