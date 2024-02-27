/*
  ==============================================================================

    EQ.h
    Created: 26 Mar 2023 12:46:26pm
    Author:  George Brown

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <vector>
#include "DelayLine.h"
#include "LFO.h"



//==============================================================================
/*
*/
class EQ  : public juce::Component
{
public:
    EQ();
    ~EQ() override;
    
    
    
    void process(float &in);
    
    void setchorusRate (float chorusRate) ;
    
    
    
    

 

private:
   
    
    //highpass
    bool highpass;
    float cutoffFrequency;
    float sampleRate;
    float output1;
    float output2;
    float newSample;

    
    float m_cutoffFreq;
    float m_numSamples;
    float m_sampleRate;
    bool m_highpass;
    std::vector<float> dnBuffer;
    
    
    //using delayLine
    
    DelayLine m_Delay;
    DelayLine m_Delay2;
    DelayLine m_Delay3;
    DelayLine m_Delay4;
    
    float chorus;
    float m_chorusRate;
    
    LFO m_chorus;
    
    
    float b0;
    float b1;
    float b2;
    
};

