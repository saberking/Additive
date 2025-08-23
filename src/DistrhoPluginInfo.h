#ifndef DISTRHO_PLUGIN_INFO_H_INCLUDED
#define DISTRHO_PLUGIN_INFO_H_INCLUDED

#define DISTRHO_PLUGIN_NAME  "Additive"
#define DISTRHO_PLUGIN_URI   "https://github.com/saberking/Additive"

#define DISTRHO_PLUGIN_NUM_INPUTS   16
#define DISTRHO_PLUGIN_NUM_OUTPUTS  1
#define DISTRHO_PLUGIN_IS_RT_SAFE   1

#define DISTRHO_PLUGIN_HAS_UI 1

#define DISTRHO_PLUGIN_WANT_PARAMETER_VALUE_CHANGE_REQUEST 1

#define DISTRHO_PLUGIN_WANT_PROGRAMS 0

#define DISTRHO_PLUGIN_WANT_STATE 1

#define DISTRHO_PLUGIN_WANT_FULL_STATE 1

#define DISTRHO_PLUGIN_WANT_TIMEPOS 1

#define DISTRHO_UI_USE_CUSTOM 1

#define DISTRHO_UI_CUSTOM_INCLUDE_PATH "DearImGui.hpp"

/**
 T he top-level-widget typedef to use for the custom toolkit.          *
 This widget class MUST be a subclass of DGL TopLevelWindow class.
 It is recommended that you keep this widget class inside the DGL namespace,
and define widget type as e.g. DGL_NAMESPACE::MyCustomTopLevelWidget.
@see DISTRHO_UI_USE_CUSTOM
*/
#define DISTRHO_UI_CUSTOM_WIDGET_TYPE DGL_NAMESPACE::ImGuiTopLevelWidget

#define DISTRHO_UI_DEFAULT_WIDTH 600

#define DISTRHO_UI_DEFAULT_HEIGHT 400

#define DISTRHO_UI_USE_NANOVG 0

#define DISTRHO_UI_USER_RESIZABLE 0

#define DISTRHO_UI_URI DISTRHO_PLUGIN_URI "#UI"

/**
 T he plugin id when exporting in CLAP format, in reverse URI form.       *
 @note This macro is required when building CLAP plugins
 */
#define DISTRHO_PLUGIN_CLAP_ID "https://github.com/saberking/Additive"

/**
 C ustom CLAP features for the plugin.@n                    *
 This is a list of features defined as a string array body, without the terminating @c , or nullptr.

 A top-level category can be set as feature and be one of the following values:

 - instrument
 - audio-effect
 - note-effect
 - analyzer

 The following sub-categories can also be set:

 - synthesizer
 - sampler
 - drum
 - drum-machine

 - filter
 - phaser
 - equalizer
 - de-esser
 - phase-vocoder
 - granular
 - frequency-shifter
 - pitch-shifter

 - distortion
 - transient-shaper
 - compressor
 - limiter

 - flanger
 - chorus
 - delay
 - reverb

 - tremolo
 - glitch

 - utility
 - pitch-correction
 - restoration

 - multi-effects

 - mixing
 - mastering

 And finally the following audio capabilities can be set:

 - mono
 - stereo
 - surround
 - ambisonic
 */
#define DISTRHO_PLUGIN_CLAP_FEATURES "audio-effect", "stereo"


enum Parameters {
    kGain,
    kVolume24hz,
    kVolume25hz,
    kVolume26hz,
    kVolume27hz,
    kVolume28hz,
    kVolume29hz,
    kVolume30hz,
    kVolume31hz,
    kVolume32hz,
    kVolume33hz,
    kVolume34hz,
    kVolume35hz,
    kVolume36hz,
    kVolume37hz,
    kVolume38hz,
    kVolume39hz,
    kVolume40hz,
    kVolume41hz,
    kVolume42hz,
    kVolume43hz,
    kVolume44hz,
    kVolume45hz,
    kVolume46hz,
    kVolume47hz,
    kPhase24hz,
    kPhase25hz,
    kPhase26hz,
    kPhase27hz,
    kPhase28hz,
    kPhase29hz,
    kPhase30hz,
    kPhase31hz,
    kPhase32hz,
    kPhase33hz,
    kPhase34hz,
    kPhase35hz,
    kPhase36hz,
    kPhase37hz,
    kPhase38hz,
    kPhase39hz,
    kPhase40hz,
    kPhase41hz,
    kPhase42hz,
    kPhase43hz,
    kPhase44hz,
    kPhase45hz,
    kPhase46hz,
    kPhase47hz,
    kOctave,
    kPitchCoarse,
    kPitchFine,
    kSampleOffset,
    kParameterCount
};

#endif
