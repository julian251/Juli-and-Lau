#include <iostream>
#include <math.h>
/*
Para realizar el ejercicio se declararon las variables necesarias de diferente tipo para calcular el monto 
de una inversion con interes compuesto, teniendo presente el ingreso del valor de cada variable
por el usuario. Finalmente se tuvo en cuenta la conversión de porcentaje a decimal de la 
varible (tasa de interés anual) y calculando con la fórmula dada el interés compuesto 
*/
int main(){
    // se declaran las variables a usar
    int n,t;
    double A,P,r;
    // se ingresan datos y se guardan
    std:: cout <<"Ingrese el monto inicial de la inversión\n" <<"$";
    std:: cin >> P ; 
    std:: cout <<"Ingrese la tasa anual de interés en porcentaje\n";
    std:: cin >> r ; 
    std:: cout <<"Ingrese el número de periodos anuales\n";
    std:: cin >> n ; 
    std:: cout <<"Ingrese el número de años\n";
    std:: cin >> t; 

    // se convierte a decimal el porcentaje de la tasa de interés 
    r=r/100;
    // se calcula el monto final de la inversión
    A=P*pow((1+r/n),n*t);

    std:: cout <<"El monto final es: $" << A << "\n";

    return 0;
}