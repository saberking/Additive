#include "DistrhoPlugin.hpp"
#include "pocketfft_hdronly.h"
#include <algorithm>
#include "parameterNames.hpp"

#define sampleRate 48000
START_NAMESPACE_DISTRHO

class Additive : public Plugin {
    public:
        Additive() : Plugin(kParameterCount, 0, 0), gain(1.0) {position=frame=0; waveformLength=sampleRate;
          //  for(int i=0;i<waveformLength;i++){
            //    waveform[i]=sin(2*M_PI  *i/800);
        //    }
            stride_in[0]=stride_out[0]=sizeof(float);


        }
  protected:
      void activate() override {
        if(PitchRange<1)PitchRange=1;
        waveformLength=(int)sampleRate/PitchRange;
        std::vector<float> data_out(waveformLength);
        std::vector<float> data_in;
                    shape_in[0]=waveformLength;

                      for (int i=0;i<waveformLength;i++){
              frequencies[i]=0.0f;
              data_in.push_back(0.0f);
          }
          pocketfft::shape_t axes;
          size_t superone=0;
          axes.push_back(superone);

          test=1;
          // std::vector<std::complex<float>> data_out(sampleRate);
          
          // frequencies[800]=1;
          float total =InputWeight1+InputWeight2+InputWeight3+InputWeight4+InputWeight5+InputWeight6+InputWeight7+InputWeight8+
          OutputWeight1+OutputWeight2+OutputWeight3+OutputWeight4+OutputWeight5+OutputWeight6+OutputWeight7+OutputWeight8+
          InputBias1+InputBias2+InputBias3+InputBias4+InputBias5+InputBias6+InputBias7+InputBias8;
          if(total<1)total=1;
          data_in[24]=InputWeight1/total;
          data_in[25]=InputWeight2/total;
          data_in[26]=InputWeight3/total;
          data_in[27]=InputWeight4/total;
          data_in[28]=InputWeight5/total;
          data_in[29]=InputWeight6/total;
          data_in[30]=InputWeight7/total;
          data_in[31]=InputWeight8/total;
          data_in[32]=InputBias1/total;
          data_in[33]=InputBias2/total;
          data_in[34]=InputBias3/total;
          data_in[35]=InputBias4/total;
          data_in[36]=InputBias5/total;
          data_in[37]=InputBias6/total;
          data_in[38]=InputBias7/total;
          data_in[39]=InputBias8/total;          
          data_in[40]=OutputWeight1/total;
          data_in[41]=OutputWeight2/total;
          data_in[42]=OutputWeight3/total;
          data_in[43]=OutputWeight4/total;
          data_in[44]=OutputWeight5/total;
          data_in[45]=OutputWeight6/total;
          data_in[46]=OutputWeight7/total;
          data_in[47]=OutputWeight8/total;
          pocketfft::r2r_fftpack(
              shape_in,
              stride_in,
              stride_out,
              axes,
              false,
              forward,
                  data_in.data(),
                                 data_out.data(),
                                 fct
          );
          for(int i=0;i<waveformLength;i++){
              waveform[i]=data_out[i];
              //waveform[i]=0;
          }
    }
      int position;
      int frame;

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
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputWeight1:
                parameter.name = "Input Weight 1";
                parameter.symbol = "InputWeight1";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;

                break;
            case kInputWeight2:
                parameter.name = "Input Weight 2";
                parameter.symbol = "InputWeight2";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;

                break;
            case kInputWeight3:
                parameter.name = "Input Weight 3";
                parameter.symbol = "InputWeight3";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;

