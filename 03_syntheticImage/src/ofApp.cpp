#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // typical: load an image
    // myImg.loadImage("...");
    
    // alternative: let's creat an image
    myImg.allocate(500, 500, OF_IMAGE_GRAYSCALE);
    ofSetWindowShape(myImg.width, myImg.height);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    unsigned char * pixels = myImg.getPixels();
    
    //    1D for loop
    if (counter == 0) {
        
        for (int i = 0; i < myImg.width * myImg.height; i++){
            pixels[i] = ofRandom(0,255);
        }
        
    }
    
    
    if (counter == 1) {
        for (int i = 0; i < myImg.width; i++){
            for (int j = 0; j < myImg.height; j++){
                
                pixels[ j * myImg.width + i ] = i + j;
                //((i % (j+1)) * 100;
                
            }
        }
        
    }
    
    
    if (counter == 2) {
        for (int i = 0; i < myImg.width; i++){
            for (int j = 0; j < myImg.height; j++){
                
                float dist = ofDist(mouseX, mouseY, i, j);
                pixels[ j * myImg.width + i ] = dist;  // *10
                //((i % (j+1)) * 100;
                
            }
        }
        
    }
    
    
    
    
    
    myImg.update();
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myImg.draw(0,0);
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
