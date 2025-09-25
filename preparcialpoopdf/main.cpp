
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<math.h>

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
    
    void addExistencias(int n){ //Método paraañadir o restar de las existencias de un modelo
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
	    //comparar menor a mayor
	       if (this->existencias < t->getExistencias()) {
	           return -1;
	       }else if(this->existencias > t-> getExistencias()){
	           return -1;
	       }else{
	           	//si empate, comparar id de mayor a menor
	           if (this -> id < t-> getID()){
	               return -1;
	           }else if(this ->id < getID()){
	               return 1;
	           }
	       }
	    /* Implementar la cardinalidad, usando -> para los métodos de acceso a los datos*/
	    return 0;
	}
    
    int compareTo(Modelo& t){
    //comparar menor a mayor
        if ( this )

	    
	    
	//si empate, comparar id de mayor a menor
	    
	    
	    /* Implementar la cardinalidad, usando . para los métodos de acceso a los datos*/
	    
	    return 0;
	}
    
};

template <typename T>
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

template <typename T>
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
    int contModelos;
    int existenciasTotales;
    Lista<Modelo*> lista;  // Lista de apuntadores de modelos
    
    /*Definir los atributos, incluida la 
    lista de apuntadores de modelos - Modelo* */

public:
    Linea(){
        id = -1;
        contModelos = 0;
        existenciasTotales = 0;
    }
    
    Linea(int i){
        id = i;
        contModelos =0;
        existenciasTotales = 0;
    }
    
    void addModelo(int existencias){
        //Crear un modelo nuevo, asignándole el id apropiado y las existencias
        int modeloId = id * 100 + contModelos;
        Modelo * nuevoModelo = new Modelo(modeloId, existencias);
        
        //Añadir el nuevo modelo a la lista
        lista.add(nuevoModelo)
        //Actualizar las existencias totales
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
        cout<<"ID :"<<id<<": ";
        lista.print();
        cout<<endl;
    }
    
    string to_string(){
        string s = "ID :"+std::to_string(id)+" : ";
        for(int i=0; i<lista.getSize();i++){
            s += lista.get(i)->getDato()->to_string()+", ";
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
		return *this;
	}
	
	int getSize(){
	    return lista.getSize();
	}
	
	int compareTo(Linea* t){
	    /* Implementar la cardinalidad, usando -> para los métodos de acceso a los datos*/
	    return 0;
	}
    
    int compareTo(Linea& t){
	    /* Implementar la cardinalidad, usando . para los métodos de acceso a los datos*/
	    
	    return 0;
	}
	
	void sort(){
	    int size = getSize();
	    if(size > 0){
	        Modelo* temp;
    	    int posmin = 0;
    	    for(int i=0; i<size-1; i++){
    	        posmin = i;
    	        for(int j=i; j<size; j++){
    	            if(lista.get(j)->compareTo(lista.get(posmin)) == -1){
    	                posmin = j;
    	            }
    	        }
    	        temp = lista.get(posmin)->getDato();
    	        lista.get(posmin)->setDato(lista.get(i)->getDato());
    	        lista.get(i)->setDato(temp);
    	    }
	    }
	}
    
};

template <typename T>
class Vector{
/* Incluya su implementación de Vector*/
    
};


class ANIF_APOR{
    //Definir el atributo que almacena las líneas (apuntadores a lineas, Linea*) Vector<Linea*> lineas;
public:
    ANIF_APOR(){
        
    }
    
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
	        Linea* temp;
    	    int posmin = 0;
    	    for(int i=0; i<size-1; i++){
    	        posmin = i;
    	        for(int j=i; j<size; j++){
    	            if(lineas.get(j)->compareTo(lineas.get(posmin)) == -1){
    	                posmin = j;
    	            }
    	        }
    	        temp = lineas.get(posmin);
    	        lineas.set(posmin,lineas.get(i));
    	        lineas.set(i,temp);
    	    }
    	    

    	    /*Ordenar cada linea, para que sus modelos aparezcan ordenados */
    	    
	    }
	}
	
	Modelo* getModelo(int id){
	    /*Implementar la búsqueda de un modelo entre todas las líneas. Debe retornar NULL si no lo encuentra
        */
	    return NULL;
	}
	
	bool comprar(int id, int num){
	    Modelo* m = getModelo(id);
	    if(m != NULL){
	        if(m->getExistencias() >= num){
	            m->addExistencias(-num);
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
    
    /*
    Escriba aquí el código para generar el inventario.
    Debe crear cada línea, con su id correspondiente, y debe añadir los modelos a cada línea.
    El número de modelos de cada línea está entre 3 y 10. 
    El número de existencias de cada modelo está entre 1 y 20
    Añadir cada línea al objeto a de la clase ANIF_APOR
    */
   
    
    /*
    //Prueba de la clase Linea
    Linea* l = new Linea(0);
    l->addModelo(5);
    l->addModelo(2);
    l->addModelo(2);
    l->addModelo(4);
    l->addModelo(5);
    l->sort();
    l->print();
    
    Linea* l2 = new Linea(1);
    l2->addModelo(1);
    l2->addModelo(2);
    l2->addModelo(3);
    
    a.addLinea(l);
    a.addLinea(l2);
*/
    
    a.print();
    a.sort();
    cout<<"Lineas ordenadas"<<endl;
    a.print();
    
    int cod;
    int num;
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
