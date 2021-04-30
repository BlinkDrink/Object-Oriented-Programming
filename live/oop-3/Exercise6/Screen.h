#pragma once
#include "Pixel.h"

struct Screen {
    float screenSize;
    unsigned brightness;
    Pixel pixels[16];
};

void reflectResults(Screen* s, unsigned screenPixels);

void fillPixels(Screen* s, const unsigned pixelsLength, Colors c);

void paintPixels(Screen* s, Colors c);

bool isFirstScreenSizeSmallerThanSecond(Screen* s1, Screen* s2);

bool reduceScreenBrightness(Screen* s, unsigned reduceWith);