#include "game/graphics/input_delay.h"

/*!
 * @file input_delay.cpp
 * Shared storage for the delayed-input mod's random roll range. C++ owns a default
 * static so the ImGui menu works from boot; GOAL registers its own struct so both
 * sides read/write the same memory (see register_input_delay_settings).
 */

InputDelaySettings s_default_input_delay_settings = {0.0f, 5.0f, 0, 0};

InputDelaySettings* g_input_delay_settings = &s_default_input_delay_settings;

void register_input_delay_settings(InputDelaySettings* settings) {
  g_input_delay_settings = settings;
}
