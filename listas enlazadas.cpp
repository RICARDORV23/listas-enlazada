#include <iostream>
#include <string>

using namespace std;

class Estudiante {
public:
    string nombre;
    string materia;
    Estudiante* siguiente;

    Estudiante() {
        nombre = "";
        materia = "";
        siguiente = NULL;
    }

    Estudiante(const string& nombre, const string& materia) {
        this->nombre = nombre;
        this->materia = materia;
        this->siguiente = NULL;
    }
};

void registrarEstudiante(Estudiante*& cabeza, const string& nombre, const string& materia) {
    Estudiante* nuevoEstudiante = new Estudiante(nombre, materia);

    if (cabeza == NULL) {
        cabeza = nuevoEstudiante;
    } else {
        Estudiante* temp = cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoEstudiante;
    }

    cout << "Estudiante registrado: " << nombre << " - " << materia << endl;
}

void procesarInscripcion(Estudiante*& cabeza) {
    if (cabeza == NULL) {
        cout << "No hay estudiantes inscritos." << endl;
        return;
    }

    Estudiante* temp = cabeza;
    cout << "Procesando inscripción de: " << temp->nombre << " - " << temp->materia << endl;
    cabeza = cabeza->siguiente;
    delete temp;
}

void mostrarInscripciones(Estudiante* cabeza) {
    if (cabeza == NULL) {
        cout << "No hay estudiantes inscritos." << endl;
        return;
    }

    cout << "Estudiantes inscritos:" << endl;
    Estudiante* temp = cabeza;
    while (temp != NULL) {
        cout << "- " << temp->nombre << " (" << temp->materia << ")" << endl;
        temp = temp->siguiente;
    }
}

int main() {
    Estudiante* cabeza = NULL;

    int opcion;
    string nombre, materia;

    do {
        cout << "\n--- Sistema de Inscripción a Exámenes ---" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Procesar inscripción" << endl;
        cout << "3. Mostrar estudiantes inscritos" << endl;
        cout << "4. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Nombre del estudiante: ";
                getline(cin, nombre);
                cout << "Materia para el examen: ";
                getline(cin, materia);
                registrarEstudiante(cabeza, nombre, materia);
                break;
            case 2:
                procesarInscripcion(cabeza);
                break;
            case 3:
                mostrarInscripciones(cabeza);
                break;
            case 4:
                cout << "Saliendo del sistema." << endl;
                break;
            default:
                cout << "Opción no válida. Intenta de nuevo." << endl;
        }
    } while (opcion != 4);

    while (cabeza != NULL) {
        procesarInscripcion(cabeza);
    }

    return 0;
}
