/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class FlangerAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    FlangerAudioProcessor();
    ~FlangerAudioProcessor() override;

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
    
    //==============================
    void setLFOFrequency(float);
    void setLFOWidth(float);
    
    void setFeedback(float);
    void setDelaySec(float);
    void setDepth(float);
    void setMaxDelay(float);
    void setBufferSize();

    float getLfoWidthSamples(float) const;
    float computeMaxTotalDelaySamples(float) const;
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FlangerAudioProcessor)
    
    float lfoFreq = 0.0f;     // Frequency of the LFO
    float lfoWidth = 0.0f;    // Width of the LFO
    float feedback = 0.0f;    // Flanger feedback
    float delaySec = 0.0f;    // Delay in seconds
    float depth = 0.0f;       // Flanger depth
    float sampleRate = 44100;   // Current sample rate
    
    float ph = 0.0f;         // Current LFO phase, always between 0-1
    float maxDelaySec = 0.0f; // Max delay in seconds (actually, it's not real delay maximum but the upper value of the knob )
    
    juce::AudioSampleBuffer delayBuffer;
    int writePointer;
    //int readPointer;
};
