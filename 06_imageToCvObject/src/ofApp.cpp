#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
	myImg.loadImage("chuckClose.png");
	myImg.setImageType(OF_IMAGE_GRAYSCALE);
	myImgCv.allocate(myImg.width, myImg.height);
    
    ofSetWindowShape(myImg.width*2, myImg.height);

}

//--------------------------------------------------------------
void ofApp::update(){
    
	myImgCv.setFromPixels(myImg.getPixelsRef());
    // blur function need odd number to operate,,,
    if (counter == 1 || counter == 2) myImgCv.blur( MAX((mouseY/10) * 2 + 1, 1));
    if (counter == 0 || counter == 2) myImgCv.threshold(mouseX/2);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
	ofSetColor(255, 255, 255);
	myImg.draw(0,0);
	myImgCv.draw(myImg.width, 0);
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
    counter++;
    counter%=3;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
