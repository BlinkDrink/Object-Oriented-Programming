#pragma once
#include <cstring>
#include <iostream>
struct Planet {
    char* name;
    double distanceFromSun;
};

bool readPlanet(Planet* planet, const char name[], double distanceToSun);

void sortPlanetsByName(Planet* planets, unsigned planetsCount);

void readMultiplePlanets(Planet* planets, unsigned planetsCount);

void printPlanet(Planet* planet);

size_t secondsFromPlanetToSun(Planet* planet);

void deletePlanet(Planet* planet);
