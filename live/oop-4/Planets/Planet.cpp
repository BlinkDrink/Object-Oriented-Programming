#include "Planet.h"

using std::cin;
using std::cout;
using std::swap;

void sortPlanetsByName(Planet* planets, unsigned planetsCount)
{
    for (unsigned i = 0; i < planetsCount - 1; i++) {
        for (unsigned j = i; j < planetsCount; j++) {
            if (strcmp(planets[i].name, planets[j].name) > 0) {
                swap(planets[i], planets[j]);
            }
        }
    }
}

bool readPlanet(Planet* p, const char name[], double distanceToSun)
{
    // name
    unsigned nameLen = strlen(name);

    if (nameLen > 50) {
        cout << "Name is longer than 50 symbols!";
        return false;
    }

    p->name = new char[nameLen + 1];
    if (!p->name) {
        cout << "There was an error during name input.";
        return false;
    }

    for (unsigned i = 0; i <= nameLen; i++) {
        p->name[i] = name[i];
    }

    // distanceFromSun
    p->distanceFromSun = distanceToSun;
    return true;
}

void readMultiplePlanets(Planet* planets, unsigned planetsCount)
{
    for (unsigned i = 0; i < planetsCount; i++) {
        cin.ignore();

        Planet p;
        readPlanet(&p, "Test", 0);

        planets[i] = p;
    }
}

void printPlanet(Planet* p)
{
    cout << "Planet's name: " << p->name << '\n'
         << "Planet's distance from sun: " << p->distanceFromSun << '\n';
}

unsigned secondsFromPlanetToSun(Planet* p)
{
    const unsigned v = 299792; // Speed of light km/sec
    const double s = p->distanceFromSun;

    unsigned t = s / v;
    return t;
}

void deletePlanet(Planet* p)
{
    delete[] p->name;
}