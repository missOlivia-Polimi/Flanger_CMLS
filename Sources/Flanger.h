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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Flanger  : public juce::Component,
                 public juce::Slider::Listener
{
public:
    //==============================================================================
    Flanger ();
    ~Flanger() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    using valueChangedCallback = std::function<void(float)>;
    void setLFOFreqChangedCallback(valueChangedCallback);
    void setLFOWidthChangedCallback(valueChangedCallback);

    void setFeedbackChangedCallback(valueChangedCallback);
    void setDelayChangedCallback(valueChangedCallback);
    void setDepthChangedCallback(valueChangedCallback);

    float getMaxDelay() const;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    valueChangedCallback lfoFreqChanged;

    valueChangedCallback lfoWidthChanged;
    valueChangedCallback lfoFeedbackChanged;
    valueChangedCallback lfoDelayChanged;
    valueChangedCallback lfoDepthChanged;

    void addSliderSuffix();
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Slider> juce__slider;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Slider> juce__slider2;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<juce::Label> juce__label4;
    std::unique_ptr<juce::Slider> juce__slider3;
    std::unique_ptr<juce::Label> juce__label5;
    std::unique_ptr<juce::Slider> juce__slider4;
    std::unique_ptr<juce::Label> juce__label6;
    std::unique_ptr<juce::Slider> juce__slider5;
    std::unique_ptr<juce::Label> juce__label7;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Flanger)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

