#include <iostream>

int main(){

    int num;

    std:: cout << "Ingrese un número\n"; //se le pide al usuario ingresar numero
    std:: cin >> num;
    if(num == 0) // se evalua la excepción de cero
        std:: cout << "El número es neutro\n";
    else if(num%2==0 && num>0) // se usa operador logico and, teniendo  en cuenta el modulo del numero si este es cero (par) y si el valor es mayor a cero es (positivo)
        std:: cout << "El número es par y positivo\n";
    else if(num%2 == 0)
        std:: cout << "El número es par y negativo\n";
    else if(num>0)
        std:: cout << "El número es impar y positivo\n";
    else 
        std:: cout << "El número es impar y negativo\n";
    return 0;
}