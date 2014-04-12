#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    myImg.loadImage("chuckClose.png");
    myImg.setImageType(OF_IMAGE_GRAYSCALE);
    
    myImg2.allocate(myImg.width, myImg.height, OF_IMAGE_GRAYSCALE);
    
    ofSetWindowShape(myImg.width*2, myImg.height);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    unsigned char * pixelsA = myImg.getPixels();
    unsigned char * pixelsB = myImg2.getPixels();
    
    for (int i = 0; i < myImg.width * myImg.height; i++){
        
        if (pixelsA[i] > mouseX){
            pixelsB[i] = 255;
        } else {
            pixelsB[i] = 0;
        }
        
        //pixelsB[i] =
    }
    
    myImg2.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0);
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    myImg.draw(0,0);
    myImg2.draw(myImg.width, 0);
    
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
