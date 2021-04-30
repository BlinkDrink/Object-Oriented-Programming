#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "Screen.h"
#include "catch.hpp"
#include <cassert>

TEST_CASE("isFirstScreenSizeSmallerThanSecond should operate properly", "[isFirstScreenSizeSmallerThanSecond]")
{
    SECTION("should return true when s1's size is smaller than s2's")
    {
        Screen s1 = { 17, 50 };
        Screen s2 = { 31, 77 };

        REQUIRE(isFirstScreenSizeSmallerThanSecond(&s1, &s2) == true);
    }

    SECTION("should return false when s1's size is bigger than s2's")
    {
        Screen s1 = { 25, 50 };
        Screen s2 = { 15, 77 };

        REQUIRE(isFirstScreenSizeSmallerThanSecond(&s1, &s2) == false);
    }

    SECTION("should return false when s1's size is equal to s2's size")
    {
        Screen s1 = { 15, 50 };
        Screen s2 = { 15, 77 };

        REQUIRE(isFirstScreenSizeSmallerThanSecond(&s1, &s2) == false);
    }
}

TEST_CASE("reduceScreenBrightness should operate properly", "[reduceScreenBrightness]")
{
    SECTION("should return false when reduceWith argument is bigger than screen's brightness")
    {
        Screen s = { 15, 50 };
        unsigned reduceWith = 51;

        REQUIRE(reduceScreenBrightness(&s, reduceWith) == false);
    }

    SECTION("should return true when reduceWith argument is smaller than screen's brightness")
    {
        Screen s = { 15, 50 };
        unsigned reduceWith = 40;

        REQUIRE(reduceScreenBrightness(&s, reduceWith) == true);
    }

    SECTION("should change the brightness correctly when reduceWith argument is smaller than s's brightness")
    {
        Screen s = { 15, 50 };
        unsigned reduceWith = 40;
        reduceScreenBrightness(&s, reduceWith);
        REQUIRE(s.brightness == 10);
    }

    SECTION("should change the brightness correctly when reduceWith argument is equal to s's brightness")
    {
        Screen s = { 15, 50 };
        unsigned reduceWith = 50;
        reduceScreenBrightness(&s, reduceWith);
        REQUIRE(s.brightness == 0);
    }
}