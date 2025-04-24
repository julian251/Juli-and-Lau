#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Paso 1: Creamos el vector de pares
    vector<pair<int, string>> datos = {
        {5, "manzana"},
        {2, "banana"},
        {8, "naranja"},
        {1, "uva"},
        {7, "pera"}};

    // Paso 2: Ordenamos de forma descendente según el valor numérico (el primer elemento del par)
    sort(datos.begin(), datos.end(), [](const pair<int, string> &a, const pair<int, string> &b)
         {
             return a.first > b.first; // orden descendente
         });

    // Paso 3: Imprimimos los resultados ordenados
    cout << "Vector ordenado (por número descendente):" << endl;
    for (const auto &elemento : datos)
    {
        cout << elemento.first << " - " << elemento.second << endl;
    }
    return 0;
}