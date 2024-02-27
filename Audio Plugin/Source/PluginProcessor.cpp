/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "LFO.h"
#include "DelayLine.h"
#include "Gate.h"
#include "EQ.h"


//==============================================================================
Tutorial5classesAudioProcessor::Tutorial5classesAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    
  
}

Tutorial5classesAudioProcessor::~Tutorial5classesAudioProcessor()
{
    theReverbParameters.dryLevel = 100;
    theReverbParameters.wetLevel = 50;
    theReverbParameters.roomSize = 50;
    theReverbParameters.damping = 10;
    theReverb.setParameters(theReverbParameters);
    
   
    
}

//==============================================================================
const juce::String Tutorial5classesAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Tutorial5classesAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Tutorial5classesAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Tutorial5classesAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Tutorial5classesAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Tutorial5classesAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Tutorial5classesAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Tutorial5classesAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Tutorial5classesAudioProcessor::getProgramName (int index)
{
    return {};
}

void Tutorial5classesAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Tutorial5classesAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    //synth1 initalise
    m_LFO.setSamplingFrequency(sampleRate);
    m_LFO.setDepth(0);
    m_LFO.setFrequency(1000);
    m_LFO.setWaveshape(kSine);
    m_detune = 0.0;
    
    //synth1 Octave initalise
    m_LFOOctave.setSamplingFrequency(sampleRate);
    m_LFOOctave.setDepth(0);
    m_LFOOctave.setFrequency(1000);
    m_LFOOctave.setWaveshape(kSine);
    
    
      //synth2 initalise
    m_LFO2.setSamplingFrequency(sampleRate);
    m_LFO2.setDepth(0);
    m_LFO2.setFrequency(1000);
    m_LFO2.setWaveshape(kSine);
    m_detune2 = 0.0;
    
      //synth2 octave initalise
    m_LFOOctave2.setSamplingFrequency(sampleRate);
    m_LFOOctave2.setDepth(0);
    m_LFOOctave2.setFrequency(1000);
    m_LFOOctave2.setWaveshape(kSine);
   
    
    //gain initalise 
    m_GainInstance.initialise(0);
    m_PanInstance.initialise(0);
    
    // stereo delay initalise
    m_DelayLineInstance.initialise(sampleRate, 2000);
    m_DelayLineInstance2.initialise(sampleRate, 2000);
    m_delayTimeMS = 0;
    m_wet = 0;
    m_DelayLineInstance.setDelay(m_delayTimeMS);
    m_DelayLineInstance2.setDelay(m_delayTimeMS);
    m_outputSample = 0;
    m_outputSample2 = 0;
    m_feedbackAmount = 50;
    //m_stereoDelay = 1;
    
    //multitap delay initialise
    
    
    m_wet_multiTap = 0;
    m_feedbackAmount_multiTap = 50;
    
    m_DelayLineInstance3.initialise(sampleRate, 2000);
    m_delayTimeMS_multiTap = 100;
    m_DelayLineInstance3.setDelay(m_delayTimeMS_multiTap);
    m_outputSampleleft = 0;
    m_outputSampleright = 0;
    
    m_DelayLineInstance4.initialise(sampleRate, 2000);
    m_delayTimeMS_multiTap2 = 200;
    m_DelayLineInstance4.setDelay(m_delayTimeMS_multiTap2);
    m_outputSampleleft2 = 0;
    m_outputSampleright2 = 0;
    
    m_DelayLineInstance5.initialise(sampleRate, 2000);
    m_delayTimeMS_multiTap3 = 300;
    m_DelayLineInstance5.setDelay(m_delayTimeMS_multiTap3);
    m_outputSampleleft3 = 0;
    m_outputSampleright3 = 0;
    
    
  // chorus
  
  m_wet_Chorus = 0.0;
  m_feedbackAmount_Chorus = 0.1;
  
  m_DelayLineInstanceleftChorus.initialise(sampleRate, 2000);
  m_delayTimeMS_leftChorus = 15;
  m_DelayLineInstanceleftChorus.setDelay(m_delayTimeMS_leftChorus);
  m_outputSampleleftChorus = 0;
  
  
  m_DelayLineInstancerightChorus.initialise(sampleRate, 2000);
  m_delayTimeMS_rightChorus = 25;
  m_DelayLineInstancerightChorus.setDelay(m_delayTimeMS_rightChorus);
  m_outputSamplerightChorus = 0;
  

  
  m_LFOChorus.setSamplingFrequency(sampleRate);
  m_LFOChorus.setDepth(0.1);
  m_LFOChorus.setFrequency(1.0);
  m_LFOChorus.setWaveshape(kSine);
    
  
    
    
    
    // Pan initalise
    m_Pan.setPan(0);
    m_Pan2.setPan(0);
    
    //ADSR
    
    theADSR.setSampleRate(sampleRate);
    theADSRParameters.attack= 0.0;
    theADSRParameters.decay= 0.3;
    theADSRParameters.sustain=0.3;
    theADSRParameters.release=0.5;
    theADSR.setParameters(theADSRParameters);
    
    theADSR2.setSampleRate(sampleRate);
    theADSRParameters2.attack= 0.0;
    theADSRParameters2.decay= 0.3;
    theADSRParameters2.sustain=0.3;
    theADSRParameters2.release=0.5;
    theADSR2.setParameters(theADSRParameters);
    
    
    //bpm
    playHead = this->getPlayHead();
    playHead->getPosition();
    myBpm = currentPositionInfo.bpm;
    
    //octave
    m_octave1 = 0;
    m_octave2 = 0;
    
    
}

