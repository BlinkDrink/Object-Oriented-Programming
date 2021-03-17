#include "./headers/Point.h"
using std::cout;

int main()
{
    Point p1 = createPoint();
    Point p2 = createPoint();

    printPoint(&p1);
    printPoint(&p2);

    cout << "Distance from p1 to center: " << distToCenter(&p1) << '\n';
    cout << "Distance from p1 to p2:" << distAtoB(&p1, &p2) << '\n';

    return 0;
}