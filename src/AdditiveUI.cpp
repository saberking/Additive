/*
 * ImGui plugin example
 * Copyright (C) 2021 Jean Pierre Cimalando <jp-dev@inbox.ru>
 * Copyright (C) 2021-2022 Filipe Coelho <falktx@falktx.com>
 * SPDX-License-Identifier: ISC
 */

#include "DistrhoUI.hpp"
#include "ResizeHandle.hpp"
#include "../ImGuiFileDialog/ImGuiFileDialog.h"
#include <iostream>
namespace bar{
#include "parameterNames.hpp"
}
START_NAMESPACE_DISTRHO
#define DEBUG 0

const char *parameterName[kParameterCount] ={
"Gain",
    "Volume24hz",
    "Phase24hz",
    "Volume25hz",
        "Phase25hz",

    "Volume26hz",
    "Phase26hz",
    "Volume27hz",
    "Phase27hz",
    "Volume28hz",
    "Phase28hz",
    "Volume29hz",
    "Phase29hz",
    "Volume30hz",
     "Phase30hz",
   "Volume31hz",
     "Phase31hz",
   "Volume32hz",
      "Phase32hz",
  "Volume33hz",
     "Phase33hz",
   "Volume34hz",
      "Phase34hz",
  "Volume35hz",
      "Phase35hz",
  "Volume36hz",
      "Phase36hz",
  "Volume37hz",
     "Phase37hz",
   "Volume38hz",
     "Phase38hz",
   "Volume39hz",
     "Phase39hz",
   "Volume40hz",
     "Phase40hz",
   "Volume41hz",
      "Phase41hz",
  "Volume42hz",
     "Phase42hz",
   "Volume43hz",
     "Phase43hz",
   "Volume44hz",
       "Phase44hz",
 "Volume45hz",
     "Phase45hz",
   "Volume46hz",
     "Phase46hz",
   "Volume47hz",
    "Phase47hz",
    "Octave",
    "PitchCoarse",
    "PitchFine",
    "SampleOffset",
    "SampleGain",
    "Drive",
        "Freeze",
    "CSVRadiusIndex",
    "CSVArgumentIndex"

};
// --------------------------------------------------------------------------------------------------------------------

class AdditiveUI : public UI
{

    float params[kParameterCount];
    ResizeHandle fResizeHandle;
    int dialogCount;

    // ----------------------------------------------------------------------------------------------------------------

public:
   /**
      UI class constructor.
      The UI should be initialized to a default state that matches the plugin side.
    */
    AdditiveUI()
        : UI(),
          fResizeHandle(this)
    {
        const double scaleFactor = getScaleFactor();
        setGeometryConstraints(DISTRHO_UI_DEFAULT_WIDTH * scaleFactor, DISTRHO_UI_DEFAULT_HEIGHT * scaleFactor);

        // hide handle if UI is resizable
        if (isResizable())
            fResizeHandle.hide();

        for(int i =0;i<kParameterCount;i++){
            params[i]=0.0f;
        }
        dialogCount=0;
        fInputFilePathName[255]='\0';
        fOutputFilePathName[255]='\0';
    }

protected:
    // ----------------------------------------------------------------------------------------------------------------
    // DSP/Plugin Callbacks

   /**
      A parameter has changed on the plugin side.@n
      This is called by the host to inform the UI about parameter changes.
    */
    void parameterChanged(uint32_t index, float value) override
    {
       params[index]=value;

        repaint();
    }

    void addSlider(int i, float start, float end){
                    if (ImGui::SliderFloat(bar::getParameterName(i), &(params[i]), start, end))
            {
                if (ImGui::IsItemActivated())
                    editParameter(i, true);

                setParameterValue(i, params[i]);
            }

            if (ImGui::IsItemDeactivated())
            {
                editParameter(i, false);
            }
    }

    // ----------------------------------------------------------------------------------------------------------------
    // Widget Callbacks

