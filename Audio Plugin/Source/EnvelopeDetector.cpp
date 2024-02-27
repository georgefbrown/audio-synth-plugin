/*
 EnvelopeDetector.cpp
 
 Created by Matthew Stephenson on 28/11/2016
 University of Huddersfield
 Copyright 2016 Matthew Stephenson
 
 License:
 This source code is provided as is, without warranty.
 You may copy and distribute verbatim copies of this document.
 You may modify and use this source code to create binary code for your own purposes, free or commercial.
 */

#include "EnvelopeDetector.h"
#include <cmath>

EnvelopeDetector::EnvelopeDetector(void)
{
	m_env = 0.0;
	m_attack = 20.0;
	m_release = 20.0;
	m_sampleRate = 44100;
}

void EnvelopeDetector::initialise(float attackInSeconds, float releaseInSeconds, float sampleRate)
{
	m_sampleRate = sampleRate;
	setAttack(attackInSeconds);
	setRelease(releaseInSeconds);
}

void EnvelopeDetector::setAttack(float attackInSeconds)
{
	m_attack = attackInSeconds;
	m_attackCoeff = (float) exp(-1.0/(m_sampleRate*m_attack));
}

float EnvelopeDetector::getAttack()
{
	return m_attack;
}

void EnvelopeDetector::setRelease(float releaseInSeconds)
{
	m_release = releaseInSeconds;
	m_releaseCoeff = (float) exp(-1.0/(m_sampleRate*m_release));
}

float EnvelopeDetector::getRelease()
{
	return m_release;
}

float EnvelopeDetector::process(float inSample)
{
	float in = fabs(inSample);

	if(in > m_env)
		m_env = m_attackCoeff * (m_env - in) + in;
	else
		m_env = m_releaseCoeff * (m_env - in) + in;

	return m_env;
}


