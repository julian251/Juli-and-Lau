#include <iostream>

int main(){
    int a = 42;
    double b = 3.1415;
    char c = 'c';

    std :: cout << "tamaño de int: " << sizeof(a) << " bytes\n";
    std :: cout << "tamaño de double: " << sizeof(b) << " bytes\n";
    std :: cout << "tamaño de char: " << sizeof(c) << " bytes\n";
    std :: cout << "dir de int: " << &a << "\n";
    std :: cout << "dir de double: " << &b << "\n";
    std :: cout << "dir de char: " << &c << "\n";
    return 0;
}