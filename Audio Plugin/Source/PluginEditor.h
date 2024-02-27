/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Tutorial5classesAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                              public juce::Slider::Listener,
                                              public juce::Button::Listener,
                                              public juce::ComboBox::Listener
{
public:
    //==============================================================================
    Tutorial5classesAudioProcessorEditor (Tutorial5classesAudioProcessor& owner);
    ~Tutorial5classesAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
     Tutorial5classesAudioProcessor& audioProcessor;

    float lastwaveform1;
    float storegain1;
    float storewaveform1;
    float storepan1;
    float storeattack1;
    float storedecay1;
    float storesustain1;
    float storerelease1;
    float storedetune1;
    bool storeoctave1;

    float lastwaveform2;
    float storegain2;
    float storewaveform2;
    float storepan2;
    float storeattack2;
    float storedecay2;
    float storesustain2;
    float storerelease2;
    float storedetune2;
    bool storeoctave2;

    float lastwaveform1preset2;
    float storegain1preset2;
    float storewaveform1preset2;
    float storepan1preset2;
    float storeattack1preset2;
    float storedecay1preset2;
    float storesustain1preset2;
    float storerelease1preset2;
    float storedetune1preset2;
    bool storeoctave1preset2;

    float lastwaveform2preset2;
    float storegain2preset2;
    float storewaveform2preset2;
    float storepan2preset2;
    float storeattack2preset2;
    float storedecay2preset2;
    float storesustain2preset2;
    float storerelease2preset2;
    float storedetune2preset2;
    bool storeoctave2preset2;

    float lastwaveform1preset3;
    float storegain1preset3;
    float storewaveform1preset3;
    float storepan1preset3;
    float storeattack1preset3;
    float storedecay1preset3;
    float storesustain1preset3;
    float storerelease1preset3;
    float storedetune1preset3;
    bool storeoctave1preset3;

    float lastwaveform2preset3;
    float storegain2preset3;
    float storewaveform2preset3;
    float storepan2preset3;
    float storeattack2preset3;
    float storedecay2preset3;
    float storesustain2preset3;
    float storerelease2preset3;
    float storedetune2preset3;
    bool storeoctave2preset3;


    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> chorusbox;
    std::unique_ptr<juce::GroupComponent> delaybox;
    std::unique_ptr<juce::GroupComponent> osc2box;
    std::unique_ptr<juce::GroupComponent> osc1box;
    std::unique_ptr<juce::GroupComponent> reverbbox;
    std::unique_ptr<juce::GroupComponent> mixerbox;
    std::unique_ptr<juce::GroupComponent> autopanbox;
    std::unique_ptr<juce::Slider> m_gainSlider;
    std::unique_ptr<juce::Slider> m_autoPanSlider;
    std::unique_ptr<juce::Slider> m_autoPanFreqSlider;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<juce::ToggleButton> m_autoPanButton;
    std::unique_ptr<juce::ComboBox> m_autoPanShape;
    std::unique_ptr<juce::Slider> m_delayDryWetSlider;
    std::unique_ptr<juce::Label> juce__label4;
    std::unique_ptr<juce::Slider> m_delayFeedback;
    std::unique_ptr<juce::Label> juce__label6;
    std::unique_ptr<juce::ToggleButton> m_delayButton;
    std::unique_ptr<juce::ToggleButton> m_sineButton;
    std::unique_ptr<juce::ToggleButton> m_triangleButton;
    std::unique_ptr<juce::ToggleButton> m_squareButton;
    std::unique_ptr<juce::ToggleButton> m_sawButton;
    std::unique_ptr<juce::Slider> m_synthDepth;
    std::unique_ptr<juce::Label> juce__label7;
    std::unique_ptr<juce::Slider> m_osc1Pan;
    std::unique_ptr<juce::Label> juce__label11;
    std::unique_ptr<juce::Slider> m_attack1;
    std::unique_ptr<juce::Slider> m_decay1;
    std::unique_ptr<juce::Slider> m_sustain1;
    std::unique_ptr<juce::Slider> m_release1;
    std::unique_ptr<juce::Label> juce__label8;
    std::unique_ptr<juce::Label> juce__label9;
    std::unique_ptr<juce::Label> juce__label10;
    std::unique_ptr<juce::Label> juce__label12;
    std::unique_ptr<juce::Slider> m_dry;
    std::unique_ptr<juce::Slider> m_wet;
    std::unique_ptr<juce::Slider> m_size;
    std::unique_ptr<juce::Slider> m_damping;
    std::unique_ptr<juce::Label> juce__label13;
    std::unique_ptr<juce::Label> juce__label14;
    std::unique_ptr<juce::Label> juce__label15;
    std::unique_ptr<juce::Label> juce__label16;
    std::unique_ptr<juce::ToggleButton> m_sineButton2;
    std::unique_ptr<juce::ToggleButton> m_sawButton2;
    std::unique_ptr<juce::ToggleButton> m_squareButton2;
    std::unique_ptr<juce::ToggleButton> m_triangleButton2;
    std::unique_ptr<juce::Slider> m_synthDepth2;
    std::unique_ptr<juce::Slider> m_osc2Pan;
    std::unique_ptr<juce::Slider> m_attack2;
    std::unique_ptr<juce::Slider> m_decay2;
    std::unique_ptr<juce::Slider> m_sustain2;
    std::unique_ptr<juce::Slider> m_release2;
    std::unique_ptr<juce::Label> juce__label17;
    std::unique_ptr<juce::Label> juce__label18;
    std::unique_ptr<juce::Label> juce__label19;
    std::unique_ptr<juce::Label> juce__label20;
    std::unique_ptr<juce::Label> juce__label21;
    std::unique_ptr<juce::Label> juce__label22;
    std::unique_ptr<juce::ToggleButton> m_delayLeft2;
    std::unique_ptr<juce::Label> juce__label23;
    std::unique_ptr<juce::ToggleButton> m_delayLeft4;
    std::unique_ptr<juce::ToggleButton> m_delayLeft8;
    std::unique_ptr<juce::ToggleButton> m_delayLeft16;
    std::unique_ptr<juce::ToggleButton> m_delayRight4;
    std::unique_ptr<juce::Label> juce__label24;
    std::unique_ptr<juce::ToggleButton> m_delayRight2;
    std::unique_ptr<juce::ToggleButton> m_delayRight8;
    std::unique_ptr<juce::ToggleButton> m_delayRight16;
    std::unique_ptr<juce::ToggleButton> m_reverbButton;
    std::unique_ptr<juce::TextButton> m_storePreset;
    std::unique_ptr<juce::TextButton> m_setPreset;
    std::unique_ptr<juce::Slider> m_chorusLFORate;
    std::unique_ptr<juce::TextButton> m_storePreset2;
    std::unique_ptr<juce::TextButton> m_setPreset2;
    std::unique_ptr<juce::TextButton> m_storePreset3;
    std::unique_ptr<juce::TextButton> m_setPreset3;
    std::unique_ptr<juce::Slider> m_detune1;
    std::unique_ptr<juce::Slider> m_detune2;
    std::unique_ptr<juce::Label> juce__label25;
    std::unique_ptr<juce::Label> juce__label26;
    std::unique_ptr<juce::TextButton> m_synthTab;
    std::unique_ptr<juce::TextButton> m_effectsTab;
    std::unique_ptr<juce::Slider> m_dryWetMultitap;
    std::unique_ptr<juce::Slider> m_multitapDelay1;
    std::unique_ptr<juce::Slider> m_multitapDelay2;
    std::unique_ptr<juce::Slider> m_multitapDelay3;
    std::unique_ptr<juce::TextButton> m_stereoDelayButton;
    std::unique_ptr<juce::TextButton> m_multitapDelayButton;
    std::unique_ptr<juce::Slider> m_multitapFeedback;
    std::unique_ptr<juce::Slider> m_chorusDryWet;
    std::unique_ptr<juce::ToggleButton> m_chorusButton;
    std::unique_ptr<juce::Label> juce__label5;
    std::unique_ptr<juce::Label> juce__label27;
    std::unique_ptr<juce::ToggleButton> m_octave1;
    std::unique_ptr<juce::ToggleButton> m_octave2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Tutorial5classesAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

