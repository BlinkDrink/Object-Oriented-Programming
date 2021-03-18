#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "Planet.h"
#include "catch.hpp"
#include <cassert>

TEST_CASE("readPlanet() should work properly", "[readPlanet]")
{
    const char name[] = "Jupiter";
    const char veryLongText[] = "SomeVeryLongTextThatExceedsTheGivenMaximumOf50Symbols55555";
    const double distanceFromSun = 759000000;

    SECTION("readPlanet should assign properties")
    {
        Planet p;
        readPlanet(&p, name, distanceFromSun);

        REQUIRE(strcmp(p.name, name) == 0);
        REQUIRE(p.distanceFromSun == distanceFromSun);

        deletePlanet(&p);
    }

    SECTION("readPlanet should exit when name is longer than 50 symbols")
    {
        Planet p;
        REQUIRE(readPlanet(&p, veryLongText, 1234) == false);
    }

    SECTION("readPlanet should return true when the functions finishes properly")
    {
        Planet p;
        REQUIRE(readPlanet(&p, name, distanceFromSun) == true);
        deletePlanet(&p);
    }
}

TEST_CASE("secondsFromPlanetToSun() should work properly", "[secondsFromPlanetToSun]")
{
    Planet p;
    const char name[] = "Jupiter";
    const double distanceFromSun = 759000000;
    readPlanet(&p, name, distanceFromSun);
    REQUIRE(secondsFromPlanetToSun(&p) == 2531);
}

TEST_CASE("sortPlanetsByName() should sort them properly", "[sortPlanetsByName()]")
{
    Planet p1, p2, p3;
    readPlanet(&p1, "Jupiter", 133);
    readPlanet(&p2, "Aproxia", 432);
    readPlanet(&p3, "Ground", 403);
    Planet planets[] = { p1, p2, p3 };

    sortPlanetsByName(planets, 3);

    REQUIRE(strcmp(planets[0].name, "Aproxia") == 0);
    REQUIRE(strcmp(planets[1].name, "Ground") == 0);
    REQUIRE(strcmp(planets[2].name, "Jupiter") == 0);

    deletePlanet(&p1);
    deletePlanet(&p2);
    deletePlanet(&p3);
}
