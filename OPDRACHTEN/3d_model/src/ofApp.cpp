#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	////loader.loadModel("dragon.dae");
	//loader.loadModel("dragon.dae");
	//loader.loadModel("dwarf.x");
	//loader.playAllAnimations();
	//loader.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
	loader.loadModel("lee.dae");
	mesh = loader.getMesh(0);
	origVertices = mesh.getVertices(); // copie de orignele mesh 
}

//--------------------------------------------------------------
void ofApp::update(){
	//loader.update(); alleen met animaties 
	vector<ofPoint> vertices = mesh.getVertices();
	for (int i = 0; i < origVertices.size(); i += 4)// 1 op de 4 pas ik aan  
	{
		ofPoint newVertex = origVertices[i] * ofMap( sin(ofGetElapsedTimef()) , -1 ,1 , 0.9 , 1,4);
		mesh.setVertex(i, newVertex);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor(64), ofColor::black);
	camera.setScale(1, -1, 1);
	camera.begin();
	ofEnableDepthTest();  // hou rekeing met de diepte 
	//loader.drawWireframe();
//	loader.drawFaces();
	ofPushMatrix();
	ofMultMatrix(loader.getModelMatrix());
	mesh.drawWireframe();
	ofPopMatrix();
	ofDisableDepthTest();
	camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){


}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
