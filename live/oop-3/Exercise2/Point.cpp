#include "./headers/Point.h"
#include <cmath>

using std::cin;
using std::cout;
using std::sqrt;

Point createPoint()
{
    Point p;
    cin >> p.x;
    cin >> p.y;

    return p;
}

void setX(Point *p, double value)
{
    p->x = value;
}

void setY(Point *p, double value)
{
    p->y = value;
}

void printPoint(Point *p)
{
    cout << "X: " << p->x << "\tY: " << p->y << '\n';
}

double distAtoB(Point *A, Point *B)
{
    double distance = sqrt((B->x - A->x) * (B->x - A->x) + (B->y - A->y) * (B->y - A->y));
    return distance;
}

double distToCenter(Point *p)
{
    Point c = {0, 0};
    return distAtoB(&c, p);
}
