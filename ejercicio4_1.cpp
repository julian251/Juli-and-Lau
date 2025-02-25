#include <iostream>
/*
Para realizar el ejercicio se tuvo en cuenta la declaracón de una variable arreglo y 
una variable de resultado, se optó por usar dos ciclos for, uno de ellos para 
que el usuario ingresara el valor de cada posición del arreglo, por otro lado el otro ciclo
for se uso para sumar el valor de cada posición del arreglo, por último se usa el mismo
proceso del ejercicio2_2 para determinar si ese resultado es par, impar, negativo o positivo.
*/

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