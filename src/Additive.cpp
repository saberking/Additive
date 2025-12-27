#include "DistrhoPlugin.hpp"
#include "pocketfft_hdronly.h"
#include <algorithm>
#include <iostream>
#include "AudioFile.h"
#include <fstream>

#define DEBUG 0

#define sampleRate 48000
#define maxWaveformLength 6144000
namespace foo{
#include "parameterNames.hpp"
}


START_NAMESPACE_DISTRHO

enum MyFileTypes{
    noFileType,
    wavFileType,
    csvFileType,
    fileTypeCount
};
  
class Additive : public Plugin {
    public:
        Additive() : Plugin(kParameterCount, 0, 1), Gain(0.0f) {
            position=envelopePosition=floatPosition=0; 
            waveformLength=sampleRate;
            sampleLength=0;
            ready=false;

            for(int i=0;i<maxWaveformLength;i++){
                waveform.push_back(0.0f);
            }
            Octave=0;
            PitchCoarse=0;
            PitchFine=0;
        Volume24hz=0;
    Volume25hz=0;
    Volume26hz=0;
    Volume27hz=0;
    Volume28hz=0;
    Volume29hz=0;
    Volume30hz=0;
    Volume31hz=0;
    Volume32hz=0;
    Volume33hz=0;
    Volume34hz=0;
    Volume35hz=0;
    Volume36hz=0;
    Volume37hz=0;
    Volume38hz=0;
    Volume39hz=0;
    Volume40hz=0;
    Volume41hz=0;
    Volume42hz=0;
    Volume43hz=0;
    Volume44hz=0;
    Volume45hz=0;
    Volume46hz=0;
    Volume47hz=0;
    Phase24hz=0;
    Phase25hz=0;
    Phase26hz=0;
    Phase27hz=0;
    Phase28hz=0;
    Phase29hz=0;
    Phase30hz=0;
    Phase31hz=0;
    Phase32hz=0;
    Phase33hz=0;
    Phase34hz=0;
    Phase35hz=0;
    Phase36hz=0;
    Phase37hz=0;
    Phase38hz=0;
    Phase39hz=0;
    Phase40hz=0;
    Phase41hz=0;
    Phase42hz=0;
    Phase43hz=0;
    Phase44hz=0;
    Phase45hz=0;
    Phase46hz=0;
    Phase47hz=0;
    PitchCoarse=0;
    PitchFine=0;
    SampleGain=0;
    Drive=0;
    Freeze=0;
   CsvRadiusIndex=0; 
   CsvArgumentIndex=0;
    Attack=0;
    Decay=0;
    Sustain=0.0f;
    Release=0;
    envelopeStage=2;
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
                parameter.symbol = "Gain";
                parameter.ranges.def = 1.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume24hz:
                parameter.symbol = "Volume24hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume25hz:
                parameter.symbol = "Volume25hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume26hz:
                parameter.symbol = "Volume26z";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume27hz:
                parameter.symbol = "Volume27hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume28hz:
                parameter.symbol = "Volume28hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume29hz:
                parameter.symbol = "Volume29hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume30hz:
                parameter.symbol = "Volume30hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume31hz:
                parameter.symbol = "Volume31hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume32hz:
                parameter.symbol = "Volume32hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume33hz:
                parameter.symbol = "Volume33hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume34hz:
                parameter.symbol = "Volume34hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume35hz:
                parameter.symbol = "Volume35hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume36hz:
                parameter.symbol = "Volume36hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume37hz:
                parameter.symbol = "Volume37hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume38hz:
                parameter.symbol = "Volume38hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume39hz:
                parameter.symbol = "Volume39hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume40hz:
                parameter.symbol = "Volume40hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume41hz:
                parameter.symbol = "Volume41hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume42hz:
                parameter.symbol = "Volume42hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume43hz:
                parameter.symbol = "Volume43hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume44hz:
                parameter.symbol = "Volume44hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume45hz:
                parameter.symbol = "Volume45hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume46hz:
                parameter.symbol = "Volume46hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kVolume47hz:
                parameter.symbol = "Volume47hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase24hz:
                parameter.symbol = "Phase24hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase25hz:
                parameter.symbol = "Phase25hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase26hz:
                parameter.symbol = "Phase26z";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase27hz:
                parameter.symbol = "Phase27hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase28hz:
                parameter.symbol = "Phase28hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase29hz:
                parameter.symbol = "Phase29hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase30hz:
                parameter.symbol = "Phase30hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase31hz:
                parameter.symbol = "Phase31hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase32hz:
                parameter.symbol = "Phase32hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase33hz:
                parameter.symbol = "Phase33hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase34hz:
                parameter.symbol = "Phase34hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase35hz:
                parameter.symbol = "Phase35hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase36hz:
                parameter.symbol = "Phase36hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase37hz:
                parameter.symbol = "Phase37hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase38hz:
                parameter.symbol = "Phase38hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase39hz:
                parameter.symbol = "Phase39hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase40hz:
                parameter.symbol = "Phase40hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase41hz:
                parameter.symbol = "Phase41hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase42hz:
                parameter.symbol = "Phase42hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase43hz:
                parameter.symbol = "Phase43hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase44hz:
                parameter.symbol = "Phase44hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase45hz:
                parameter.symbol = "Phase45hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase46hz:
                parameter.symbol = "Phase46hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPhase47hz:
                parameter.symbol = "Phase47hz";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOctave:
                parameter.symbol = "Octave";
                parameter.ranges.def = 0;
                parameter.ranges.min = -10;
                parameter.ranges.max = 10;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPitchCoarse:
                parameter.symbol = "PitchCoarse";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max =48.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPitchFine:
                parameter.symbol = "PitchFine";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max =12.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kSampleOffset:
                parameter.symbol = "SampleOffset";
                parameter.ranges.def = 0;
                parameter.ranges.min = 0;
                parameter.ranges.max = 1000;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kSampleGain:
                parameter.symbol = "SampleGain";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0;
                parameter.ranges.max =2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
                        case kDrive:
                parameter.symbol = "Drive";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = 0.0;
                parameter.ranges.max =2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
                                        case kFreeze:
                parameter.symbol = "Freeze";
                parameter.ranges.def = 0;
                parameter.ranges.min = 0;
                parameter.ranges.max =2;
                break;
                                        case kCsvRadiusIndex:
                parameter.symbol = "CSVRadiusIndex";
                parameter.ranges.def = 0;
                parameter.ranges.min = 0;
                parameter.ranges.max =31;
                break;
                                        case kCsvArgumentIndex:
                parameter.symbol = "CSVArgumentIndex";
                parameter.ranges.def = 0;
                parameter.ranges.min = 0;
                parameter.ranges.max =31;
                break;
            case kAttack:
                parameter.symbol = "Attack";
                parameter.ranges.def = 4800;
                parameter.ranges.min = 0;
                parameter.ranges.max =48000;
                parameter.hints=kParameterIsAutomatable;
                break;
                        case kDecay:
                parameter.symbol = "Decay";
                parameter.ranges.def = 4800;
                parameter.ranges.min = 0;
                parameter.ranges.max =48000;
                                parameter.hints=kParameterIsAutomatable;

                break;
                        case kSustain:
                parameter.symbol = "Sustain";
                parameter.ranges.def = 0.5f;
                parameter.ranges.min = 0.0f;
                parameter.ranges.max =2.0f;
                                parameter.hints=kParameterIsAutomatable;

                break;
                            case kRelease:
                parameter.symbol = "Release";
                parameter.ranges.def = 4800;
                parameter.ranges.min = 0;
                parameter.ranges.max =48000;
                                parameter.hints=kParameterIsAutomatable;

                break;
        }
                        parameter.name = foo::getParameterName(index);

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
        case kFreeze:
            return Freeze;
        case kCsvRadiusIndex:
            return CsvRadiusIndex;
        case kCsvArgumentIndex:
            return CsvArgumentIndex;
        case kAttack:
            return Attack;
        case kDecay:
            return Decay;
        case kSustain:
            return Sustain;
        case kRelease:
            return Release;
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
        case kFreeze:
            Freeze=value;break;
        case kCsvRadiusIndex:
            CsvRadiusIndex=(int)value;break;
        case kCsvArgumentIndex:
            CsvArgumentIndex=(int)value;break;
        case kAttack:
            Attack=(int)value;break;
        case kDecay:
            Decay=(int)value;break;
        case kSustain:
            Sustain=value;
            break;
        case kRelease:
            Release=(int)value;
            break;
        }
        if(DEBUG)std::cout<<"Param updated"<<Freeze<<"\n"<<index<<"    "<<value<<"\n"<<kFreeze<<"should"<<"\n";
        paramUpdated=true;
                if(paramUpdated&&Freeze<1&&index!=kGain) calculate(index);

    }
    int determineFileType(const char *value){
        if(value[strlen(value)-4]=='.'&&value[strlen(value)-3]=='c'&&value[strlen(value)-2]=='s'&&value[strlen(value)-1]=='v'){
            return csvFileType;
        }else if(value[strlen(value)-4]=='.'&&value[strlen(value)-3]=='w'&&value[strlen(value)-2]=='a'&&value[strlen(value)-1]=='v'){
            return wavFileType;
        }else{
            return noFileType;
        }
    }
    bool loadFile(const char *value){
        int fileType=determineFileType(value);
        switch(fileType){
            case wavFileType:
                loadWavFile(value);
                calculate();
                return true;
                break;
            case csvFileType:
                parseCsv(value);
                calculate();
                return true;
                break;
            default:
                return false;
                break;
        }

    }
    void loadWavFile(const char *value){
        audioFile.load (value);
                //intAudioFile.load(value);
                int numChannels = audioFile.getNumChannels();
                if( numChannels==2){
                    sampleLength = audioFile.getNumSamplesPerChannel();
                    csvRadius=audioFile.samples[0];
                    csvArgument=audioFile.samples[1];
                }else if(numChannels==1){
                    sampleLength = audioFile.getNumSamplesPerChannel();
                    csvRadius=audioFile.samples[0];
                    csvArgument=audioFile.samples[0];
                }
    }
    void setState  (const char *key, const char *value) override {
        if(strcmp(key, "ui_plugin_sample_filepath")==0){
            std::cout<<"about toload: "<<value<<"\n\n";
            if(!loadFile(value))sampleLength=0;
            else{
                filePath=value;
            }

            std::cout<<"state set!!!"<<"\n\n";
        }else if(strcmp(key, "ui_plugin_calculate")==0){
            std::cout<<"calculatebuttonpressed"<<"\n\n";
                    calculate();

        }else if(strcmp(key, "ui_plugin_save_sample")==0){
            saveSample(value);
        }
    }
