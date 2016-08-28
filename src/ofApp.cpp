#include "ofApp.h"
#include "ofxOpenCv.h"
#include "myo/myo.hpp"
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
	kinect.init();
	kinect.open();

	kinect.setRegistration(true);
	ofSetFrameRate(60);


	myoDevice.enjoy = false;
	myo::Myo* myo = hub.waitForMyo(10000);
	myo->setStreamEmg(myo::Myo::streamEmgEnabled);
	hub.addListener(&myoDevice);

	hazuiImage.load("hazui.png");
	haarFinder.setup("haarcascade_frontalface_default.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
	kinect.update();

	int width = kinect.width;
	int height = kinect.height;
	
	ofPixels pixels = kinect.getPixels();
	colorImage.allocate(width, height, OF_IMAGE_COLOR);
	colorImage.setFromPixels(pixels,width,height,OF_IMAGE_COLOR,true);

	cv::Mat mat = cv::Mat(height, width, CV_8UC3, colorImage.getPixels());
	cvtColor(mat, mat, CV_RGB2GRAY);
	grayImage.allocate(width, height, OF_IMAGE_GRAYSCALE);
	grayImage.setFromPixels(mat.ptr(), mat.cols,mat.rows, OF_IMAGE_GRAYSCALE);

	haarFinder.findHaarObjects(grayImage);

	hub.run(100);
	myoDevice.print();
}

//--------------------------------------------------------------
void ofApp::draw(){
	int width = kinect.width;
	int height = kinect.height;

	//kinect.draw(0, 0, width,height);

	colorImage.draw(0, 0, width, height);
	//grayImage.draw(0, 0, width, height);

	if (myoDevice.enjoy) {
		ofNoFill();
		for (unsigned int i = 0; i < haarFinder.blobs.size(); i++) {
			ofRectangle cur = haarFinder.blobs[i].boundingRect;
			float hazuiHeight = (cur.height / 5.0);
			float hazuiWidth = (cur.width * 0.8);
			float hazuiX = cur.x + (cur.width * 0.1);
			float hazuiY = cur.y + (cur.height * 0.4);
			hazuiImage.draw(hazuiX, hazuiY, hazuiWidth, hazuiHeight);
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

void ofApp::exit() {
	kinect.close();
}