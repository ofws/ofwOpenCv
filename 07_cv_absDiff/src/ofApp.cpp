#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    grabber.initGrabber(320,240);
    colorImage.allocate(320, 240);
    grayImage.allocate(320, 240);
    diffImage.allocate(320, 240);
    
    bTakeBackground = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();
    
    if (grabber.isFrameNew()){
        
        colorImage.setFromPixels(grabber.getPixelsRef());
        grayImage = colorImage;
        grayImage.flagImageChanged();
        
        if (bTakeBackground == true){
            bg = grayImage;
            bTakeBackground = false;
        }
        
        // abs(-10) = 10
        // | |
        // abs(10) = 10;
        
        diffImage.absDiff( bg, grayImage );
        diffImage.threshold(mouseX/10);
        
        for (int i = 0; i < mouseY / 100; i++){
            diffImage.erode_3x3();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    grabber.draw(0,0);
    grayImage.draw(320,0);
    bg.draw(0,240);
    diffImage.draw(320,240);
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
    
    bTakeBackground = true;
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
