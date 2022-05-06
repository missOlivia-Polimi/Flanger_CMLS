/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.1.6

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "Flanger.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Flanger::Flanger ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("LFO")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (24.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (56, 40, 150, 24);

    juce__slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider.get());
    juce__slider->setRange (0, 100, 1);
    juce__slider->setSliderStyle (juce::Slider::Rotary);
    juce__slider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 60, 20);
    juce__slider->addListener (this);

    juce__slider->setBounds (16, 120, 96, 88);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Width (%)")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (32, 88, 100, 24);

    juce__slider2.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider2.get());
    juce__slider2->setRange (0, 10, 0.1);
    juce__slider2->setSliderStyle (juce::Slider::Rotary);
    juce__slider2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 60, 20);
    juce__slider2->addListener (this);

    juce__slider2->setBounds (136, 120, 96, 88);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("Frequency (Hz)")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (144, 88, 100, 24);

    juce__label4.reset (new juce::Label ("new label",
                                         TRANS("Flanger\n")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (24.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredLeft);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (334, 40, 150, 24);

    juce__slider3.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider3.get());
    juce__slider3->setRange (0, 100, 1);
    juce__slider3->setSliderStyle (juce::Slider::Rotary);
    juce__slider3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 60, 20);
    juce__slider3->addListener (this);

    juce__slider3->setBounds (296, 120, 96, 88);

    juce__label5.reset (new juce::Label ("new label",
                                         TRANS("Feedback (%)")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centredLeft);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (312, 88, 100, 24);

    juce__slider4.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider4.get());
    juce__slider4->setRange (0, 20, 0.1);
    juce__slider4->setSliderStyle (juce::Slider::Rotary);
    juce__slider4->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 60, 20);
    juce__slider4->addListener (this);

    juce__slider4->setBounds (424, 120, 96, 88);

    juce__label6.reset (new juce::Label ("new label",
                                         TRANS("Delay (ms)")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centredLeft);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6->setBounds (440, 88, 100, 24);

    juce__slider5.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider5.get());
    juce__slider5->setRange (0, 100, 1);
    juce__slider5->setSliderStyle (juce::Slider::Rotary);
    juce__slider5->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 60, 20);
    juce__slider5->addListener (this);

    juce__slider5->setBounds (544, 120, 96, 88);

    juce__label7.reset (new juce::Label ("new label",
                                         TRANS("Depth (%)")));
    addAndMakeVisible (juce__label7.get());
    juce__label7->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label7->setJustificationType (juce::Justification::centredLeft);
    juce__label7->setEditable (false, false, false);
    juce__label7->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label7->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label7->setBounds (560, 88, 100, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (700, 300);


    //[Constructor] You can add your own custom stuff here..
    addSliderSuffix();
    //[/Constructor]
}

Flanger::~Flanger()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__label = nullptr;
    juce__slider = nullptr;
    juce__label2 = nullptr;
    juce__slider2 = nullptr;
    juce__label3 = nullptr;
    juce__label4 = nullptr;
    juce__slider3 = nullptr;
    juce__label5 = nullptr;
    juce__slider4 = nullptr;
    juce__label6 = nullptr;
    juce__slider5 = nullptr;
    juce__label7 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Flanger::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Flanger::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Flanger::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    const auto value = sliderThatWasMoved->getValue();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == juce__slider.get())
    {
        //[UserSliderCode_juce__slider] -- add your slider handling code here..
        if (lfoWidthChanged)
        {
            lfoWidthChanged(value);
        }
        //[/UserSliderCode_juce__slider]
    }
    else if (sliderThatWasMoved == juce__slider2.get())
    {
        //[UserSliderCode_juce__slider2] -- add your slider handling code here..
        if (lfoFreqChanged)
        {
            lfoFreqChanged(value);
        }
        //[/UserSliderCode_juce__slider2]
    }
    else if (sliderThatWasMoved == juce__slider3.get())
    {
        //[UserSliderCode_juce__slider3] -- add your slider handling code here..
        if (lfoFeedbackChanged)
        {
            lfoFeedbackChanged(value);
        }
        //[/UserSliderCode_juce__slider3]
    }
    else if (sliderThatWasMoved == juce__slider4.get())
    {
        //[UserSliderCode_juce__slider4] -- add your slider handling code here..
        if (lfoDelayChanged)
        {
            lfoDelayChanged(value);
        }
        //[/UserSliderCode_juce__slider4]
    }
    else if (sliderThatWasMoved == juce__slider5.get())
    {
        //[UserSliderCode_juce__slider5] -- add your slider handling code here..
        if (lfoDepthChanged)
        {
            lfoDepthChanged(value);
        }
        //[/UserSliderCode_juce__slider5]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Flanger::addSliderSuffix()
{
    juce__slider->setTextValueSuffix(" %");
    juce__slider2->setTextValueSuffix(" Hz");
    juce__slider3->setTextValueSuffix(" %");
    juce__slider4->setTextValueSuffix(" ms");
    juce__slider5->setTextValueSuffix(" %");
}

void Flanger::setLFOFreqChangedCallback(valueChangedCallback callback)
{
    lfoFreqChanged = callback;
}

void Flanger::setLFOWidthChangedCallback(valueChangedCallback callback)
{
    lfoWidthChanged = callback;
}

void Flanger::setFeedbackChangedCallback(valueChangedCallback callback)
{
    lfoFeedbackChanged = callback;
}

void Flanger::setDelayChangedCallback(valueChangedCallback callback)
{
    lfoDelayChanged = callback;
}

void Flanger::setDepthChangedCallback(valueChangedCallback callback)
{
    lfoDepthChanged = callback;
}

float Flanger::getMaxDelay() const
{
    return juce__slider4->getMaximum();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Flanger" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="700" initialHeight="300">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="new label" id="95a4cbca23ecef34" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="56 40 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="24.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="ea890515376c3c82" memberName="juce__slider"
          virtualName="" explicitFocusOrder="0" pos="16 120 96 88" min="0.0"
          max="100.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="438da2f777a8b127" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="32 88 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Width (%)" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="6f48675399f70d81" memberName="juce__slider2"
          virtualName="" explicitFocusOrder="0" pos="136 120 96 88" min="0.0"
          max="10.0" int="0.1" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="cebd848857b4df2b" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="144 88 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Frequency (Hz)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="96a95c680d9a9ba8" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="334 40 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Flanger&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="24.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="1f57107ad52afa45" memberName="juce__slider3"
          virtualName="" explicitFocusOrder="0" pos="296 120 96 88" min="0.0"
          max="100.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="9b79e1378f41324e" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="312 88 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Feedback (%)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="bca277353b53d5fe" memberName="juce__slider4"
          virtualName="" explicitFocusOrder="0" pos="424 120 96 88" min="0.0"
          max="20.0" int="0.1" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a64c3a9b178b84b7" memberName="juce__label6"
         virtualName="" explicitFocusOrder="0" pos="440 88 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Delay (ms)" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="2fcca84f31fd1a30" memberName="juce__slider5"
          virtualName="" explicitFocusOrder="0" pos="544 120 96 88" min="0.0"
          max="100.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="675a16fc0ad7b2af" memberName="juce__label7"
         virtualName="" explicitFocusOrder="0" pos="560 88 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth (%)" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

