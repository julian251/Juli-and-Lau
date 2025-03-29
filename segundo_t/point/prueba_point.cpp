#include <iostream>
#include <cmath>
#include "Point2D.h"
using namespace std;

int main(){

    Point2D p1(1, 2);
    Point2D p2(3, 4);
    cout << "p1: (" << p1.getX() << ", " << p1.getY() << ")" << endl;
    cout << "p2: (" << p2.getX() << ", " << p2.getY() << ")" << endl;
    cout << "p1 + p2: (" << (p1 + p2).getX() << ", " << (p1 + p2).getY() << ")" << endl;
    cout << "p1 - p2: (" << (p1 - p2).getX() << ", " << (p1 - p2).getY() << ")" << endl;
    cout << "p1 * 2: (" << (p1 * 2).getX() << ", " << (p1 * 2).getY() << ")" << endl;
    cout << "p1 / 2: (" << (p1 / 2).getX() << ", " << (p1 / 2).getY() << ")" << endl;
    cout << "p1 == p2 ? " << (p1 == p2) << endl;
    cout << "p1 != p2 ? " << (p1 != p2) << endl;
    cout << "p1.distance(p2): " << p1.distance(p2) << endl;
    cout << "p1.distance(): " << p1.distance() << endl;
    cout << "p1.midpoint(p2): (" << p1.midpoint(p2).getX() << ", " << p1.midpoint(p2).getY() << ")" << endl;
    cout << "p1.unitVector(): (" << p1.unitVector().getX() << ", " << p1.unitVector().getY() << ")" << endl;
    
    return 0;
}