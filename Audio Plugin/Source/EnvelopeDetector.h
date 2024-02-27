/*
 EnvelopeDetector.h
 
 Created by Matthew Stephenson on 28/11/2016
 University of Huddersfield
 Copyright 2016 Matthew Stephenson
 
 License:
 This source code is provided as is, without warranty.
 You may copy and distribute verbatim copies of this document.
 You may modify and use this source code to create binary code for your own purposes, free or commercial.
 */

#ifndef ENVELOPEDETECTOR_H_INCLUDED
#define ENVELOPEDETECTOR_H_INCLUDED

//This is a peak detector envelope
class EnvelopeDetector
{
public:

	EnvelopeDetector();

	void initialise(float attackInSeconds, float releaseInSeconds, float sampleRate);

	float process(float inSample);

	void setAttack(float attackInSeconds);
	float getAttack();

	void setRelease(float releaseInSeconds);
	float getRelease();


private:

	float m_env;
	float m_sampleRate;
	float m_attack;
	float m_release;
	float m_attackCoeff;
	float m_releaseCoeff;

};


#endif  // ENVELOPEDETECTOR_H_INCLUDED
