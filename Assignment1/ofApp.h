#pragma once

#include "ofMain.h"


//  Shape base class
//
class Shape {
public:
	Shape() {}
	virtual void draw() {}
	virtual bool inside() { return false;  }
	float x = ofGetWindowWidth() / 2.0;
	float y = ofGetWindowHeight() / 2.0;
	bool in = false;
	glm::vec3 pos;
	float rotation = 0.0;
	glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
	glm::mat4 T;
	vector<glm::vec3> verts;
};

//  TriangleShape
//
class TriangleShape : public Shape {
public:
	TriangleShape(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3) {
		verts.push_back(p1);
		verts.push_back(p2);
		verts.push_back(p3);
	}
	bool inside(glm::vec3 p, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);

	void draw();
};

//  Example - we could define any type of shape we want
//
class LineDrawingShape : public Shape {
public:
	void draw() {};
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		// initialize triangle - note: I changed vertices to match what I had in demo video
		//
	    TriangleShape tri = TriangleShape(glm::vec3(-20, -20, 0), glm::vec3(0, 40, 0), glm::vec3(20, -20, 0));
	
};
