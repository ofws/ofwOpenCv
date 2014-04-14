#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
	videoGrabber.initGrabber(320, 240);
    
	colorImg.allocate(videoGrabber.width, videoGrabber.height);
	grayImage.allocate(videoGrabber.width, videoGrabber.height);
	
	points[0] = (CvPoint2D32f*)cvAlloc(MAX_COUNT*sizeof(points[0][0]));
	points[1] = (CvPoint2D32f*)cvAlloc(MAX_COUNT*sizeof(points[0][0]));
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100,100,100);
    
	videoGrabber.update();
	
	bool bNewFrame = false;
	unsigned char * pixels;
    
	pixels = videoGrabber.getPixels();
	bNewFrame = videoGrabber.isFrameNew();
    
	if (bNewFrame){
		colorImg.setFromPixels(pixels, videoGrabber.width, videoGrabber.height);
        
		grayImage = colorImg;
		grayImage.mirror(false, true);
	}
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
	ofSetHexColor(0xffffff);
	
    
    IplImage* eig = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    IplImage* temp = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    
	double quality = 0.01;
	double min_distance = 10;
	int count = 100;
    //    int win_size = 10;
    
	cvGoodFeaturesToTrack( grayImage.getCvImage(), eig, temp, points[1], &count, quality, min_distance, 0, 3, 0, 0.04 );
    //    cvFindCornerSubPix( grayImage.getCvImage(), points[1], count, cvSize(win_size,win_size), cvSize(-1,-1), cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03));
	
    cvReleaseImage( &eig );
    cvReleaseImage( &temp );
    
	grayImage.draw(0,0, 320, 240);
    
	for(int i=0; i<count; i++){
		float x = points[1][i].x;
		float y = points[1][i].y;
		ofLine(x-5, y, x+5, y);
		ofLine(x, y-5, x, y+5);
	}
    
	ofDrawBitmapString("capture  : "+ofToString((int) ofGetFrameRate())+" fps", 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
	switch (key){
		case 's' :
			ofImage img;
			img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
			img.grabScreen(0,0,ofGetWidth(), ofGetHeight());
			img.saveImage("faceTracking.jpg");
			break;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
