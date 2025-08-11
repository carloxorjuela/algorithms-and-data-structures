#include <iostream>
#include <algorithm> // std::fill_n
using namespace std;

class Vector {
private:
    int* v;
    int capacidad;
    int size;

public:
    Vector() {
        capacidad = 5;
        size = 0;
        v = new int[capacidad](); // () para inicializar en 0
    }

    Vector(int t) {
        if (t <= 0) t = 1;
        capacidad = t;
        size = 0;
        v = new int[capacidad](); // en 0
    }

    ~Vector() {
        delete[] v;
    }

    void add(int dato) {
        if (size >= capacidad) resize();
        v[size++] = dato;
    }

    void insert(int posicion, int dato) {
        if (posicion < 0 || posicion > size) {
            cout << "POSICION ERRONEA" << endl;
            return;
        }
        if (size >= capacidad) resize();
        for (int i = size; i > posicion; --i) {
            v[i] = v[i - 1];
        }
        v[posicion] = dato;
        ++size;
    }

    void resize() {
        int nuevaCapacidad = capacidad * 2;
        int* nuevoVector = new int[nuevaCapacidad](); // en 0
        for (int i = 0; i < size; ++i) {
            nuevoVector[i] = v[i];
        }
        delete[] v;
        v = nuevoVector;
        capacidad = nuevaCapacidad;
    }

    // Imprime SOLO los elementos "activos"
    void print() {
        for (int i = 0; i < size; ++i) cout << v[i] << "\t";
        cout << endl;
    }

    // Imprime TODA la capacidad (incluye ceros)
    void printAll() {
        for (int i = 0; i < capacidad; ++i) cout << v[i] << "\t";
        cout << endl;
    }

    // eliminar una posicion
    void eliminarp(int posicionr) {
        if (posicionr < 0 || posicionr >= size) {
            cout << "POSICION ERRONEA" << endl;
            return;
        }
        for (int i = posicionr; i < size - 1; ++i) {
            v[i] = v[i + 1];
        }
        --size;
        v[size] = 0; // limpia el hueco al final
    }

    // "Vaciar" el vector: deja size=0 y rellena con 0 para que printAll muestre ceros
    void clear() {
        std::fill_n(v, capacidad, 0);
        size = 0;
    }
};

int main() {
    Vector v;

    for (int i = 0; i < 6; ++i) v.add(i * 10);

    cout << "Vector inicial:" << endl;
    v.print();

    int datoUsuario, posicionusuario;
    cout << "\nIngrese el dato que quieras insertar: ";
    cin >> datoUsuario;
    cout << "Ingrese la posicion donde insertar: ";
    cin >> posicionusuario;

    v.insert(posicionusuario, datoUsuario);

    cout << "\nVector despues de insertar " << datoUsuario
         << " en posicion: " << posicionusuario << endl;
    v.print();

    int posicionr;
    cout << "\nIngrese la posicion que quieras eliminar: ";
    cin >> posicionr;

    v.eliminarp(posicionr);
    v.print();

    v.clear();
    cout << "\nVector despues de clear() (printAll para ver ceros):" << endl;
    v.printAll();

    return 0;
}
