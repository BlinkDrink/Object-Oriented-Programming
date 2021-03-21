#pragma once
#include <iostream>

struct Point {
    double x;
    double y;
};

struct Rectangular {
    Point p1;
    Point p2;
};

void initRectangular(Rectangular* r);

void initRectangular(Rectangular* r, Point* p1, Point* p2);

void printRectangular(Rectangular* r);

bool liesInsideRect(Rectangular* r, Point* p);

bool rectsOverlap(Rectangular* r1, Rectangular* r2);