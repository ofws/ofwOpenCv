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
    
	ofVideoGrabber 		vidGrabber;
    
    
	ofxCvColorImage		colorImg;
    
	ofxCvGrayscaleImage 	grayImage,prevGrayImage;
    
	IplImage *pyramid, *prev_pyramid, *swap_temp;
	char* status;
    
	static const int MAX_COUNT = 500;
	CvPoint2D32f* points[2];
    
	double quality;
	double min_distance;
	int count;
	int flags;
	int win_size;
    
	bool opticalFlow;
	
	bool selecting;
	CvPoint origin;
	CvRect selection;
};
