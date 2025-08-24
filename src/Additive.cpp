#include "DistrhoPlugin.hpp"
#include "pocketfft_hdronly.h"
#include <algorithm>
#include "parameterNames.hpp"
#include <iostream>
#include "AudioFile.h"

#define sampleRate 48000
#define maxWaveformLength 3072000
START_NAMESPACE_DISTRHO

class Additive : public Plugin {
    public:
        Additive() : Plugin(kParameterCount, 0, 0), Gain(0.0f) {position=frame=0; waveformLength=sampleRate;
            sampleLength=0;
          //  for(int i=0;i<waveformLength;i++){
            //    waveform[i]=sin(2*M_PI  *i/800);
        //    }
        calculate();



        }
    protected:


        const char *getLabel() const override { return "Additive"; }
        const char *getDescription() const override {
            return "Additive.";
        }
        const char *getMaker() const override { return "saber"; }
        const char *getLicense() const override { return "MIT"; }
        uint32_t getVersion() const override { return d_version(1,0,0); }
        int64_t getUniqueId() const override { 
            return d_cconst('A','D','D','T');
        }
        void initProgramName 	( 	uint32_t  	index,
		String &  	programName ){
            programName="foo";
        } 	
    void initParameter (uint32_t index, Parameter& parameter) override {
        switch (index) {
            case kGain:
                parameter.name = "Gain";
                parameter.symbol = "Gain";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume24hz:
                parameter.name = "Volume 24hz";
                parameter.symbol = "Volume24hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume25hz:
                parameter.name = "Volume 25hz";
                parameter.symbol = "Volume25hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume26hz:
                parameter.name = "Volume 26hz";
                parameter.symbol = "Volume26z";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume27hz:
                parameter.name = "Volume 27hz";
                parameter.symbol = "Volume27hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume28hz:
                parameter.name = "Volume 28hz";
                parameter.symbol = "Volume28hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume29hz:
                parameter.name = "Volume 29hz";
                parameter.symbol = "Volume29hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume30hz:
                parameter.name = "Volume 30hz";
                parameter.symbol = "Volume30hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume31hz:
                parameter.name = "Volume 31hz";
                parameter.symbol = "Volume31hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume32hz:
                parameter.name = "Volume 32hz";
                parameter.symbol = "Volume32hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume33hz:
                parameter.name = "Volume 33hz";
                parameter.symbol = "Volume33hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume34hz:
                parameter.name = "Volume 34hz";
                parameter.symbol = "Volume34hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume35hz:
                parameter.name = "Volume 35hz";
                parameter.symbol = "Volume35hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume36hz:
                parameter.name = "Volume 36hz";
                parameter.symbol = "Volume36hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume37hz:
                parameter.name = "Volume 37hz";
                parameter.symbol = "Volume37hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume38hz:
                parameter.name = "Volume 38hz";
                parameter.symbol = "Volume38hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume39hz:
                parameter.name = "Volume 39hz";
                parameter.symbol = "Volume39hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume40hz:
                parameter.name = "Volume 40hz";
                parameter.symbol = "Volume40hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume41hz:
                parameter.name = "Volume 41hz";
                parameter.symbol = "Volume41hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume42hz:
                parameter.name = "Volume 42hz";
                parameter.symbol = "Volume42hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume43hz:
                parameter.name = "Volume 43hz";
                parameter.symbol = "Volume43hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume44hz:
                parameter.name = "Volume 44hz";
                parameter.symbol = "Volume44hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume45hz:
                parameter.name = "Volume 45hz";
                parameter.symbol = "Volume45hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume46hz:
                parameter.name = "Volume 46hz";
                parameter.symbol = "Volume46hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume47hz:
                parameter.name = "Volume 47hz";
                parameter.symbol = "Volume47hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase24hz:
                parameter.name = "Phase 24hz";
                parameter.symbol = "Phase24hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase25hz:
                parameter.name = "Phase 25hz";
                parameter.symbol = "Phase25hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase26hz:
                parameter.name = "Phase 26hz";
                parameter.symbol = "Phase26z";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase27hz:
                parameter.name = "Phase 27hz";
                parameter.symbol = "Phase27hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase28hz:
                parameter.name = "Phase 28hz";
                parameter.symbol = "Phase28hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase29hz:
                parameter.name = "Phase 29hz";
                parameter.symbol = "Phase29hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase30hz:
                parameter.name = "Phase 30hz";
                parameter.symbol = "Phase30hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase31hz:
                parameter.name = "Phase 31hz";
                parameter.symbol = "Phase31hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase32hz:
                parameter.name = "Phase 32hz";
                parameter.symbol = "Phase32hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase33hz:
                parameter.name = "Phase 33hz";
                parameter.symbol = "Phase33hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase34hz:
                parameter.name = "Phase 34hz";
                parameter.symbol = "Phase34hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase35hz:
                parameter.name = "Phase 35hz";
                parameter.symbol = "Phase35hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase36hz:
                parameter.name = "Phase 36hz";
                parameter.symbol = "Phase36hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase37hz:
                parameter.name = "Phase 37hz";
                parameter.symbol = "Phase37hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase38hz:
                parameter.name = "Phase 38hz";
                parameter.symbol = "Phase38hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase39hz:
                parameter.name = "Phase 39hz";
                parameter.symbol = "Phase39hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase40hz:
                parameter.name = "Phase 40hz";
                parameter.symbol = "Phase40hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase41hz:
                parameter.name = "Phase 41hz";
                parameter.symbol = "Phase41hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase42hz:
                parameter.name = "Phase 42hz";
                parameter.symbol = "Phase42hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase43hz:
                parameter.name = "Phase 43hz";
                parameter.symbol = "Phase43hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase44hz:
                parameter.name = "Phase 44hz";
                parameter.symbol = "Phase44hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase45hz:
                parameter.name = "Phase 45hz";
                parameter.symbol = "Phase45hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase46hz:
                parameter.name = "Phase 46hz";
                parameter.symbol = "Phase46hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase47hz:
                parameter.name = "Phase 47hz";
                parameter.symbol = "Phase47hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOctave:
                parameter.name = "Octave";
                parameter.symbol = "Octave";
                parameter.ranges.def = 0;
                parameter.ranges.min = -6;
                parameter.ranges.max = 6;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPitchCoarse:
                parameter.name = "Pitch Coarse";
                parameter.symbol = "PitchCoarse";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -48.0f;
                parameter.ranges.max =48.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPitchFine:
                parameter.name = "Pitch Fine";
                parameter.symbol = "PitchFine";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -12.0f;
                parameter.ranges.max =12.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kSampleOffset:
                parameter.name = "Sanple Offset";
                parameter.symbol = "SampleOffset";
                parameter.ranges.def = 0;
                parameter.ranges.min = 0;
                parameter.ranges.max = 1000;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kSampleGain:
                parameter.name = "Sample Gain";
                parameter.symbol = "SampleGain";
                parameter.ranges.def = 1.0f;
                parameter.ranges.min = 0.0;
                parameter.ranges.max =12.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
                        case kDrive:
                parameter.name = "Drive";
                parameter.symbol = "Drive";
                parameter.ranges.def = 100.0f;
                parameter.ranges.min = 1.0;
                parameter.ranges.max =200.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
                                        case kAutoCalculate:
                parameter.name = "AutoCalculate";
                parameter.symbol = "AutoCalculate";
                parameter.ranges.def = 0;
                parameter.ranges.min = 0;
                parameter.ranges.max =2;
                break;

        }
    }
    float getParameterValue(uint32_t index) const override {
        switch (index) {
        case kGain:
            return Gain;
        case kVolume24hz:
            return Volume24hz;
        case kVolume25hz:
            return Volume25hz;
        case kVolume26hz:
            return Volume26hz;
        case kVolume27hz:
            return Volume27hz;
        case kVolume28hz:
            return Volume28hz;
        case kVolume29hz:
            return Volume29hz;
        case kVolume30hz:
            return Volume30hz;
        case kVolume31hz:
            return Volume31hz;
        case kVolume32hz:
            return Volume32hz;
        case kVolume33hz:
            return Volume33hz;
        case kVolume34hz:
            return Volume34hz;
        case kVolume35hz:
            return Volume35hz;
        case kVolume36hz:
            return Volume36hz;
        case kVolume37hz:
            return Volume37hz;
        case kVolume38hz:
            return Volume38hz;
        case kVolume39hz:
            return Volume39hz;
        case kVolume40hz:
            return Volume40hz;
        case kVolume41hz:
            return Volume41hz;
        case kVolume42hz:
            return Volume42hz;
        case kVolume43hz:
            return Volume43hz;
        case kVolume44hz:
            return Volume44hz;
        case kVolume45hz:
            return Volume45hz;
        case kVolume46hz:
            return Volume46hz;
        case kVolume47hz:
            return Volume47hz;

        case kPhase24hz:
            return Phase24hz;
        case kPhase25hz:
            return Phase25hz;
        case kPhase26hz:
            return Phase26hz;
        case kPhase27hz:
            return Phase27hz;
        case kPhase28hz:
            return Phase28hz;
        case kPhase29hz:
            return Phase29hz;
        case kPhase30hz:
            return Phase30hz;
        case kPhase31hz:
            return Phase31hz;
        case kPhase32hz:
            return Phase32hz;
        case kPhase33hz:
            return Phase33hz;
        case kPhase34hz:
            return Phase34hz;
        case kPhase35hz:
            return Phase35hz;
        case kPhase36hz:
            return Phase36hz;
        case kPhase37hz:
            return Phase37hz;
        case kPhase38hz:
            return Phase38hz;
        case kPhase39hz:
            return Phase39hz;
        case kPhase40hz:
            return Phase40hz;
        case kPhase41hz:
            return Phase41hz;
        case kPhase42hz:
            return Phase42hz;
        case kPhase43hz:
            return Phase43hz;
        case kPhase44hz:
            return Phase44hz;
        case kPhase45hz:
            return Phase45hz;
        case kPhase46hz:
            return Phase46hz;
        case kPhase47hz:
            return Phase47hz;


        case kOctave:
            return Octave;
        case kPitchCoarse:
            return PitchCoarse;
        case kPitchFine:
            return PitchFine;
        case kSampleOffset:
            return SampleOffset;
        case kSampleGain:
            return SampleGain;
                    case kDrive:
            return Drive;
        case kAutoCalculate:
            return AutoCalculate;
        }

    }

