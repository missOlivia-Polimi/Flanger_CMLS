/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
FlangerAudioProcessor::FlangerAudioProcessor()
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

FlangerAudioProcessor::~FlangerAudioProcessor()
{
}

//==============================================================================
void FlangerAudioProcessor::setLFOFrequency(float value)
{
    lfoFreq = value;
}
void FlangerAudioProcessor::setLFOWidth(float value)
{
    lfoWidth = value;
}

void FlangerAudioProcessor::setFeedback(float value)
{
    feedback = value;
}

void FlangerAudioProcessor::setDelaySec(float value)
{
    delaySec = value;
}

void FlangerAudioProcessor::setDepth(float value)
{
    depth = value;
}

void FlangerAudioProcessor::setMaxDelay(float value)
{
    maxDelaySec = value;
    
    setBufferSize();
}

void FlangerAudioProcessor::setBufferSize()
{
    const int maxBufferSize = int(computeMaxTotalDelaySamples(maxDelaySec)) + 1;

    delayBuffer.setSize(getTotalNumOutputChannels(), maxBufferSize);
    delayBuffer.clear();
}
//==============================================================================
const juce::String FlangerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FlangerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FlangerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FlangerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FlangerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FlangerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FlangerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FlangerAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String FlangerAudioProcessor::getProgramName (int index)
{
    return {};
}

void FlangerAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void FlangerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // 10) Initialize the variables that we are going to need in processBlock function:
    // the buffer, the write and read pointer, the delay value
     
    //TODO: check buffer size and pointers
    this->sampleRate = sampleRate;
    
    setBufferSize();
     
    writePointer = 0;
}

void FlangerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FlangerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void FlangerAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    //==============================================================================
    // Flanger effect implementation
    int numSamples = buffer.getNumSamples();
    
    float* channelOutDataL = buffer.getWritePointer(0);
    float* channelOutDataR = buffer.getWritePointer(1);
    
    const float* channelInDataL = buffer.getReadPointer(0);
    const float* channelInDataR = buffer.getReadPointer(1);
    
    const float* channelInData = buffer.getReadPointer(0);
    
    const auto curFeedback = feedback / 100.0f;
    const auto curDepth = depth / 100.0f;
    
    const int delayBufCurrentLength = computeMaxTotalDelaySamples(delaySec);
    for (int i = 0; i < numSamples; ++i)
    {
        const float inLeft = channelInDataL[i];
        const float inRight = channelInDataR[i];
        
        float interpolatedSampleLeft = 0.0f;
        float interpolatedSampleRight = 0.0f;
        // Recalculate the read pointer position with respect to the write pointer.
        float currentDelay = 0.5f * getLfoWidthSamples(lfoWidth) * (1 + sinf(2.0 * M_PI * ph));
        
        //TODO: not sure about subtracting 3 samples
        // Subtract 3 samples to the delay pointer to make sure we have enough previous samples to interpolate with
        float readPointer = fmodf((float)writePointer - (currentDelay) +
                                  (float)delayBufCurrentLength - 3.0, (float)delayBufCurrentLength);
        
        //TODO: not sure if it's possible to get negative readPointer, anyway, better to check
        if (readPointer < 0)
            readPointer += delayBufCurrentLength;
        
        // Use linear interpolation to read a fractional index into the buffer.
        float fraction = readPointer - floorf(readPointer);
    
        int previousSample = (int)floorf(readPointer);
        int nextSample = (previousSample + 1) % delayBufCurrentLength;
    
        interpolatedSampleLeft = fraction*delayBuffer.getSample(0, nextSample) + (1.0f-fraction)*delayBuffer.getSample(0, previousSample);
        interpolatedSampleRight = fraction*delayBuffer.getSample(1, nextSample) + (1.0f-fraction)*delayBuffer.getSample(1, previousSample);
        
        // Store the current information in the delay buffer.
        delayBuffer.setSample(0, writePointer, inLeft + (interpolatedSampleLeft * curFeedback));
        delayBuffer.setSample(1, writePointer, inRight + (interpolatedSampleRight * curFeedback));
        
        // Increment the write pointer at a constant rate.
        if (++writePointer >= delayBufCurrentLength)
        {
            writePointer = 0;
        }
        // Store the output in the buffer, replacing the input
        channelOutDataL[i] = inLeft + curDepth * interpolatedSampleLeft;
        channelOutDataR[i] = inRight + curDepth * interpolatedSampleRight;
        
        // Update the LFO phase, keeping it in the range 0-1
        ph += lfoFreq / sampleRate;
        if(ph >= 1.0)
        {
            ph -= 1.0;
        }
    }
}

float FlangerAudioProcessor::getLfoWidthSamples(float lfoWidth) const
{
    // Match LFO width to number of samples
    if (lfoWidth > 100.0f)
        lfoWidth = 100.0f;
    
    if (lfoWidth < 0)
        lfoWidth = 0.0f;
    
    float lfoInSec = juce::jmap(lfoWidth, 0.f, 100.f, 0.001f, 0.010f);
    return lfoInSec * sampleRate;
}

float FlangerAudioProcessor::computeMaxTotalDelaySamples(float minDelaySec) const
{
    const auto minDelaySamples = minDelaySec * sampleRate;
    const auto maxCurrentDelay = getLfoWidthSamples(100);
    
    const auto maxTotalDelay = minDelaySamples + maxCurrentDelay;
    return maxTotalDelay;
}

//==============================================================================
bool FlangerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* FlangerAudioProcessor::createEditor()
{
    return new FlangerAudioProcessorEditor (*this);
}

//==============================================================================
void FlangerAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FlangerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FlangerAudioProcessor();
}