                break;
            case kInputWeight4:
                parameter.name = "Input Weight 4";
                parameter.symbol = "InputWeight4";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputWeight5:
                parameter.name = "Input Weight 5";
                parameter.symbol = "InputWeight5";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputWeight6:
                parameter.name = "Input Weight 6";
                parameter.symbol = "InputWeight6";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputWeight7:
                parameter.name = "Input Weight 7";
                parameter.symbol = "InputWeight7";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputWeight8:
                parameter.name = "Input Weight 8";
                parameter.symbol = "InputWeight8";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputBias1:
                parameter.name = "Input Bias 1";
                parameter.symbol = "InputBias1";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputBias2:
                parameter.name = "Input Bias 2";
                parameter.symbol = "InputBias2";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputBias3:
                parameter.name = "Input Bias 3";
                parameter.symbol = "InputBias3";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputBias4:
                parameter.name = "Input Bias 4";
                parameter.symbol = "InputBias4";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputBias5:
                parameter.name = "Input Bias 5";
                parameter.symbol = "InputBias5";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputBias6:
                parameter.name = "Input Bias 6";
                parameter.symbol = "InputBias6";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputBias7:
                parameter.name = "Input Bias 7";
                parameter.symbol = "InputBias7";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kInputBias8:
                parameter.name = "Input Bias 8";
                parameter.symbol = "InputBias8";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputWeight1:
                parameter.name = "Output Weight 1";
                parameter.symbol = "OutputWeight1";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputWeight2:
                parameter.name = "Output Weight 2";
                parameter.symbol = "OutputWeight2";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputWeight3:
                parameter.name = "Output Weight 3";
                parameter.symbol = "OutputWeight3";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputWeight4:
                parameter.name = "Output Weight 4";
                parameter.symbol = "OutputWeight4";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputWeight5:
                parameter.name = "Output Weight 5";
                parameter.symbol = "OutputWeight5";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputWeight6:
                parameter.name = "Output Weight 6";
                parameter.symbol = "OutputWeight6";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputWeight7:
                parameter.name = "Output Weight 7";
                parameter.symbol = "OutputWeight7";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputWeight8:
                parameter.name = "Output Weight 8";
                parameter.symbol = "OutputWeight8";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputBias1:
                parameter.name = "Output Bias 1";
                parameter.symbol = "OutputBias1";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputBias2:
                parameter.name = "Output Bias 2";
                parameter.symbol = "OutputBias2";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputBias3:
                parameter.name = "Output Bias 3";
                parameter.symbol = "OutputBias3";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputBias4:
                parameter.name = "Output Bias 4";
                parameter.symbol = "OutputBias4";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputBias5:
                parameter.name = "Output Bias 5";
                parameter.symbol = "OutputBias5";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputBias6:
                parameter.name = "Output Bias 6";
                parameter.symbol = "OutputBias6";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputBias7:
                parameter.name = "Output Bias 7";
                parameter.symbol = "OutputBias7";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kOutputBias8:
                parameter.name = "Output Bias 8";
                parameter.symbol = "OutputBias8";
                parameter.ranges.def = 0.0f;
                parameter.ranges.min = -2.0f;
                parameter.ranges.max = 2.0f;
                parameter.hints=kParameterIsAutomatable;
                break;
            case kPitch:
                parameter.name = "Pitch";
                parameter.symbol = "Pitch";
                parameter.ranges.def = 1.0f;
                parameter.ranges.min = 0.0000001f;
                parameter.hints=kParameterIsAutomatable;
                parameter.ranges.max = 1.0f;

                break;
            case kPitchRange:
                parameter.name = "PitchRange";
                parameter.symbol = "PitchRange";
                parameter.ranges.def = 1.0f;
                parameter.ranges.min = 1.0f;
                parameter.hints=kParameterIsAutomatable;
                parameter.ranges.max = 40.0f;

