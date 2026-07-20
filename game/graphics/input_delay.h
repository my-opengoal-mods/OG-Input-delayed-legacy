#pragma once

#include "common/common_types.h"

/*!
 * @file input_delay.h
 * Shared settings for the delayed-input mod so the ImGui debug menu and the GOAL
 * kernel can agree on the random roll range. Mirrors the screenshot settings pattern.
 */

// this must match the `input-delay-settings` structure in engine/ps2/pad.gc
struct InputDelaySettings {
  float roll_min;  // low end of the random delay roll, in seconds
  float roll_max;  // high end of the random delay roll, in seconds
};

extern InputDelaySettings* g_input_delay_settings;

void register_input_delay_settings(InputDelaySettings* settings);