    void setParameterValue(uint32_t index, float value) override {
        switch (index) {
         case kGain:
            Gain=value;break;
        case kVolume24hz:
             Volume24hz=value;break;
        case kVolume25hz:
             Volume25hz=value;break;
        case kVolume26hz:
             Volume26hz=value;break;
        case kVolume27hz:
             Volume27hz=value;break;
        case kVolume28hz:
             Volume28hz=value;break;
        case kVolume29hz:
             Volume29hz=value;break;
        case kVolume30hz:
             Volume30hz=value;break;
        case kVolume31hz:
             Volume31hz=value;break;
        case kVolume32hz:
             Volume32hz=value;break;
        case kVolume33hz:
             Volume33hz=value;break;
        case kVolume34hz:
             Volume34hz=value;break;
        case kVolume35hz:
             Volume35hz=value;break;
        case kVolume36hz:
             Volume36hz=value;break;
        case kVolume37hz:
             Volume37hz=value;break;
        case kVolume38hz:
             Volume38hz=value;break;
        case kVolume39hz:
             Volume39hz=value;break;
        case kVolume40hz:
             Volume40hz=value;break;
        case kVolume41hz:
             Volume41hz=value;break;
        case kVolume42hz:
             Volume42hz=value;break;
        case kVolume43hz:
             Volume43hz=value;break;
        case kVolume44hz:
             Volume44hz=value;break;
        case kVolume45hz:
             Volume45hz=value;break;
        case kVolume46hz:
             Volume46hz=value;break;
        case kVolume47hz:
             Volume47hz=value;break;
        case kPhase24hz:
             Phase24hz=value;break;
        case kPhase25hz:
             Phase25hz=value;break;
        case kPhase26hz:
             Phase26hz=value;break;
        case kPhase27hz:
             Phase27hz=value;break;
        case kPhase28hz:
             Phase28hz=value;break;
        case kPhase29hz:
             Phase29hz=value;break;
        case kPhase30hz:
             Phase30hz=value;break;
        case kPhase31hz:
             Phase31hz=value;break;
        case kPhase32hz:
             Phase32hz=value;break;
        case kPhase33hz:
             Phase33hz=value;break;
        case kPhase34hz:
             Phase34hz=value;break;
        case kPhase35hz:
             Phase35hz=value;break;
        case kPhase36hz:
             Phase36hz=value;break;
        case kPhase37hz:
             Phase37hz=value;break;
        case kPhase38hz:
             Phase38hz=value;break;
        case kPhase39hz:
             Phase39hz=value;break;
        case kPhase40hz:
             Phase40hz=value;break;
        case kPhase41hz:
             Phase41hz=value;break;
        case kPhase42hz:
             Phase42hz=value;break;
        case kPhase43hz:
             Phase43hz=value;break;
        case kPhase44hz:
             Phase44hz=value;break;
        case kPhase45hz:
             Phase45hz=value;break;
        case kPhase46hz:
             Phase46hz=value;break;
        case kPhase47hz:
             Phase47hz=value;break;
        
   
        case kOctave:
             Octave=(int)value;break;
        case kPitchCoarse:
            PitchCoarse=value;break;
        case kPitchFine:
            PitchFine=value;break;
        case kSampleOffset:
            SampleOffset=(int)value;break;
        case kSampleGain:
            SampleGain=value;break;
                    case kDrive:
            Drive=value; break;
        case kAutoCalculate:
            AutoCalculate=value;break;

        }
        if(AutoCalculate>1){
            calculate();
        }

    }
    void setState(const char *key, const char *value){
        if(strcmp(key, "ui_plugin_load_sample")==0){
                    SampleFilePath=value;
            std::cout<<"Sample loaded: "<<value<<"\n\n";
            audioFile.load (value);
            int numChannels = audioFile.getNumChannels();
            if( numChannels==2){
            sampleLength = audioFile.getNumSamplesPerChannel();

            }
            else{
                sampleLength=0;
            }
        }

       
       calculate();
    }
    float clamp(float a){
        return std::max<float>(-1.0, std::min<float>(1.0,a));
    }
        float getPitch(){
            return pow(2,Octave+PitchCoarse/12+PitchFine/12);
        }
        void activate() override {
            calculate();
        }