                break;
        }
    }
    float getParameterValue(uint32_t index) const override {
        switch (index) {
        case kGain:
            return gain;
        case kInputWeight1:
            return InputWeight1;
        case kInputWeight2:
            return InputWeight2;
        case kInputWeight3:
            return InputWeight3;
        case kInputWeight4:
            return InputWeight4;
        case kInputWeight5:
            return InputWeight5;
        case kInputWeight6:
            return InputWeight6;
        case kInputWeight7:
            return InputWeight7;
        case kInputWeight8:
            return InputWeight8;
        case kInputBias1:
            return InputBias1;
        case kInputBias2:
            return InputBias2;
        case kInputBias3:
            return InputBias3;
        case kInputBias4:
            return InputBias4;
        case kInputBias5:
            return InputBias5;
        case kInputBias6:
            return InputBias6;
        case kInputBias7:
            return InputBias7;
        case kInputBias8:
            return InputBias8;
        case kOutputWeight1:
            return OutputWeight1;
        case kOutputWeight2:
            return OutputWeight2;
        case kOutputWeight3:
            return OutputWeight3;
        case kOutputWeight4:
            return OutputWeight4;
        case kOutputWeight5:
            return OutputWeight5;
        case kOutputWeight6:
            return OutputWeight6;
        case kOutputWeight7:
            return OutputWeight7;
        case kOutputWeight8:
            return OutputWeight8;
        case kOutputBias1:
            return OutputBias1;
        case kOutputBias2:
            return OutputBias2;
        case kOutputBias3:
            return OutputBias3;
        case kOutputBias4:
            return OutputBias4;
        case kOutputBias5:
            return OutputBias5;
        case kOutputBias6:
            return OutputBias6;
        case kOutputBias7:
            return OutputBias7;
        case kOutputBias8:
            return OutputBias8;
        case kPitch:
            return Pitch;
        case kPitchRange:
            return PitchRange;
        default:
            return 0.0;
        }
    }

    void setParameterValue(uint32_t index, float value) override {
        switch (index) {
        case kGain:
            gain = value;
            break;
        case kInputWeight1:
            InputWeight1=value;
                        break;
        case kInputWeight2:
            InputWeight2=value;
                        break;
        case kInputWeight3:
            InputWeight3=value;
                        break;
        case kInputWeight4:
            InputWeight4=value;
                        break;
        case kInputWeight5:
            InputWeight5=value;
                        break;
        case kInputWeight6:
            InputWeight6=value;
                        break;
        case kInputWeight7:
            InputWeight7=value;
                        break;
        case kInputWeight8:
            InputWeight8=value;
                        break;
        case kInputBias1:
            InputBias1=value;
                        break;
        case kInputBias2:
            InputBias2=value;
                        break;
        case kInputBias3:
            InputBias3=value;
                        break;
        case kInputBias4:
            InputBias4=value;
                        break;
        case kInputBias5:
            InputBias5=value;
                        break;
        case kInputBias6:
            InputBias6=value;
                        break;
        case kInputBias7:
            InputBias7=value;
                        break;
        case kInputBias8:
            InputBias8=value;
                        break;
        case kOutputWeight1:
            OutputWeight1=value;
                        break;
        case kOutputWeight2:
            OutputWeight2=value;
                        break;
        case kOutputWeight3:
            OutputWeight3=value;
                        break;
        case kOutputWeight4:
            OutputWeight4=value;
                        break;
        case kOutputWeight5:
            OutputWeight5=value;
                        break;
        case kOutputWeight6:
            OutputWeight6=value;
                        break;
        case kOutputWeight7:
            OutputWeight7=value;
                        break;
        case kOutputWeight8:
            OutputWeight8=value;
                        break;
        case kOutputBias1:
            OutputBias1=value;
                        break;
        case kOutputBias2:
            OutputBias2=value;
                        break;
        case kOutputBias3:
            OutputBias3=value;
                        break;
        case kOutputBias4:
            OutputBias4=value;
                        break;


        case kOutputBias5:
            OutputBias5=value;
                        break;
        case kOutputBias6:
            OutputBias6=value;
                        break;
        case kOutputBias7:
            OutputBias7=value;
                        break;
        case kOutputBias8:
            OutputBias8=value;
            break;
        case kPitch:
            Pitch=value;
            break;
        case kPitchRange:
            PitchRange=value;
            break;
        }
        activate();
    }
    float clamp(float a){
        return std::max<float>(-1.0, std::min<float>(1.0,a));
    }

    float calculate(float i){
        float n1, n2, n3, n4, n5, n6, n7, n8, result;
        n1=clamp(InputWeight1*sin(position/64)*i+InputBias1);
        n2=clamp(InputWeight2*sin(position/64)+InputBias2);
        n3=clamp(InputWeight3*sin(position/64)+InputBias3);
        n4=clamp(InputWeight4*sin(position/64)+InputBias4);
        n5=clamp(InputWeight5*sin(position/64)+InputBias5);
        n6=clamp(InputWeight6*sin(position/64)+InputBias6);
        n7=clamp(InputWeight7*sin(position/64)+InputBias7);
        n8=clamp(InputWeight8*sin(position/64)+InputBias8);
        result=clamp(n1*OutputWeight1+
        n2*OutputWeight2+
        n3*OutputWeight3+
        n4*OutputWeight4+
        n5*OutputWeight5+
        n6*OutputWeight6+
        n7*OutputWeight7+
        n8*OutputWeight8+
        OutputBias1

        );
        return result;
    }
       void run(const float **inputs, float **outputs, uint32_t frames) override {
        const float *const in = inputs[0];
        float *const out = outputs[0];
        out[0]=(fmod(pow(0.5,0.5)+position*M_PI,2)-1)*gain;
        // for(int i=0;i<waveformLength;i++){
        //     waveform[i]=sin(2*M_PI  *i*PitchRange/800);
        // }

        for (uint32_t i = 0; i < frames; i++) {
            //calculate();
            //out[i] = in[i] +1;
            //out[i]=rand()*gain/100000000;
            //out[i]= calculate(in[i])/2;

            out[i]=waveform[position]*gain;

            position+=1;
          while(position>=waveformLength){
                position-=waveformLength;
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
        float gain,
        InputWeight1,
        InputWeight2,
        InputWeight3,
        InputWeight4,
        InputWeight5,
        InputWeight6,
        InputWeight7,
        InputWeight8,
        InputBias1,
        InputBias2,
        InputBias3,
        InputBias4,
        InputBias5,
        InputBias6,
        InputBias7,
        InputBias8,
        OutputWeight1,
        OutputWeight2,
        OutputWeight3,
        OutputWeight4,
        OutputWeight5,
        OutputWeight6,
        OutputWeight7,
        OutputWeight8,
        OutputBias1,
        OutputBias2,
        OutputBias3,
        OutputBias4,
        OutputBias5,
        OutputBias6,
        OutputBias7,
        OutputBias8,
        Pitch,
        PitchRange;
        float waveform[sampleRate];
        int waveformLength, test;

        pocketfft::shape_t shape_in{1};                                              // dimensions of the input shape
        pocketfft::stride_t stride_in{1};                    // must have the size of each element. Must have size() equal to shape_in.size()
        pocketfft::stride_t stride_out{1}; // must have the size of each element. Must have size() equal to shape_in.size()
      //  pocketfft::shape_t axes{1};                                                  // 0 to shape.size()-1 inclusive
        bool forward{ pocketfft::BACKWARD };                                            // FORWARD or BACKWARD
                                                                // input data (reals)
                              // output data (FFT(input))
        float fct{ 1.0f };    // scaling factor
        float frequencies[48000];

        DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Additive);
};


Plugin* createPlugin() { return new Additive(); }

END_NAMESPACE_DISTRHO

