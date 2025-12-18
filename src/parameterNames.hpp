
#include<string>



String getParameterName(uint32_t index){
       switch (index) {
            case kGain:
                return String("Gain");

                break;
            case kVolume24hz:
                return String("Volume 24hz");
                break;
            case kVolume25hz:
                return String("Volume 25hz");
                break;
            case kVolume26hz:
                return String("Volume 26hz");
                break;
            case kVolume27hz:
                return String("Volume 27hz");
               break;
            case kVolume28hz:
                return String("Volume 28hz");
                break;
            case kVolume29hz:
                return String("Volume 29hz");
                break;
            case kVolume30hz:
                return String("Volume 30hz");
               break;
            case kVolume31hz:
                return String("Volume 31hz");
               break;
            case kVolume32hz:
                return String("Volume 32hz");
                break;
            case kVolume33hz:
                return String("Volume 33hz");
                break;
            case kVolume34hz:
                return String("Volume 34hz");
               break;
            case kVolume35hz:
                return String("Volume 35hz");
                break;
            case kVolume36hz:
                return String("Volume 36hz");
                 break;
            case kVolume37hz:
                return String("Volume 37hz");
                 break;
            case kVolume38hz:
                return String("Volume 38hz");
                break;
            case kVolume39hz:
                return String("Volume 39hz");
                 break;
            case kVolume40hz:
                return String("Volume 40hz");
                break;
            case kVolume41hz:
                return String("Volume 41hz");
                break;
            case kVolume42hz:
                return String("Volume 42hz");
                break;
            case kVolume43hz:
                return String("Volume 43hz");
                break;
            case kVolume44hz:
                return String("Volume 44hz");
                break;
            case kVolume45hz:
                return String("Volume 45hz");

                break;
            case kVolume46hz:
                return String("Volume 46hz");
                break;
            case kVolume47hz:
                return String("Volume 47hz");
                 break;
            case kPhase24hz:
                return String("Phase 24hz");
                break;
            case kPhase25hz:
                return String("Phase 25hz");
                break;
            case kPhase26hz:
                return String("Phase 26hz");
                 break;
            case kPhase27hz:
                return String("Phase 27hz");
               break;
            case kPhase28hz:
                return String("Phase 28hz");
                break;
            case kPhase29hz:
                return String("Phase 29hz");
                break;
            case kPhase30hz:
                return String("Phase 30hz");
                break;
            case kPhase31hz:
                return String("Phase 31hz");
                 break;
            case kPhase32hz:
                return String("Phase 32hz");
                 break;
            case kPhase33hz:
                return String("Phase 33hz");
                 break;
            case kPhase34hz:
                return String("Phase 34hz");
                 break;
            case kPhase35hz:
                return String("Phase 35hz");
                break;
            case kPhase36hz:
                return String("Phase 36hz");
                break;
            case kPhase37hz:
                return String("Phase 37hz");
                 break;
            case kPhase38hz:
                return String("Phase 38hz");
                break;
            case kPhase39hz:
                return String("Phase 39hz");
                 break;
            case kPhase40hz:
                return String("Phase 40hz");
                 break;
            case kPhase41hz:
                return String("Phase 41hz");
                 break;
            case kPhase42hz:
                return String("Phase 42hz");
                break;
            case kPhase43hz:
                return String("Phase 43hz");
                 break;
            case kPhase44hz:
                return String("Phase 44hz");
                break;
            case kPhase45hz:
                return String("Phase 45hz");
                break;
            case kPhase46hz:
                return String("Phase 46hz");
                break;
            case kPhase47hz:
                return String("Phase 47hz");
                 break;
            case kOctave:
                return String("Octave");
                break;
            case kPitchCoarse:
                return String("Pitch Coarse");
                 break;
            case kPitchFine:
                return String("Pitch Fine");
                 break;
            case kSampleOffset:
                return String("Sample Offset");
                 break;
            case kSampleGain:
                return String("Sample Gain");
                break;
                        case kDrive:
                return String("Drive");
                break;
                                        case kFreeze:
                return String("Freeze");
                break;
                                        case kCsvRadiusIndex:
                return String("CSVRadiusIndex");
                break;
                                        case kCsvArgumentIndex:
                return String("CSVArgumentIndex");
                break;
            case kAttack:
                return String("Attack");
                break;
            case kDecay:
                return String("Decay");
                break;
            case kSustain:
                return String("Sustain");
                break;
            case kRelease:
                return String("Release");
                break;
        }
        return String("error");
    }


