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


        dialogCount=0;
        int i;
        for(i=0;i<sizeof(fInputFilePathName);i++){
            fInputFilePathName[i]=fOutputFilePathName[i]='\0';
        }
    }
    bool onKeyboard(const KeyboardEvent& ev)
    {
        // Check if a key was pressed down
        if (ev.press)
        {
            bool ctrlPressed = (ev.mod & kModifierControl) != 0;

            // Trap Ctrl + V (or character code 22 / 'v' / 'V')
            if (ctrlPressed && (ev.key == 'v' || ev.key == 'V' || ev.key == 22))
            {
                // Get ImGui's IO configuration context
                ImGuiIO& io = ImGui::GetIO();

                // 1. Manually check if any ImGui InputText field currently wants text input
                if (io.WantCaptureKeyboard)
                {
                    // Force ImGui to register the Paste command internally
                    io.AddKeyEvent(ImGuiKey_ModCtrl, true);
                    io.AddKeyEvent(ImGuiKey_V, true);

                    // Release the keys for the next frame simulation loop
                    io.AddKeyEvent(ImGuiKey_V, false);
                    io.AddKeyEvent(ImGuiKey_ModCtrl, false);

                    // 2. CRITICAL: Return true so DPF tells REAPER "This event was handled"
                    return true;
                }
            }
        }

        // Allow all other keys (like Ctrl+A) to propagate to the ImGui context naturally
        return UI::onKeyboard(ev);
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
    void stateChanged(const char* key, const char * value) override {
        if(strcmp(key, "ui_plugin_sample_filepath")==0){
            std::cout<<"loading from save "<<value<<"\n\n";
           strcpy(fInputFilePathName, value);
        }
    }

    void uiIdle() override
    {
        repaint();
    }

    void onImGuiDisplay() override
    {
        if(DEBUG)std::cout<<"GUIDISPLAY"<<"\n\n";
        float start, end;

        // Check if the window is being opened/drawn for the first frame
        ImGuiIO& io = ImGui::GetIO();

        // The official workaround: if the user clicks inside the plugin window...
        if (ImGui::IsMouseClicked(0) || ImGui::IsMouseClicked(1))
        {
            // ...and they want to use an input box
            if (io.WantCaptureKeyboard)
            {
                // Direct DPF widget call to aggressively snap focus to this view
                this->getWindow().focus();
            }
        }


        const float width = getWidth();
        const float height = getHeight();
        const float margin = 20.0f * getScaleFactor();
                            start = 0.0f;
                    end=2.0f;
        ImGui::SetNextWindowPos(ImVec2(margin, margin));
        ImGui::SetNextWindowSize(ImVec2(width - 2 * margin, height - 2 * margin));

        if (ImGui::Begin("Additive", nullptr, ImGuiWindowFlags_NoResize))
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
            //                                 setState( "ui_plugin_sample_filepath", fInputFilePathName.c_str());    
            //         // action
            //     }
                
            //     // close
            //     ImGuiFileDialog::Instance()->Close();
            // }
            addSlider(kGain, 0, 2);
            addSlider(kDrive, 0, 2);
            if (ImGui::CollapsingHeader("Partials"))
            {
                ImGui::Indent();
                for(int i=0;i<kParameterCount;i++){
;
                    if(i==kOctave){
                    }else if(i==kPitchCoarse){
                    }else if(i==kPitchFine){
                    }else if(i==kAttack||i==kDecay||i==kRelease||i==kGain||i==kSampleGain||i==kSampleOffset||i==kFreeze||i==kDrive||i==kCsvArgumentIndex||i==kCsvRadiusIndex||i==kSustain){
                    }
                    else addSlider(i, start, end);
                }
                ImGui::Unindent();
            }

            if(ImGui::CollapsingHeader("Freeze waveform")){
                if (ImGui::Button("calculate")) {   
                    setState("ui_plugin_calculate","foo");
                }
                addSlider(kFreeze, 0.0f, 1.0f);
            }
            if(ImGui::CollapsingHeader("Import wav/CSV")){
                ImGui::InputTextMultiline("Input filepath", fInputFilePathName, sizeof(fInputFilePathName));
                if (ImGui::Button("import")) {   
                    setState("ui_plugin_sample_filepath",fInputFilePathName);
                }
                addSlider(kSampleGain, 0, 2);
                addSlider(kSampleOffset, 0, 1000);
                addSlider(kCsvRadiusIndex, 0, 31);
                addSlider(kCsvArgumentIndex, 0, 31);
            }
            if(ImGui::CollapsingHeader("Export wav")){

                ImGui::InputTextMultiline("Output filepath", fOutputFilePathName, sizeof(fOutputFilePathName));
                if (ImGui::Button("export")) {   
                    setState("ui_plugin_save_sample",fOutputFilePathName);
                }
            }
            if (ImGui::CollapsingHeader("Envelope"))
            {

                addSlider(kAttack, 0, 48000);
                addSlider(kDecay, 0, 48000);
                addSlider(kSustain, 0, 2);
                                addSlider(kRelease, 0, 48000);

            }

            if (ImGui::CollapsingHeader("Pitch"))
            {
                for(int i=0;i<kParameterCount;i++){
                    if(i==kOctave){
                                    addSlider(i, -10, 10);
                    }else if(i==kPitchCoarse){
                        addSlider(i, 0, 48);
                    }else if(i==kPitchFine){
                        addSlider(i, 0, 12);
                    }

                }
            }
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
