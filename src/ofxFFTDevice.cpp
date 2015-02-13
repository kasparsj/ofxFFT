#include "ofxFFTDevice.h"

ofxFFTDevice::ofxFFTDevice() : ofxFFTBase() {
	soundStream = NULL;
}

ofxFFTDevice::~ofxFFTDevice() {
	if(soundStream == NULL) {
		return;
	}
	soundStream->stop();
	soundStream->close();
	delete soundStream;
	soundStream = NULL;
}

void ofxFFTDevice::setup(int deviceID) {
	ofSoundStream * soundStream = new ofSoundStream();
	soundStream->setDeviceID(deviceID);
	soundStream->setup(this,                   // callback obj.
					   0,                      // out channels.
					   1,                      // in channels.
					   getSampleRate(),                  // sample rate.
					   getBufferSize(),        // buffer size.
					   4);                     // number of buffers.
	this->soundStream = soundStream;
}

void ofxFFTDevice::audioReceived(float * input, int bufferSize, int nChannels) {
	ofxFFTBase::audioIn(input);
}