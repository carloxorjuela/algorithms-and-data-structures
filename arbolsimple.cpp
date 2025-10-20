#include <iostream>
#include <string>

using namespace std;

class Nodo{
    int dato;
    Nodo* izq;
    Nodo* der;
public:
    Nodo(int valor) : dato(valor), izq(nullptr), der(nullptr) {}

    int getDato() const { return dato; }
    Nodo* getIzq() const { return izq; }
    Nodo* getDer() const { return der; }

    void setIzq(Nodo* nodo) { izq = nodo; }
    void setDer(Nodo* nodo) { der = nodo; }

    bool esHoja() const { return izq == nullptr && der == nullptr; }

    string to_string() const {
        return std::to_string(dato);
    }

    void print(){
        cout<<to_string();
    }


    friend ostream& operator<<(ostream& os, const Nodo& nodo) {
        os << nodo.to_string();
        return os;
    }
};

class Arbol{
    Nodo* raiz;
public:
    Arbol() : raiz(nullptr) {}

    void addRec(Nodo* nodo, int dato) {
        if(nodo->getDato() != dato){
            if(nodo->getDato() > dato){
                if(nodo->getIzq() == nullptr){
                    nodo->setIzq(new Nodo(dato));
                }else{
                    addRec(nodo->getIzq(), dato);
                }
            }else{
                if(nodo->getDer() == nullptr){
                    nodo->setDer(new Nodo(dato));
                }else{
                    addRec(nodo->getDer(), dato);
                }
            }
            
        }
    }

    void add(int dato){
        if(!raiz){
            raiz = new Nodo(dato); 
        }
        else{
            addRec(raiz, dato);
        }
    }


    void preordenRec(Nodo* nodo){
        if(nodo){
            cout<<nodo->getDato()<<", ";
            preordenRec(nodo->getIzq());
            preordenRec(nodo->getDer());
        }
    }

    void preorden(){
        preordenRec(raiz);
        cout<<endl;
    }

    void inordenRec(Nodo* nodo){
        if(nodo){
            inordenRec(nodo->getIzq());
            cout<<nodo->getDato()<<", ";
            inordenRec(nodo->getDer());
        }
    }

    void inorden(){
        inordenRec(raiz);
        cout<<endl;
    }

    void posordenRec(Nodo* nodo){
        if(nodo){
            posordenRec(nodo->getIzq());
            posordenRec(nodo->getDer());
            cout<<nodo->getDato()<<", ";
        }
    }

    void posorden(){
        posordenRec(raiz);
        cout<<endl;
    }

};

int main(){

    srand(1234);
    Arbol arbol;
    int t;
    for(int i = 0; i<10;i++){
        t = rand()%100;
        cout<<t<<", ";
        arbol.add(t);
    }
    cout<<endl;
    cout<<"Recorrido en preorden: "<<endl;
    arbol.preorden();

    cout<<endl;
    cout<<"Recorrido en inorden: "<<endl;
    arbol.inorden();

    cout<<endl;
    cout<<"Recorrido en posorden: "<<endl;
    arbol.posorden();

}
