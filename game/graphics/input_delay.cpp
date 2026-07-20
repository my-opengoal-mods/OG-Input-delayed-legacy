#include "game/graphics/input_delay.h"

/*!
 * @file input_delay.cpp
 * Shared storage for the delayed-input mod's random roll range. C++ owns a default
 * static so the ImGui menu works from boot; GOAL registers its own struct so both
 * sides read/write the same memory (see register_input_delay_settings).
 */

// perm starts as the identity mapping so the debug display is always valid
// (never an out-of-range index) even before GOAL seeds a real permutation.
InputDelaySettings s_default_input_delay_settings = {
    0.0f, 5.0f, 0, 0,
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}};

InputDelaySettings* g_input_delay_settings = &s_default_input_delay_settings;

const char* const g_input_signal_names[INPUT_SCRAMBLE_COUNT] = {
    "Select", "L3",      "R3",        "Start",     "D-Up",    "D-Right",
    "D-Down", "D-Left",  "L2",        "R2",        "L1",      "R1",
    "Triangle", "Circle", "X",        "Square",    "LS Up",   "LS Down",
    "LS Left", "LS Right", "RS Up",   "RS Down",   "RS Left", "RS Right"};

void register_input_delay_settings(InputDelaySettings* settings) {
  g_input_delay_settings = settings;
}
