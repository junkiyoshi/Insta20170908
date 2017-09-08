#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	this->cap.open(1);

	this->frame_img.allocate(this->cap.get(CV_CAP_PROP_FRAME_WIDTH), this->cap.get(CV_CAP_PROP_FRAME_HEIGHT), OF_IMAGE_COLOR);
	this->frame = cv::Mat(this->frame_img.getHeight(), this->frame_img.getWidth(), CV_MAKETYPE(CV_8UC3, this->frame_img.getPixels().getNumChannels()), this->frame_img.getPixels().getData(), 0);

	cout << this->cap.get(CV_CAP_PROP_FRAME_WIDTH) << " : " << this->cap.get(CV_CAP_PROP_FRAME_HEIGHT) << endl;
}

//--------------------------------------------------------------
void ofApp::update() {
	if (!this->cap.isOpened()) { return; }

	this->cap >> this->frame;
	if (this->frame.empty()) { return; }

	cv::cvtColor(this->frame, this->frame, CV_RGB2BGR);
	cv::flip(this->frame, this->frame, 1);

	switch (ofGetFrameNum() % 15)
	{
	case 0:
		this->frame.copyTo(this->save_frame[0]);
		break;
	case 3:
		this->frame.copyTo(this->save_frame[1]);
		break;
	case 6:
		this->frame.copyTo(this->save_frame[2]);
		break;
	case 9:
		this->frame.copyTo(this->save_frame[3]);
		break;
	case 12:
		this->frame.copyTo(this->save_frame[4]);
		break;
	}

	this->frame = this->frame / 6 + this->save_frame[0] / 6 + this->save_frame[1] / 6 + this->save_frame[2] / 6 + this->save_frame[3] / 6 + this->save_frame[4] / 6
		+ this->save_frame[5] / 6;
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();
	
	ofTranslate(-this->frame_img.getWidth() / 2, -this->frame_img.getHeight() / 2);

	this->frame_img.update();
	this->frame_img.draw(0, 0);

	this->cam.end();
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