   /**
      ImGui specific onDisplay function.
    */
    void stateChanged(const char* key, const char * value){}
    void onImGuiDisplay() override
    {
        if(DEBUG)std::cout<<"GUIDISPLAY"<<"\n\n";
        float start, end;
        const float width = getWidth();
        const float height = getHeight();
        const float margin = 20.0f * getScaleFactor();

        ImGui::SetNextWindowPos(ImVec2(margin, margin));
        ImGui::SetNextWindowSize(ImVec2(width - 2 * margin, height - 2 * margin));

        if (ImGui::Begin("Simple gain", nullptr, ImGuiWindowFlags_NoResize))
        {
            

            // //if (ImGui::Begin("##OpenDialogCommand")) {
            // if (ImGui::Button("Open File Dialog")) {
            //      std::cout<<"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"<<"\n\n";
            //     IGFD::FileDialogConfig config;config.path = ".";
            //     std::cout<<"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"<<"\n\n";
            //     ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey"+std::to_string(dialogCount++), "Choose File", ".wav", config);
            //     std::cout<<"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"<<"\n\n";
            // }
        
            // //ImGui::End();
            //  std::cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<dialogCount<<"\n\n";
            // // display
            // if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"+std::to_string(dialogCount))) { // => will show a dialog
            //     std::cout<<"is it ok???"<<"\n\n";
            //     if (ImGuiFileDialog::Instance()->IsOk()) { // action if OK
            //         std::cout<<"Its ok"<<"\n\n";
            //     fFilePath = ImGuiFileDialog::Instance()->GetCurrentPath();
            //     fInputFilePathName = ImGuiFileDialog::Instance()->GetFilePathName();
            //     //std::cout<<"\n\n\n\n"<<"*******************8";
            //                         // std::cout<<"lszdfghlsadiufhglsifdughlsdiufghlsdifugh8";
            //                         // std::cout<<"lszdfghlsadiufhglsifdughlsdiufghlsdifugh8";
            //                         // std::cout<<"lszdfghlsadiufhglsifdughlsdiufghlsdifugh8";
            //                         // std::cout<<"lszdfghlsadiufhglsifdughlsdiufghlsdifugh8";
            //                         // std::cout<<"lszdfghlsadiufhglsifdughlsdiufghlsdifugh8";
            //         std::cout<<fFilePath;
            //     //   std::cout<<filePath;
            //     //   std::cout<<filePath;
            //         std::cout<<"\n\n";
            //         std::cout<<fInputFilePathName; 
            //                                 std::cout<<"\n\n"<<"Setting State"<<"\n\n"<<fInputFilePathName<<"\n\n";    
            //                                 setState( "ui_plugin_load_sample", fInputFilePathName.c_str());    
            //         // action
            //     }
                
            //     // close
            //     ImGuiFileDialog::Instance()->Close();
            // }

            for(int i=0;i<kParameterCount;i++){
                start = 0.0f;
                end=2.0f;
                if(i==kOctave){
                                addSlider(i, -6, 6);
                }else if(i==kPitchCoarse){
                    addSlider(i, 0, 48);
                }else if(i==kPitchFine){
                    addSlider(i, 0, 12);
                }
                else addSlider(i, start, end);
            }
            static char aboutText[256] = "This is a demo plugin made with ImGui.\n";
           // ImGui::InputTextMultiline("About", aboutText, sizeof(aboutText));
            if (ImGui::Button("calculate")) {   
                setState("ui_plugin_calculate","foo");
            }
            ImGui::InputTextMultiline("Input filepath", fInputFilePathName, sizeof(fInputFilePathName));
            if (ImGui::Button("load")) {   
                setState("ui_plugin_load_sample",fInputFilePathName);
            }
            ImGui::InputTextMultiline("Output filepath", fOutputFilePathName, sizeof(fOutputFilePathName));
            if (ImGui::Button("save")) {   
                setState("ui_plugin_save_sample",fOutputFilePathName);
            }
          //  }
        }
        ImGui::End();
                if(DEBUG)std::cout<<"GUIDISPLAYfinished"<<"\n\n";
    }
    private:
                                 char fInputFilePathName[256], fOutputFilePathName[256];
    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AdditiveUI)
};

// --------------------------------------------------------------------------------------------------------------------

UI* createUI()
{
    return new AdditiveUI();
}

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
