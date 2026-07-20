#pragma once

#include "common/common_types.h"

/*!
 * @file input_delay.h
 * Shared settings for the delayed-input mod so the ImGui debug menu and the GOAL
 * kernel can agree on the random roll range. Mirrors the screenshot settings pattern.
 */

// number of scramble input signals: 16 button bits + 8 stick directions
constexpr int INPUT_SCRAMBLE_COUNT = 24;

// this must match the `input-delay-settings` structure in engine/ps2/pad.gc
struct InputDelaySettings {
  float roll_min;  // low end of the random delay roll, in seconds
  float roll_max;  // high end of the random delay roll, in seconds
  s32 mode;        // 0 = delay, 1 = scramble (random 1:1 input remap)
  s32 reshuffle;   // bump this to request a fresh scramble mapping
  u8 perm[INPUT_SCRAMBLE_COUNT];  // current scramble mapping: source -> dest signal
};

extern InputDelaySettings* g_input_delay_settings;

// human-readable names for the 24 scramble input signals, indexed by signal id.
extern const char* const g_input_signal_names[INPUT_SCRAMBLE_COUNT];

void register_input_delay_settings(InputDelaySettings* settings);