String getState(const char *key) const override
{
    String retString = String("undefined state");

std::cout<<"getstate"<<retString<<"\n\n";
    if (strcmp(key, "ui_plugin_sample_filepath") == 0)
    {
        retString = filePath.c_str();
        std::cout<<"getstate"<<retString<<"\n\n";
    }
    if (strcmp(key, "ui_sample_loaded") == 0)
    {
        retString = "ui_sample_loaded yes/no";
    }
    return retString;
};
void initState(unsigned int index, String &stateKey, String &defaultStateValue) override
{
    switch (index)
    {
    case 0:
        stateKey = "ui_plugin_sample_filepath";
        defaultStateValue = "";
        break;

    default:

        break;
    }
}

    void parseCsv(const char *value){
        sampleLength=0;
        csvRadius.resize(0);
        csvArgument.resize(0);
        int i=0,j=0, test;;
        std::ifstream file(value);
        std::string str, str2; 
        while (std::getline(file, str)&&i<sampleRate)
        {
            std::stringstream input(str);

            //std::cout<<std::getline(input, str2, ','); 
            j=0;
            while(std::getline(input, str2, ',')){
                //std::cout<<"j: "<<j<<" Csvradiusindex"<<CsvRadiusIndex<<"\n"<<i<<str2;


                if(j==CsvRadiusIndex){
                                                                    //if(!(i%100))
                                                                    std::cout<<"str2"<<str2<<"i"<<i<<"\n\n";

                    csvRadius.push_back(std::stof(str2));
                }
                                if(j==CsvArgumentIndex){
                    csvArgument.push_back(std::stof(str2));
                }
                j++;
            }
            i++;
        }
        sampleLength=std::min<int>(csvRadius.size(), csvArgument.size());
        std::cout<<csvRadius.size()<<csvArgument.size()<<"Ist ibig enough"<<"\n\n";
    }
    void saveSample(const char *fileName){
        calculate();
        AudioFile<float> outputFile;
        // 1. Create an AudioBuffer
        // (BTW, AudioBuffer is just a vector of vectors)

        AudioFile<float>::AudioBuffer buffer;

        // 2. Set to (e.g.) two channels
        buffer.resize (1);
        std::cout<<"bufffer resized"<<"\n";
        // 3. Set number of samples per channel
        buffer[0].resize (waveformLength);
        std::cout<<"bufffer resized"<<"\n";
        buffer[0]=waveform;

        bool ok = outputFile.setAudioBuffer (buffer);
        if(ok){
        outputFile.setAudioBufferSize (1, waveformLength);
        std::cout<<"audipo resized"<<"\n";

        outputFile.setBitDepth (16);
        std::cout<<"bitdept resized"<<"\n";
        outputFile.setSampleRate (48000);
        std::cout<<"saplerateresized"<<fileName<<"\n";

        outputFile.save (fileName);
        }else{
            std::cout<<"error!!!!!!!"<<"\n";
        }

    }

       
       
    float clamp(float a){
        return std::max<float>(-1.0, std::min<float>(1.0,a));
    }
        float getPitch(){
                            if (DEBUG) std::cout<<"gettingpiutch"<<Octave<<"    "<<PitchCoarse<<"    "<<PitchFine<<"\n\n";
            return std::min<float>(pow(2,Octave+PitchCoarse/12+PitchFine/12),sampleRate/48) ;
        }
        void activate() override {
            //calculate();
        }

    void calculate(uint32_t index=9999){
        if (DEBUG) std::cout<<"calculate"<<"\n\n";
        float pitch=getPitch();
                if (DEBUG) std::cout<<"pitch"<<pitch<<"\n\n";

        if (DEBUG) std::cout<<sampleRate/pitch<<sampleRate<<pitch<<"\n\n";
                if (DEBUG) std::cout<<maxWaveformLength<<"\n\n";

        int newWaveformLength=std::min<int>(sampleRate/pitch, maxWaveformLength);
        if(waveformLength){
            int temp_multiplier=newWaveformLength/waveformLength;
            floatPosition=floatPosition*temp_multiplier;
        }
        waveformLength=newWaveformLength;
        floatPosition=fmod(floatPosition, waveformLength);
        if(DEBUG)std::cout<<waveformLength<<"\n\n";
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
           total =Volume24hz+Volume25hz+Volume26hz+Volume27hz+Volume28hz+Volume29hz+Volume30hz+Volume31hz+Volume32hz+Volume33hz+
        Volume34hz+Volume35hz+Volume36hz+Volume37hz+Volume38hz+Volume39hz+Volume40hz+Volume41hz+Volume42hz+Volume43hz+
        Volume44hz+Volume45hz+Volume46hz+Volume47hz;
        total=std::max<float>(total,1.0f);
                    float rc=1/total;
        float normalisedDrive=(Drive*30+1)*rc;
            data_in[24]=std::polar<float>(Volume24hz*normalisedDrive, M_PI*Phase24hz-M_PI/2);
            data_in[25]=std::polar<float>(Volume25hz*normalisedDrive, M_PI*Phase25hz-M_PI/2);
            data_in[26]=std::polar<float>(Volume26hz*normalisedDrive, M_PI*Phase26hz-M_PI/2);
            data_in[27]=std::polar<float>(Volume27hz*normalisedDrive, M_PI*Phase27hz-M_PI/2);
            data_in[28]=std::polar<float>(Volume28hz*normalisedDrive, M_PI*Phase28hz-M_PI/2);
            data_in[29]=std::polar<float>(Volume29hz*normalisedDrive, M_PI*Phase29hz-M_PI/2);
            data_in[30]=std::polar<float>(Volume30hz*normalisedDrive, M_PI*Phase30hz-M_PI/2);
            data_in[31]=std::polar<float>(Volume31hz*normalisedDrive, M_PI*Phase31hz-M_PI/2);
            data_in[32]=std::polar<float>(Volume32hz*normalisedDrive, M_PI*Phase32hz-M_PI/2);
            data_in[33]=std::polar<float>(Volume33hz*normalisedDrive, M_PI*Phase33hz-M_PI/2);
            data_in[34]=std::polar<float>(Volume34hz*normalisedDrive, M_PI*Phase34hz-M_PI/2);
            data_in[35]=std::polar<float>(Volume35hz*normalisedDrive, M_PI*Phase35hz-M_PI/2);
            data_in[36]=std::polar<float>(Volume36hz*normalisedDrive, M_PI*Phase36hz-M_PI/2);
            data_in[37]=std::polar<float>(Volume37hz*normalisedDrive, M_PI*Phase37hz-M_PI/2);
            data_in[38]=std::polar<float>(Volume38hz*normalisedDrive, M_PI*Phase38hz-M_PI/2);
            data_in[39]=std::polar<float>(Volume39hz*normalisedDrive, M_PI*Phase39hz-M_PI/2);
            data_in[40]=std::polar<float>(Volume40hz*normalisedDrive, M_PI*Phase40hz-M_PI/2);
            data_in[41]=std::polar<float>(Volume41hz*normalisedDrive, M_PI*Phase41hz-M_PI/2);
            data_in[42]=std::polar<float>(Volume42hz*normalisedDrive, M_PI*Phase42hz-M_PI/2);
            data_in[43]=std::polar<float>(Volume43hz*normalisedDrive, M_PI*Phase43hz-M_PI/2);
            data_in[44]=std::polar<float>(Volume44hz*normalisedDrive, M_PI*Phase44hz-M_PI/2);
            data_in[45]=std::polar<float>(Volume45hz*normalisedDrive, M_PI*Phase45hz-M_PI/2);
            data_in[46]=std::polar<float>(Volume46hz*normalisedDrive, M_PI*Phase46hz-M_PI/2);
            data_in[47]=std::polar<float>(Volume47hz*normalisedDrive, M_PI*Phase47hz-M_PI/2);


            SampleGain=std::min<float>(SampleGain,1);
            int halfWave=waveformLength/2;
            if(waveformLength%2){
                halfWave-=1;
            }
            int endLoop=std::min<float>(sampleLength, halfWave);
            float halfPi=M_PI/2;
            float gainMultiplier=SampleGain*normalisedDrive;
            if(SampleGain>0.0001f)
                for(int i=0;i<endLoop;i++){
                    //data_in[i]/=100;//weirdness


                    if(csvRadius[i]>0){

                        data_in[i]+=std::polar<float>((csvRadius[i])*gainMultiplier,csvArgument[i]*M_PI-halfPi);
                    }
                }
            //   for (int i=0;i<waveformLength;i++){
            
            //     total+=std::abs(data_in[i]);
            //   }
            //             if(total<0.000001f)total=0.000001f;
            //   float recip=1/total;
            //             for (int i=1;i<waveformLength;i++){
            //  //weird effect
            //     data_in[i]*=recip*(Drive+1);//100
            //   }

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
            for(int i=0;i<waveformLength;i++){
                waveform[i]=clamp(data_out[i].real());
                //waveform[i]=0;
            }
            safeWaveformLength=waveformLength;
            ready=true;
            paramUpdated=false;
            if(DEBUG) std::cout<<"baz"<<"\n\n";
    }
    void noteOn(){
        floatPosition=0;
        envelopePosition=0;
        envelopeStage=1;
    }
    void noteOff(){
        envelopePosition=std::min<int>(envelopePosition,Attack+Decay);
        envelopeStage=2;
    }
    float attackCurve(float x){
        return x;
    }
    float decayCurve(float x){
        return x;
    }
    float releaseCurve(float x){
        return x;
    }
    float envelope(){
        if(envelopePosition<Attack){
            return attackCurve((float) envelopePosition/Attack);
        }else if(envelopePosition<Attack+Decay){
            return decayCurve((float)1 - (envelopePosition-Attack)*(1-Sustain)/Decay);
        }else if(envelopeStage==1){
            return Sustain;
        }else if (Release>=1){

            return releaseCurve((float) Sustain*(1-(float) std::min<int>(envelopePosition-Attack-Decay,Release)/Release));
        }else return 0;
    }

    void run(const float **inputs, float **outputs, uint32_t frames,
            const MidiEvent *midiEvents, // MIDI pointer
            uint32_t midiEventCount      // Number of MIDI events in block
        ) override {
        const float *const in = inputs[0];
        float *const out = outputs[0];
        //out[0]=(fmod(pow(0.5,0.5)+position*M_PI,2)-1)*gain;
        // for(int i=0;i<waveformLength;i++){
        //     waveform[i]=sin(2*M_PI  *i*PitchRange/800);
        // }
        //if(DEBUG)std::cout<<"running"<<"\n\n";

        int minlength=std::min(waveformLength,safeWaveformLength);
        int curEventIndex =0;
        for (uint32_t i = 0; i < frames; i++) {
            while (curEventIndex < midiEventCount && i == midiEvents[curEventIndex].frame)
            {

                int status = midiEvents[curEventIndex].data[0]; // midi status
                                                                //  int channel = status & 0x0F ; // get midi channel
                int midi_message = status & 0xF0;
                int midi_data1 = midiEvents[curEventIndex].data[1];
                int midi_data2 = midiEvents[curEventIndex].data[2];
                midiNote=midi_data1;
                #ifdef DEBUG
                printf("midi note %i\n", midi_data1);
                #endif


                switch (midi_message)
                {
                case 0x80: // note_off
                    noteOff();
                    break;
                case 0x90: // note_on
                    noteOn();
                    velocity=midi_data2;
                    break;
                default:
                    break;
                }
                curEventIndex++;

            }
            out[i]=0.0f;
            if(ready){
        float positionIncrement=pow(2,(float)(midiNote-60)/12);

                floatPosition=fmod(floatPosition,minlength);
               // if(DEBUG)std::cout<<"floatposition"<<floatPosition<<"\n\n"<<"minlength:"<<minlength<<"\n";
                float mult=((float)velocity)/127.0f;
                out[i]=waveform[(int)floatPosition]*Gain*envelope()*mult;

                floatPosition+=positionIncrement;
                envelopePosition+=1;

            }
            //position+=1;
            //out[i]=sin(i/15)/;

        }
               // if(DEBUG)std::cout<<"finisedrunning"<<"\n\n";
        // while(position>2*M_PI){
        //     position-=2*M_PI;
        // }
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
    Freeze;
    int Octave, CsvRadiusIndex, CsvArgumentIndex;
    float Sustain;
    int Attack, Decay, Release;
        std::vector<float> waveform;
        int waveformLength,safeWaveformLength;
                uint64_t position, envelopePosition;
        int sampleLength, SampleOffset, envelopeStage;
    bool ready=false, paramUpdated=true;
    std::string filePath; 
    int midiNote=60;
    int velocity=0;

AudioFile<float> audioFile;

float floatPosition;

//AudioFile<int> intAudioFile;
std::vector<float> csvRadius, csvArgument;


        DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Additive);
};


Plugin* createPlugin() { return new Additive(); }

END_NAMESPACE_DISTRHO

