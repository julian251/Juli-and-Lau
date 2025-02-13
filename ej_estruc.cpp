#include <iostream>
struct Point{
    int x, y;
};

int main(){
    Point p1 = {10, 20};
    Point p2 = {-2,3};
    p2.x =-5;
    std:: cout << "Point P1(" << p1.x << ", " << p1.y << ")\n";
    std:: cout << "Point P1(" << p2.x << ", " << p2.y << ")\n";
    return 0; 
}