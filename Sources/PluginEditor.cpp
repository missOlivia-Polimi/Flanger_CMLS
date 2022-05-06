/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Flanger.h"

//==============================================================================
FlangerAudioProcessorEditor::FlangerAudioProcessorEditor (FlangerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    flangerWindow = std::make_unique<Flanger>();
    
    flangerWindow->setLFOFreqChangedCallback( [this](float value) {audioProcessor.setLFOFrequency(value);});
    flangerWindow->setLFOWidthChangedCallback( [this](float value) {audioProcessor.setLFOWidth(value);});
    
    flangerWindow->setFeedbackChangedCallback( [this](float value) {audioProcessor.setFeedback(value);});
    flangerWindow->setDelayChangedCallback( [this](float value) {audioProcessor.setDelaySec(value / 1000.0f);});
    flangerWindow->setDepthChangedCallback( [this](float value) {audioProcessor.setDepth(value);});
    audioProcessor.setMaxDelay(flangerWindow->getMaxDelay());
    
    addAndMakeVisible (flangerWindow.get());
    
    setSize (700, 300);
}

FlangerAudioProcessorEditor::~FlangerAudioProcessorEditor()
{
}

//==============================================================================
void FlangerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void FlangerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
