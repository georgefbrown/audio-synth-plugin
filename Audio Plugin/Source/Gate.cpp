/*
 Gate.cpp
 
 Created by Matthew Stephenson on 28/11/2016
 University of Huddersfield
 Copyright 2016 Matthew Stephenson
 
 License:
 This source code is provided as is, without warranty.
 You may copy and distribute verbatim copies of this document.
 You may modify and use this source code to create binary code for your own purposes, free or commercial.
 */

#include "Gate.h"
#include "Math.h"

Gate::Gate(void)
{
	m_threshold = 0.0;
    m_env.initialise(0.001, 0.025, 44100);
    m_envGain = 1.0;
}

void Gate::initialise(float attackInSeconds, float releaseInSeconds, float sampleRate)
{
    m_env.initialise(attackInSeconds, releaseInSeconds, sampleRate);
}

void Gate::process(float& inSample)


{
    if(fabs(inSample) > m_threshold)
        m_envGain = m_env.process(1.0);
    else
        m_envGain = m_env.process(0.0);
    
    inSample = inSample * m_envGain;
   
    
     
    
    
}

void Gate::setThreshold(float threshold)
{
	m_threshold = threshold;
}

float Gate::getThreshold()
{
	return m_threshold;
}

void Gate::setAttack(float attackInSeconds)
{
    m_env.setAttack(attackInSeconds);
}

float Gate::getAttack()
{
    return m_env.getAttack();
}

void Gate::setRelease(float releaseInSeconds)
{
    m_env.setRelease(releaseInSeconds);
}

float Gate::getRelease()
{
    return m_env.getRelease();
}
