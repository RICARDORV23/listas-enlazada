#include <iostream>
using namespace std;

// Definición de la estructura Nodo
struct Nodo {
    int valor;
    Nodo* siguiente;
    
    // Constructor para crear un Nodo
    Nodo(int v) {
        valor = v;
        siguiente = NULL; // Usamos NULL en lugar de nullptr
    }
};

// Función para agregar un nodo al final de la lista
void agregarNodo(Nodo*& cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    
    if (cabeza == NULL) {  // Usamos NULL en lugar de nullptr
        cabeza = nuevoNodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != NULL) {  // Usamos NULL en lugar de nullptr
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista enlazada
void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != NULL) {  // Usamos NULL en lugar de nullptr
        cout << temp->valor << " -> ";
        temp = temp->siguiente;
    }
    cout << "NULL" << endl;  // Usamos NULL en lugar de nullptr
}

// Función para eliminar la lista y liberar la memoria
void eliminarLista(Nodo*& cabeza) {
    Nodo* temp;
    while (cabeza != NULL) {  // Usamos NULL en lugar de nullptr
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

int main() {
    Nodo* lista = NULL;  // Usamos NULL en lugar de nullptr

    // Agregar nodos a la lista
    agregarNodo(lista, 10);
    agregarNodo(lista, 20);
    agregarNodo(lista, 30);

    // Imprimir la lista
    cout << "Lista enlazada: ";
    imprimirLista(lista);

    // Eliminar la lista
    eliminarLista(lista);

    return 0;
}
