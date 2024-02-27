/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Gain.h"
#include "Pan.h"
#include "LFO.h"
#include "DelayLine.h"
#include "Gate.h"
#include "EQ.h"

//==============================================================================
/**
*/



enum Parameters

{
  kGain,
  kautoPanDepth,
  kautoPanFreq,
  kautoPanButton,
  kautoPanShapeButton,
  
  kdelayTime,
  kdelayDryWet,
  kdelayFeedback,
  kdelayButton,
  kstereoDelayButton,
  
  kdryWetMultitap,
  kmultitapDelay1,
  kmultitapDelay2,
  kmultitapDelay3,
  kmultitapDelayButton,
  kmultitapFeedback,
  
  kchorusDryWet,
  kchorusLFORate,
  kchorusLFODepth,
  kchorusButton,
  
  ksynthDepth,
  kWaveform,
  kosc1Pan,
  kosc1Button,
  kattack1,
  kdecay1,
  ksustain1,
  krelease1,
  kdetune1,
  koctave1,
  
  kdry,
  kwet,
  ksize,
  kdamping,
  kreverbButton,
  
  ksynthDepth2,
  kWaveform2,
  kosc2Pan,
  kosc2Button,
  kattack2,
  kdecay2,
  ksustain2,
  krelease2,
  kdetune2,
  koctave2,
  
  kdelayLeft2,
  kdelayLeft4,
  kdelayLeft8,
  kdelayLeft16,
  
  kdelayRight2,
  kdelayRight4,
  kdelayRight8,
  kdelayRight16,
  
  kchorusRate,
  
  
  
};


class Tutorial5classesAudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    Tutorial5classesAudioProcessor();
    ~Tutorial5classesAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void updateParameters (int param, float value);

private:
    //==============================================================================
    Gain m_GainInstance;
    Pan m_PanInstance;
    LFO m_LfoInstance;
    
    LFO m_LFO;
    LFO m_LFO2;
    
    LFO m_LFOOctave;
    LFO m_LFOOctave2;
    
    LFO m_LFOChorus;
    
    
    DelayLine m_DelayLineInstance;
    DelayLine m_DelayLineInstance2;
    DelayLine m_DelayLineInstance3;
    DelayLine m_DelayLineInstance4;
    DelayLine m_DelayLineInstance5;
    
    Gate m_GateInstance;
    
    Pan m_Pan;
    Pan m_Pan2;
    
    EQ m_EQ;
    
    //octave
    
    int m_octave1;
    int m_octave2;
    
    //chorus
    DelayLine m_DelayLineInstanceleftChorus;
    DelayLine m_DelayLineInstancerightChorus;
    
    float m_delayTimeMS_leftChorus;
    float m_delayTimeMS_rightChorus;
    float m_wet_Chorus;
    float delayedSampleleftChorus;
    float m_outputSampleleftChorus;
    float m_feedbackAmount_Chorus;
    float chorusRate;
    float LFOleftChorus;
    float LFOleftChorus2;
    float LFOrightChorus;
    float LFOrightChorus2;
    int chorussection;
    
    
    float delayedSamplerightChorus;
    float m_outputSamplerightChorus;
    
    //delay
   int m_delayTimeMS;
   int m_delayTimeMS_multiTap;
   int m_delayTimeMS_multiTap2;
   int m_delayTimeMS_multiTap3;
   
   float m_outputSample2;
   float m_outputSample;
   float m_outputSample3;
   
   float m_outputSampleleft;
   float m_outputSampleleft2;
   float m_outputSampleleft3;
   float m_outputSampleright;
   float m_outputSampleright2;
   float m_outputSampleright3;
   float m_feedbackAmount;
   float m_feedbackAmount_multiTap;
   
  bool m_stereoDelayButton;
  bool m_multitapDelayButton;
  int m_multitapDelay;
  int m_stereoDelay ;
   
   float m_wet;
   float m_wet_multiTap;
  

   float delayedSample2;
   float delayedSample;
   float delayedSampleright;
   float delayedSampleleft;
   
   float delayedSampleright2;
   float delayedSampleleft2;
   
   float delayedSampleright3;
   float delayedSampleleft3;
   
   juce::AudioPlayHead::CurrentPositionInfo currentPositionInfo;
    juce::AudioPlayHead* playHead;
    float myBpm;
    float lfoVal;
    int noteToFreq(int note);
    int autopansection;
    int delaysection;
    int reverbsection;
    int synthonesection;
    float synthdepth;
    float synthdepth2;
    float lfoSumLeft;
    float lfoSumRight;
    float midiVelocity;
    float m_detune;
    float m_detune2;
    
    
    
    
    
    
    juce::Reverb theReverb;
    juce::Reverb::Parameters theReverbParameters;
    
    juce::ADSR theADSR;
    juce::ADSR::Parameters theADSRParameters;
    
     juce::ADSR theADSR2;
    juce::ADSR::Parameters theADSRParameters2;
   
   
  
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Tutorial5classesAudioProcessor)
};