    void calculate(){
        waveformLength=(int)(sampleRate/getPitch());
        
        std::cout<<waveformLength;
        std::vector<std::complex<float>> data_out(waveformLength);
        std::vector<std::complex<float>> data_in(waveformLength);
                pocketfft::shape_t shape_in{1};                                              // dimensions of the input shape
        pocketfft::stride_t stride_in{1};                    // must have the size of each element. Must have size() equal to shape_in.size()
        pocketfft::stride_t stride_out{1}; // must have the size of each element. Must have size() equal to shape_in.size()
                    stride_in[0]=stride_out[0]=sizeof(std::complex<float>);
      //  pocketfft::shape_t axes{1};                                                  // 0 to shape.size()-1 inclusive
        bool forward{ pocketfft::BACKWARD };                                            // FORWARD or BACKWARD
                                                                // input data (reals)
                              // output data (FFT(input))
        float fct{ 1.0f };    // scaling factor
        shape_in[0]=waveformLength;
          pocketfft::shape_t axes;

          axes.push_back(0);

          float total=0;
         for (int i=0;i<waveformLength;i++){
               data_in[i]=std::polar<float>(0.0f,0.0f);
           }



        //   // std::vector<std::complex<float>> data_out(sampleRate);
          
        //   // frequencies[800]=1;
        //    total =Volume24hz+Volume25hz+Volume26hz+Volume27hz+Volume28hz+Volume29hz+Volume30hz+Volume31hz+Volume32hz+Volume33hz+
        // Volume34hz+Volume35hz+Volume36hz+Volume37hz+Volume38hz+Volume39hz+Volume40hz+Volume41hz+Volume42hz+Volume43hz+
        // Volume44hz+Volume45hz+Volume46hz+Volume47hz;
        
            data_in[24]=std::polar<float>(Volume24hz, Phase24hz);
            data_in[25]=std::polar<float>(Volume25hz, Phase25hz);
            data_in[26]=std::polar<float>(Volume26hz, Phase26hz);
            data_in[27]=std::polar<float>(Volume27hz, Phase27hz);
            data_in[28]=std::polar<float>(Volume28hz, Phase28hz);
            data_in[29]=std::polar<float>(Volume29hz, Phase29hz);
            data_in[30]=std::polar<float>(Volume30hz, Phase30hz);
            data_in[31]=std::polar<float>(Volume31hz, Phase31hz);
            data_in[32]=std::polar<float>(Volume32hz, Phase32hz);
            data_in[33]=std::polar<float>(Volume33hz, Phase33hz);
            data_in[34]=std::polar<float>(Volume34hz, Phase34hz);
            data_in[35]=std::polar<float>(Volume35hz, Phase35hz);
            data_in[36]=std::polar<float>(Volume36hz, Phase36hz);
            data_in[37]=std::polar<float>(Volume37hz, Phase37hz);
            data_in[38]=std::polar<float>(Volume38hz, Phase38hz);
            data_in[39]=std::polar<float>(Volume39hz, Phase39hz);
            data_in[40]=std::polar<float>(Volume40hz, Phase40hz);
            data_in[41]=std::polar<float>(Volume41hz, Phase41hz);
            data_in[42]=std::polar<float>(Volume42hz, Phase42hz);
            data_in[43]=std::polar<float>(Volume43hz, Phase43hz);
            data_in[44]=std::polar<float>(Volume44hz, Phase44hz);
            data_in[45]=std::polar<float>(Volume45hz, Phase45hz);
            data_in[46]=std::polar<float>(Volume46hz, Phase46hz);
            data_in[47]=std::polar<float>(Volume47hz, Phase47hz);
            for(int i=SampleOffset;i<sampleLength+SampleOffset&&i<=waveformLength/2-1;i++){
                data_in[i]/=100;//weirdness
                if(audioFile.samples[0][i-SampleOffset]+1>0)
                    data_in[i]+=std::polar<float>((audioFile.samples[0][i-SampleOffset]+1)*SampleGain/2,audioFile.samples[1][i-SampleOffset]*M_PI);
        }
        for (int i=1;i<waveformLength/2-1;i++){
         
             if(i) data_in[waveformLength-i]=data_in[i];
          }
          for (int i=1;i<waveformLength;i++){
         
            total+=std::abs(data_in[i]);
          }
                    if(total<1)total=1;
          float recip=1/total;
                    for (int i=1;i<waveformLength;i++){
         //weird effect
            data_in[i]*=recip*Drive;//100
          }

          std::cout<<"foo";
          pocketfft::c2c(
              shape_in,
              stride_in,
              stride_out,
              axes,
              forward,
                  data_in.data(),
                                 data_out.data(),
                                 fct
          );
          std::cout<<"bar";
          for(int i=0;i<waveformLength;i++){
              waveform[i]=data_out[i].real();
              //waveform[i]=0;
          }
          safeWaveformLength=waveformLength;
          std::cout<<"baz"<<"\n\n";
    }
       void run(const float **inputs, float **outputs, uint32_t frames) override {
        const float *const in = inputs[0];
        float *const out = outputs[0];
        //out[0]=(fmod(pow(0.5,0.5)+position*M_PI,2)-1)*gain;
        // for(int i=0;i<waveformLength;i++){
        //     waveform[i]=sin(2*M_PI  *i*PitchRange/800);
        // }

        for (uint32_t i = 0; i < frames; i++) {
            //calculate();
            //out[i] = in[i] +1;
            //out[i]=rand()*gain/100000000;
            //out[i]= calculate(in[i])/2;

            out[i]=waveform[position]*Gain;

            position+=1;
          while(position>=std::min(waveformLength,safeWaveformLength)){
                position-=std::min(waveformLength,safeWaveformLength);
           }
            //position+=1;
            //out[i]=sin(i/15)/;

        }
        // while(position>2*M_PI){
        //     position-=2*M_PI;
        // }
        frame++;
    }
    private:
        float Gain,
        Volume24hz,
    Volume25hz,
    Volume26hz,
    Volume27hz,
    Volume28hz,
    Volume29hz,
    Volume30hz,
    Volume31hz,
    Volume32hz,
    Volume33hz,
    Volume34hz,
    Volume35hz,
    Volume36hz,
    Volume37hz,
    Volume38hz,
    Volume39hz,
    Volume40hz,
    Volume41hz,
    Volume42hz,
    Volume43hz,
    Volume44hz,
    Volume45hz,
    Volume46hz,
    Volume47hz,
    Phase24hz,
    Phase25hz,
    Phase26hz,
    Phase27hz,
    Phase28hz,
    Phase29hz,
    Phase30hz,
    Phase31hz,
    Phase32hz,
    Phase33hz,
    Phase34hz,
    Phase35hz,
    Phase36hz,
    Phase37hz,
    Phase38hz,
    Phase39hz,
    Phase40hz,
    Phase41hz,
    Phase42hz,
    Phase43hz,
    Phase44hz,
    Phase45hz,
    Phase46hz,
    Phase47hz,
    PitchCoarse,
    PitchFine,
    SampleGain,
    Drive,
    AutoCalculate;
    int Octave;
        float waveform[maxWaveformLength];
        int waveformLength,safeWaveformLength;
                int position;
        int frame;
        std::string SampleFilePath;
        int sampleLength, SampleOffset;

AudioFile<double> audioFile;

        DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Additive);
};


Plugin* createPlugin() { return new Additive(); }

END_NAMESPACE_DISTRHO

