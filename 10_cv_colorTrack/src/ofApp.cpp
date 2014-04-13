#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
	// setup video grabber:
	grabber.initGrabber(320, 240);
	
	
	colorImage.allocate(320, 240);
	colorHSVImage.allocate(320, 240);
	
	hueImage.allocate(320, 240);
	satImage.allocate(320, 240);
	briImage.allocate(320, 240);
	
	colorTrackImage.allocate(320, 240);
	
	grayPixels = new unsigned char [320 * 240];
	
	
	hueRange = 20;
	satRange = 30;
	briRange = 25;
	
	hue = 0;
	sat = 0;
	bri = 0;
    
    
    hueFader.set(660, 20, 255, 20);
    satFader.set(660, 60, 255, 20);
    briFader.set(660, 100, 255, 20);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();
    
	if (grabber.isFrameNew()){
		
		colorImage.setFromPixels(grabber.getPixelsRef());
		colorHSVImage = colorImage;
		colorHSVImage.convertRgbToHsv();
		
		colorHSVImage.convertToGrayscalePlanarImages(hueImage, satImage, briImage);
		
        
		unsigned char * colorHsvPixels = colorHSVImage.getPixels();
		
		for (int i = 0; i < 320*240; i++){
			
            // since hue is cyclical:
            int hueDiff = colorHsvPixels[i*3] - hue;
            if (hueDiff < -127) hueDiff += 255;
            if (hueDiff > 127) hueDiff -= 255;
			
			
            if ( (fabs(hueDiff) < hueRange) &&
                (colorHsvPixels[i*3+1] > (sat - satRange) && colorHsvPixels[i*3+1] < (sat + satRange)) &&
                (colorHsvPixels[i*3+2] > (bri - briRange) && colorHsvPixels[i*3+2] < (bri + briRange))){
                
                grayPixels[i] = 255;
                
            } else {
                
                grayPixels[i] = 0;
            }
            
        }
        
        colorTrackImage.setFromPixels(grayPixels, 320, 240);
        
	}

    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    
	colorImage.draw(0,0, 320,240);
    ofDrawBitmapString("video input", 10,20);
    
	colorHSVImage.draw(0, 240, 320, 240);
    ofDrawBitmapString("HSV", 10,260);
    
	colorTrackImage.draw(0,480,320,240);
    ofDrawBitmapString("color tracking", 10,500);
    
	hueImage.draw(320,0);
    ofDrawBitmapString("HUE data", 330,20);
	satImage.draw(320,240);
    ofDrawBitmapString("SAT data", 330,260);
	briImage.draw(320,480);
    ofDrawBitmapString("BRI data/grayscale", 330,500);
    
    
    
    
    ofSetColor(255);
    ofRect(hueFader);
    ofRect(satFader);
    ofRect(briFader);
    
    ofSetColor(ofColor::lightBlue);
    ofRect(hueFader.x, hueFader.y, hueRange, hueFader.height);
    ofRect(satFader.x, satFader.y, satRange, satFader.height);
    ofRect(briFader.x, briFader.y, briRange, briFader.height);
    
    ofSetColor(0);
    ofDrawBitmapString("hue : " + ofToString(hueRange), hueFader.position-5);
    ofDrawBitmapString("saturation : " + ofToString(satRange), satFader.position-5);
    ofDrawBitmapString("brightness : " + ofToString(briRange), briFader.position-5);
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
    
    if(hueFader.inside(x, y)) hueRange = x - hueFader.x;
    if(satFader.inside(x, y)) satRange = x - satFader.x;
    if(briFader.inside(x, y)) briRange = x - briFader.x;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
	if (x >= 0 && x < 320 && y >= 0 && y < 240){
		int pixel = y * 320 + x;
		hue = hueImage.getPixels()[pixel];
		sat = satImage.getPixels()[pixel];
		bri = briImage.getPixels()[pixel];
		
	}
    
    
    if(hueFader.inside(x, y)) hueRange = x - hueFader.x;
    if(satFader.inside(x, y)) satRange = x - satFader.x;
    if(briFader.inside(x, y)) briRange = x - briFader.x;
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
