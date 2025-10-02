// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<string>
using namespace std;

class Modelo{
    int id;
    int existencias;
public:
    Modelo(){
        id = -1;
        existencias = -1;
    }
    
    Modelo(int i, int e){
        id = i;
        existencias = e;
    }
    
    int getID(){
        return id;
    }
    
    int getExistencias(){
        return existencias;
    }
    
    void addExistencias(int n){ //Método para añadir o restar de las existencias de un modelo
        existencias+=n;
    }
    
    string to_string(){
        return "("+std::to_string(id)+","+std::to_string(existencias)+")";
    }
    
    friend std::ostream& operator<<(std::ostream& os, Modelo& b) {
        return os << b.to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Modelo* b) {
        return os << b->to_string();
    }
    
    Modelo& operator=(const Modelo& f) {
        id = f.id;
        existencias = f.existencias;
        return *this;
    }
    
    int compareTo(Modelo* t){
        // Ordenar por existencias ascendente
        if(this->existencias < t->existencias) return -1;
        if(this->existencias > t->existencias) return 1;
        
        // Si hay empate, ordenar por ID descendente
        if(this->id > t->id) return -1;
        if(this->id < t->id) return 1;
        
        return 0;
    }
    
    int compareTo(Modelo& t){
        // Ordenar por existencias ascendente
        if(this->existencias < t.existencias) return -1;
        if(this->existencias > t.existencias) return 1;
        
        // Si hay empate, ordenar por ID descendente
        if(this->id > t.id) return -1;
        if(this->id < t.id) return 1;
        
        return 0;
    }
};

template<typename T>
class Node{
    T dato;
    Node* next;
public:
    Node(){
        next = NULL;
    }
    
    Node(T d){
        dato = d;
        next = NULL;
    }
    
    ~Node(){}
    
    T getDato(){
        return dato;
    }
    
    void setDato(T d){
        dato = d;
    }
    
    Node* getNext(){
        return next;
    }
    
    void setNext(Node* n){
        next = n;
    }
    
    string to_string(){
        return dato.to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Node& b) {
        return os << b.to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Node* b) {
        return os << b->to_string();
    }
    
    Node& operator=(const Node& f) {
        dato = f.dato;
        next = f.next;
        return *this;
    }
    
    int compareTo(Node* t){
        return dato->compareTo(t->getDato());
    }
    
    int compareTo(Node& t){
        return dato->compareTo(t.getDato());
    }
};

template<typename T>
class Lista{
    Node<T>* ptr;
    int size;
public:
    Lista(){
        ptr = NULL;
        size = 0;
    }
    
    void add(T d){
        if(ptr == NULL){
            ptr = new Node<T>(d);
        }else{
            Node<T>* temp = ptr;
            while(temp->getNext() != NULL){
                temp = temp->getNext();
            }
            temp->setNext(new Node<T>(d));
        }
        size++;
    }
    
    Node<T>* get(int i){
        if(i >= 0 && i < size){
            int cont=0;
            Node<T>* temp = ptr;
            while(cont < i && temp != NULL){
                temp = temp->getNext();
                cont++;
            }
            return temp;
        }
        return NULL;
    }
    
    void print(){
        Node<T>* temp = ptr;
        while(temp != NULL){
            cout<<temp->getDato()<<", ";
            temp = temp->getNext();
        }
    }
    
    int getSize(){
        return size;
    }
    
    Lista& operator=(const Lista& f) {
        ptr = f.ptr;
        size = f.size;
        return *this;
    }
};

class Linea{
    int id;
    Lista<Modelo*> lista;
    int contModelos;
    int existenciasTotales;

public:
    Linea(){
        id = -1;
        contModelos = 0;
        existenciasTotales = 0;
    }
    
    Linea(int i){
        id = i;
        contModelos = 0;
        existenciasTotales = 0;
    }
    
    void addModelo(int existencias){
        // Crear un modelo nuevo con ID = (id_linea * 100) + contador_modelos
        Modelo* nuevoModelo = new Modelo(id * 100 + contModelos, existencias);
        
        // Añadir el nuevo modelo a la lista
        lista.add(nuevoModelo);
        
        // Actualizar las existencias totales
        existenciasTotales += existencias;
        contModelos++;
    }
    
    Modelo* getModelo(int i){
        return lista.get(i)->getDato();
    }
    
    int getID(){
        return id;
    }
    
    int getExistenciasTotales(){
        return existenciasTotales;
    }
    
    void print(){
        cout<<"ID :"<<id<<" : ";
        lista.print();
        cout<<endl;
    }
    
    string to_string(){
        string s = "ID :"+std::to_string(id)+" : ";
        for(int i=0; i<lista.getSize(); i++){
            s = s + lista.get(i)->getDato()->to_string()+", ";
        }
        return s;
    }
    
    friend std::ostream& operator<<(std::ostream& os, Linea& b) {
        return os << b.to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Linea* b) {
        return os << b->to_string();
    }
    
    Linea& operator=(const Linea& f) {
        id = f.id;
        lista = f.lista;
        contModelos = f.contModelos;
        existenciasTotales = f.existenciasTotales;
        return *this;
    }
    
    int getSize(){
        return lista.getSize();
    }
    
    int compareTo(Linea* t){
        // Ordenar por existencias totales ascendente
        if(this->existenciasTotales < t->existenciasTotales) return -1;
        if(this->existenciasTotales > t->existenciasTotales) return 1;
        
        // Si hay empate, ordenar por número de modelos ascendente
        if(this->contModelos < t->contModelos) return -1;
        if(this->contModelos > t->contModelos) return 1;
        
        return 0;
    }
    
