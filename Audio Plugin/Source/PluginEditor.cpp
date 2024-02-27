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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Tutorial5classesAudioProcessorEditor::Tutorial5classesAudioProcessorEditor (Tutorial5classesAudioProcessor& owner)
    : AudioProcessorEditor(owner),audioProcessor(owner)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    chorusbox.reset (new juce::GroupComponent ("new group",
                                               TRANS("Chorus")));
    addAndMakeVisible (chorusbox.get());
    chorusbox->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xff08b9ee));

    chorusbox->setBounds (144, 208, 200, 120);

    delaybox.reset (new juce::GroupComponent ("new group",
                                              TRANS("Delay")));
    addAndMakeVisible (delaybox.get());
    delaybox->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xff08b9ee));

    delaybox->setBounds (360, 80, 272, 248);

    osc2box.reset (new juce::GroupComponent ("new group",
                                             TRANS("Osc 2")));
    addAndMakeVisible (osc2box.get());
    osc2box->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xff08b9ee));

    osc2box->setBounds (448, 80, 408, 232);

    osc1box.reset (new juce::GroupComponent ("new group",
                                             TRANS("Osc 1")));
    addAndMakeVisible (osc1box.get());
    osc1box->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xff08b9ee));

    osc1box->setBounds (16, 80, 416, 232);

    reverbbox.reset (new juce::GroupComponent ("new group",
                                               TRANS("Reverb")));
    addAndMakeVisible (reverbbox.get());
    reverbbox->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xff08b9ee));

    reverbbox->setBounds (648, 80, 208, 248);

    mixerbox.reset (new juce::GroupComponent ("new group",
                                              TRANS("Mixer")));
    addAndMakeVisible (mixerbox.get());
    mixerbox->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xff08b9ee));

    mixerbox->setBounds (16, 80, 112, 248);

    autopanbox.reset (new juce::GroupComponent ("new group",
                                                TRANS("Auto Pan")));
    addAndMakeVisible (autopanbox.get());
    autopanbox->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xff08b9ee));

    autopanbox->setBounds (144, 80, 200, 128);

    m_gainSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (m_gainSlider.get());
    m_gainSlider->setRange (-60, 0, 1);
    m_gainSlider->setSliderStyle (juce::Slider::LinearVertical);
    m_gainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_gainSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff2097d2));
    m_gainSlider->addListener (this);

    m_gainSlider->setBounds (-8, 152, 160, 152);

    m_autoPanSlider.reset (new juce::Slider ("autoPan"));
    addAndMakeVisible (m_autoPanSlider.get());
    m_autoPanSlider->setRange (0, 100, 1);
    m_autoPanSlider->setSliderStyle (juce::Slider::Rotary);
    m_autoPanSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_autoPanSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff108bc8));
    m_autoPanSlider->addListener (this);

    m_autoPanSlider->setBounds (168, 104, 56, 72);

    m_autoPanFreqSlider.reset (new juce::Slider ("autoPanFreq"));
    addAndMakeVisible (m_autoPanFreqSlider.get());
    m_autoPanFreqSlider->setRange (0.05, 5, 0.01);
    m_autoPanFreqSlider->setSliderStyle (juce::Slider::Rotary);
    m_autoPanFreqSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_autoPanFreqSlider->addListener (this);

    m_autoPanFreqSlider->setBounds (248, 104, 71, 72);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Amount")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (160, 96, 64, 16);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Rate ")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (256, 96, 40, 16);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("Volume")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (0.033f));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (48, 104, 80, 24);

    m_autoPanButton.reset (new juce::ToggleButton ("autoPanButton"));
    addAndMakeVisible (m_autoPanButton.get());
    m_autoPanButton->setButtonText (juce::String());
    m_autoPanButton->addListener (this);
    m_autoPanButton->setColour (juce::ToggleButton::textColourId, juce::Colour (0xffc10e0e));

    m_autoPanButton->setBounds (312, 96, 24, 24);

    m_autoPanShape.reset (new juce::ComboBox ("autoPanShape"));
    addAndMakeVisible (m_autoPanShape.get());
    m_autoPanShape->setEditableText (false);
    m_autoPanShape->setJustificationType (juce::Justification::centredLeft);
    m_autoPanShape->setTextWhenNothingSelected (TRANS("Sine"));
    m_autoPanShape->setTextWhenNoChoicesAvailable (juce::String());
    m_autoPanShape->addItem (TRANS("Sine"), 1);
    m_autoPanShape->addItem (TRANS("Square"), 2);
    m_autoPanShape->addItem (TRANS("Saw"), 3);
    m_autoPanShape->addItem (TRANS("Triangle"), 4);
    m_autoPanShape->addListener (this);

    m_autoPanShape->setBounds (176, 184, 142, 16);

    m_delayDryWetSlider.reset (new juce::Slider ("delayDryWet"));
    addAndMakeVisible (m_delayDryWetSlider.get());
    m_delayDryWetSlider->setRange (0, 100, 1);
    m_delayDryWetSlider->setSliderStyle (juce::Slider::Rotary);
    m_delayDryWetSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_delayDryWetSlider->addListener (this);

    m_delayDryWetSlider->setBounds (400, 136, 64, 80);

    juce__label4.reset (new juce::Label ("new label",
                                         TRANS("Dry/Wet")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredLeft);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (400, 128, 64, 16);

    m_delayFeedback.reset (new juce::Slider ("delayFeedback"));
    addAndMakeVisible (m_delayFeedback.get());
    m_delayFeedback->setRange (0, 100, 1);
    m_delayFeedback->setSliderStyle (juce::Slider::Rotary);
    m_delayFeedback->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_delayFeedback->addListener (this);

    m_delayFeedback->setBounds (512, 136, 87, 80);

    juce__label6.reset (new juce::Label ("new label",
                                         TRANS("Feedback")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centredLeft);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6->setBounds (520, 120, 72, 24);

    m_delayButton.reset (new juce::ToggleButton ("delayButton"));
    addAndMakeVisible (m_delayButton.get());
    m_delayButton->setButtonText (juce::String());
    m_delayButton->addListener (this);

    m_delayButton->setBounds (592, 96, 32, 24);

    m_sineButton.reset (new juce::ToggleButton ("sineButton"));
    addAndMakeVisible (m_sineButton.get());
    m_sineButton->setButtonText (TRANS("Sine"));
    m_sineButton->setRadioGroupId (1);
    m_sineButton->addListener (this);
    m_sineButton->setToggleState (true, juce::dontSendNotification);

    m_sineButton->setBounds (32, 104, 150, 24);

    m_triangleButton.reset (new juce::ToggleButton ("triangleButton"));
    addAndMakeVisible (m_triangleButton.get());
    m_triangleButton->setButtonText (TRANS("Triangle"));
    m_triangleButton->setRadioGroupId (1);
    m_triangleButton->addListener (this);

    m_triangleButton->setBounds (32, 248, 88, 24);

    m_squareButton.reset (new juce::ToggleButton ("squareButton"));
    addAndMakeVisible (m_squareButton.get());
    m_squareButton->setButtonText (TRANS("Square"));
    m_squareButton->setRadioGroupId (1);
    m_squareButton->addListener (this);

    m_squareButton->setBounds (32, 200, 150, 24);

    m_sawButton.reset (new juce::ToggleButton ("sawButton"));
    addAndMakeVisible (m_sawButton.get());
    m_sawButton->setButtonText (TRANS("Saw"));
    m_sawButton->setRadioGroupId (1);
    m_sawButton->addListener (this);

    m_sawButton->setBounds (32, 152, 150, 24);

    m_synthDepth.reset (new juce::Slider ("synthDepth"));
    addAndMakeVisible (m_synthDepth.get());
    m_synthDepth->setRange (0, 1, 0.1);
    m_synthDepth->setSliderStyle (juce::Slider::LinearVertical);
    m_synthDepth->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_synthDepth->addListener (this);

    m_synthDepth->setBounds (128, 152, 64, 88);

    juce__label7.reset (new juce::Label ("new label",
                                         TRANS("Gain")));
    addAndMakeVisible (juce__label7.get());
    juce__label7->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label7->setJustificationType (juce::Justification::centredLeft);
    juce__label7->setEditable (false, false, false);
    juce__label7->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label7->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label7->setBounds (144, 128, 40, 24);

    m_osc1Pan.reset (new juce::Slider ("osc1Pan"));
    addAndMakeVisible (m_osc1Pan.get());
    m_osc1Pan->setRange (-1, 1, 0.1);
    m_osc1Pan->setSliderStyle (juce::Slider::Rotary);
    m_osc1Pan->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_osc1Pan->addListener (this);

    m_osc1Pan->setBounds (208, 160, 80, 80);

    juce__label11.reset (new juce::Label ("new label",
                                          TRANS("Pan")));
    addAndMakeVisible (juce__label11.get());
    juce__label11->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label11->setJustificationType (juce::Justification::centredLeft);
    juce__label11->setEditable (false, false, false);
    juce__label11->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label11->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label11->setBounds (232, 128, 40, 24);

    m_attack1.reset (new juce::Slider ("attack1"));
    addAndMakeVisible (m_attack1.get());
    m_attack1->setRange (0, 5, 0.1);
    m_attack1->setSliderStyle (juce::Slider::LinearHorizontal);
    m_attack1->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 80, 20);
    m_attack1->addListener (this);

    m_attack1->setBounds (328, 112, 88, 32);

    m_decay1.reset (new juce::Slider ("decay1"));
    addAndMakeVisible (m_decay1.get());
    m_decay1->setRange (0, 5, 0.1);
    m_decay1->setSliderStyle (juce::Slider::LinearHorizontal);
    m_decay1->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 80, 20);
    m_decay1->addListener (this);

    m_decay1->setBounds (328, 160, 88, 32);

    m_sustain1.reset (new juce::Slider ("sustain1"));
    addAndMakeVisible (m_sustain1.get());
    m_sustain1->setRange (0, 5, 0.1);
    m_sustain1->setSliderStyle (juce::Slider::LinearHorizontal);
    m_sustain1->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 80, 20);
    m_sustain1->addListener (this);

    m_sustain1->setBounds (328, 208, 88, 32);

    m_release1.reset (new juce::Slider ("release1"));
    addAndMakeVisible (m_release1.get());
    m_release1->setRange (0, 5, 0.1);
    m_release1->setSliderStyle (juce::Slider::LinearHorizontal);
    m_release1->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 80, 20);
    m_release1->addListener (this);

    m_release1->setBounds (328, 256, 88, 32);

    juce__label8.reset (new juce::Label ("new label",
                                         TRANS("A")));
    addAndMakeVisible (juce__label8.get());
    juce__label8->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label8->setJustificationType (juce::Justification::centredLeft);
    juce__label8->setEditable (false, false, false);
    juce__label8->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label8->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label8->setBounds (304, 120, 24, 24);

    juce__label9.reset (new juce::Label ("new label",
                                         TRANS("D")));
    addAndMakeVisible (juce__label9.get());
    juce__label9->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label9->setJustificationType (juce::Justification::centredLeft);
    juce__label9->setEditable (false, false, false);
    juce__label9->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label9->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label9->setBounds (304, 168, 24, 24);

    juce__label10.reset (new juce::Label ("new label",
                                          TRANS("S")));
    addAndMakeVisible (juce__label10.get());
    juce__label10->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label10->setJustificationType (juce::Justification::centredLeft);
    juce__label10->setEditable (false, false, false);
    juce__label10->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label10->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label10->setBounds (304, 216, 24, 24);

    juce__label12.reset (new juce::Label ("new label",
                                          TRANS("R")));
    addAndMakeVisible (juce__label12.get());
    juce__label12->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label12->setJustificationType (juce::Justification::centredLeft);
    juce__label12->setEditable (false, false, false);
    juce__label12->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label12->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label12->setBounds (304, 264, 24, 24);

    m_dry.reset (new juce::Slider ("dry"));
    addAndMakeVisible (m_dry.get());
    m_dry->setRange (0, 100, 1);
    m_dry->setSliderStyle (juce::Slider::Rotary);
    m_dry->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_dry->addListener (this);

    m_dry->setBounds (664, 112, 72, 80);

    m_wet.reset (new juce::Slider ("wet"));
    addAndMakeVisible (m_wet.get());
    m_wet->setRange (0, 100, 1);
    m_wet->setSliderStyle (juce::Slider::Rotary);
    m_wet->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_wet->addListener (this);

    m_wet->setBounds (752, 112, 88, 80);

    m_size.reset (new juce::Slider ("size"));
    addAndMakeVisible (m_size.get());
    m_size->setRange (0, 100, 1);
    m_size->setSliderStyle (juce::Slider::Rotary);
    m_size->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_size->addListener (this);

    m_size->setBounds (656, 208, 88, 80);

    m_damping.reset (new juce::Slider ("damping"));
    addAndMakeVisible (m_damping.get());
    m_damping->setRange (0, 100, 1);
    m_damping->setSliderStyle (juce::Slider::Rotary);
    m_damping->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_damping->addListener (this);

    m_damping->setBounds (768, 208, 64, 80);

    juce__label13.reset (new juce::Label ("new label",
                                          TRANS("Dry")));
    addAndMakeVisible (juce__label13.get());
    juce__label13->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label13->setJustificationType (juce::Justification::centredLeft);
    juce__label13->setEditable (false, false, false);
    juce__label13->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label13->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label13->setBounds (680, 104, 40, 16);

    juce__label14.reset (new juce::Label ("new label",
                                          TRANS("Wet")));
    addAndMakeVisible (juce__label14.get());
    juce__label14->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label14->setJustificationType (juce::Justification::centredLeft);
    juce__label14->setEditable (false, false, false);
    juce__label14->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label14->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label14->setBounds (776, 104, 32, 16);

    juce__label15.reset (new juce::Label ("new label",
                                          TRANS("Size")));
    addAndMakeVisible (juce__label15.get());
    juce__label15->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label15->setJustificationType (juce::Justification::centredLeft);
    juce__label15->setEditable (false, false, false);
    juce__label15->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label15->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label15->setBounds (680, 200, 40, 16);

    juce__label16.reset (new juce::Label ("new label",
                                          TRANS("Damping")));
    addAndMakeVisible (juce__label16.get());
    juce__label16->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label16->setJustificationType (juce::Justification::centredLeft);
    juce__label16->setEditable (false, false, false);
    juce__label16->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label16->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label16->setBounds (776, 200, 63, 16);

    m_sineButton2.reset (new juce::ToggleButton ("sineButton2"));
    addAndMakeVisible (m_sineButton2.get());
    m_sineButton2->setButtonText (TRANS("Sine"));
    m_sineButton2->setRadioGroupId (2);
    m_sineButton2->addListener (this);
    m_sineButton2->setToggleState (true, juce::dontSendNotification);

    m_sineButton2->setBounds (472, 112, 64, 24);

    m_sawButton2.reset (new juce::ToggleButton ("SawButton2"));
    addAndMakeVisible (m_sawButton2.get());
    m_sawButton2->setButtonText (TRANS("Saw"));
    m_sawButton2->setRadioGroupId (2);
    m_sawButton2->addListener (this);

    m_sawButton2->setBounds (472, 160, 64, 24);

    m_squareButton2.reset (new juce::ToggleButton ("squareButton2"));
    addAndMakeVisible (m_squareButton2.get());
    m_squareButton2->setButtonText (TRANS("Square"));
    m_squareButton2->setRadioGroupId (2);
    m_squareButton2->addListener (this);

    m_squareButton2->setBounds (472, 208, 150, 24);

    m_triangleButton2.reset (new juce::ToggleButton ("triangleButton2"));
    addAndMakeVisible (m_triangleButton2.get());
    m_triangleButton2->setButtonText (TRANS("Triangle"));
    m_triangleButton2->setRadioGroupId (2);
    m_triangleButton2->addListener (this);

    m_triangleButton2->setBounds (472, 256, 80, 24);

    m_synthDepth2.reset (new juce::Slider ("synthDepth"));
    addAndMakeVisible (m_synthDepth2.get());
    m_synthDepth2->setRange (0, 1, 0.1);
    m_synthDepth2->setSliderStyle (juce::Slider::LinearVertical);
    m_synthDepth2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_synthDepth2->addListener (this);

    m_synthDepth2->setBounds (552, 152, 88, 80);

    m_osc2Pan.reset (new juce::Slider ("osc2Pan"));
    addAndMakeVisible (m_osc2Pan.get());
    m_osc2Pan->setRange (-1, 1, 0.1);
    m_osc2Pan->setSliderStyle (juce::Slider::Rotary);
    m_osc2Pan->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_osc2Pan->addListener (this);

    m_osc2Pan->setBounds (648, 152, 80, 80);

    m_attack2.reset (new juce::Slider ("attack2"));
    addAndMakeVisible (m_attack2.get());
    m_attack2->setRange (0, 5, 0.1);
    m_attack2->setSliderStyle (juce::Slider::LinearHorizontal);
    m_attack2->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 80, 20);
    m_attack2->addListener (this);

    m_attack2->setBounds (744, 104, 88, 32);

    m_decay2.reset (new juce::Slider ("decay2"));
    addAndMakeVisible (m_decay2.get());
    m_decay2->setRange (0, 5, 0.1);
    m_decay2->setSliderStyle (juce::Slider::LinearHorizontal);
    m_decay2->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 80, 20);
    m_decay2->addListener (this);

    m_decay2->setBounds (744, 152, 88, 32);

    m_sustain2.reset (new juce::Slider ("sustain2"));
    addAndMakeVisible (m_sustain2.get());
    m_sustain2->setRange (0, 5, 0.1);
    m_sustain2->setSliderStyle (juce::Slider::LinearHorizontal);
    m_sustain2->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 80, 20);
    m_sustain2->addListener (this);

    m_sustain2->setBounds (744, 200, 88, 32);

    m_release2.reset (new juce::Slider ("release2"));
    addAndMakeVisible (m_release2.get());
    m_release2->setRange (0, 5, 0.1);
    m_release2->setSliderStyle (juce::Slider::LinearHorizontal);
    m_release2->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 80, 20);
    m_release2->addListener (this);

    m_release2->setBounds (744, 248, 88, 32);

    juce__label17.reset (new juce::Label ("new label",
                                          TRANS("A")));
    addAndMakeVisible (juce__label17.get());
    juce__label17->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label17->setJustificationType (juce::Justification::centredLeft);
    juce__label17->setEditable (false, false, false);
    juce__label17->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label17->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label17->setBounds (728, 104, 24, 24);

    juce__label18.reset (new juce::Label ("new label",
                                          TRANS("D")));
    addAndMakeVisible (juce__label18.get());
    juce__label18->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label18->setJustificationType (juce::Justification::centredLeft);
    juce__label18->setEditable (false, false, false);
    juce__label18->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label18->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label18->setBounds (728, 152, 24, 24);

    juce__label19.reset (new juce::Label ("new label",
                                          TRANS("S")));
    addAndMakeVisible (juce__label19.get());
    juce__label19->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label19->setJustificationType (juce::Justification::centredLeft);
    juce__label19->setEditable (false, false, false);
    juce__label19->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label19->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label19->setBounds (728, 200, 24, 24);

    juce__label20.reset (new juce::Label ("new label",
                                          TRANS("R")));
    addAndMakeVisible (juce__label20.get());
    juce__label20->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label20->setJustificationType (juce::Justification::centredLeft);
    juce__label20->setEditable (false, false, false);
    juce__label20->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label20->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label20->setBounds (728, 248, 24, 24);

    juce__label21.reset (new juce::Label ("new label",
                                          TRANS("Gain")));
    addAndMakeVisible (juce__label21.get());
    juce__label21->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label21->setJustificationType (juce::Justification::centredLeft);
    juce__label21->setEditable (false, false, false);
    juce__label21->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label21->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label21->setBounds (576, 128, 47, 24);

    juce__label22.reset (new juce::Label ("new label",
                                          TRANS("Pan")));
    addAndMakeVisible (juce__label22.get());
    juce__label22->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label22->setJustificationType (juce::Justification::centredLeft);
    juce__label22->setEditable (false, false, false);
    juce__label22->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label22->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label22->setBounds (672, 128, 31, 24);

    m_delayLeft2.reset (new juce::ToggleButton ("delayLeft2"));
    addAndMakeVisible (m_delayLeft2.get());
    m_delayLeft2->setButtonText (TRANS("2"));
    m_delayLeft2->setRadioGroupId (3);
    m_delayLeft2->addListener (this);
    m_delayLeft2->setToggleState (true, juce::dontSendNotification);

    m_delayLeft2->setBounds (376, 248, 48, 24);

    juce__label23.reset (new juce::Label ("new label",
                                          TRANS("Left")));
    addAndMakeVisible (juce__label23.get());
    juce__label23->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label23->setJustificationType (juce::Justification::centredLeft);
    juce__label23->setEditable (false, false, false);
    juce__label23->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label23->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label23->setBounds (400, 216, 40, 24);

    m_delayLeft4.reset (new juce::ToggleButton ("delaylLeft4"));
    addAndMakeVisible (m_delayLeft4.get());
    m_delayLeft4->setButtonText (TRANS("4"));
    m_delayLeft4->setRadioGroupId (3);
    m_delayLeft4->addListener (this);

    m_delayLeft4->setBounds (432, 248, 48, 24);

    m_delayLeft8.reset (new juce::ToggleButton ("delayLeft8"));
    addAndMakeVisible (m_delayLeft8.get());
    m_delayLeft8->setButtonText (TRANS("8"));
    m_delayLeft8->setRadioGroupId (3);
    m_delayLeft8->addListener (this);

    m_delayLeft8->setBounds (376, 280, 48, 24);

    m_delayLeft16.reset (new juce::ToggleButton ("delayLeft16"));
    addAndMakeVisible (m_delayLeft16.get());
    m_delayLeft16->setButtonText (TRANS("16"));
    m_delayLeft16->setRadioGroupId (3);
    m_delayLeft16->addListener (this);

    m_delayLeft16->setBounds (432, 280, 56, 24);

    m_delayRight4.reset (new juce::ToggleButton ("delayRight4"));
    addAndMakeVisible (m_delayRight4.get());
    m_delayRight4->setButtonText (TRANS("4"));
    m_delayRight4->setRadioGroupId (4);
    m_delayRight4->addListener (this);

    m_delayRight4->setBounds (584, 248, 48, 24);

    juce__label24.reset (new juce::Label ("new label",
                                          TRANS("Right")));
    addAndMakeVisible (juce__label24.get());
    juce__label24->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label24->setJustificationType (juce::Justification::centredLeft);
    juce__label24->setEditable (false, false, false);
    juce__label24->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label24->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label24->setBounds (552, 216, 40, 24);

    m_delayRight2.reset (new juce::ToggleButton ("delayRight2"));
    addAndMakeVisible (m_delayRight2.get());
    m_delayRight2->setButtonText (TRANS("2"));
    m_delayRight2->setRadioGroupId (4);
    m_delayRight2->addListener (this);
    m_delayRight2->setToggleState (true, juce::dontSendNotification);

    m_delayRight2->setBounds (528, 248, 48, 24);

    m_delayRight8.reset (new juce::ToggleButton ("delayRight8"));
    addAndMakeVisible (m_delayRight8.get());
    m_delayRight8->setButtonText (TRANS("8"));
    m_delayRight8->setRadioGroupId (4);
    m_delayRight8->addListener (this);

    m_delayRight8->setBounds (528, 280, 48, 24);

    m_delayRight16.reset (new juce::ToggleButton ("delayRight16"));
    addAndMakeVisible (m_delayRight16.get());
    m_delayRight16->setButtonText (TRANS("16"));
    m_delayRight16->setRadioGroupId (4);
    m_delayRight16->addListener (this);

    m_delayRight16->setBounds (584, 280, 56, 24);

    m_reverbButton.reset (new juce::ToggleButton ("reverbButton"));
    addAndMakeVisible (m_reverbButton.get());
    m_reverbButton->setButtonText (juce::String());
    m_reverbButton->addListener (this);

    m_reverbButton->setBounds (816, 96, 24, 24);

    m_storePreset.reset (new juce::TextButton ("storePreset"));
    addAndMakeVisible (m_storePreset.get());
    m_storePreset->setButtonText (TRANS("Store Preset 1"));
    m_storePreset->addListener (this);
    m_storePreset->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff08b9ee));

    m_storePreset->setBounds (632, 8, 72, 16);

    m_setPreset.reset (new juce::TextButton ("setPreset"));
    addAndMakeVisible (m_setPreset.get());
    m_setPreset->setButtonText (TRANS("Set Preset 1"));
    m_setPreset->addListener (this);
    m_setPreset->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff08b9ee));

    m_setPreset->setBounds (744, 8, 72, 16);

    m_chorusLFORate.reset (new juce::Slider ("chorusRate"));
    addAndMakeVisible (m_chorusLFORate.get());
    m_chorusLFORate->setRange (0.01, 10, 0.01);
    m_chorusLFORate->setSliderStyle (juce::Slider::Rotary);
    m_chorusLFORate->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_chorusLFORate->addListener (this);

    m_chorusLFORate->setBounds (248, 232, 80, 72);

    m_storePreset2.reset (new juce::TextButton ("storePreset2"));
    addAndMakeVisible (m_storePreset2.get());
    m_storePreset2->setButtonText (TRANS("Store Preset 2"));
    m_storePreset2->addListener (this);
    m_storePreset2->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff08b9ee));

    m_storePreset2->setBounds (632, 32, 72, 16);

    m_setPreset2.reset (new juce::TextButton ("setPreset2"));
    addAndMakeVisible (m_setPreset2.get());
    m_setPreset2->setButtonText (TRANS("Set Preset 2"));
    m_setPreset2->addListener (this);
    m_setPreset2->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff08b9ee));

    m_setPreset2->setBounds (744, 32, 72, 16);

    m_storePreset3.reset (new juce::TextButton ("storePreset3"));
    addAndMakeVisible (m_storePreset3.get());
    m_storePreset3->setButtonText (TRANS("Store Preset 3"));
    m_storePreset3->addListener (this);
    m_storePreset3->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff08b9ee));

    m_storePreset3->setBounds (632, 56, 72, 16);

    m_setPreset3.reset (new juce::TextButton ("setPreset3"));
    addAndMakeVisible (m_setPreset3.get());
    m_setPreset3->setButtonText (TRANS("Set Preset 3"));
    m_setPreset3->addListener (this);
    m_setPreset3->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff08b9ee));

    m_setPreset3->setBounds (744, 56, 72, 16);

    m_detune1.reset (new juce::Slider ("detune1"));
    addAndMakeVisible (m_detune1.get());
    m_detune1->setRange (-6, 6, 0.1);
    m_detune1->setSliderStyle (juce::Slider::LinearHorizontal);
    m_detune1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_detune1->addListener (this);

    m_detune1->setBounds (144, 272, 150, 32);

    m_detune2.reset (new juce::Slider ("detune1"));
    addAndMakeVisible (m_detune2.get());
    m_detune2->setRange (-6, 6, 0.1);
    m_detune2->setSliderStyle (juce::Slider::LinearHorizontal);
    m_detune2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_detune2->addListener (this);

    m_detune2->setBounds (568, 272, 150, 32);

    juce__label25.reset (new juce::Label ("new label",
                                          TRANS("Detune")));
    addAndMakeVisible (juce__label25.get());
    juce__label25->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label25->setJustificationType (juce::Justification::centredLeft);
    juce__label25->setEditable (false, false, false);
    juce__label25->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label25->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label25->setBounds (184, 248, 56, 24);

    juce__label26.reset (new juce::Label ("new label",
                                          TRANS("Detune")));
    addAndMakeVisible (juce__label26.get());
    juce__label26->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label26->setJustificationType (juce::Justification::centredLeft);
    juce__label26->setEditable (false, false, false);
    juce__label26->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label26->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label26->setBounds (616, 248, 56, 24);

    m_synthTab.reset (new juce::TextButton ("synth tab"));
    addAndMakeVisible (m_synthTab.get());
    m_synthTab->setButtonText (TRANS("Synth"));
    m_synthTab->addListener (this);

    m_synthTab->setBounds (264, 40, 150, 24);

    m_effectsTab.reset (new juce::TextButton ("effectstab"));
    addAndMakeVisible (m_effectsTab.get());
    m_effectsTab->setButtonText (TRANS("Effects"));
    m_effectsTab->addListener (this);

    m_effectsTab->setBounds (440, 40, 150, 24);

    m_dryWetMultitap.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_dryWetMultitap.get());
    m_dryWetMultitap->setRange (0, 100, 1);
    m_dryWetMultitap->setSliderStyle (juce::Slider::Rotary);
    m_dryWetMultitap->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_dryWetMultitap->addListener (this);

    m_dryWetMultitap->setBounds (400, 136, 64, 80);

    m_multitapDelay1.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_multitapDelay1.get());
    m_multitapDelay1->setRange (200, 2000, 1);
    m_multitapDelay1->setSliderStyle (juce::Slider::LinearHorizontal);
    m_multitapDelay1->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);
    m_multitapDelay1->addListener (this);

    m_multitapDelay1->setBounds (424, 232, 168, 24);

    m_multitapDelay2.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_multitapDelay2.get());
    m_multitapDelay2->setRange (200, 2000, 1);
    m_multitapDelay2->setSliderStyle (juce::Slider::LinearHorizontal);
    m_multitapDelay2->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);
    m_multitapDelay2->addListener (this);

    m_multitapDelay2->setBounds (424, 256, 168, 24);

    m_multitapDelay3.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_multitapDelay3.get());
    m_multitapDelay3->setRange (200, 2000, 1);
    m_multitapDelay3->setSliderStyle (juce::Slider::LinearHorizontal);
    m_multitapDelay3->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);
    m_multitapDelay3->addListener (this);

    m_multitapDelay3->setBounds (424, 280, 168, 24);

    m_stereoDelayButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (m_stereoDelayButton.get());
    m_stereoDelayButton->setButtonText (TRANS("Stereo Delay"));
    m_stereoDelayButton->addListener (this);

    m_stereoDelayButton->setBounds (392, 104, 88, 16);

    m_multitapDelayButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (m_multitapDelayButton.get());
    m_multitapDelayButton->setButtonText (TRANS("Multitap Delay"));
    m_multitapDelayButton->addListener (this);

    m_multitapDelayButton->setBounds (496, 104, 88, 16);

    m_multitapFeedback.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_multitapFeedback.get());
    m_multitapFeedback->setRange (0, 100, 1);
    m_multitapFeedback->setSliderStyle (juce::Slider::Rotary);
    m_multitapFeedback->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_multitapFeedback->addListener (this);

    m_multitapFeedback->setBounds (488, 136, 127, 80);

    m_chorusDryWet.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (m_chorusDryWet.get());
    m_chorusDryWet->setRange (0, 100, 1);
    m_chorusDryWet->setSliderStyle (juce::Slider::Rotary);
    m_chorusDryWet->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    m_chorusDryWet->addListener (this);

    m_chorusDryWet->setBounds (160, 232, 64, 72);

    m_chorusButton.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (m_chorusButton.get());
    m_chorusButton->setButtonText (juce::String());
    m_chorusButton->addListener (this);

    m_chorusButton->setBounds (304, 224, 32, 24);

    juce__label5.reset (new juce::Label ("new label",
                                         TRANS("Amount")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centredLeft);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (160, 224, 64, 16);

    juce__label27.reset (new juce::Label ("new label",
                                          TRANS("Rate ")));
    addAndMakeVisible (juce__label27.get());
    juce__label27->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label27->setJustificationType (juce::Justification::centredLeft);
    juce__label27->setEditable (false, false, false);
    juce__label27->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label27->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label27->setBounds (264, 224, 40, 16);

    m_octave1.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (m_octave1.get());
    m_octave1->setButtonText (TRANS("+1 octave"));
    m_octave1->addListener (this);

    m_octave1->setBounds (168, 96, 104, 24);

    m_octave2.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (m_octave2.get());
    m_octave2->setButtonText (TRANS("+1 octave"));
    m_octave2->addListener (this);

    m_octave2->setBounds (600, 96, 104, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (900, 400);


    //[Constructor] You can add your own custom stuff here..
   m_delayFeedback->setTextValueSuffix("%");
   m_delayDryWetSlider->setTextValueSuffix("%");
   m_autoPanSlider->setTextValueSuffix( "%");
   m_autoPanFreqSlider->setTextValueSuffix("Hz");

   m_delayFeedback->setValue(50);
   m_autoPanFreqSlider->setValue(1);

   m_gainSlider->setValue(-10);

   m_delayDryWetSlider->setValue(0);
   m_attack1->setValue(0.0);
   m_decay1->setValue(0.3);
   m_sustain1->setValue(0.3);
   m_release1->setValue(0.5);
   m_dry->setValue(100);
   m_wet->setValue(50);
   m_size->setValue(50);
   m_damping->setValue(10);
   m_dry->setTextValueSuffix("%");
   m_wet->setTextValueSuffix("%");
   m_size->setTextValueSuffix("%");
   m_damping->setTextValueSuffix("%");
    m_attack2->setValue(0.0);
   m_decay2->setValue(0.3);
   m_sustain2->setValue(0.3);
   m_release2->setValue(0.5);

   m_dryWetMultitap->setTextValueSuffix("%");
   m_multitapFeedback->setTextValueSuffix("%");
   m_dryWetMultitap->setValue(0);
   m_multitapFeedback->setValue(50);
   m_chorusDryWet->setValue(0);
   m_chorusDryWet->setTextValueSuffix( "%");


       //synth
        m_sineButton->setVisible(true);
        m_sawButton->setVisible(true);
        m_squareButton->setVisible(true);
        m_triangleButton->setVisible(true);
        m_synthDepth->setVisible(true);
        m_detune1->setVisible(true);
        m_osc1Pan->setVisible(true);
        m_attack1->setVisible(true);
        m_decay1->setVisible(true);
        m_sustain1->setVisible(true);
        m_release1->setVisible(true);
        juce__label7->setVisible(true);
        juce__label11->setVisible(true);
        juce__label25->setVisible(true);
        juce__label8->setVisible(true);
        juce__label9->setVisible(true);
        juce__label10->setVisible(true);
        juce__label12->setVisible(true);
        osc1box->setVisible(true);

        m_sineButton2->setVisible(true);
        m_sawButton2->setVisible(true);
        m_squareButton2->setVisible(true);
        m_triangleButton2->setVisible(true);
        m_synthDepth2->setVisible(true);
        m_detune2->setVisible(true);
        m_osc2Pan->setVisible(true);
        m_attack2->setVisible(true);
        m_decay2->setVisible(true);
        m_sustain2->setVisible(true);
        m_release2->setVisible(true);
        juce__label21->setVisible(true);
        juce__label22->setVisible(true);
        juce__label26->setVisible(true);
        juce__label17->setVisible(true);
        juce__label18->setVisible(true);
        juce__label19->setVisible(true);
        juce__label20->setVisible(true);
        osc2box->setVisible(true);
        m_octave1->setVisible(true);
        m_octave2->setVisible(true);


        //effects

        mixerbox->setVisible(false);
        juce__label3->setVisible(false);
        m_gainSlider->setVisible(false);

        autopanbox->setVisible(false);
        m_autoPanSlider->setVisible(false);
        m_autoPanFreqSlider->setVisible(false);
        m_autoPanShape->setVisible(false);
        m_autoPanButton->setVisible(false);
        juce__label->setVisible(false);
        juce__label2->setVisible(false);

        delaybox->setVisible(false);
        m_delayDryWetSlider->setVisible(false);
        m_delayFeedback->setVisible(false);
        m_delayLeft2->setVisible(false);
        m_delayLeft4->setVisible(false);
        m_delayLeft8->setVisible(false);
        m_delayLeft16->setVisible(false);
        m_delayRight2->setVisible(false);
        m_delayRight4->setVisible(false);
        m_delayRight8->setVisible(false);
        m_delayRight16->setVisible(false);
        m_delayButton->setVisible(false);
        juce__label4->setVisible(false);
        juce__label6->setVisible(false);

        juce__label23->setVisible(false);
        juce__label24->setVisible(false);

        m_dry->setVisible(false);
        m_wet->setVisible(false);
        m_size->setVisible(false);
        m_damping->setVisible(false);
        reverbbox->setVisible(false);
        m_reverbButton->setVisible(false);
        juce__label13->setVisible(false);
        juce__label14->setVisible(false);
        juce__label15->setVisible(false);
        juce__label16->setVisible(false);
        m_stereoDelayButton->setVisible(false);
        m_multitapDelayButton->setVisible(false);
        m_dryWetMultitap->setVisible(false);
        m_multitapDelay1->setVisible(false);
        m_multitapDelay2->setVisible(false);
        m_multitapDelay3->setVisible(false);
        m_multitapFeedback->setVisible(false);
        m_chorusDryWet->setVisible(false);
        m_chorusLFORate->setVisible(false);
        m_chorusButton->setVisible(false);
        chorusbox->setVisible(false);
        juce__label5->setVisible(false);
        juce__label27->setVisible(false);


        //delay







    //[/Constructor]
}

Tutorial5classesAudioProcessorEditor::~Tutorial5classesAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    chorusbox = nullptr;
    delaybox = nullptr;
    osc2box = nullptr;
    osc1box = nullptr;
    reverbbox = nullptr;
    mixerbox = nullptr;
    autopanbox = nullptr;
    m_gainSlider = nullptr;
    m_autoPanSlider = nullptr;
    m_autoPanFreqSlider = nullptr;
    juce__label = nullptr;
    juce__label2 = nullptr;
    juce__label3 = nullptr;
    m_autoPanButton = nullptr;
    m_autoPanShape = nullptr;
    m_delayDryWetSlider = nullptr;
    juce__label4 = nullptr;
    m_delayFeedback = nullptr;
    juce__label6 = nullptr;
    m_delayButton = nullptr;
    m_sineButton = nullptr;
    m_triangleButton = nullptr;
    m_squareButton = nullptr;
    m_sawButton = nullptr;
    m_synthDepth = nullptr;
    juce__label7 = nullptr;
    m_osc1Pan = nullptr;
    juce__label11 = nullptr;
    m_attack1 = nullptr;
    m_decay1 = nullptr;
    m_sustain1 = nullptr;
    m_release1 = nullptr;
    juce__label8 = nullptr;
    juce__label9 = nullptr;
    juce__label10 = nullptr;
    juce__label12 = nullptr;
    m_dry = nullptr;
    m_wet = nullptr;
    m_size = nullptr;
    m_damping = nullptr;
    juce__label13 = nullptr;
    juce__label14 = nullptr;
    juce__label15 = nullptr;
    juce__label16 = nullptr;
    m_sineButton2 = nullptr;
    m_sawButton2 = nullptr;
    m_squareButton2 = nullptr;
    m_triangleButton2 = nullptr;
    m_synthDepth2 = nullptr;
    m_osc2Pan = nullptr;
    m_attack2 = nullptr;
    m_decay2 = nullptr;
    m_sustain2 = nullptr;
    m_release2 = nullptr;
    juce__label17 = nullptr;
    juce__label18 = nullptr;
    juce__label19 = nullptr;
    juce__label20 = nullptr;
    juce__label21 = nullptr;
    juce__label22 = nullptr;
    m_delayLeft2 = nullptr;
    juce__label23 = nullptr;
    m_delayLeft4 = nullptr;
    m_delayLeft8 = nullptr;
    m_delayLeft16 = nullptr;
    m_delayRight4 = nullptr;
    juce__label24 = nullptr;
    m_delayRight2 = nullptr;
    m_delayRight8 = nullptr;
    m_delayRight16 = nullptr;
    m_reverbButton = nullptr;
    m_storePreset = nullptr;
    m_setPreset = nullptr;
    m_chorusLFORate = nullptr;
    m_storePreset2 = nullptr;
    m_setPreset2 = nullptr;
    m_storePreset3 = nullptr;
    m_setPreset3 = nullptr;
    m_detune1 = nullptr;
    m_detune2 = nullptr;
    juce__label25 = nullptr;
    juce__label26 = nullptr;
    m_synthTab = nullptr;
    m_effectsTab = nullptr;
    m_dryWetMultitap = nullptr;
    m_multitapDelay1 = nullptr;
    m_multitapDelay2 = nullptr;
    m_multitapDelay3 = nullptr;
    m_stereoDelayButton = nullptr;
    m_multitapDelayButton = nullptr;
    m_multitapFeedback = nullptr;
    m_chorusDryWet = nullptr;
    m_chorusButton = nullptr;
    juce__label5 = nullptr;
    juce__label27 = nullptr;
    m_octave1 = nullptr;
    m_octave2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Tutorial5classesAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Tutorial5classesAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Tutorial5classesAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_gainSlider.get())
    {
        //[UserSliderCode_m_gainSlider] -- add your slider handling code here..
        audioProcessor.updateParameters(kGain, m_gainSlider->getValue());
        //[/UserSliderCode_m_gainSlider]
    }
    else if (sliderThatWasMoved == m_autoPanSlider.get())
    {
        //[UserSliderCode_m_autoPanSlider] -- add your slider handling code here..
        audioProcessor.updateParameters(kautoPanDepth, m_autoPanSlider->getValue());
        //[/UserSliderCode_m_autoPanSlider]
    }
    else if (sliderThatWasMoved == m_autoPanFreqSlider.get())
    {
        //[UserSliderCode_m_autoPanFreqSlider] -- add your slider handling code here..
        audioProcessor.updateParameters(kautoPanFreq, m_autoPanFreqSlider->getValue());
        //[/UserSliderCode_m_autoPanFreqSlider]
    }
    else if (sliderThatWasMoved == m_delayDryWetSlider.get())
    {
        //[UserSliderCode_m_delayDryWetSlider] -- add your slider handling code here..
        audioProcessor.updateParameters(kdelayDryWet, m_delayDryWetSlider->getValue());
        //[/UserSliderCode_m_delayDryWetSlider]
    }
    else if (sliderThatWasMoved == m_delayFeedback.get())
    {
        //[UserSliderCode_m_delayFeedback] -- add your slider handling code here..
        audioProcessor.updateParameters(kdelayFeedback, m_delayFeedback->getValue());
        //[/UserSliderCode_m_delayFeedback]
    }
    else if (sliderThatWasMoved == m_synthDepth.get())
    {
        //[UserSliderCode_m_synthDepth] -- add your slider handling code here..
        audioProcessor.updateParameters(ksynthDepth, m_synthDepth->getValue());
        //[/UserSliderCode_m_synthDepth]
    }
    else if (sliderThatWasMoved == m_osc1Pan.get())
    {
        //[UserSliderCode_m_osc1Pan] -- add your slider handling code here..
        audioProcessor.updateParameters(kosc1Pan, m_osc1Pan->getValue());
        //[/UserSliderCode_m_osc1Pan]
    }
    else if (sliderThatWasMoved == m_attack1.get())
    {
        //[UserSliderCode_m_attack1] -- add your slider handling code here..
        audioProcessor.updateParameters(kattack1, m_attack1->getValue());
        //[/UserSliderCode_m_attack1]
    }
    else if (sliderThatWasMoved == m_decay1.get())
    {
        //[UserSliderCode_m_decay1] -- add your slider handling code here..
        audioProcessor.updateParameters(kdecay1, m_decay1->getValue());
        //[/UserSliderCode_m_decay1]
    }
    else if (sliderThatWasMoved == m_sustain1.get())
    {
        //[UserSliderCode_m_sustain1] -- add your slider handling code here..
        audioProcessor.updateParameters(ksustain1, m_sustain1->getValue());
        //[/UserSliderCode_m_sustain1]
    }
    else if (sliderThatWasMoved == m_release1.get())
    {
        //[UserSliderCode_m_release1] -- add your slider handling code here..
        audioProcessor.updateParameters(krelease1, m_release1->getValue());
        //[/UserSliderCode_m_release1]
    }
    else if (sliderThatWasMoved == m_dry.get())
    {
        //[UserSliderCode_m_dry] -- add your slider handling code here..
          audioProcessor.updateParameters(kdry, m_dry->getValue());
        //[/UserSliderCode_m_dry]
    }
    else if (sliderThatWasMoved == m_wet.get())
    {
        //[UserSliderCode_m_wet] -- add your slider handling code here..
          audioProcessor.updateParameters(kwet, m_wet->getValue());
        //[/UserSliderCode_m_wet]
    }
    else if (sliderThatWasMoved == m_size.get())
    {
        //[UserSliderCode_m_size] -- add your slider handling code here..
          audioProcessor.updateParameters(ksize, m_size->getValue());
        //[/UserSliderCode_m_size]
    }
    else if (sliderThatWasMoved == m_damping.get())
    {
        //[UserSliderCode_m_damping] -- add your slider handling code here..
          audioProcessor.updateParameters(kdamping, m_damping->getValue());
        //[/UserSliderCode_m_damping]
    }
    else if (sliderThatWasMoved == m_synthDepth2.get())
    {
        //[UserSliderCode_m_synthDepth2] -- add your slider handling code here..
        audioProcessor.updateParameters(ksynthDepth2, m_synthDepth2->getValue());
        //[/UserSliderCode_m_synthDepth2]
    }
    else if (sliderThatWasMoved == m_osc2Pan.get())
    {
        //[UserSliderCode_m_osc2Pan] -- add your slider handling code here..
         audioProcessor.updateParameters(kosc2Pan, m_osc2Pan->getValue());

        //[/UserSliderCode_m_osc2Pan]
    }
    else if (sliderThatWasMoved == m_attack2.get())
    {
        //[UserSliderCode_m_attack2] -- add your slider handling code here..
         audioProcessor.updateParameters(kattack2, m_attack2->getValue());
        //[/UserSliderCode_m_attack2]
    }
    else if (sliderThatWasMoved == m_decay2.get())
    {
        //[UserSliderCode_m_decay2] -- add your slider handling code here..
         audioProcessor.updateParameters(kdecay2, m_decay2->getValue());
        //[/UserSliderCode_m_decay2]
    }
    else if (sliderThatWasMoved == m_sustain2.get())
    {
        //[UserSliderCode_m_sustain2] -- add your slider handling code here..
         audioProcessor.updateParameters(ksustain2, m_sustain2->getValue());
        //[/UserSliderCode_m_sustain2]
    }
    else if (sliderThatWasMoved == m_release2.get())
    {
        //[UserSliderCode_m_release2] -- add your slider handling code here..
         audioProcessor.updateParameters(krelease2, m_release2->getValue());
        //[/UserSliderCode_m_release2]
    }
    else if (sliderThatWasMoved == m_chorusLFORate.get())
    {
        //[UserSliderCode_m_chorusLFORate] -- add your slider handling code here..
         audioProcessor.updateParameters(kchorusLFORate, m_chorusLFORate->getValue());
        //[/UserSliderCode_m_chorusLFORate]
    }
    else if (sliderThatWasMoved == m_detune1.get())
    {
        //[UserSliderCode_m_detune1] -- add your slider handling code here..
        audioProcessor.updateParameters(kdetune1, m_detune1->getValue());
        //[/UserSliderCode_m_detune1]
    }
    else if (sliderThatWasMoved == m_detune2.get())
    {
        //[UserSliderCode_m_detune2] -- add your slider handling code here..
        audioProcessor.updateParameters(kdetune2, m_detune2->getValue());
        //[/UserSliderCode_m_detune2]
    }
    else if (sliderThatWasMoved == m_dryWetMultitap.get())
    {
        //[UserSliderCode_m_dryWetMultitap] -- add your slider handling code here..
        audioProcessor.updateParameters(kdryWetMultitap, m_dryWetMultitap->getValue());
        //[/UserSliderCode_m_dryWetMultitap]
    }
    else if (sliderThatWasMoved == m_multitapDelay1.get())
    {
        //[UserSliderCode_m_multitapDelay1] -- add your slider handling code here..
        audioProcessor.updateParameters(kmultitapDelay1, m_multitapDelay1->getValue());
        //[/UserSliderCode_m_multitapDelay1]
    }
    else if (sliderThatWasMoved == m_multitapDelay2.get())
    {
        //[UserSliderCode_m_multitapDelay2] -- add your slider handling code here..
        audioProcessor.updateParameters(kmultitapDelay2, m_multitapDelay2->getValue());
        //[/UserSliderCode_m_multitapDelay2]
    }
    else if (sliderThatWasMoved == m_multitapDelay3.get())
    {
        //[UserSliderCode_m_multitapDelay3] -- add your slider handling code here..
        audioProcessor.updateParameters(kmultitapDelay3, m_multitapDelay3->getValue());
        //[/UserSliderCode_m_multitapDelay3]
    }
    else if (sliderThatWasMoved == m_multitapFeedback.get())
    {
        //[UserSliderCode_m_multitapFeedback] -- add your slider handling code here..
        audioProcessor.updateParameters(kmultitapFeedback, m_multitapFeedback->getValue());
        //[/UserSliderCode_m_multitapFeedback]
    }
    else if (sliderThatWasMoved == m_chorusDryWet.get())
    {
        //[UserSliderCode_m_chorusDryWet] -- add your slider handling code here..
         audioProcessor.updateParameters(kchorusDryWet, m_chorusDryWet->getValue());
        //[/UserSliderCode_m_chorusDryWet]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void Tutorial5classesAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_autoPanButton.get())
    {
        //[UserButtonCode_m_autoPanButton] -- add your button handler code here..
        audioProcessor.updateParameters(kautoPanButton, m_autoPanButton->getToggleState());

        //[/UserButtonCode_m_autoPanButton]
    }
    else if (buttonThatWasClicked == m_delayButton.get())
    {
        //[UserButtonCode_m_delayButton] -- add your button handler code here..
        audioProcessor.updateParameters(kdelayButton, m_delayButton->getToggleState());
        //[/UserButtonCode_m_delayButton]
    }
    else if (buttonThatWasClicked == m_sineButton.get())
    {
        //[UserButtonCode_m_sineButton] -- add your button handler code here..
        audioProcessor.updateParameters(kWaveform, kSine);
        lastwaveform1 = kSine;
        //[/UserButtonCode_m_sineButton]
    }
    else if (buttonThatWasClicked == m_triangleButton.get())
    {
        //[UserButtonCode_m_triangleButton] -- add your button handler code here..
        audioProcessor.updateParameters(kWaveform, kTriangle);
        lastwaveform1 = kTriangle;
        //[/UserButtonCode_m_triangleButton]
    }
    else if (buttonThatWasClicked == m_squareButton.get())
    {
        //[UserButtonCode_m_squareButton] -- add your button handler code here..
       audioProcessor.updateParameters(kWaveform, kSquare);
       lastwaveform1 = kSquare;
        //[/UserButtonCode_m_squareButton]
    }
    else if (buttonThatWasClicked == m_sawButton.get())
    {
        //[UserButtonCode_m_sawButton] -- add your button handler code here..
          audioProcessor.updateParameters(kWaveform, kSaw);
          lastwaveform1 = kSaw;
        //[/UserButtonCode_m_sawButton]
    }
    else if (buttonThatWasClicked == m_sineButton2.get())
    {
        //[UserButtonCode_m_sineButton2] -- add your button handler code here..
         audioProcessor.updateParameters(kWaveform2, kSine);
         lastwaveform2 = kSine;
        //[/UserButtonCode_m_sineButton2]
    }
    else if (buttonThatWasClicked == m_sawButton2.get())
    {
        //[UserButtonCode_m_sawButton2] -- add your button handler code here..
          audioProcessor.updateParameters(kWaveform2, kSaw);
          lastwaveform2 = kSaw;

        //[/UserButtonCode_m_sawButton2]
    }
    else if (buttonThatWasClicked == m_squareButton2.get())
    {
        //[UserButtonCode_m_squareButton2] -- add your button handler code here..
         audioProcessor.updateParameters(kWaveform2, kSquare);
         lastwaveform2 = kSquare;
        //[/UserButtonCode_m_squareButton2]
    }
    else if (buttonThatWasClicked == m_triangleButton2.get())
    {
        //[UserButtonCode_m_triangleButton2] -- add your button handler code here..
         audioProcessor.updateParameters(kWaveform2, kTriangle);
         lastwaveform2 = kTriangle;
        //[/UserButtonCode_m_triangleButton2]
    }
    else if (buttonThatWasClicked == m_delayLeft2.get())
    {
        //[UserButtonCode_m_delayLeft2] -- add your button handler code here..
        audioProcessor.updateParameters(kdelayLeft2, m_delayLeft2->getToggleState());
        //[/UserButtonCode_m_delayLeft2]
    }
    else if (buttonThatWasClicked == m_delayLeft4.get())
    {
        //[UserButtonCode_m_delayLeft4] -- add your button handler code here..
         audioProcessor.updateParameters(kdelayLeft4, m_delayLeft4->getToggleState());
        //[/UserButtonCode_m_delayLeft4]
    }
    else if (buttonThatWasClicked == m_delayLeft8.get())
    {
        //[UserButtonCode_m_delayLeft8] -- add your button handler code here..
           audioProcessor.updateParameters(kdelayLeft8, m_delayLeft8->getToggleState());
        //[/UserButtonCode_m_delayLeft8]
    }
    else if (buttonThatWasClicked == m_delayLeft16.get())
    {
        //[UserButtonCode_m_delayLeft16] -- add your button handler code here..
           audioProcessor.updateParameters(kdelayRight16, m_delayRight16->getToggleState());
        //[/UserButtonCode_m_delayLeft16]
    }
    else if (buttonThatWasClicked == m_delayRight4.get())
    {
        //[UserButtonCode_m_delayRight4] -- add your button handler code here..
         audioProcessor.updateParameters(kdelayRight4, m_delayRight4->getToggleState());
        //[/UserButtonCode_m_delayRight4]
    }
    else if (buttonThatWasClicked == m_delayRight2.get())
    {
        //[UserButtonCode_m_delayRight2] -- add your button handler code here..
         audioProcessor.updateParameters(kdelayRight2, m_delayRight2->getToggleState());
        //[/UserButtonCode_m_delayRight2]
    }
    else if (buttonThatWasClicked == m_delayRight8.get())
    {
        //[UserButtonCode_m_delayRight8] -- add your button handler code here..
           audioProcessor.updateParameters(kdelayRight8, m_delayRight8->getToggleState());
        //[/UserButtonCode_m_delayRight8]
    }
    else if (buttonThatWasClicked == m_delayRight16.get())
    {
        //[UserButtonCode_m_delayRight16] -- add your button handler code here..
           audioProcessor.updateParameters(kdelayRight16, m_delayRight16->getToggleState());
        //[/UserButtonCode_m_delayRight16]
    }
    else if (buttonThatWasClicked == m_reverbButton.get())
    {
        //[UserButtonCode_m_reverbButton] -- add your button handler code here..
         audioProcessor.updateParameters(kreverbButton, m_reverbButton->getToggleState());
        //[/UserButtonCode_m_reverbButton]
    }
    else if (buttonThatWasClicked == m_storePreset.get())
    {
        //[UserButtonCode_m_storePreset] -- add your button handler code here..
        storewaveform1 = lastwaveform1;
        storegain1 = m_synthDepth->getValue();
        storepan1 = m_osc1Pan->getValue();
        storeattack1 = m_attack1->getValue();
        storedecay1 = m_decay1->getValue();
        storesustain1 = m_sustain1->getValue();
        storerelease1 = m_release1->getValue();
        storedetune1 = m_detune1->getValue();
        storeoctave1 = m_octave1->getToggleState();


        storewaveform2 = lastwaveform2;
        storegain2 = m_synthDepth2->getValue();
        storepan2 = m_osc2Pan->getValue();
        storeattack2 = m_attack2->getValue();
        storedecay2 = m_decay2->getValue();
        storesustain2 = m_sustain2->getValue();
        storerelease2 = m_release2->getValue();
        storedetune2 = m_detune2->getValue();
        storeoctave2 = m_octave2->getToggleState();
        //[/UserButtonCode_m_storePreset]
    }
    else if (buttonThatWasClicked == m_setPreset.get())
    {
        //[UserButtonCode_m_setPreset] -- add your button handler code here..

        m_synthDepth->setValue(storegain1);
        audioProcessor.updateParameters(ksynthDepth,m_synthDepth->getValue());

        m_osc1Pan->setValue(storepan1);
        audioProcessor.updateParameters(kosc1Pan,m_osc1Pan->getValue());

        m_attack1->setValue(storeattack1);
        audioProcessor.updateParameters(kattack1,m_attack1->getValue());

        m_decay1->setValue(storedecay1);
        audioProcessor.updateParameters(kdecay1,m_decay1->getValue());

        m_sustain1->setValue(storesustain1);
        audioProcessor.updateParameters(ksustain1,m_sustain1->getValue());

        m_release1->setValue(storerelease1);
        audioProcessor.updateParameters(krelease1,m_release1->getValue());

        m_detune1->setValue(storedetune1);
        audioProcessor.updateParameters(kdetune1,m_detune1->getValue());

        m_octave1->setToggleState(storeoctave1, juce::sendNotificationSync);




        if (storewaveform1 == kSine)
        {
            audioProcessor.updateParameters(kWaveform, kSine);
            m_sineButton->setToggleState(true,0);
        }

         if (storewaveform1 == kSaw)
        {
            audioProcessor.updateParameters(kWaveform, kSaw);
            m_sawButton->setToggleState(true,0);
        }

         if (storewaveform1 == kSquare)
        {
            audioProcessor.updateParameters(kWaveform, kSquare);
            m_squareButton->setToggleState(true,0);
        }

         if (storewaveform1 == kTriangle)
        {
            audioProcessor.updateParameters(kWaveform, kTriangle);
            m_triangleButton->setToggleState(true,0);
        }



        m_synthDepth2->setValue(storegain2);
        audioProcessor.updateParameters(ksynthDepth2,m_synthDepth2->getValue());

        m_osc2Pan->setValue(storepan2);
        audioProcessor.updateParameters(kosc2Pan,m_osc2Pan->getValue());

        m_attack2->setValue(storeattack2);
        audioProcessor.updateParameters(kattack2,m_attack2->getValue());

        m_decay2->setValue(storedecay2);
        audioProcessor.updateParameters(kdecay2,m_decay2->getValue());

        m_sustain2->setValue(storesustain2);
        audioProcessor.updateParameters(ksustain2,m_sustain2->getValue());

        m_release2->setValue(storerelease2);
        audioProcessor.updateParameters(krelease2,m_release2->getValue());

        m_detune2->setValue(storedetune2);
        audioProcessor.updateParameters(kdetune2,m_detune2->getValue());

        m_octave2->setToggleState(storeoctave2, juce::sendNotificationSync);




        if (storewaveform2 == kSine)
        {
            audioProcessor.updateParameters(kWaveform2, kSine);
            m_sineButton2->setToggleState(true,0);
        }

         if (storewaveform2 == kSaw)
        {
            audioProcessor.updateParameters(kWaveform2, kSaw);
            m_sawButton2->setToggleState(true,0);
        }

         if (storewaveform2 == kSquare)
        {
            audioProcessor.updateParameters(kWaveform2, kSquare);
            m_squareButton2->setToggleState(true,0);
        }

         if (storewaveform2 == kTriangle)
        {
            audioProcessor.updateParameters(kWaveform2, kTriangle);
            m_triangleButton2->setToggleState(true,0);
        }






        //[/UserButtonCode_m_setPreset]
    }
    else if (buttonThatWasClicked == m_storePreset2.get())
    {
        //[UserButtonCode_m_storePreset2] -- add your button handler code here..
        storewaveform1preset2 = lastwaveform1;
        storegain1preset2 = m_synthDepth->getValue();
        storepan1preset2 = m_osc1Pan->getValue();
        storeattack1preset2 = m_attack1->getValue();
        storedecay1preset2 = m_decay1->getValue();
        storesustain1preset2 = m_sustain1->getValue();
        storerelease1preset2 = m_release1->getValue();
        storedetune1preset2 = m_detune1->getValue();
        storeoctave1preset2 = m_octave1->getToggleState();


        storewaveform2preset2 = lastwaveform2;
        storegain2preset2 = m_synthDepth2->getValue();
        storepan2preset2 = m_osc2Pan->getValue();
        storeattack2preset2 = m_attack2->getValue();
        storedecay2preset2 = m_decay2->getValue();
        storesustain2preset2 = m_sustain2->getValue();
        storerelease2preset2 = m_release2->getValue();
        storedetune2preset2 = m_detune2->getValue();
        storeoctave2preset2 = m_octave2->getToggleState();
        //[/UserButtonCode_m_storePreset2]
    }
    else if (buttonThatWasClicked == m_setPreset2.get())
    {
        //[UserButtonCode_m_setPreset2] -- add your button handler code here..
        m_synthDepth->setValue(storegain1preset2);
        audioProcessor.updateParameters(ksynthDepth,m_synthDepth->getValue());

        m_osc1Pan->setValue(storepan1preset2);
        audioProcessor.updateParameters(kosc1Pan,m_osc1Pan->getValue());

        m_attack1->setValue(storeattack1preset2);
        audioProcessor.updateParameters(kattack1,m_attack1->getValue());

        m_decay1->setValue(storedecay1preset2);
        audioProcessor.updateParameters(kdecay1,m_decay1->getValue());

        m_sustain1->setValue(storesustain1preset2);
        audioProcessor.updateParameters(ksustain1,m_sustain1->getValue());

        m_release1->setValue(storerelease1preset2);
        audioProcessor.updateParameters(krelease1,m_release1->getValue());

        m_detune1->setValue(storedetune1preset2);
        audioProcessor.updateParameters(kdetune1,m_detune1->getValue());

        m_octave1->setToggleState(storeoctave1preset2, juce::sendNotificationSync);




        if (storewaveform1preset2 == kSine)
        {
            audioProcessor.updateParameters(kWaveform, kSine);
            m_sineButton->setToggleState(true,0);
        }

         if (storewaveform1preset2 == kSaw)
        {
            audioProcessor.updateParameters(kWaveform, kSaw);
            m_sawButton->setToggleState(true,0);
        }

         if (storewaveform1preset2 == kSquare)
        {
            audioProcessor.updateParameters(kWaveform, kSquare);
            m_squareButton->setToggleState(true,0);
        }

         if (storewaveform1preset2 == kTriangle)
        {
            audioProcessor.updateParameters(kWaveform, kTriangle);
            m_triangleButton->setToggleState(true,0);
        }



        m_synthDepth2->setValue(storegain2preset2);
        audioProcessor.updateParameters(ksynthDepth2,m_synthDepth2->getValue());

        m_osc2Pan->setValue(storepan2preset2);
        audioProcessor.updateParameters(kosc2Pan,m_osc2Pan->getValue());

        m_attack2->setValue(storeattack2preset2);
        audioProcessor.updateParameters(kattack2,m_attack2->getValue());

        m_decay2->setValue(storedecay2preset2);
        audioProcessor.updateParameters(kdecay2,m_decay2->getValue());

        m_sustain2->setValue(storesustain2preset2);
        audioProcessor.updateParameters(ksustain2,m_sustain2->getValue());

        m_release2->setValue(storerelease2preset2);
        audioProcessor.updateParameters(krelease2,m_release2->getValue());

        m_detune2->setValue(storedetune2preset2);
        audioProcessor.updateParameters(kdetune2,m_detune2->getValue());

        m_octave2->setToggleState(storeoctave2preset2, juce::sendNotificationSync);




        if (storewaveform2preset2 == kSine)
        {
            audioProcessor.updateParameters(kWaveform2, kSine);
            m_sineButton2->setToggleState(true,0);
        }

         if (storewaveform2preset2 == kSaw)
        {
            audioProcessor.updateParameters(kWaveform2, kSaw);
            m_sawButton2->setToggleState(true,0);
        }

         if (storewaveform2preset2 == kSquare)
        {
            audioProcessor.updateParameters(kWaveform2, kSquare);
            m_squareButton2->setToggleState(true,0);
        }

         if (storewaveform2preset2 == kTriangle)
        {
            audioProcessor.updateParameters(kWaveform2, kTriangle);
            m_triangleButton2->setToggleState(true,0);
        }

        //[/UserButtonCode_m_setPreset2]
    }
    else if (buttonThatWasClicked == m_storePreset3.get())
    {
        //[UserButtonCode_m_storePreset3] -- add your button handler code here..
        storewaveform1preset3 = lastwaveform1;
        storegain1preset3 = m_synthDepth->getValue();
        storepan1preset3 = m_osc1Pan->getValue();
        storeattack1preset3 = m_attack1->getValue();
        storedecay1preset3 = m_decay1->getValue();
        storesustain1preset3 = m_sustain1->getValue();
        storerelease1preset3 = m_release1->getValue();
        storedetune1preset3 = m_detune1->getValue();
        storeoctave1preset3 = m_octave1->getToggleState();


        storewaveform2preset3 = lastwaveform2;
        storegain2preset3 = m_synthDepth2->getValue();
        storepan2preset3 = m_osc2Pan->getValue();
        storeattack2preset3 = m_attack2->getValue();
        storedecay2preset3 = m_decay2->getValue();
        storesustain2preset3 = m_sustain2->getValue();
        storerelease2preset3 = m_release2->getValue();
        storedetune2preset3 = m_detune2->getValue();
        storeoctave2preset3 = m_octave2->getToggleState();

        //[/UserButtonCode_m_storePreset3]
    }
    else if (buttonThatWasClicked == m_setPreset3.get())
    {
        //[UserButtonCode_m_setPreset3] -- add your button handler code here..

            m_synthDepth->setValue(storegain1preset3);
        audioProcessor.updateParameters(ksynthDepth,m_synthDepth->getValue());

        m_osc1Pan->setValue(storepan1preset3);
        audioProcessor.updateParameters(kosc1Pan,m_osc1Pan->getValue());

        m_attack1->setValue(storeattack1preset3);
        audioProcessor.updateParameters(kattack1,m_attack1->getValue());

        m_decay1->setValue(storedecay1preset3);
        audioProcessor.updateParameters(kdecay1,m_decay1->getValue());

        m_sustain1->setValue(storesustain1preset3);
        audioProcessor.updateParameters(ksustain1,m_sustain1->getValue());

        m_release1->setValue(storerelease1preset3);
        audioProcessor.updateParameters(krelease1,m_release1->getValue());

        m_detune1->setValue(storedetune1preset3);
        audioProcessor.updateParameters(kdetune1, m_detune1->getValue());

        m_octave1->setToggleState(storeoctave1preset3, juce::sendNotificationSync);




        if (storewaveform1preset3 == kSine)
        {
            audioProcessor.updateParameters(kWaveform, kSine);
            m_sineButton->setToggleState(true,0);
        }

         if (storewaveform1preset3 == kSaw)
        {
            audioProcessor.updateParameters(kWaveform, kSaw);
            m_sawButton->setToggleState(true,0);
        }

         if (storewaveform1preset3 == kSquare)
        {
            audioProcessor.updateParameters(kWaveform, kSquare);
            m_squareButton->setToggleState(true,0);
        }

         if (storewaveform1preset3 == kTriangle)
        {
            audioProcessor.updateParameters(kWaveform, kTriangle);
            m_triangleButton->setToggleState(true,0);
        }



        m_synthDepth2->setValue(storegain2preset3);
        audioProcessor.updateParameters(ksynthDepth2,m_synthDepth2->getValue());

        m_osc2Pan->setValue(storepan2preset3);
        audioProcessor.updateParameters(kosc2Pan,m_osc2Pan->getValue());

        m_attack2->setValue(storeattack2preset3);
        audioProcessor.updateParameters(kattack2,m_attack2->getValue());

        m_decay2->setValue(storedecay2preset3);
        audioProcessor.updateParameters(kdecay2,m_decay2->getValue());

        m_sustain2->setValue(storesustain2preset3);
        audioProcessor.updateParameters(ksustain2,m_sustain2->getValue());

        m_release2->setValue(storerelease2preset3);
        audioProcessor.updateParameters(krelease2,m_release2->getValue());

        m_detune2->setValue(storedetune2preset3);
        audioProcessor.updateParameters(kdetune2,m_detune2->getValue());

        m_octave2->setToggleState(storeoctave2preset3, juce::sendNotificationSync);




        if (storewaveform2preset3 == kSine)
        {
            audioProcessor.updateParameters(kWaveform2, kSine);
            m_sineButton2->setToggleState(true,0);
        }

         if (storewaveform2preset3 == kSaw)
        {
            audioProcessor.updateParameters(kWaveform2, kSaw);
            m_sawButton2->setToggleState(true,0);
        }

         if (storewaveform2preset3 == kSquare)
        {
            audioProcessor.updateParameters(kWaveform2, kSquare);
            m_squareButton2->setToggleState(true,0);
        }

         if (storewaveform2preset3 == kTriangle)
        {
            audioProcessor.updateParameters(kWaveform2, kTriangle);
            m_triangleButton2->setToggleState(true,0);
        }
        //[/UserButtonCode_m_setPreset3]
    }
    else if (buttonThatWasClicked == m_synthTab.get())
    {
        //[UserButtonCode_m_synthTab] -- add your button handler code here..

       //synth
        m_sineButton->setVisible(true);
        m_sawButton->setVisible(true);
        m_squareButton->setVisible(true);
        m_triangleButton->setVisible(true);
        m_synthDepth->setVisible(true);
        m_detune1->setVisible(true);
        m_osc1Pan->setVisible(true);
        m_attack1->setVisible(true);
        m_decay1->setVisible(true);
        m_sustain1->setVisible(true);
        m_release1->setVisible(true);
        juce__label7->setVisible(true);
        juce__label11->setVisible(true);
        juce__label25->setVisible(true);
        juce__label8->setVisible(true);
        juce__label9->setVisible(true);
        juce__label10->setVisible(true);
        juce__label12->setVisible(true);
        osc1box->setVisible(true);

        m_sineButton2->setVisible(true);
        m_sawButton2->setVisible(true);
        m_squareButton2->setVisible(true);
        m_triangleButton2->setVisible(true);
        m_synthDepth2->setVisible(true);
        m_detune2->setVisible(true);
        m_osc2Pan->setVisible(true);
        m_attack2->setVisible(true);
        m_decay2->setVisible(true);
        m_sustain2->setVisible(true);
        m_release2->setVisible(true);
        juce__label21->setVisible(true);
        juce__label22->setVisible(true);
        juce__label26->setVisible(true);
        juce__label17->setVisible(true);
        juce__label18->setVisible(true);
        juce__label19->setVisible(true);
        juce__label20->setVisible(true);
        osc2box->setVisible(true);
        m_octave1->setVisible(true);
        m_octave2->setVisible(true);

        //effects

        mixerbox->setVisible(false);
        juce__label3->setVisible(false);
        m_gainSlider->setVisible(false);

        autopanbox->setVisible(false);
        m_autoPanSlider->setVisible(false);
        m_autoPanFreqSlider->setVisible(false);
        m_autoPanShape->setVisible(false);
        m_autoPanButton->setVisible(false);
        juce__label->setVisible(false);
        juce__label2->setVisible(false);

        delaybox->setVisible(false);
        m_delayDryWetSlider->setVisible(false);
        m_delayFeedback->setVisible(false);
        m_delayLeft2->setVisible(false);
        m_delayLeft4->setVisible(false);
        m_delayLeft8->setVisible(false);
        m_delayLeft16->setVisible(false);
        m_delayRight2->setVisible(false);
        m_delayRight4->setVisible(false);
        m_delayRight8->setVisible(false);
        m_delayRight16->setVisible(false);
        m_delayButton->setVisible(false);
        juce__label4->setVisible(false);
        juce__label6->setVisible(false);

        juce__label23->setVisible(false);
        juce__label24->setVisible(false);

        m_dry->setVisible(false);
        m_wet->setVisible(false);
        m_size->setVisible(false);
        m_damping->setVisible(false);
        reverbbox->setVisible(false);
        m_reverbButton->setVisible(false);
        juce__label13->setVisible(false);
        juce__label14->setVisible(false);
        juce__label15->setVisible(false);
        juce__label16->setVisible(false);
        m_stereoDelayButton->setVisible(false);
        m_multitapDelayButton->setVisible(false);
        m_dryWetMultitap->setVisible(false);
        m_multitapDelay1->setVisible(false);
        m_multitapDelay2->setVisible(false);
        m_multitapDelay3->setVisible(false);
        m_multitapFeedback->setVisible(false);
        m_chorusDryWet->setVisible(false);
        m_chorusLFORate->setVisible(false);
        m_chorusButton->setVisible(false);
        chorusbox->setVisible(false);
        juce__label5->setVisible(false);
        juce__label27->setVisible(false);






        //[/UserButtonCode_m_synthTab]
    }
    else if (buttonThatWasClicked == m_effectsTab.get())
    {
        //[UserButtonCode_m_effectsTab] -- add your button handler code here..
           //synth
        m_sineButton->setVisible(false);
        m_sawButton->setVisible(false);
        m_squareButton->setVisible(false);
        m_triangleButton->setVisible(false);
        m_synthDepth->setVisible(false);
        m_detune1->setVisible(false);
        m_osc1Pan->setVisible(false);
        m_attack1->setVisible(false);
        m_decay1->setVisible(false);
        m_sustain1->setVisible(false);
        m_release1->setVisible(false);
        juce__label7->setVisible(false);
        juce__label11->setVisible(false);
        juce__label25->setVisible(false);
        juce__label8->setVisible(false);
        juce__label9->setVisible(false);
        juce__label10->setVisible(false);
        juce__label12->setVisible(false);
        osc1box->setVisible(false);

        m_sineButton2->setVisible(false);
        m_sawButton2->setVisible(false);
        m_squareButton2->setVisible(false);
        m_triangleButton2->setVisible(false);
        m_synthDepth2->setVisible(false);
        m_detune2->setVisible(false);
        m_osc2Pan->setVisible(false);
        m_attack2->setVisible(false);
        m_decay2->setVisible(false);
        m_sustain2->setVisible(false);
        m_release2->setVisible(false);
        juce__label21->setVisible(false);
        juce__label22->setVisible(false);
        juce__label26->setVisible(false);
        juce__label17->setVisible(false);
        juce__label18->setVisible(false);
        juce__label19->setVisible(false);
        juce__label20->setVisible(false);
        osc2box->setVisible(false);
        m_octave1->setVisible(false);
        m_octave2->setVisible(false);
;

        //effects

        mixerbox->setVisible(true);
        juce__label3->setVisible(true);
        m_gainSlider->setVisible(true);

        autopanbox->setVisible(true);
        m_autoPanSlider->setVisible(true);
        m_autoPanFreqSlider->setVisible(true);
        m_autoPanShape->setVisible(true);
        m_autoPanButton->setVisible(true);
        juce__label->setVisible(true);
        juce__label2->setVisible(true);

        delaybox->setVisible(true);
        m_delayDryWetSlider->setVisible(true);
        m_delayFeedback->setVisible(true);
        m_delayLeft2->setVisible(true);
        m_delayLeft4->setVisible(true);
        m_delayLeft8->setVisible(true);
        m_delayLeft16->setVisible(true);
        m_delayRight2->setVisible(true);
        m_delayRight4->setVisible(true);
        m_delayRight8->setVisible(true);
        m_delayRight16->setVisible(true);
        m_delayButton->setVisible(true);
        juce__label4->setVisible(true);
        juce__label6->setVisible(true);

        juce__label23->setVisible(true);
        juce__label24->setVisible(true);

        m_dry->setVisible(true);
        m_wet->setVisible(true);
        m_size->setVisible(true);
        m_damping->setVisible(true);
        reverbbox->setVisible(true);
        m_reverbButton->setVisible(true);
        juce__label13->setVisible(true);
        juce__label14->setVisible(true);
        juce__label15->setVisible(true);
        juce__label16->setVisible(true);
        m_stereoDelayButton->setVisible(true);
        m_multitapDelayButton->setVisible(true);
        m_chorusDryWet->setVisible(true);
        m_chorusLFORate->setVisible(true);
        m_chorusButton->setVisible(true);
        chorusbox->setVisible(true);
        juce__label5->setVisible(true);
        juce__label27->setVisible(true);

        //[/UserButtonCode_m_effectsTab]
    }
    else if (buttonThatWasClicked == m_stereoDelayButton.get())
    {
        //[UserButtonCode_m_stereoDelayButton] -- add your button handler code here..
        audioProcessor.updateParameters(kstereoDelayButton, m_stereoDelayButton->getState());


        m_delayDryWetSlider->setVisible(true);
        m_delayFeedback->setVisible(true);
        juce__label23->setVisible(true);
        juce__label24->setVisible(true);
        m_delayLeft2->setVisible(true);
        m_delayLeft4->setVisible(true);
        m_delayLeft8->setVisible(true);
        m_delayLeft16->setVisible(true);
        m_delayRight2->setVisible(true);
        m_delayRight4->setVisible(true);
        m_delayRight8->setVisible(true);
        m_delayRight16->setVisible(true);

        m_dryWetMultitap->setVisible(false);
        m_multitapDelay1->setVisible(false);
        m_multitapDelay2->setVisible(false);
        m_multitapDelay3->setVisible(false);
        m_multitapFeedback->setVisible(false);



        //[/UserButtonCode_m_stereoDelayButton]
    }
    else if (buttonThatWasClicked == m_multitapDelayButton.get())
    {
        //[UserButtonCode_m_multitapDelayButton] -- add your button handler code here..
        audioProcessor.updateParameters(kmultitapDelayButton, m_multitapDelayButton->getState());


        m_delayDryWetSlider->setVisible(false);
        m_delayFeedback->setVisible(false);
        juce__label23->setVisible(false);
        juce__label24->setVisible(false);
        m_delayLeft2->setVisible(false);
        m_delayLeft4->setVisible(false);
        m_delayLeft8->setVisible(false);
        m_delayLeft16->setVisible(false);
        m_delayRight2->setVisible(false);
        m_delayRight4->setVisible(false);
        m_delayRight8->setVisible(false);
        m_delayRight16->setVisible(false);

        m_dryWetMultitap->setVisible(true);
        m_multitapDelay1->setVisible(true);
        m_multitapDelay2->setVisible(true);
        m_multitapDelay3->setVisible(true);
        m_multitapFeedback->setVisible(true);
        //[/UserButtonCode_m_multitapDelayButton]
    }
    else if (buttonThatWasClicked == m_chorusButton.get())
    {
        //[UserButtonCode_m_chorusButton] -- add your button handler code here..
        audioProcessor.updateParameters(kchorusButton, m_chorusButton->getToggleState());
        //[/UserButtonCode_m_chorusButton]
    }
    else if (buttonThatWasClicked == m_octave1.get())
    {
        //[UserButtonCode_m_octave1] -- add your button handler code here..
        audioProcessor.updateParameters(koctave1, m_octave1->getToggleState());
        //[/UserButtonCode_m_octave1]
    }
    else if (buttonThatWasClicked == m_octave2.get())
    {
        //[UserButtonCode_m_octave2] -- add your button handler code here..
        audioProcessor.updateParameters(koctave2, m_octave2->getToggleState());
        //[/UserButtonCode_m_octave2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void Tutorial5classesAudioProcessorEditor::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_autoPanShape.get())
    {
        //[UserComboBoxCode_m_autoPanShape] -- add your combo box handling code here..
        audioProcessor.updateParameters(kautoPanShapeButton, m_autoPanShape->getSelectedId());

        //[/UserComboBoxCode_m_autoPanShape]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Tutorial5classesAudioProcessorEditor"
                 componentName="" parentClasses="public juce::AudioProcessorEditor"
                 constructorParams="Tutorial5classesAudioProcessor&amp; owner"
                 variableInitialisers="AudioProcessorEditor(owner),audioProcessor(owner)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="900" initialHeight="400">
  <BACKGROUND backgroundColour="ff000000"/>
  <GROUPCOMPONENT name="new group" id="508d59e752383ce7" memberName="chorusbox"
                  virtualName="" explicitFocusOrder="0" pos="144 208 200 120" outlinecol="ff08b9ee"
                  title="Chorus"/>
  <GROUPCOMPONENT name="new group" id="dfe5f3ce90bea1c3" memberName="delaybox"
                  virtualName="" explicitFocusOrder="0" pos="360 80 272 248" outlinecol="ff08b9ee"
                  title="Delay"/>
  <GROUPCOMPONENT name="new group" id="35e26f2ad634f9ca" memberName="osc2box" virtualName=""
                  explicitFocusOrder="0" pos="448 80 408 232" outlinecol="ff08b9ee"
                  title="Osc 2"/>
  <GROUPCOMPONENT name="new group" id="c80bae1c03243772" memberName="osc1box" virtualName=""
                  explicitFocusOrder="0" pos="16 80 416 232" outlinecol="ff08b9ee"
                  title="Osc 1"/>
  <GROUPCOMPONENT name="new group" id="4f4a0d585429616b" memberName="reverbbox"
                  virtualName="" explicitFocusOrder="0" pos="648 80 208 248" outlinecol="ff08b9ee"
                  title="Reverb"/>
  <GROUPCOMPONENT name="new group" id="bd8f39cac066bd15" memberName="mixerbox"
                  virtualName="" explicitFocusOrder="0" pos="16 80 112 248" outlinecol="ff08b9ee"
                  title="Mixer"/>
  <GROUPCOMPONENT name="new group" id="14986862fd02e53a" memberName="autopanbox"
                  virtualName="" explicitFocusOrder="0" pos="144 80 200 128" outlinecol="ff08b9ee"
                  title="Auto Pan"/>
  <SLIDER name="Gain" id="6d81f5f3385a696c" memberName="m_gainSlider" virtualName=""
          explicitFocusOrder="0" pos="-8 152 160 152" bkgcol="ff2097d2"
          min="-60.0" max="0.0" int="1.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="autoPan" id="994f11aa76960f15" memberName="m_autoPanSlider"
          virtualName="" explicitFocusOrder="0" pos="168 104 56 72" bkgcol="ff108bc8"
          min="0.0" max="100.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="autoPanFreq" id="9ced909b933d55de" memberName="m_autoPanFreqSlider"
          virtualName="" explicitFocusOrder="0" pos="248 104 71 72" min="0.05"
          max="5.0" int="0.01" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="ab7e8ce75f52ca79" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="160 96 64 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Amount" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="7a7b1de451209810" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="256 96 40 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Rate " editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="91501ec05afd1ec4" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="48 104 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.033" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="autoPanButton" id="1878fba306d451be" memberName="m_autoPanButton"
                virtualName="" explicitFocusOrder="0" pos="312 96 24 24" txtcol="ffc10e0e"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <COMBOBOX name="autoPanShape" id="fa327bddd1c7bf94" memberName="m_autoPanShape"
            virtualName="" explicitFocusOrder="0" pos="176 184 142 16" editable="0"
            layout="33" items="Sine&#10;Square&#10;Saw&#10;Triangle" textWhenNonSelected="Sine"
            textWhenNoItems=""/>
  <SLIDER name="delayDryWet" id="81cc53eaa6b550e3" memberName="m_delayDryWetSlider"
          virtualName="" explicitFocusOrder="0" pos="400 136 64 80" min="0.0"
          max="100.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="169a4faea4a8919d" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="400 128 64 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Dry/Wet" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="delayFeedback" id="86ec0c371f36c0f" memberName="m_delayFeedback"
          virtualName="" explicitFocusOrder="0" pos="512 136 87 80" min="0.0"
          max="100.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="897c5ca83581b649" memberName="juce__label6"
         virtualName="" explicitFocusOrder="0" pos="520 120 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Feedback" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="delayButton" id="5d2773a59317d317" memberName="m_delayButton"
                virtualName="" explicitFocusOrder="0" pos="592 96 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="sineButton" id="b2b9b043c884af9d" memberName="m_sineButton"
                virtualName="" explicitFocusOrder="0" pos="32 104 150 24" buttonText="Sine"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="1"/>
  <TOGGLEBUTTON name="triangleButton" id="c28e65effd5f417a" memberName="m_triangleButton"
                virtualName="" explicitFocusOrder="0" pos="32 248 88 24" buttonText="Triangle"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <TOGGLEBUTTON name="squareButton" id="40677f38f1ec1983" memberName="m_squareButton"
                virtualName="" explicitFocusOrder="0" pos="32 200 150 24" buttonText="Square"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <TOGGLEBUTTON name="sawButton" id="96e517a75731b2a4" memberName="m_sawButton"
                virtualName="" explicitFocusOrder="0" pos="32 152 150 24" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <SLIDER name="synthDepth" id="ad91a72ea51a3ea9" memberName="m_synthDepth"
          virtualName="" explicitFocusOrder="0" pos="128 152 64 88" min="0.0"
          max="1.0" int="0.1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="c5180c07276afb44" memberName="juce__label7"
         virtualName="" explicitFocusOrder="0" pos="144 128 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="osc1Pan" id="6f2e718a9857fa7b" memberName="m_osc1Pan" virtualName=""
          explicitFocusOrder="0" pos="208 160 80 80" min="-1.0" max="1.0"
          int="0.1" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="c011854dc7ec3919" memberName="juce__label11"
         virtualName="" explicitFocusOrder="0" pos="232 128 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="attack1" id="b49aca06b2c38563" memberName="m_attack1" virtualName=""
          explicitFocusOrder="0" pos="328 112 88 32" min="0.0" max="5.0"
          int="0.1" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="decay1" id="161dc046cd92d0f3" memberName="m_decay1" virtualName=""
          explicitFocusOrder="0" pos="328 160 88 32" min="0.0" max="5.0"
          int="0.1" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="sustain1" id="d29c0e69cf50d32c" memberName="m_sustain1"
          virtualName="" explicitFocusOrder="0" pos="328 208 88 32" min="0.0"
          max="5.0" int="0.1" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="release1" id="86f5c3ca79fd0556" memberName="m_release1"
          virtualName="" explicitFocusOrder="0" pos="328 256 88 32" min="0.0"
          max="5.0" int="0.1" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="bbf7c3ffe40f081" memberName="juce__label8"
         virtualName="" explicitFocusOrder="0" pos="304 120 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8a08a207ce3ca203" memberName="juce__label9"
         virtualName="" explicitFocusOrder="0" pos="304 168 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="D" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="68bbc1b115d5e8fb" memberName="juce__label10"
         virtualName="" explicitFocusOrder="0" pos="304 216 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="S" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="4d4c344fa34dadc1" memberName="juce__label12"
         virtualName="" explicitFocusOrder="0" pos="304 264 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="dry" id="48c8c32e56ea73ca" memberName="m_dry" virtualName=""
          explicitFocusOrder="0" pos="664 112 72 80" min="0.0" max="100.0"
          int="1.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="wet" id="3bab9c8600f17692" memberName="m_wet" virtualName=""
          explicitFocusOrder="0" pos="752 112 88 80" min="0.0" max="100.0"
          int="1.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="size" id="e1951e83aca54e9c" memberName="m_size" virtualName=""
          explicitFocusOrder="0" pos="656 208 88 80" min="0.0" max="100.0"
          int="1.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="damping" id="e4e8bc524e4100bb" memberName="m_damping" virtualName=""
          explicitFocusOrder="0" pos="768 208 64 80" min="0.0" max="100.0"
          int="1.0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="7811886433418246" memberName="juce__label13"
         virtualName="" explicitFocusOrder="0" pos="680 104 40 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Dry" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="7ab590d93fe48395" memberName="juce__label14"
         virtualName="" explicitFocusOrder="0" pos="776 104 32 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Wet" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a098f47d90881cc0" memberName="juce__label15"
         virtualName="" explicitFocusOrder="0" pos="680 200 40 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Size" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="18aedbd05942ffd3" memberName="juce__label16"
         virtualName="" explicitFocusOrder="0" pos="776 200 63 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Damping" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="sineButton2" id="b7b0911bb70a6fa" memberName="m_sineButton2"
                virtualName="" explicitFocusOrder="0" pos="472 112 64 24" buttonText="Sine"
                connectedEdges="0" needsCallback="1" radioGroupId="2" state="1"/>
  <TOGGLEBUTTON name="SawButton2" id="11dfdce6a43c2aa6" memberName="m_sawButton2"
                virtualName="" explicitFocusOrder="0" pos="472 160 64 24" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="squareButton2" id="f1678b1b865753b6" memberName="m_squareButton2"
                virtualName="" explicitFocusOrder="0" pos="472 208 150 24" buttonText="Square"
                connectedEdges="0" needsCallback="1" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="triangleButton2" id="51b44a874b5f47be" memberName="m_triangleButton2"
                virtualName="" explicitFocusOrder="0" pos="472 256 80 24" buttonText="Triangle"
                connectedEdges="0" needsCallback="1" radioGroupId="2" state="0"/>
  <SLIDER name="synthDepth" id="9f2076b5d9370b48" memberName="m_synthDepth2"
          virtualName="" explicitFocusOrder="0" pos="552 152 88 80" min="0.0"
          max="1.0" int="0.1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="osc2Pan" id="1f15a1b43c8e911f" memberName="m_osc2Pan" virtualName=""
          explicitFocusOrder="0" pos="648 152 80 80" min="-1.0" max="1.0"
          int="0.1" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="attack2" id="11ce5a5b03294115" memberName="m_attack2" virtualName=""
          explicitFocusOrder="0" pos="744 104 88 32" min="0.0" max="5.0"
          int="0.1" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="decay2" id="59aa8caf29d0c756" memberName="m_decay2" virtualName=""
          explicitFocusOrder="0" pos="744 152 88 32" min="0.0" max="5.0"
          int="0.1" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="sustain2" id="689791a5e7b4028a" memberName="m_sustain2"
          virtualName="" explicitFocusOrder="0" pos="744 200 88 32" min="0.0"
          max="5.0" int="0.1" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="release2" id="fbed5b57f5010959" memberName="m_release2"
          virtualName="" explicitFocusOrder="0" pos="744 248 88 32" min="0.0"
          max="5.0" int="0.1" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="f5d51e907496c532" memberName="juce__label17"
         virtualName="" explicitFocusOrder="0" pos="728 104 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="699fef1b6577328" memberName="juce__label18"
         virtualName="" explicitFocusOrder="0" pos="728 152 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="D" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="b449c42fd2c61e95" memberName="juce__label19"
         virtualName="" explicitFocusOrder="0" pos="728 200 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="S" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="dcacf1a2b0d3b6d6" memberName="juce__label20"
         virtualName="" explicitFocusOrder="0" pos="728 248 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="ad6b833574356524" memberName="juce__label21"
         virtualName="" explicitFocusOrder="0" pos="576 128 47 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="728b868a98ad3168" memberName="juce__label22"
         virtualName="" explicitFocusOrder="0" pos="672 128 31 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="delayLeft2" id="66edfea745035ecb" memberName="m_delayLeft2"
                virtualName="" explicitFocusOrder="0" pos="376 248 48 24" buttonText="2"
                connectedEdges="0" needsCallback="1" radioGroupId="3" state="1"/>
  <LABEL name="new label" id="5e229b33f97e1ad6" memberName="juce__label23"
         virtualName="" explicitFocusOrder="0" pos="400 216 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Left" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="delaylLeft4" id="d6cb53f2c8c2e46" memberName="m_delayLeft4"
                virtualName="" explicitFocusOrder="0" pos="432 248 48 24" buttonText="4"
                connectedEdges="0" needsCallback="1" radioGroupId="3" state="0"/>
  <TOGGLEBUTTON name="delayLeft8" id="59f0e472eea1adaa" memberName="m_delayLeft8"
                virtualName="" explicitFocusOrder="0" pos="376 280 48 24" buttonText="8"
                connectedEdges="0" needsCallback="1" radioGroupId="3" state="0"/>
  <TOGGLEBUTTON name="delayLeft16" id="c80fc5cddf7c5733" memberName="m_delayLeft16"
                virtualName="" explicitFocusOrder="0" pos="432 280 56 24" buttonText="16"
                connectedEdges="0" needsCallback="1" radioGroupId="3" state="0"/>
  <TOGGLEBUTTON name="delayRight4" id="86f2d917ffe0f479" memberName="m_delayRight4"
                virtualName="" explicitFocusOrder="0" pos="584 248 48 24" buttonText="4"
                connectedEdges="0" needsCallback="1" radioGroupId="4" state="0"/>
  <LABEL name="new label" id="b81cd670dd00eecb" memberName="juce__label24"
         virtualName="" explicitFocusOrder="0" pos="552 216 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Right" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="delayRight2" id="90492e07efb3b1a3" memberName="m_delayRight2"
                virtualName="" explicitFocusOrder="0" pos="528 248 48 24" buttonText="2"
                connectedEdges="0" needsCallback="1" radioGroupId="4" state="1"/>
  <TOGGLEBUTTON name="delayRight8" id="5a177d32e12ead72" memberName="m_delayRight8"
                virtualName="" explicitFocusOrder="0" pos="528 280 48 24" buttonText="8"
                connectedEdges="0" needsCallback="1" radioGroupId="4" state="0"/>
  <TOGGLEBUTTON name="delayRight16" id="48fcdf63b19fb2e7" memberName="m_delayRight16"
                virtualName="" explicitFocusOrder="0" pos="584 280 56 24" buttonText="16"
                connectedEdges="0" needsCallback="1" radioGroupId="4" state="0"/>
  <TOGGLEBUTTON name="reverbButton" id="52b8622b697776a8" memberName="m_reverbButton"
                virtualName="" explicitFocusOrder="0" pos="816 96 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="storePreset" id="3602ff415fbdffd" memberName="m_storePreset"
              virtualName="" explicitFocusOrder="0" pos="632 8 72 16" bgColOff="ff08b9ee"
              buttonText="Store Preset 1" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="setPreset" id="23e7b2e4c7f75e9a" memberName="m_setPreset"
              virtualName="" explicitFocusOrder="0" pos="744 8 72 16" bgColOff="ff08b9ee"
              buttonText="Set Preset 1" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="chorusRate" id="7d1f295ee55eb006" memberName="m_chorusLFORate"
          virtualName="" explicitFocusOrder="0" pos="248 232 80 72" min="0.01"
          max="10.0" int="0.01" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="storePreset2" id="c89c28c54294e53f" memberName="m_storePreset2"
              virtualName="" explicitFocusOrder="0" pos="632 32 72 16" bgColOff="ff08b9ee"
              buttonText="Store Preset 2" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="setPreset2" id="4f29df99b819a0b5" memberName="m_setPreset2"
              virtualName="" explicitFocusOrder="0" pos="744 32 72 16" bgColOff="ff08b9ee"
              buttonText="Set Preset 2" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="storePreset3" id="f0ae6020423d06b0" memberName="m_storePreset3"
              virtualName="" explicitFocusOrder="0" pos="632 56 72 16" bgColOff="ff08b9ee"
              buttonText="Store Preset 3" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="setPreset3" id="138873d94f899e4b" memberName="m_setPreset3"
              virtualName="" explicitFocusOrder="0" pos="744 56 72 16" bgColOff="ff08b9ee"
              buttonText="Set Preset 3" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="detune1" id="95227020fb26c253" memberName="m_detune1" virtualName=""
          explicitFocusOrder="0" pos="144 272 150 32" min="-6.0" max="6.0"
          int="0.1" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="detune1" id="2f77d47585b353e2" memberName="m_detune2" virtualName=""
          explicitFocusOrder="0" pos="568 272 150 32" min="-6.0" max="6.0"
          int="0.1" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="f793e65a297e2c3c" memberName="juce__label25"
         virtualName="" explicitFocusOrder="0" pos="184 248 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Detune" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="fbe4038b978e184d" memberName="juce__label26"
         virtualName="" explicitFocusOrder="0" pos="616 248 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Detune" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="synth tab" id="e8b6f4a2ace01def" memberName="m_synthTab"
              virtualName="" explicitFocusOrder="0" pos="264 40 150 24" buttonText="Synth"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="effectstab" id="493d77542821be77" memberName="m_effectsTab"
              virtualName="" explicitFocusOrder="0" pos="440 40 150 24" buttonText="Effects"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="9b1b2d69a173e8da" memberName="m_dryWetMultitap"
          virtualName="" explicitFocusOrder="0" pos="400 136 64 80" min="0.0"
          max="100.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="fbe53488ad59fc39" memberName="m_multitapDelay1"
          virtualName="" explicitFocusOrder="0" pos="424 232 168 24" min="200.0"
          max="2000.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="a4305aeacbc0b06c" memberName="m_multitapDelay2"
          virtualName="" explicitFocusOrder="0" pos="424 256 168 24" min="200.0"
          max="2000.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="5434a6eb1e553776" memberName="m_multitapDelay3"
          virtualName="" explicitFocusOrder="0" pos="424 280 168 24" min="200.0"
          max="2000.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="new button" id="a916e048ad3b69a1" memberName="m_stereoDelayButton"
              virtualName="" explicitFocusOrder="0" pos="392 104 88 16" buttonText="Stereo Delay"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="48e606ab6e6053da" memberName="m_multitapDelayButton"
              virtualName="" explicitFocusOrder="0" pos="496 104 88 16" buttonText="Multitap Delay"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="fc75b50311563b50" memberName="m_multitapFeedback"
          virtualName="" explicitFocusOrder="0" pos="488 136 127 80" min="0.0"
          max="100.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="daa283a25da89598" memberName="m_chorusDryWet"
          virtualName="" explicitFocusOrder="0" pos="160 232 64 72" min="0.0"
          max="100.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TOGGLEBUTTON name="new toggle button" id="a3b276c220c1bbd" memberName="m_chorusButton"
                virtualName="" explicitFocusOrder="0" pos="304 224 32 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="82a7b36a27386146" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="160 224 64 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Amount" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2f9f4be5875dc53a" memberName="juce__label27"
         virtualName="" explicitFocusOrder="0" pos="264 224 40 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Rate " editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="9d1cb67600f286c9" memberName="m_octave1"
                virtualName="" explicitFocusOrder="0" pos="168 96 104 24" buttonText="+1 octave"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="4b0a76340bdbe8c4" memberName="m_octave2"
                virtualName="" explicitFocusOrder="0" pos="600 96 104 24" buttonText="+1 octave"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

