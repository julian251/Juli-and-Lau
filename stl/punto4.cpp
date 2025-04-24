#include <iostream>
#include <vector>
#include <algorithm> // para find_if

using namespace std;

int main()
{
    // Paso 1: Creamos el vector con los números dados
    vector<int> numeros = {7, 13, 131, 7, 3, 1, 12};

    // Paso 2: Usamos find_if con una función lambda que detecte el primer número par
    auto it = find_if(numeros.begin(), numeros.end(), [](int n)
                      { return n != 0 && n % 2 == 0; }); // se tiene presente que el 0 no es par
    // El lambda devuelve true si el número es par y diferente de 0
    // Paso 3: Verificamos si encontramos un número par
    if (it != numeros.end())
    {
        cout << "Primer número par encontrado: " << *it << endl;
    }
    else
    {
        cout << "No se encontró ningún número par." << endl;
    }
    return 0;
}