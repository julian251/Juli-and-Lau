#include <iostream>
#include <math.h>
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