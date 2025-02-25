#include <iostream>
int main(){
    // se define el arreglo y variable de control
    int cadena[5];
    int sum =0;
    // se ingresa el valor de cada posición del arreglo
    for (int i=0; i<=4; i++){
        std:: cout <<"Ingrese el número, en la posición " << i <<"\n";
        std:: cin >> cadena[i];
    }
    // se suma el valor de todas las posiciones del arreglo "cadena"
    for (int i=0; i<=4; i++){
        sum=cadena[i]+sum;
    }
    std:: cout <<"El valor de la suma es:" << sum <<"\n";
    // se evalua el signo y la paridad del resultado (sum)
    if(sum == 0) // se evalua la excepción de cero
        std:: cout << "El resultado es neutro \n";
    else if(sum%2==0 && sum>0)
        std:: cout << "El resultado es par y positivo\n";
    else if(sum%2 == 0)
        std:: cout << "El resultado es par y negativo\n";
    else if(sum>0)
        std:: cout << "El resultado es impar y positivo\n";
    else
        std:: cout << "El resultado es impar y negativo\n";
    return 0;
}