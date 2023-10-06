#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	index = 0;

	cells.clear();
	lines.clear();
	const auto height = ofGetHeight();
	const auto width = ofGetWidth();

	// create cells with random positions and colors
	for (auto i = 0; i < 2000; i++) {
		Cell cell;
		cell.position.x = ofRandom(0, width);
		cell.position.y = ofRandom(0, height);
		cell.color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
		cells.push_back(cell);
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	const auto height = ofGetHeight();
	const auto width = ofGetWidth();

	// loop through all the cells and compare them to each other to see if they are close enough to change color
	// effectively, this creates a "neighborhood" of cells that are close to each other
	for (auto& cell : cells) {
		if (&cells[index] != &cell) {
			float distance = ofDist(cell.position.x, cell.position.y, cells[index].position.x, cells[index].position.y);
			if (distance < 100) {
				cell.color = cells[index].color;
				Line l;
				l.line = ofVec4f(cell.position.x, cell.position.y, cells[index].position.x, cells[index].position.y);
				l.color = cell.color;
				lines.push_back(l);
			}
		}
	}

	// if index is less than cells vector size, increment index
	if (index < cells.size()) {
		index++;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	// Clear the screen with a black color
	ofBackground(0, 0, 0);

	// draw the lines
	for (auto& line : lines) {
		ofSetColor(line.color, 50);
		ofDrawLine(line.line.x, line.line.y, line.line.z, line.line.w);
	}

	// draw the cells
	for (auto& cell : cells) {
		ofSetColor(cell.color);
		ofDrawCircle(cell.position.x, cell.position.y, 7);
	}
	
	// redraw the cell at the current index with a transparent color and a larger radius
	ofSetColor(cells[index].color, 127);
	ofDrawCircle(cells[index].position.x, cells[index].position.y, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	// if backspace is pressed run setup again
	if (key == ofKey::OF_KEY_BACKSPACE) {
		setup();
	}
	
	
	if (index < cells.size()) {
		index++;
	}
	
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