void Tutorial5classesAudioProcessor:: updateParameters(int param, float value)



{
    
    
    
    //if (param== kdelayTime)
   // {
    //    m_DelayLineInstance.setDelay(value);
    //}
    
    
    
    if (param== kdelayLeft2)
    {
        playHead->getPosition();
        value = (60000 / myBpm)*2;
        m_DelayLineInstance.setDelay(value);
        
        
    }
    
    
     if (param== kdelayLeft4)
    {
        playHead->getPosition();
        value = (60000 / myBpm);
        m_DelayLineInstance.setDelay(value);
        
    }
    
    
      if (param== kdelayLeft8)
    {
        playHead->getPosition();
        value = (60000 / myBpm)/2;
        m_DelayLineInstance.setDelay(value);
        
    }
    
    
      if (param== kdelayLeft16)
    {
        playHead->getPosition();
        value = (60000 / myBpm)/4;
        m_DelayLineInstance.setDelay(value);
        
    }
    
       if (param== kdelayRight2)
    {
        playHead->getPosition();
        value = (60000 / myBpm)*2;
        m_DelayLineInstance2.setDelay(value);
        
    }
    
    
     if (param== kdelayRight4)
    {
        playHead->getPosition();
        value = (60000 / myBpm);
        m_DelayLineInstance2.setDelay(value);
        
    }
    
    
      if (param== kdelayRight8)
    {
        playHead->getPosition();
        value = (60000 / myBpm)/2;
        m_DelayLineInstance2.setDelay(value);
        
    }
    
    
      if (param== kdelayRight16)
    {
        playHead->getPosition();
        value = (60000 / myBpm)/4;
        m_DelayLineInstance2.setDelay(value);
        
    }
    
    
     if (param== kdelayDryWet)
    {
       m_wet = (value/100);
    }
    
    
     if (param== kdelayFeedback)
    {
       m_feedbackAmount = (value/100);
    }
    
   
    if (param== kdelayButton)
    {
        
    
     delaysection = value;
        
     
    }
    
    
    if (param== kreverbButton)
    {
        
    
     reverbsection = value;
        
     
    }
    
    
    if (param== kGain)
        
    {
        m_GainInstance.setGain(value);
        
    }
    
    
    
    
    if (param== kautoPanDepth)
        
    {
        
        m_LfoInstance.setDepth((value/100));
        
        
    }
    
    
    if (param== kautoPanFreq)
        
    {
        
        
        
        m_LfoInstance.setFrequency(value);
        
        
    }
    
    
    
    if (param== kautoPanButton)
        
    {
        autopansection = value;
    }
    
    
     if (param== kosc1Button)
        
    {
        synthonesection = value;
    }
    
    
    if (param== kautoPanShapeButton)
        
    {
        if (value==1)
        {
            m_LfoInstance.setWaveshape(kSine);
        }
        
        if (value==2)
        {
            m_LfoInstance.setWaveshape(kTriangle);
        }
        
        if (value==3)
        {
            m_LfoInstance.setWaveshape(kSaw);
        }
        
        if (value==4)
        {
            m_LfoInstance.setWaveshape(kSquare);
        }
        
        
        
        
    }
    
    
    
    
      if (param == kosc1Pan)
        
    {
        m_Pan.setPan(value);
        
        
    }
    
   if (param == ksynthDepth)
    {
       synthdepth = value;
    
        }
    
    
   else if (param ==kWaveform)
    {
        if (value == kSine)
        {
            m_LFO.setWaveshape(kSine);
            m_LFOOctave.setWaveshape(kSine);
        }
        else if (value ==kSaw)
        {
            m_LFO.setWaveshape(kSaw);
            m_LFOOctave.setWaveshape(kSaw);
        }
        else if (value == kSquare)
        {
            m_LFO.setWaveshape(kSquare);
            m_LFOOctave.setWaveshape(kSquare);
        }
        else if (value == kTriangle)
        {
            m_LFO.setWaveshape(kTriangle);
            m_LFOOctave.setWaveshape(kTriangle);
        }
            
    }
    
    
    if (param == ksynthDepth2)
    {
       synthdepth2 = value;
    
        }
    
    
   else if (param ==kWaveform2)
    {
        if (value == kSine)
        {
            m_LFO2.setWaveshape(kSine);
            m_LFOOctave2.setWaveshape(kSine);
        }
        else if (value ==kSaw)
        {
            m_LFO2.setWaveshape(kSaw);
            m_LFOOctave2.setWaveshape(kSaw);
        }
        else if (value == kSquare)
        {
            m_LFO2.setWaveshape(kSquare);
            m_LFOOctave2.setWaveshape(kSquare);
        }
        else if (value == kTriangle)
        {
            m_LFO2.setWaveshape(kTriangle);
            m_LFOOctave2.setWaveshape(kTriangle);
        }
            
    }
    
            
      if (param == kattack1)
        
    {
        theADSRParameters.attack=value;
        theADSR.setParameters(theADSRParameters);
        
        
    }
    
     if (param == kdecay1)
        
    {
        theADSRParameters.decay=value;
        theADSR.setParameters(theADSRParameters);
        
        
    }

    
     if (param == ksustain1)
        
    {
        theADSRParameters.sustain=value;
        theADSR.setParameters(theADSRParameters);
        
        
    }
               
     if (param == krelease1)
        
    {
        theADSRParameters.release=value;
        theADSR.setParameters(theADSRParameters);
        
        
    }
    
      if (param == kattack2)
        
    {
        theADSRParameters2.attack=value;
        theADSR2.setParameters(theADSRParameters2);
        
        
    }
    
     if (param == kdecay2)
        
    {
        theADSRParameters2.decay=value;
        theADSR2.setParameters(theADSRParameters2);
        
        
    }

    
     if (param == ksustain2)
        
    {
        theADSRParameters2.sustain=value;
        theADSR2.setParameters(theADSRParameters2);
        
        
    }
               
     if (param == krelease2)
        
    {
        theADSRParameters2.release=value;
        theADSR2.setParameters(theADSRParameters2);
        
        
    }
    
    
    
      if (param == kosc2Pan)
        
    {
        m_Pan2.setPan(value);
        
        
    }
    
    if (param == kdry)
        
    {
        theReverbParameters.dryLevel = (value/100);
        theReverb.setParameters(theReverbParameters);
        
        
        
    }
    
     if (param == kwet)
        
    {
        theReverbParameters.wetLevel = (value/100);
        theReverb.setParameters(theReverbParameters);
        
        
        
    }
    
     if (param == ksize)
        
    {
        theReverbParameters.roomSize = (value/100);
        theReverb.setParameters(theReverbParameters);
        
        
        
    }
    
     if (param == kdamping)
        
    {
        theReverbParameters.damping = (value/100);
        theReverb.setParameters(theReverbParameters);
        
        
        
    }
    
    

    
        if (param== kdetune1)
        
    {
        
        
         m_detune = value;
        
        
        
    }
    
            if (param== kdetune2)
        
    {
        
        
         m_detune2 = value;
        
        
        
    }
    
           if (param== kdryWetMultitap)
        
    {
        
        
          m_wet_multiTap = (value/100);
        
        
        
    }
    
             if (param== kmultitapDelay1)
        
    {
        
        
         m_DelayLineInstance3.setDelay(value);
        
        
        
    }
    
                 if (param== kmultitapDelay2)
        
    {
        
        
         m_DelayLineInstance4.setDelay(value);
        
        
        
    }
                 if (param== kmultitapDelay3)
        
    {
        
        
         m_DelayLineInstance4.setDelay(value);
        
        
        
    }
    
                    if (param== kmultitapDelayButton)
        
    {
        
        
         m_multitapDelayButton = value;
        
        
        
    }
    
                      if (param== kstereoDelayButton)
        
    {
        
        
         m_stereoDelayButton = value;
        
        
        
    }
    
                        if (param== kmultitapFeedback)
        
    {
        
        
         m_feedbackAmount_multiTap = (value/100);
        
        
        
    }
    
                       if (param== kchorusDryWet)
        
    {
        
        
        m_wet_Chorus  = (value/100);
        
        
        
    }
    
        if (param== kchorusButton)
    {
        
    
     chorussection = value;
        
     
    }
    
            if (param== kchorusLFORate)
    {
        
    
      m_LFOChorus.setFrequency(value);
        
     
    }
    
                if (param== koctave1)
    {
        
    
      m_octave1 = value;
        
     
    }
    
                if (param== koctave2)
    {
        
    
      m_octave2 = value;
        
     
    }
      
}
void Tutorial5classesAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Tutorial5classesAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

