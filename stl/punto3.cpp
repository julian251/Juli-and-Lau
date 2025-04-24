#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Estructura que representa una tarea
struct Tarea
{
    int prioridad;
    string descripcion;

    // Constructor
    Tarea(int p, string d) : prioridad(p), descripcion(d) {}
};

// Comparador para que la prioridad más baja tenga mayor prioridad en la cola
struct Comparador
{
    bool operator()(Tarea const &a, Tarea const &b)
    {
        return a.prioridad > b.prioridad; // min-heap: menor prioridad primero
    }
};

int main()
{
    // Cola de prioridad con el comparador personalizado
    priority_queue<Tarea, vector<Tarea>, Comparador> tareas;

    // Insertamos las tareas
    tareas.push(Tarea(3, "Revisión de informes"));
    tareas.push(Tarea(1, "Preparar presentación"));
    tareas.push(Tarea(4, "Responder correos urgentes"));
    tareas.push(Tarea(2, "Reunión con el equipo"));
    tareas.push(Tarea(5, "Planificar nueva estrategia"));

    // Mostramos y extraemos las tareas en orden de prioridad
    cout << "Tareas por orden de prioridad:\n";
    while (!tareas.empty())
    {
        Tarea t = tareas.top();
        cout << t.prioridad << ": " << t.descripcion << endl;
        tareas.pop();
    }

    return 0;
}