#include <iostream>
int main(){
    int x, y, aux;
    std::cin >> x >> y;
    aux = x;
    x=y;
    y= aux;
    std::cout << x << y << "\n";
    return 0;
}