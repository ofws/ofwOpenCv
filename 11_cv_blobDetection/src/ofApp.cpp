#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
	// setup video grabber:
	grabber.initGrabber(320, 240);
	
	colorImage.allocate(320, 240);
	grayscaleImage.allocate(320, 240);
	bgImage.allocate(320, 240);
	diffImage.allocate(320, 240);
    
    //set defaults
    bLearnBg = true;
	threshold = 52;
	minBlobSize = 100;
	maxBlobSize = 10000;
	nBlobsConsidered = 3;
    
    //UI
    thresholdFader.set(660, 20, 255, 20);
    minBlobFader.set(660, 60, 255, 20);
    maxBlobFader.set(660, 100, 255, 20);
    maxnBlobsFader.set(660, 140, 255, 20);

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
	
	grabber.update();
	
	if (grabber.isFrameNew()){
		
		colorImage.setFromPixels(grabber.getPixelsRef());
		grayscaleImage = colorImage;
		
		if (bLearnBg ){
			bgImage = grayscaleImage;
            bLearnBg = false;
		}
		
		diffImage.absDiff(grayscaleImage, bgImage);
		diffImage.threshold(threshold);
		
		contourFinder.findContours(diffImage, minBlobSize, maxBlobSize, nBlobsConsidered, false, true);
		
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofSetColor(255);
    grayscaleImage.draw(0,0,320,240);
	bgImage.draw(320, 0, 320, 240);
	diffImage.draw(0,240);
	contourFinder.draw(0,240);
	
	contourFinder.draw(320,240);
    
    
    
    
    //UI
    ofSetColor(255);
    ofRect(thresholdFader);
    ofRect(minBlobFader);
    ofRect(maxBlobFader);
    ofRect(maxnBlobsFader);
    
    ofSetColor(ofColor::lightBlue);
    ofRect(thresholdFader.x, thresholdFader.y, threshold, thresholdFader.height);
    ofRect(minBlobFader.x, minBlobFader.y, sqrt(minBlobSize) , minBlobFader.height);
    ofRect(maxBlobFader.x, maxBlobFader.y, sqrt(maxBlobSize), maxBlobFader.height);
    ofRect(maxnBlobsFader.x, maxnBlobsFader.y, nBlobsConsidered*10, maxnBlobsFader.height);
    
    ofSetColor(0);
    ofDrawBitmapString("threshold : " + ofToString(threshold), thresholdFader.position-5);
    ofDrawBitmapString("minBlob : " + ofToString(minBlobSize), minBlobFader.position-5);
    ofDrawBitmapString("maxBlob : " + ofToString(maxBlobSize), maxBlobFader.position-5);
    ofDrawBitmapString("n Blobs considered : " + ofToString(nBlobsConsidered), maxnBlobsFader.position-5);

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
    
    //UI
    if(thresholdFader.inside(x, y)) threshold = x - thresholdFader.x;
    if(minBlobFader.inside(x, y)) minBlobSize = pow(x - minBlobFader.x,2);
    if(maxBlobFader.inside(x, y)) maxBlobSize = pow(x - maxBlobFader.x,2);
    if(maxnBlobsFader.inside(x, y)) nBlobsConsidered = (x - maxnBlobsFader.x)/10;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //UI
    if(thresholdFader.inside(x, y)) threshold = x - thresholdFader.x;
    else if(minBlobFader.inside(x, y)) minBlobSize = pow(x - minBlobFader.x,2);
    else if(maxBlobFader.inside(x, y)) maxBlobSize = pow(x - maxBlobFader.x,2);
    else if(maxnBlobsFader.inside(x, y)) nBlobsConsidered = (x - maxnBlobsFader.x)/10;
    
    //take bg
    else bLearnBg = true;
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
