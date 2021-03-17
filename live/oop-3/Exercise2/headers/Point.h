#pragma once
#include <iostream>

struct Point
{
    double x;
    double y;
};

Point createPoint();

void setX(Point *p, double value);
void setY(Point *p, double value);

void printPoint(Point *p);

double distToCenter(Point *p);

double distAtoB(Point *A, Point *B);