    int compareTo(Linea& t){
        // Ordenar por existencias totales ascendente
        if(this->existenciasTotales < t.existenciasTotales) return -1;
        if(this->existenciasTotales > t.existenciasTotales) return 1;
        
        // Si hay empate, ordenar por número de modelos ascendente
        if(this->contModelos < t.contModelos) return -1;
        if(this->contModelos > t.contModelos) return 1;
        
        return 0;
    }
    
    void sort(){
        int size = getSize();
        if(size > 0){
            Modelo* temp;
            int posmin = 0;
            for(int i=0; i<size-1; i++){
                posmin = i;
                for(int j=i+1; j<size; j++){
                    if(lista.get(j)->getDato()->compareTo(lista.get(posmin)->getDato()) == -1){
                        posmin = j;
                    }
                }
                temp = lista.get(posmin)->getDato();
                lista.get(posmin)->setDato(lista.get(i)->getDato());
                lista.get(i)->setDato(temp);
            }
        }
    }
    
    // Método para buscar un modelo por ID dentro de esta línea
    Modelo* buscarModelo(int idModelo){
        for(int i=0; i<lista.getSize(); i++){
            if(lista.get(i)->getDato()->getID() == idModelo){
                return lista.get(i)->getDato();
            }
        }
        return NULL;
    }
    
    // Método para actualizar existencias totales después de una compra
    void actualizarExistenciasTotales(){
        existenciasTotales = 0;
        for(int i=0; i<lista.getSize(); i++){
            existenciasTotales += lista.get(i)->getDato()->getExistencias();
        }
    }
};

template<typename T>
class Vector{
    T* v;
    int capacidad;
    int size;
    
public:
    Vector(){
        capacidad = 10;
        size = 0;
        v = new T[capacidad];
    }
    
    Vector(int c){
        capacidad = c;
        size = 0;
        v = new T[capacidad];
    }
    
    ~Vector(){
        delete[] v;
    }
    
    void add(T dato){
        if(size >= capacidad){
            resize();
        }
        v[size++] = dato;
    }
    
    void resize(){
        capacidad *= 2;
        T* nuevoVector = new T[capacidad];
        for(int i = 0; i < size; i++){
            nuevoVector[i] = v[i];
        }
        delete[] v;
        v = nuevoVector;
    }
    
    T get(int i){
        if(i >= 0 && i < size){
            return v[i];
        }
        return NULL;
    }
    
    void set(int i, T dato){
        if(i >= 0 && i < size){
            v[i] = dato;
        }
    }
    
    int getSize(){
        return size;
    }
    
    void print(){
        for(int i = 0; i < size; i++){
            v[i]->print();
        }
    }
};

class ANIF_APOR{
    Vector<Linea*> lineas;
    
public:
    ANIF_APOR(){}
    
    void addLinea(Linea* l){
        lineas.add(l);
    }
    
    void print(){
        lineas.print();
    }
    
    int getSize(){
        return lineas.getSize();
    }
    
    void sort(){
        int size = getSize();
        if(size > 0){
            // Bubble Sort para ordenar líneas
            Linea* temp;
            for(int i = 0; i < size-1; i++){
                for(int j = 0; j < size-i-1; j++){
                    if(lineas.get(j)->compareTo(lineas.get(j+1)) == 1){
                        temp = lineas.get(j);
                        lineas.set(j, lineas.get(j+1));
                        lineas.set(j+1, temp);
                    }
                }
            }
            
            // Ordenar cada línea internamente
            for(int i=0; i<size; i++){
                lineas.get(i)->sort();
            }
        }
    }
    
    Modelo* getModelo(int id){
        // Calcular a qué línea pertenece el modelo (id / 100)
        int idLinea = id / 100;
        
        // Buscar la línea con ese ID
        for(int i=0; i<lineas.getSize(); i++){
            if(lineas.get(i)->getID() == idLinea){
                // Buscar el modelo dentro de esa línea
                return lineas.get(i)->buscarModelo(id);
            }
        }
        return NULL;
    }
    
    bool comprar(int id, int num){
        Modelo* m = getModelo(id);
        if(m != NULL){
            if(m->getExistencias() >= num){
                m->addExistencias(-num);
                
                // Actualizar existencias totales de la línea
                int idLinea = id / 100;
                for(int i=0; i<lineas.getSize(); i++){
                    if(lineas.get(i)->getID() == idLinea){
                        lineas.get(i)->actualizarExistenciasTotales();
                        break;
                    }
                }
                
                return true;
            }
        }
        return false;
    }
};

int main()
{
    srand(1234);
    const int MAX_MODELOS = 8;
    const int MAX_EXISTENCIAS = 21;
    int numLineas = 5;
    int numModelos;
    Linea* l;
    ANIF_APOR a;
    
    // Generar el inventario
    for(int i=0; i<numLineas; i++){
        l = new Linea(i);
        numModelos = 3 + rand() % MAX_MODELOS; // Entre 3 y 10 modelos
        
        for(int j=0; j<numModelos; j++){
            int existencias = 1 + rand() % MAX_EXISTENCIAS; // Entre 1 y 20 existencias
            l->addModelo(existencias);
        }
        
        a.addLinea(l);
    }
    
    a.print();
    a.sort();
    cout<<"Lineas ordenadas"<<endl;
    a.print();
    
    int cod, num;
    bool comprar;
    
    do{
        cout<<"Inserte el código del modelo que quiere comprar: ";
        cin>>cod;
        cout<<"Inserte el número de existencias del modelo que quiere comprar: ";
        cin>>num;
        
        comprar = a.comprar(cod, num);
        
        if(comprar){
            cout<<"Se pudo realizar la compra!"<<endl;
        }else{
            cout<<"No se pudo realizar la compra!"<<endl;
        }
    }while(!comprar);
    
    cout<<"Inventario final: "<<endl;
    a.sort();
    a.print();
    
    return 0;
}
