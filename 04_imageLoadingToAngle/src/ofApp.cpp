#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    myImg.loadImage("chuckClose.png");
    myImg.setImageType(OF_IMAGE_GRAYSCALE);
    
    
    
    ofSetWindowShape(myImg.width*2, myImg.height);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0);
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    myImg.draw(0,0);
    
    unsigned char * pixels = myImg.getPixels();
    
    
    if (counter == 0 ) {
        
        ofSetRectMode(OF_RECTMODE_CENTER);
        
        for (int i = 0; i < myImg.width; i += 10){
            for (int j = 0; j < myImg.width; j+=10){
                int pixelVal = pixels[j*myImg.width + i];
                
                float angle = ofMap(pixelVal, 0, 255, 0, 180);
                
                ofPushMatrix();  // take a snapshot (identity matrix)
                ofTranslate(i + myImg.width, j);
                ofRotateZ(angle);
                ofRect(0,0, 10,2);
                ofPopMatrix();
            }
        }
    }
    
    if (counter == 1 ) {
    
        for (int i = 0; i < myImg.width; i += 10){
            for (int j = 0; j < myImg.width; j+=10){
                int pixelVal = pixels[j*myImg.width + i];

                float radius = ofMap(pixelVal, 0, 255, .5, 3.6);

                ofCircle(i + myImg.width, j, radius);
            }
        }
    }
    
    
    
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
    counter%=2;
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
