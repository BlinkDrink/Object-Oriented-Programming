#include "Rectangular.h"

using std::abs;
using std::cin;
using std::cout;
using std::max;
using std::min;

void initRectangular(Rectangular* r)
{
    double x1, y1, x2, y2;

    cout << "Enter rectangle's x1, y1,x2,y2: ";
    cin >> x1 >> y1 >> x2 >> y2;

    r->p1.x = x1;
    r->p1.y = y1;
    r->p2.x = x2;
    r->p2.y = y2;
}

void initRectangular(Rectangular* r, Point* p1, Point* p2)
{
    r->p1 = *p1;
    r->p2 = *p2;
}

void printRectangular(Rectangular* r)
{
    int width = abs(r->p2.x - r->p1.x);
    int height = abs(r->p2.y - r->p1.y);

    if (!(r->p1.x > 0 && r->p2.x > 0 && r->p1.y > 0 && r->p2.y > 0)) {
        cout << "We can only print rectangles with positive width and height.";
        return;
    }

    // Width
    for (unsigned i = 1; i <= height; i++) {
        for (unsigned j = 1; j <= width; j++) {
            if (j == 1 || j == width) {
                cout << '*';
            } else if (i == 1 || i == height) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}

bool liesInsideRect(Rectangular* r, Point* p)
{
    Point leftMostPoint = r->p1.x < r->p2.x ? r->p1 : r->p2;
    Point rightMostPoint = r->p1.x > r->p2.x ? r->p1 : r->p2;

    double minY = min(leftMostPoint.y, rightMostPoint.y);
    double maxY = max(leftMostPoint.y, rightMostPoint.y);

    if (p->x > leftMostPoint.x && p->x < rightMostPoint.x && p->y > minY && p->y < maxY) {
        return true;
    }

    return false;
}

bool rectsOverlap(Rectangular* r1, Rectangular* r2)
{
    Point r2ThirdPoint, r2FourthPoint;
    Point r1ThirdPoint, r1FourthPoint;

    r1ThirdPoint.x = r1->p1.x;
    r1ThirdPoint.y = r1->p2.y;

    r1FourthPoint.x = r1->p2.x;
    r1FourthPoint.y = r1->p1.y;

    r2ThirdPoint.x = r2->p1.x;
    r2ThirdPoint.y = r2->p2.y;

    r2FourthPoint.x = r2->p2.x;
    r2FourthPoint.y = r2->p1.y;

    if (liesInsideRect(r1, &r2->p1) || liesInsideRect(r1, &r2->p2)
        || liesInsideRect(r1, &r2ThirdPoint) || liesInsideRect(r1, &r2FourthPoint)) {
        return true;
    }

    if (liesInsideRect(r2, &r1->p1) || liesInsideRect(r2, &r1->p2)
        || liesInsideRect(r2, &r1ThirdPoint) || liesInsideRect(r2, &r1FourthPoint)) {
        return true;
    }

    return false;
}