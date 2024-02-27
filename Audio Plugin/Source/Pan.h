/*
  ==============================================================================

    Pan.h
    Created: 15 Nov 2022 11:58:09am
    Author:  George Brown

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/


class Pan  
{
public:
    Pan();
    ~Pan();
    
    void setPan(float pan);
    float getPan();
    void initialise(float pan);
    void process(float& leftSample, float& rightSample);
    

    

private:

float m_pan;
    
};