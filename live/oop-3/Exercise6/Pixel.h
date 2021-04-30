#pragma once
#include "termcolor.hpp"
#include <iostream>

enum Colors {
    ERed,
    EGreen,
    EBlue,
};

struct Pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};
