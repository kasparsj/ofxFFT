#pragma once

#include "ofMain.h"
#include "ofxFFTBase.h"

class ofxFFTDevice : public ofxFFTBase {
	
public:
	
	ofxFFTDevice();
	~ofxFFTDevice();
	
	void setup(int deviceID);
	void audioReceived(float * input, int bufferSize, int nChannels);
	
	ofSoundStream * soundStream;
};