int Tutorial5classesAudioProcessor::noteToFreq(int note)
{
    float a = 440; // Frequency of A
    float freq; // Used to store frequency
    freq = (a/32)*pow(2,(((float)note-9)/12));
    return freq;
}

void Tutorial5classesAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

   float* leftData = buffer.getWritePointer(0);
   float* rightData = buffer.getWritePointer(1);
   int midiNotenumber = 0;
    float leftosc1;
    float leftosc2;
    float rightosc1;
    float rightosc2;
    float currentSampleleft;
    float currentSampleright;

    
    
   
   
   juce::MidiBuffer processedMidi;
   
   if (midiMessages.isEmpty() == false)
    {
        for (const auto metadata : midiMessages)
        {
            auto message = metadata.getMessage();
            // const auto time = metdata.samplePosition;
            
            
            if (message.isNoteOn())
                {
            midiVelocity = message.getVelocity();
                
            if(midiVelocity>0.0)
            
            {
                
                    midiNotenumber = message.getNoteNumber();
                    m_LFO.setFrequency(noteToFreq(midiNotenumber+m_detune));
                    m_LFO.setDepth((float)message.getVelocity()/127.0*synthdepth);
                    
                    m_LFOOctave.setFrequency(noteToFreq(midiNotenumber+m_detune+12));
                    m_LFOOctave.setDepth((float)message.getVelocity()/127.0*synthdepth);
                    
                    m_LFO2.setFrequency(noteToFreq(midiNotenumber+m_detune2));
                    m_LFO2.setDepth((float)message.getVelocity()/127.0*synthdepth2);
                    
                    m_LFOOctave2.setFrequency(noteToFreq(midiNotenumber+m_detune2+12));
                    m_LFOOctave2.setDepth((float)message.getVelocity()/127.0*synthdepth2);
                    
                    theADSR.noteOn();
                    theADSR2.noteOn();
                    
                
            }
            else
                {
                    
                    theADSR.noteOff();
                    theADSR2.noteOff();
                    
                }
                
                }
            
            
            
            if (message.isNoteOff())
            {
               // m_LFO2.setDepth(0);
                
                theADSR.noteOff();
                theADSR2.noteOff();
            }
        }

    }
   
    
    for (int i = 0; i< buffer.getNumSamples(); i++)
       
    
    {
        
     
      
       
      
        
   
        
       
           // leftData[i] =  (m_LFO.process()*theADSR.getNextSample()) + (m_LFO2.process()*theADSR2.getNextSample())/2;
            //rightData[i] = leftData[i];
            
        if (m_octave1 == 1)
        {
            
       leftosc1 =  m_LFO.process()*theADSR.getNextSample() + m_LFOOctave.process()*theADSR.getNextSample();
       rightosc1 = leftosc1;
        }
        
        
        if (m_octave1 == 0)
        {
           leftosc1 =  m_LFO.process()*theADSR.getNextSample() ;
           rightosc1 = leftosc1;
        }
    
        if (m_octave2 == 1)
        {
       leftosc2 =  m_LFO2.process()*theADSR2.getNextSample() + m_LFOOctave2.process()*theADSR2.getNextSample();
       rightosc2 = leftosc2; 
       
        }
        
        if (m_octave2 == 0)
        {
            leftosc2 =  m_LFO2.process()*theADSR2.getNextSample();
            rightosc2 = leftosc2; 
        }
        
        
       
        
       
      //Pan
        
        
        
        
       m_Pan.process(leftosc1, rightosc1) ;
       m_Pan2.process(leftosc2, rightosc2); // m_LFO2.process()*theADSR2.getNextSample());
       leftData[i]=(leftosc1+leftosc2);
       rightData[i]=(rightosc1+rightosc2);   
       
       
       
  
        
        
        //autopan
        if (autopansection == true)
        {
        lfoVal = m_LfoInstance.process();
        m_PanInstance.setPan(lfoVal); 
        m_PanInstance.process(leftData[i], rightData[i]);
       
        
        }
        
      
        
        
        // gain
        
        m_GainInstance.process(leftData[i], rightData[i]);
        
        //chorus
       if (chorussection == true)
        {
        delayedSampleleftChorus = leftData[i] + (m_outputSampleleftChorus*m_feedbackAmount_Chorus);
        m_DelayLineInstanceleftChorus.process(delayedSampleleftChorus);
        m_outputSampleleftChorus = delayedSampleleftChorus;
        
        
        delayedSamplerightChorus = rightData[i] + (m_outputSamplerightChorus*m_feedbackAmount_Chorus);
        m_DelayLineInstancerightChorus.process(delayedSamplerightChorus);
        m_outputSamplerightChorus = delayedSamplerightChorus;
         

        LFOleftChorus =  m_LFOChorus.process();
        LFOrightChorus = m_LFOChorus.process();
      
        LFOleftChorus2 = LFOleftChorus * m_delayTimeMS_leftChorus;
        LFOrightChorus2 = LFOrightChorus * m_delayTimeMS_rightChorus;
       
        m_DelayLineInstanceleftChorus.setDelay(LFOleftChorus2);
        m_DelayLineInstancerightChorus.setDelay(LFOrightChorus2);
      
        leftData[i] = (m_wet_Chorus * delayedSampleleftChorus) + ((1-m_wet_Chorus) * leftData[i]);
        rightData[i] = (m_wet_Chorus * delayedSamplerightChorus) + ((1-m_wet_Chorus) * rightData[i]);
        

        

       
       
        }
        
        //delay
        
      if (delaysection ==true)
        
      
        {
                
            {
            
        delayedSample = leftData[i] + (m_outputSample*m_feedbackAmount);
        m_DelayLineInstance.process(delayedSample);
        leftData[i] = (m_wet * delayedSample) + ((1-m_wet) * leftData[i]);
        m_outputSample = delayedSample;
        
        
        delayedSample2 = rightData[i] + (m_outputSample2*m_feedbackAmount);
        m_DelayLineInstance2.process(delayedSample2);
        rightData[i] = (m_wet * delayedSample2) + ((1-m_wet) * rightData[i]);
        m_outputSample2 = delayedSample2;
        
            }
        
            
            
         
            
            {
         

        //time 1
        delayedSampleleft = leftData[i] + (m_outputSampleleft*m_feedbackAmount_multiTap);
        m_DelayLineInstance3.process(delayedSampleleft);
        m_outputSampleleft = delayedSampleleft;
        
        delayedSampleright = rightData[i] + (m_outputSampleright*m_feedbackAmount_multiTap);
        m_DelayLineInstance3.process(delayedSampleright);
        m_outputSampleright = delayedSampleright;
        
        
        //time 2 
        delayedSampleleft2 = leftData[i] + (m_outputSampleleft2*m_feedbackAmount_multiTap);
        m_DelayLineInstance4.process(delayedSampleleft2);
        m_outputSampleleft2 = delayedSampleleft2;
        
        delayedSampleright2 = rightData[i] + (m_outputSampleright2*m_feedbackAmount_multiTap);
        m_DelayLineInstance4.process(delayedSampleright2);
        m_outputSampleright2 = delayedSampleright2;
        
        
        
       //time 3
        delayedSampleleft3 = leftData[i] + (m_outputSampleleft3*m_feedbackAmount_multiTap);
        m_DelayLineInstance5.process(delayedSampleleft3);
        m_outputSampleleft3 = delayedSampleleft3;
        
        delayedSampleright3 = rightData[i] + (m_outputSampleright3*m_feedbackAmount_multiTap);
        m_DelayLineInstance5.process(delayedSampleright3);
        m_outputSampleright3 = delayedSampleright3;       
        
       
        leftData[i] = ((m_wet_multiTap * delayedSampleleft) + ((1-m_wet_multiTap) * leftData[i])) + ((m_wet_multiTap * delayedSampleleft2) + ((1-m_wet_multiTap) * leftData[i])) + ((m_wet_multiTap * delayedSampleleft3) + ((1-m_wet_multiTap) * leftData[i]));;
        rightData[i] = ((m_wet_multiTap * delayedSampleright) + ((1-m_wet_multiTap) * rightData[i])) + ((m_wet_multiTap * delayedSampleright2) + ((1-m_wet_multiTap) * rightData[i])) + ((m_wet_multiTap * delayedSampleright3) + ((1-m_wet_multiTap) * rightData[i]));
       

            
            }  
           
        
        }  
        
    }
    //reverb
    
     if (reverbsection ==true)
        
        {
            theReverb.processStereo (leftData, rightData, buffer.getNumSamples());
            
        }
    
   
    
    
    
   
        
    
}

//==============================================================================
bool Tutorial5classesAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Tutorial5classesAudioProcessor::createEditor()
{
    return new Tutorial5classesAudioProcessorEditor (*this);
}

//==============================================================================
void Tutorial5classesAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Tutorial5classesAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Tutorial5classesAudioProcessor();
}

