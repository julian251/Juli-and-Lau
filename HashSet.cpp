#include <iostream>
#include <vector>
using namespace std;

/**
 * Clase solución que contiene una implementación de un conjunto hash (HashSet).
 * Un HashSet es una estructura de datos que permite almacenar elementos únicos
 * y realizar operaciones como agregar, eliminar y verificar la existencia de elementos.
 */
class solution
{
public:
    /**
     * Clase interna MyHashSet que implementa un HashSet utilizando un vector de booleanos.
     * El tamaño del vector es fijo (1,000,001) para manejar claves en el rango [0, 1,000,000].
     */
    class MyHashSet
    {
    public:
        vector<bool> table; // Vector que actúa como tabla hash para almacenar claves.

        /**
         * Constructor por defecto.
         * Inicializa el vector `table` con un tamaño de 1,000,001 y valores `false`.
         * Esto indica que inicialmente no hay claves almacenadas en el HashSet.
         */
        MyHashSet()
        {
            table.resize(1000001, false);
        }

        /**
         * Método para agregar una clave al HashSet.
         * @param key La clave que se desea agregar.
         * Marca la posición correspondiente en el vector como `true`.
         */
        void add(int key)
        {
            table[key] = true;
        }

        /**
         * Método para eliminar una clave del HashSet.
         * @param key La clave que se desea eliminar.
         * Marca la posición correspondiente en el vector como `false`.
         */
        void remove(int key)
        {
            table[key] = false;
        }

        /**
         * Método para verificar si una clave existe en el HashSet.
         * @param key La clave que se desea verificar.
         * @return `true` si la clave está presente, `false` en caso contrario.
         */
        bool contains(int key)
        {
            return table[key];
        }
    };
};

int main()
{
    // Crear una instancia de MyHashSet
    solution::MyHashSet hashSet;

    // Agregar elementos al HashSet
    hashSet.add(1);
    hashSet.add(2);

    // Verificar si ciertos elementos están presentes
    cout << hashSet.contains(1) << endl; // Devuelve true (1 está presente)
    cout << hashSet.contains(3) << endl; // Devuelve false (3 no está presente)

    // Agregar un elemento duplicado (no afecta el resultado)
    hashSet.add(2);
    cout << hashSet.contains(2) << endl; // Devuelve true (2 está presente)

    // Eliminar un elemento del HashSet
    hashSet.remove(2);
    cout << hashSet.contains(2) << endl; // Devuelve false (2 fue eliminado)

    return 0;
}