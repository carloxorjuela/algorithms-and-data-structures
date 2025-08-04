
#include<iostream>
using namespace std;

class Vector{
private:
    int* v;
    int capacidad;    
    int size;
    
public:
    Vector(){
        capacidad = 5;
        size = 0;
        v = new int[capacidad];
    }
    
    Vector(int t){
        if(t <= 0){
            t = 1;
        }
        capacidad = t;
        size = 0;
        v = new int[capacidad];
    }
    
    
    void add(int dato) {
    if (size < capacidad) {
        v[size++] = dato;
    } else {
        cout << "Error: El vector está lleno. No se puede agregar más datos." << endl;
    }
    }
    
    
    void print(){
        for (int i = 0; i < size; i++) {
            cout<<v[i]<<"\t";
        }
        cout<<endl;
    }
    
    
};





int main()
{
    srand(1234);
    
    Vector v;
    
    for (int i = 0; i < 6; i++) {
        v.add(i*17);
    }
    
    v.print();
    
    return 0;
}
