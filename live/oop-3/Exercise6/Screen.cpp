#include "Screen.h"
#include <iostream>

using std::cout;
using termcolor::color;
using termcolor::on_blue;
using termcolor::on_green;
using termcolor::on_red;
using termcolor::reset;

void fillPixels(Screen* s, const unsigned pixelsLength, Colors c)
{
    switch (c) {
    case ERed:
        for (unsigned i = 0; i < pixelsLength; i++) {
            s->pixels[i].red = 255;
            s->pixels[i].green = 0;
            s->pixels[i].blue = 0;
        }
        break;
    case EGreen:
        for (unsigned i = 0; i < pixelsLength; i++) {
            s->pixels[i].red = 0;
            s->pixels[i].green = 255;
            s->pixels[i].blue = 0;
        }
        break;
    case EBlue:
        for (unsigned i = 0; i < pixelsLength; i++) {
            s->pixels[i].red = 0;
            s->pixels[i].green = 0;
            s->pixels[i].blue = 255;
        }
        break;
    default:
        break;
    }
}

void reflectResults(Screen* s, unsigned screenPixels)
{
    for (unsigned i = 0; i < screenPixels; i++) {
        Pixel p = s->pixels[i];

        if (p.red != 0) {
            cout << on_red << p.red;
        }

        if (p.green != 0) {
            cout << on_green << p.green;
        }

        if (p.blue != 0) {
            cout << on_blue << p.blue;
        }
    }

    cout << reset;
}

void paintPixels(Screen* s, Colors c)
{
    const unsigned screenPixels = 16;
    switch (c) {
    case ERed:
        fillPixels(s, screenPixels, ERed);
        break;
    case EGreen:
        fillPixels(s, screenPixels, EGreen);
        break;
    case EBlue:
        fillPixels(s, screenPixels, EBlue);
        break;
    default:
        break;
    }
}

bool isFirstScreenSizeSmallerThanSecond(Screen* s1, Screen* s2)
{
    return s1->screenSize < s2->screenSize;
}

bool reduceScreenBrightness(Screen* s, unsigned reduceWith)
{
    if (reduceWith > s->brightness) {
        return false;
    }

    s->brightness -= reduceWith;
    return true;
}