/*
  ==============================================================================

    EQ.cpp
    Created: 26 Mar 2023 12:46:26pm
    Author:  George Brown

  ==============================================================================
*/

#include <JuceHeader.h>
#include "EQ.h"
#include <cmath>


//==============================================================================
EQ::EQ()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    
    m_Delay.initialise(48000,2000);
    m_Delay.setDelay(0);
    m_Delay.setFeedback(0);
    m_Delay.setFeedforward(0);
    
    m_Delay2.initialise(48000,2000);
    m_Delay2.setDelay(25);
    m_Delay2.setFeedback(0.1);
    m_Delay2.setFeedforward(0);
    
  

}

EQ::~EQ()
{  
}
 




void EQ::setchorusRate (float chorusRate)
{
    m_chorusRate = chorusRate;
    //m_Delay.setDelay(m_chorusRate);
   // m_Delay2.setDelay(m_chorusRate);
   // m_Delay3.setDelay(m_chorusRate);
    
    
}

void EQ::process(float &in)
{

//newSample = in;


    m_Delay.process(in) ;
    m_Delay2.process(in) ;

//in = output1;
//return (in);
}
