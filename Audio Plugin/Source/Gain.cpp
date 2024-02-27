/*
  ==============================================================================

    Gain.cpp
    Created: 25 Oct 2022 11:49:01am
    Author:  George Brown

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Gain.h"

//==============================================================================
Gain::Gain()
{
   

}

Gain::~Gain()
{
}



void Gain::setGain(float gain)
{
   m_gain = gain;
}


float Gain :: getGain()
{
    return m_gain;
}


void Gain:: initialise(float gain)
{
    setGain(gain);
}

void Gain:: process(float &leftSample, float &rightSample)
{
    leftSample = leftSample * juce::Decibels::decibelsToGain(m_gain);
    rightSample = rightSample *juce::Decibels::decibelsToGain(m_gain);
    
}
    


