#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//intercambiar dos elementos
void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//partición
int particion(int *v, int inicio, int fin){
    int pivote = v[fin];
    int i = inicio - 1;
    
    for (int j = inicio; j < fin; j++) {
        if (v[j] <= pivote) {
            i++;
            intercambiar(v[i], v[j]);
        }
    }
    
    intercambiar(v[i + 1], v[fin]);
    return i + 1;
}

//QuickSort
void quickSort(int *v, int inicio, int fin) {
    if (inicio < fin) {
        int posPivote = particion(v, inicio, fin);
        quickSort(v, inicio, posPivote - 1);
        quickSort(v, posPivote + 1,fin);
    }
}

//imprimir el array
void imprimirArray(int *v, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

//números aleatorios
void generarAleatorios(int *v, int tamaño) {
    srand(time(0)); 
    for (int i = 0; i < tamaño; i++) {
        v[i] = rand() % 100 + 1; 
    }
}

//caso de que el usuario ingrese los números
void ingresarManual(int *v, int tamaño) {
    cout << "Ingrese " << tamaño << " numeros:" << endl;
    for (int i = 0; i < tamaño; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> v[i];
    }
}

//menú
void mostrarMenu() {
    cout << "\n=== MENU QUICKSORT ===" << endl;
    cout << "1. Generar vector con valores aleatorios" << endl;
    cout << "2. Ingresar valores manualmente" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    int opcion;
    int tamaño;
    int *arr = nullptr;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                cout << "\nIngrese el tamaño del vector: ";
                cin >> tamaño;
                
                if (tamaño <= 0) {
                    cout << "Tamaño invalido!" << endl;
                    break;
                }
                
                arr = new int[tamaño];
                generarAleatorios(arr, tamaño);
                
                cout << "\nVector generado aleatoriamente: ";
                imprimirArray(arr, tamaño);
                
                quickSort(arr, 0, tamaño - 1);
                
                cout << "Vector ordenado: ";
                imprimirArray(arr, tamaño);
                
                delete[] arr;
                break;
            }
            
            case 2: {
                cout << "\nIngrese el tamaño del vector: ";
                cin >> tamaño;
                
                if (tamaño <= 0) {
                    cout << "Tamaño invalido!" << endl;
                    break;
                }
                
                arr = new int[tamaño];
                ingresarManual(arr, tamaño);
                
                cout << "\nVector original: ";
                imprimirArray(arr, tamaño);
                
                quickSort(arr, 0, tamaño - 1);
                
                cout << "Vector ordenado: ";
                imprimirArray(arr, tamaño);
                
                delete[] arr;
                break;
            }
            
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
                
            default:
                cout << "Opcion invalida! Intente de nuevo." << endl;
        }
        
    } while (opcion != 3);
    
    return 0;
}
    
    
    
    
    
    
    
    
