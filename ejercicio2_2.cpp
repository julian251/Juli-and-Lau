#include <iostream>
/*
Para la solución del ejercicio se planteo el uso de condicionales que evaluan las 
propiedades requeridas de un número ingresado por el usuario, usando su modulo de 2
y comparando su tamaño con cero
*/
int main(){

    int num;
    //se le pide al usuario ingresar numero
    std:: cout << "Ingrese un número\n"; 
    std:: cin >> num;
    //se evalua la excepción de cero
    if(num == 0) 
        std:: cout << "El número es neutro\n";
    /*
    se usa operador logico and, teniendo  en cuenta el modulo del numero si este 
    es cero (par) y si el valor es mayor a cero es (positivo)*/
    else if(num%2==0 && num>0) 
        std:: cout << "El número es par y positivo\n";
    else if(num%2 == 0)
        std:: cout << "El número es par y negativo\n";
    else if(num>0)
        std:: cout << "El número es impar y positivo\n";
    else 
        std:: cout << "El número es impar y negativo\n";
    return 0;
}