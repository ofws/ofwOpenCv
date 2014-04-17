#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    grabber.initGrabber(320,240);
    colorImage.allocate(320, 240);
    currFrame.allocate(320, 240);
    prevFrame.allocate(320, 240);
    diffImage.allocate(320, 240);
    
    player.loadSound("8LJ0wHPxuGeq.128.mp3");
    player.setLoop(true);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (ofGetFrameNum() == 200)
        player.play();
    
    
    grabber.update();
    
    if (grabber.isFrameNew()){
        
        colorImage.setFromPixels(grabber.getPixelsRef());
        currFrame = colorImage;
        currFrame.flagImageChanged();
        
        
        
        diffImage.absDiff( currFrame, prevFrame );
        diffImage.threshold(mouseX/10);
        
        int nWhitePixels = diffImage.countNonZeroInRegion(0, 0, 320, 240);
        cout << nWhitePixels << endl;
        
        float speed = ofMap(nWhitePixels, 0, 10000, 0.1, 1.5, true);
        player.setSpeed(speed);
        
        prevFrame = currFrame;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    grabber.draw(0,0);
    currFrame.draw(320,0);
    prevFrame.draw(0,240);
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
