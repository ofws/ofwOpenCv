#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    grabber.initGrabber(320,240);
    colorImage.allocate(320, 240);
    currFrame.allocate(320, 240);
    prevFrame.allocate(320, 240);
    diffImage.allocate(320, 240);
    diffMHI.allocate(320, 240);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();
    
    if (grabber.isFrameNew()){
        
        colorImage.setFromPixels(grabber.getPixelsRef());
        currFrame = colorImage;
        
        
        diffImage.absDiff( currFrame, prevFrame );
        if(ofGetFrameNum() < 200) diffImage.threshold(50);
        else diffImage.threshold(mouseX/10);
        
        cout << "threshold : " << mouseX/10 << endl;
        
        //darken non-movement areas overtime
        diffMHI -=2;
        //lighten movement area
        diffMHI += diffImage;
        diffMHI.blur(9);
        
        prevFrame = currFrame;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    grabber.draw(0,0);
    prevFrame.draw(320,0);
    diffImage.draw(0,240);
    diffMHI.draw(320,240);
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
