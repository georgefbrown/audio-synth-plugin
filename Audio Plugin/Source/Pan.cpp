/*
  ==============================================================================

    Pan.cpp
    Created: 15 Nov 2022 11:58:09am
    Author:  George Brown

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Pan.h"


//==============================================================================

const float PI = 3.141593;


Pan::Pan()
{
   

}

Pan::~Pan()
{
}



void Pan::setPan(float pan)
{
   m_pan = pan;
}


float Pan :: getPan()
{
    return m_pan;
}


void Pan:: initialise(float pan)
{
    setPan(pan);
}

void Pan:: process(float &leftSample, float &rightSample)
{
   float pCoeff;
   float leftGain;
   float rightGain;
   
   pCoeff = (PI * (m_pan + 1))/4;
   
   leftGain = cos(pCoeff);
   rightGain = sin(pCoeff);
   
   leftSample = leftSample* leftGain;
   rightSample = rightSample*rightGain;
    
}
  
