
#include<string>



 const char * getParameterName(uint32_t index){
       switch (index) {
            case kGain:
                return "Gain";

                break;
            case kVolume24hz:
                return "Volume 24hz";
                break;
            case kVolume25hz:
                return "Volume 25hz";
                break;
            case kVolume26hz:
                return "Volume 26hz";
                break;
            case kVolume27hz:
                return "Volume 27hz";
               break;
            case kVolume28hz:
                return "Volume 28hz";
                break;
            case kVolume29hz:
                return "Volume 29hz";
                break;
            case kVolume30hz:
                return "Volume 30hz";
               break;
            case kVolume31hz:
                return "Volume 31hz";
               break;
            case kVolume32hz:
                return "Volume 32hz";
                break;
            case kVolume33hz:
                return "Volume 33hz";
                break;
            case kVolume34hz:
                return "Volume 34hz";
               break;
            case kVolume35hz:
                return "Volume 35hz";
                break;
            case kVolume36hz:
                return "Volume 36hz";
                 break;
            case kVolume37hz:
                return "Volume 37hz";
                 break;
            case kVolume38hz:
                return "Volume 38hz";
                break;
            case kVolume39hz:
                return "Volume 39hz";
                 break;
            case kVolume40hz:
                return "Volume 40hz";
                break;
            case kVolume41hz:
                return "Volume 41hz";
                break;
            case kVolume42hz:
                return "Volume 42hz";
                break;
            case kVolume43hz:
                return "Volume 43hz";
                break;
            case kVolume44hz:
                return "Volume 44hz";
                break;
            case kVolume45hz:
                return "Volume 45hz";

                break;
            case kVolume46hz:
                return "Volume 46hz";
                break;
            case kVolume47hz:
                return "Volume 47hz";
                 break;
            case kPhase24hz:
                return "Phase 24hz";
                break;
            case kPhase25hz:
                return "Phase 25hz";
                break;
            case kPhase26hz:
                return "Phase 26hz";
                 break;
            case kPhase27hz:
                return "Phase 27hz";
               break;
            case kPhase28hz:
                return "Phase 28hz";
                break;
            case kPhase29hz:
                return "Phase 29hz";
                break;
            case kPhase30hz:
                return "Phase 30hz";
                break;
            case kPhase31hz:
                return "Phase 31hz";
                 break;
            case kPhase32hz:
                return "Phase 32hz";
                 break;
            case kPhase33hz:
                return "Phase 33hz";
                 break;
            case kPhase34hz:
                return "Phase 34hz";
                 break;
            case kPhase35hz:
                return "Phase 35hz";
                break;
            case kPhase36hz:
                return "Phase 36hz";
                break;
            case kPhase37hz:
                return "Phase 37hz";
                 break;
            case kPhase38hz:
                return "Phase 38hz";
                break;
            case kPhase39hz:
                return "Phase 39hz";
                 break;
            case kPhase40hz:
                return "Phase 40hz";
                 break;
            case kPhase41hz:
                return "Phase 41hz";
                 break;
            case kPhase42hz:
                return "Phase 42hz";
                break;
            case kPhase43hz:
                return "Phase 43hz";
                 break;
            case kPhase44hz:
                return "Phase 44hz";
                break;
            case kPhase45hz:
                return "Phase 45hz";
                break;
            case kPhase46hz:
                return "Phase 46hz";
                break;
            case kPhase47hz:
                return "Phase 47hz";
                 break;
            case kOctave:
                return "Octave";
                break;
            case kPitchCoarse:
                return "Pitch Coarse";
                 break;
            case kPitchFine:
                return "Pitch Fine";
                 break;
            case kSampleOffset:
                return "Sanple Offset";
                 break;
            case kSampleGain:
                return "Sample Gain";
                break;
                        case kDrive:
                return "Drive";
                break;
                                        case kFreeze:
                return "Freeze";
                break;
                                        case kCsvRadiusIndex:
                return "CSVRadiusIndex";
                break;
                                        case kCsvArgumentIndex:
                return "CSVArgumentIndex";
                break;
            case kAttack:
                return "Attack";
                break;
            case kDecay:
                return "Decay";
                break;
            case kSustain:
                return "Sustain";
                break;
            case kRelease:
                return "Release";
                break;
        }
        return "error";
    }


