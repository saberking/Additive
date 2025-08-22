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
const char *parameterName[35] ={
        "kGain",
    "kInputWeight1",
    "kInputWeight2",
    "kInputWeight3",
    "kInputWeight4",
    "kInputWeight5",
    "kInputWeight6",
    "kInputWeight7",
    "kInputWeight8",
    "kInputBias1",
    "kInputBias2",
    "kInputBias3",
    "kInputBias4",
    "kInputBias5",
    "kInputBias6",
    "kInputBias7",
    "kInputBias8",
    "kOutputWeight1",
    "kOutputWeight2",
    "kOutputWeight3",
    "kOutputWeight4",
    "kOutputWeight5",
    "kOutputWeight6",
    "kOutputWeight7",
    "kOutputWeight8",
    "kOutputBias1",
    "kOutputBias2",
    "kOutputBias3",
    "kOutputBias4",
    "kOutputBias5",
    "kOutputBias6",
    "kOutputBias7",
    "kOutputBias8",
    "kPitch",
    "kPitchRange"
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
            start = i?-90.0f:-2.0f;
            end=i?30.0f:2.0f;
            addSlider(i, start, end);
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
