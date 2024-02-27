/*
  ==============================================================================

    Gain.h
    Created: 25 Oct 2022 11:49:01am
    Author:  George Brown

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Gain  
{
public:
    Gain();
    ~Gain();
    
    void setGain(float gain);
    float getGain();
    void initialise(float gain);
    void process(float& leftSample, float& rightSample);
    

    

private:

float m_gain;
    
};
