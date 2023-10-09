#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	// in case of reset, clear the vectors and reset the index
	index = 0;
	cells.clear();
	lines.clear();

	ofBackground(0, 0, 0);

	// provide a tiny performance boost by caching the height and width
	const auto height = ofGetHeight();
	const auto width = ofGetWidth();

	// create cells with random positions and colors and push them into the cells vector
	// add some padding to the width and height to prevent cells from being drawn on the edge
	for (auto i = 0; i < numCells; i++) {
		Cell cell;
		cell.position.x = ofRandom(10, width - 10);
		cell.position.y = ofRandom(10, height - 10);
		cell.color = ofColor(ofRandom(50, 255), ofRandom(50, 255), ofRandom(50, 255));
		cells.push_back(cell);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	//const auto height = ofGetHeight();
	//const auto width = ofGetWidth();

	// loop through all the cells and compare them to each other to see if they are close enough to change color
	// effectively, this creates a "neighborhood" of cells that are close to each other
	for (auto& cell : cells) {
		if (&cells[index] != &cell) {
			float distance = ofDist(cell.position.x, cell.position.y, cells[index].position.x, cells[index].position.y);
			if (distance < distanceThreshold) {
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

	// draw the lines
	for (auto& line : lines) {
		ofSetColor(line.color, 50);
		ofDrawLine(line.line.x, line.line.y, line.line.z, line.line.w);
	}

	// draw the cells
	for (auto& cell : cells) {
		ofSetColor(cell.color);
		ofDrawCircle(cell.position.x, cell.position.y, distanceThreshold / 20);
	}
	
	// redraw the cell at the current index with a transparent color and a larger radius
	ofSetColor(cells[index].color, 150);
	ofDrawCircle(cells[index].position.x, cells[index].position.y, distanceThreshold);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	// if backspace is pressed run setup again
	if (key == ofKey::OF_KEY_BACKSPACE) {
		setup();
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
