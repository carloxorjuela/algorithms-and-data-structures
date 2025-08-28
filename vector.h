// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // FUNCIONES_H

using namespace std;

#ifndef FUNCIONES_TO_STRING
#define FUNCIONES_TO_STRING

// Verificación si un tipo tiene un método to_string()
template <typename, typename = void>
struct has_to_string : std::false_type {};

template <typename T>
struct has_to_string<T, std::void_t<decltype(std::declval<T>().to_string())>> 
    : std::is_same<decltype(std::declval<T>().to_string()), std::string> {};

#endif // FUNCIONES_H



template <typename T>
class Vector{
    T* v;
    int capacity;
    int size;
    
    
public:
    Vector(){
        capacity = 10;
        size = 0;
        v = new T[capacity];
    }
    
    Vector(int c){
        capacity = c;
        size = 0;
        v = new T[capacity];
    }
    
    ~Vector(){
        //delete[] v;
    }
    
    int getSize(){
        return size;
    }
    
    int getCapacity(){
        return capacity;
    }
    
    T get(int i){
        if(i>=0 && i<size){
            return v[i];
        }else{
            return -1;
        }
    }
    
    void corrimientoDer(int i){
        //Corre todos los elementos desde la posición insert
        //una posición a la derecha
        for(int j = size; j > i; j--){
            v[j] = v[j-1];
        }
    }
    
    void insert(T d, int i){
        //Inserta el elemento d en la posición i
        //luego de correr a la derecha el elemento 
        //en i y todos los elementos a la derecha
        //de i
        if(size == capacity){
            resize();
        }
        corrimientoDer(i);
        v[i] = d;
        size++;
    }
    
    void corrimientoIzq(int i){
        //Corre todos los elementos desde la izquierda hacia la posición i
        for(int j = i; j < size - 1; j++){
            v[j] = v[j+1];
        }
    }
    
    void removeI(int i){
        corrimientoIzq(i);
        size--;
    }
    
    int find(T d){
        //Retorne la posición donde encontró el dato o -1 si no lo encontró
        for(int i = 0; i < size; i++){
            if(v[i] == d){
                return i;
            }
        }
        return -1;
    }
    
    void resize(){
        capacity *= 2;
        T* nv = new T[capacity];
        for(int i=0; i<size; i++){
            nv[i] = v[i];
        }
        delete[] v;
        v = nv;
    }
    
    void add(T d){
        if(size == capacity){
            resize();
        }
        v[size++] = d;
    }
    
    void print(){
        for(int i = 0; i<size ;i++){
            cout<<v[i]<<"\t";
        }
        cout<<endl;
    }
    
    
    T& operator[](size_t index) {
        return v[index];
    }

    const T& operator[](size_t index) const {
        return v[index];
    }

    
    // Método to_string() para objetos con método to_string()
    template <typename U = T>
    typename std::enable_if<has_to_string<U>::value, string>::type
    to_string() const {
        ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < size; i++) {
            oss << v[i].to_string();
            if (i < size - 1) oss << ", ";
        }
        oss << "]";
        return oss.str();
    }

    // Método to_string() para punteros a objetos con to_string()
    template <typename U = T>
    typename std::enable_if<std::is_pointer<U>::value && has_to_string<typename std::remove_pointer<U>::type>::value, string>::type
    to_string() const {
        ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < size; i++) {
            if (v[i]) {
                oss << v[i]->to_string();
            } else {
                oss << "null";
            }
            if (i < size - 1) oss << ", ";
        }
        oss << "]";
        return oss.str();
    }

    // Método to_string() para tipos numéricos
    template <typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value, string>::type
    to_string() const {
        ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < size; i++) {
            oss << std::to_string(v[i]);
            if (i < size - 1) oss << ", ";
        }
        oss << "]";
        return oss.str();
    }

    // Método to_string() por defecto
    template <typename U = T>
    typename std::enable_if<!has_to_string<U>::value && !std::is_arithmetic<U>::value, string>::type
    to_string() const {
        return "[No to_string() available]";
    }
    
    
    
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& obj) {
        return os << obj.to_string();
    }
    
    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {
            v = other.v;
            size = other.size;
            capacity = other.capacity;
        }
        return *this;
    }

    
};
