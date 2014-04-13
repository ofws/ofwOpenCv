#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
        ofVideoGrabber			grabber;
        ofxCvColorImage			colorImage;
        ofxCvColorImage			colorHSVImage;
        
        ofxCvGrayscaleImage		hueImage;
        ofxCvGrayscaleImage		satImage;
        ofxCvGrayscaleImage		briImage;
        
        unsigned char *			grayPixels;
        ofxCvGrayscaleImage		colorTrackImage;
        
        
        // for tracking...
        int hue, sat, bri;
        
        int hueRange;
        int satRange;
        int briRange;
    
        ofRectangle hueFader;
        ofRectangle satFader;
        ofRectangle briFader;
        ofRectangle thresholdFader;
    
};
