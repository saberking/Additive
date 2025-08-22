/*
 * ImGui plugin example
 * Copyright (C) 2021 Jean Pierre Cimalando <jp-dev@inbox.ru>
 * Copyright (C) 2021-2022 Filipe Coelho <falktx@falktx.com>
 * SPDX-License-Identifier: ISC
 */

#include "DistrhoUI.hpp"
#include "ResizeHandle.hpp"
#include "parameterNames.hpp"

START_NAMESPACE_DISTRHO
const char *parameterName[kParameterCount] ={
"Gain",
    "Volume24hz",
    "Volume25hz",
    "Volume26hz",
    "Volume27hz",
    "Volume28hz",
    "Volume29hz",
    "Volume30hz",
    "Volume31hz",
    "Volume32hz",
    "Volume33hz",
    "Volume34hz",
    "Volume35hz",
    "Volume36hz",
    "Volume37hz",
    "Volume38hz",
    "Volume39hz",
    "Volume40hz",
    "Volume41hz",
    "Volume42hz",
    "Volume43hz",
    "Volume44hz",
    "Volume45hz",
    "Volume46hz",
    "Volume47hz",
    "Phase24hz",
    "Phase25hz",
    "Phase26hz",
    "Phase27hz",
    "Phase28hz",
    "Phase29hz",
    "Phase30hz",
    "Phase31hz",
    "Phase32hz",
    "Phase33hz",
    "Phase34hz",
    "Phase35hz",
    "Phase36hz",
    "Phase37hz",
    "Phase38hz",
    "Phase39hz",
    "Phase40hz",
    "Phase41hz",
    "Phase42hz",
    "Phase43hz",
    "Phase44hz",
    "Phase45hz",
    "Phase46hz",
    "Phase47hz",
    "Octave",
    "PitchCoarse",
    "PitchFine"
};
// --------------------------------------------------------------------------------------------------------------------

class AdditiveUI : public UI
{

    float params[kParameterCount];
    ResizeHandle fResizeHandle;

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
        DISTRHO_SAFE_ASSERT_RETURN(index == 0,);


        repaint();
    }

    void addSlider(int i, float start, float end){
                    if (ImGui::SliderFloat(parameterName[i], &(params[i]), start, end))
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
    void onImGuiDisplay() override
    {
        float start, end;
        const float width = getWidth();
        const float height = getHeight();
        const float margin = 20.0f * getScaleFactor();

        ImGui::SetNextWindowPos(ImVec2(margin, margin));
        ImGui::SetNextWindowSize(ImVec2(width - 2 * margin, height - 2 * margin));

        if (ImGui::Begin("Simple gain", nullptr, ImGuiWindowFlags_NoResize))
        {
            static char aboutText[256] = "This is a demo plugin made with ImGui.\n";
            ImGui::InputTextMultiline("About", aboutText, sizeof(aboutText));
        for(int i=0;i<kParameterCount;i++){
            start = 0.0f;
            end=i?30.0f:2.0f;
            if(i==kOctave){
                            addSlider(i, -6, 6);
            }
            else addSlider(i, start, end);
        }

        }
        ImGui::End();
    }

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AdditiveUI)
};

// --------------------------------------------------------------------------------------------------------------------

UI* createUI()
{
    return new AdditiveUI();
}

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
