#include<iostream>
using namespace std;

// ============= VECTOR DINÁMICO =============
class Vector{
private:
    int* v;
    int capacidad;    
    int size;
    
public:
    Vector(){
        capacidad = 3;
        size = 0;
        v = new int[capacidad];
        cout << "Vector creado con capacidad: " << capacidad << endl;
    }
    
    ~Vector(){
        delete[] v;
    }
    
    void add(int dato){
        if(size >= capacidad){
            resize();
        }
        v[size] = dato;
        size++;
        cout << "Agregado " << dato << " al vector. Tamaño: " << size << endl;
    }
    
    void resize(){
        capacidad = capacidad * 2;
        int* nuevoVector = new int[capacidad];
        for(int i = 0; i < size; i++){
            nuevoVector[i] = v[i];
        }
        delete[] v;
        v = nuevoVector;
        cout << "¡Vector redimensionado! Nueva capacidad: " << capacidad << endl;
    }
    
    void print(){
        cout << "Vector: [";
        for(int i = 0; i < size; i++){
            cout << v[i];
            if(i < size-1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    int get(int pos){
        if(pos >= 0 && pos < size)
            return v[pos];
        return 0;
    }
    
    int getSize(){
        return size;
    }
};

// ============= LISTA ENLAZADA =============
class Nodo{
private:
    int dato;
    Nodo* next;
    
public:
    Nodo(int d){
        dato = d;
        next = nullptr;
        cout << "Nodo creado con dato: " << dato << endl;
    }
    
    int getDato(){ return dato; }
    Nodo* getNext(){ return next; }
    void setNext(Nodo* n){ next = n; }
};

class Lista{
private:
    Nodo* ptr;
    int size;
    
public:
    Lista(){
        ptr = nullptr;
        size = 0;
        cout << "Lista enlazada creada (vacía)" << endl;
    }
    
    ~Lista(){
        Nodo* temp = ptr;
        while(temp != nullptr){
            Nodo* siguiente = temp->getNext();
            delete temp;
            temp = siguiente;
        }
    }
    
    void add(int dato){
        Nodo* nuevoNodo = new Nodo(dato);
        if(ptr == nullptr){
            ptr = nuevoNodo;
            cout << "Primer elemento agregado a la lista" << endl;
        }else{
            Nodo* temp = ptr;
            while(temp->getNext() != nullptr){
                temp = temp->getNext();
            }
            temp->setNext(nuevoNodo);
            cout << "Elemento agregado al final de la lista" << endl;
        }
        size++;
    }
    
    void print(){
        cout << "Lista enlazada: ";
        if(ptr == nullptr){
            cout << "(vacía)" << endl;
            return;
        }
        
        Nodo* temp = ptr;
        while(temp != nullptr){
            cout << temp->getDato();
            if(temp->getNext() != nullptr) cout << " -> ";
            temp = temp->getNext();
        }
        cout << " -> NULL" << endl;
    }
    
    int getSize(){ return size; }
    
    int get(int pos){
        if(pos < 0 || pos >= size) return 0;
        Nodo* temp = ptr;
        for(int i = 0; i < pos; i++){
            temp = temp->getNext();
        }
        return temp->getDato();
    }
};

// ============= MATRIZ DINÁMICA =============
class Matriz{
private:
    int** m;
    int filas;
    int columnas;
    
public:
    Matriz(int f, int c){
        filas = f;
        columnas = c;
        cout << "Creando matriz de " << filas << "x" << columnas << endl;
        
        m = new int*[filas];
        for(int i = 0; i < filas; i++){
            m[i] = new int[columnas];
            for(int j = 0; j < columnas; j++){
                m[i][j] = 0;
            }
        }
        cout << "Matriz creada e inicializada en 0" << endl;
    }
    
    ~Matriz(){
        for(int i = 0; i < filas; i++){
            delete[] m[i];
        }
        delete[] m;
    }
    
    void llenarConVector(Vector& v){
        cout << "Llenando matriz con datos del vector..." << endl;
        int pos = 0;
        for(int i = 0; i < filas && pos < v.getSize(); i++){
            for(int j = 0; j < columnas && pos < v.getSize(); j++){
                m[i][j] = v.get(pos);
                pos++;
            }
        }
    }
    
    void llenarConLista(Lista& lista){
        cout << "Llenando matriz con datos de la lista..." << endl;
        int pos = 0;
        for(int i = 0; i < filas && pos < lista.getSize(); i++){
            for(int j = 0; j < columnas && pos < lista.getSize(); j++){
                m[i][j] = lista.get(pos);
                pos++;
            }
        }
    }
    
    void print(){
        cout << "\n=== MATRIZ " << filas << "x" << columnas << " ===" << endl;
        for(int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                cout << m[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void sumaTotal(){
        int suma = 0;
        for(int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                suma += m[i][j];
            }
        }
        cout << "Suma total de elementos en matriz: " << suma << endl;
    }
};

// ============= FUNCIÓN PRINCIPAL =============
int main(){
    cout << "==================================================" << endl;
    cout << "DEMOSTRANDO LAS 3 ESTRUCTURAS DE DATOS" << endl;
    cout << "==================================================" << endl;
    
    // ========== 1. VECTOR DINÁMICO ==========
    cout << "\n--- 1. VECTOR DINÁMICO ---" << endl;
    Vector miVector;
    
    cout << "Agregando elementos al vector:" << endl;
    miVector.add(10);
    miVector.add(20); 
    miVector.add(30);
    miVector.add(40);  // Aquí debería redimensionarse
    miVector.add(50);
    
    miVector.print();
    
    // ========== 2. LISTA ENLAZADA ==========
    cout << "\n--- 2. LISTA ENLAZADA ---" << endl;
    Lista miLista;
    
    cout << "Agregando elementos a la lista:" << endl;
    miLista.add(100);
    miLista.add(200);
    miLista.add(300);
    miLista.add(400);
    miLista.add(500);
    
    miLista.print();
    
    // ========== 3. MATRIZ DINÁMICA ==========
    cout << "\n--- 3. MATRIZ DINÁMICA ---" << endl;
    Matriz miMatriz(3, 4);
    
    cout << "\n>> Llenando matriz con datos del VECTOR:" << endl;
    miMatriz.llenarConVector(miVector);
    miMatriz.print();
    miMatriz.sumaTotal();
    
    cout << "\n>> Creando nueva matriz con datos de la LISTA:" << endl;
    Matriz miMatriz2(2, 3);
    miMatriz2.llenarConLista(miLista);
    miMatriz2.print();
    miMatriz2.sumaTotal();
    
    // ========== RESUMEN FINAL ==========
    cout << "\n==================================================" << endl;
    cout << "RESUMEN DE ESTRUCTURAS CREADAS:" << endl;
    cout << "==================================================" << endl;
    cout << "✅ Vector dinámico: " << miVector.getSize() << " elementos" << endl;
    miVector.print();
    
    cout << "✅ Lista enlazada: " << miLista.getSize() << " elementos" << endl;
    miLista.print();
    
    cout << "✅ Matriz dinámica 1: 3x4" << endl;
    miMatriz.print();
    
    cout << "✅ Matriz dinámica 2: 2x3" << endl;
    miMatriz2.print();
    
    cout << "¡PROGRAMA TERMINADO EXITOSAMENTE!" << endl;
    
    return 0;
}
