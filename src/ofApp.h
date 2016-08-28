#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxCvHaarFinder.h"
#include "myo/myo.hpp"
#include "MyoDevice.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

private:
	ofImage hazuiImage;
	ofImage grayImage;
	ofImage colorImage;
	ofxCvHaarFinder haarFinder;

	myo::Hub hub;
	MyoDevice myoDevice;
	ofxKinect kinect;
};
