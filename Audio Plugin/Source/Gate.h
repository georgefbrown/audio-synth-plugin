/*
 Gate.h
 
 Created by Matthew Stephenson on 28/11/2016
 University of Huddersfield
 Copyright 2016 Matthew Stephenson
 
 License:
 This source code is provided as is, without warranty.
 You may copy and distribute verbatim copies of this document.
 You may modify and use this source code to create binary code for your own purposes, free or commercial.
 */

#ifndef GATE_H_INCLUDED
#define GATE_H_INCLUDED

#include "EnvelopeDetector.h"

class Gate
{
public:

	Gate(void);
    
    void initialise(float attackInSeconds, float releaseInSeconds, float sampleRate);

	void process(float& inSample);
	
    void setThreshold(float m_threshold);
	float getThreshold();
    
    void setAttack(float attackInSeconds);
    float getAttack();
    
    void setRelease(float releaseInSeconds);
    float getRelease();
    
private:

	float m_threshold;
    float m_envGain;
    EnvelopeDetector m_env;
};


#endif  // GATE_H_INCLUDED
