#include "ofApp.h"

void TriangleShape::draw() {

	glm::mat4 trans = glm::translate(glm::mat4(1.0), glm::vec3(pos));
	glm::mat4 rot = glm::rotate(glm::mat4(1.0), glm::radians(rotation+180), glm::vec3(0, 0, 1));
	glm::mat4 scale = glm::scale(glm::mat4(1.0), this->scale);

	T = trans * rot * scale;


	//  1st approach transform each point
	//
	glm::vec3 p1 = T* glm::vec4(verts[0], 1);
	glm::vec3 p2 = T * glm::vec4(verts[1], 1);
	glm::vec3 p3 = T * glm::vec4(verts[2], 1);

	ofDrawTriangle(p1, p2, p3);


	
}
//--------------------------------------------------------------
void ofApp::setup(){
	tri.pos = glm::vec3(tri.x, tri.y, 1);
	tri.rotation = 0;
	ofSetColor(ofColor::darkBlue);
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	tri.draw();
}

// inside() test method - check to see if point p is inside triangle.
// how could you improve the design of this method ?
//
bool TriangleShape::inside(glm::vec3 p, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3) {
	glm::vec3 v1 = glm::normalize(p1 - p);
	glm::vec3 v2 = glm::normalize(p2 - p);
	glm::vec3 v3 = glm::normalize(p3 - p);
	float a1 = glm::orientedAngle(v1, v2, glm::vec3(0, 0, 1));
	float a2 = glm::orientedAngle(v2, v3, glm::vec3(0, 0, 1));
	float a3 = glm::orientedAngle(v3, v1, glm::vec3(0, 0, 1));
	if (a1 < 0 && a2 < 0 && a3 < 0) return true;
	else return false;
}
//--------------------------------------------------------------
//
void ofApp::keyPressed(int key){
	ofSetColor(ofColor::white);
	switch (key) {
	case OF_KEY_LEFT:
		tri.rotation -= 1;
		break;
	case OF_KEY_RIGHT:
		tri.rotation += 1;
		break;
	case OF_KEY_UP:
		tri.y -= glm::cos(glm::radians(tri.rotation));
		tri.x += glm::sin(glm::radians(tri.rotation));
		tri.pos = glm::vec3(tri.x, tri.y, 1);
		break;
	case OF_KEY_DOWN:
		tri.y += glm::cos(glm::radians(tri.rotation));
		tri.x -= glm::sin(glm::radians(tri.rotation));
		tri.pos = glm::vec3(tri.x, tri.y, 1);
		break;
	default:
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	ofSetColor(ofColor::darkBlue);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (tri.in){
		tri.pos = glm::vec3(x, y, 1);
		tri.x = x;
		tri.y = y;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	glm::vec4 newP = glm::inverse(tri.T) * glm::vec4(x,y,1,1);
	if (tri.inside(newP, tri.verts[0], tri.verts[1], tri.verts[2])) {
		tri.in = true;
	}
	else {
		tri.in = false;
	}
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
