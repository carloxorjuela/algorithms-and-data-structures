#include<iostream>
using namespace std;


int** crear_mat(int f, int c) {
    int** m = new int*[f];
    for (int i = 0; i < f; i++) {
        m[i] = new int[c];
        for(int j=0; j<c ; j++){
            m[i][j] =  0;
        }
    }
    return m;
}

void destruir_mat(int** m, int f) {
    for (int i = 0; i < f; i++) {
        delete[] m[i];
    }
    delete m;
}

void print_mat(int** m, int  f, int c){
    for (int i = 0; i < f; i++) {
        for(int j=0; j<c ; j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

class Cita{
    private:
    /*Añada el código aquí*/
        int paciente;
        int medico;
        int enfermedad;
    
    public:
    
    Cita(){
        /*Añada el código aquí*/
        paciente= -1;
        medico = -1;
        enfermedad = -1;
    }
    
    Cita(int p, int m, int e){
        /*Añada el código aquí*/
        paciente = p;
        medico = m;
        enfermedad = e;
    }
    
//Hacer el get y el set para cada atributo
    int getPaciente(){
        return paciente;
    }
    
    void setPaciente(int p){
        paciente = p;
    }
    
    int getMedico(){
        return medico;
    }
    
    void setMedico(int p){
        medico = p;
    }
    
    int getEnfermedad(){
        return enfermedad;
    }
    
    void setEnfermedad(int p){
        enfermedad = p;
    }
    
    
    
    Cita& operator=(const Cita& f) { 
		paciente = f.paciente;
		medico = f.medico;
		enfermedad = f.enfermedad;
	
		return *this;
	}
	
	string to_string() {
	    string s = std::to_string(paciente)+", "+std::to_string(medico)+", "+std::to_string(enfermedad);
	    return s;
	}

	friend std::ostream& operator<<(std::ostream& os, Cita& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Cita b) {
		return os << b.to_string();
	}
    
    
};


template<typename T>
class Nodo{
private:
  T dato;
  Nodo* next;

public:

 Nodo(T d){
     dato = d;
     next =  NULL;
 }
 
 ~Nodo(){
 }
 
 T get_dato(){
     return dato;
 }
 
 void set_dato(T d){
     dato = d;
 }
 
 Nodo* get_next(){
     return next;
 }
 
 void set_next(Nodo* n){
     next = n;
 }
 
 
    
};

template<typename T>
class Lista{
private:
  Nodo<T>* ptr;
  int size;

public:

    Lista(){
        ptr = NULL;
        size = 0;
    }
  
    ~Lista(){
        Nodo<T>* temp = ptr;
        if(ptr != NULL){
            Nodo<T>* temp_next = ptr->get_next();
            while(temp_next != NULL){
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; //Borrar el último nodo
        }
    }
    
    void add(T d){
        Nodo<T>* nodo = new Nodo<T>(d);
        
        if(ptr == NULL){//La lista está vacía
            ptr  = nodo;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(nodo);
        }
        size++;
    }
    
    void insert(T d, int i){
        if(i<=size && i>=0 && ptr != NULL){
            Nodo<T>* nodo = new Nodo<T>(d);
            if(i == 0){
                nodo->set_next(ptr);
                ptr = nodo;
            }else{
                int j = 0;
                Nodo<T>* temp =  ptr;
                while(j<i-1){
                    temp = temp->get_next();
                    j++;
                }
                nodo->set_next(temp->get_next());
                temp->set_next(nodo);
            }
            size++;
        }else{//Si el índice es incorrecto o la lista está vacía, se añade al final
            add(d);
        }
        
    }
    
    int get_size(){
        return size;
    }
    
    void print(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp != NULL){
                cout<<temp->get_dato()<<"\t";
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    void println(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp != NULL){
                cout<<temp->get_dato()<<endl;
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    Nodo<T>* get(int i){
        if(i>=0 && i<size){
          int j=0;
          Nodo<T>* temp = ptr;
          while(j<i){
              temp = temp->get_next();
              j++;
          }
          return temp;
        }
        return NULL;
    }
    
};

class EPSUrsa{
    private:
    /*Añada el código aquí*/
    Lista<Cita> citas;
    int** matriz;
    int np, nm, ne, nc;
    
    public:
    
    EPSUrsa(){
/*Añada el código aquí*/
        np=0;
        ne=0;
        nm=0; 
        nc=0;
    }
    
    EPSUrsa(int p, int m, int e, int c){
/*Añada el código aquí*/
        np=p;
        ne=e;
        nm=m; 
        nc=c;
        matriz = crear_mat(nm, ne);
    }
    
    ~EPSUrsa(){
        destruir_mat(matriz, nm);
    }
    
    void init_lista(){
        Cita* t;
        int p;
        int m;
        int e;
        for(int i = 0; i<nc; i++){
            p = rand()%np;
            m = rand()%nm;
            e = rand()%ne;
            t = new Cita(p,m,e);
            citas.add(*t);
        }
        cout<<"Fueron creadas "<<citas.get_size()<<" en la plataforma"<<endl;
        println();   
     }
    
    void print(){
        citas.print();
    }
    
    void println(){
        citas.println();
    }
    
    void calc_mat(){
/*Añada el código aquí*/
        int med = -1;
        int enf = -1;
        Cita cit;
        for (int i = 0; i < nc; i++) {
            cit = citas.get(i)->get_dato();
            med = cit.getMedico();
            enf = cit.getEnfermedad();
            matriz[med][enf]++;
        }
        print_mat(matriz, nm, ne);
    }
    
    int enfermedad_mayor(){
/*Añada el código aquí*/
        int may = 0;
        int may_pos = 0;
        int colenf = 0;
        for (int i = 0; i < ne; i++) {
            colenf = 0;
            for (int j = 0; j < nm; j++) {
                colenf+= matriz[j][i];
            }
            if(may < colenf){
                may = colenf;
                may_pos = i;
            }
        }
        return may_pos;
    }
    
    int enfermedad_menor(){
/*Añada el código aquí*/
        int men = nc+1;
        int men_pos = 0;
        int colenf = 0;
        for (int i = 0; i < ne; i++) {
            colenf = 0;
            for (int j = 0; j < nm; j++) {
                colenf+= matriz[j][i];
            }
            if(men > colenf){
                men = colenf;
                men_pos = i;
            }
        }
        return men_pos;
    }
    
    int medico_mayor(){
        /*Añada el código aquí*/
        int may = 0;
        int may_pos = 0;
        int filmed = 0;
        for (int i = 0; i < nm; i++) {
            filmed = 0;
            for (int j = 0; j < ne; j++) {
                filmed+= matriz[i][j];
            }
            if(may < filmed){
                may = filmed;
                may_pos = i;
            }
        }
        return may_pos;
    }
    
    int medico_menor(){
/*Añada el código aquí*/
        int men = nc+1;
        int men_pos = 0;
        int filmed = 0;
        for (int i = 0; i < nm; i++) {
            filmed = 0;
            for (int j = 0; j < ne; j++) {
                filmed+= matriz[i][j];
            }
            if(men > filmed){
                men = filmed;
                men_pos = i;
            }
        }
        return men_pos;
    }
    
    float promedio_citas(){
/*Añada el código aquí*/
        //return (float)nc/nm;
        float total = 0;
        int filmed = 0;
        for (int i = 0; i < nm; i++) {
            for (int j = 0; j < ne; j++) {
                total+= matriz[i][j];
            }
        }
        return total/nm;
        
    }
    
    
    int medico_mayor_e(int e){
/*Añada el código aquí*/
        int may = matriz[0][e];
        int may_pos = 0;
        for (int i = 1; i < nm; i++) {
            if(may < matriz[i][e]){
                may = matriz[i][e];
                may_pos = i;
            }
        }
        return may_pos;
    }
    
    
};

int main()
{
    srand(1234);
    int p = 10;
    int m = 10;
    int e = 10;
    int c = 100;
    EPSUrsa eps = EPSUrsa(p,m,e,c);
    eps.init_lista();
    
    cout<<endl;
    eps.calc_mat();
    
    

    cout<<"La enfermedad con mayor prevalencia es "<<eps.enfermedad_mayor()<<endl;
    cout<<"La enfermedad con menor prevalencia es "<<eps.enfermedad_menor()<<endl;
    cout<<"El medico con mayor numero de citas es "<<eps.medico_mayor()<<endl;
    cout<<"El medico con menor numero de citas es "<<eps.medico_menor()<<endl;
    cout<<"El promedio de citas por medico es "<<eps.promedio_citas()<<endl;
    for(int i=0; i<e; i++){
        cout<<"La enfermedad "<<i<<" fue atendida con mayor frecuencia por el medico "<<eps.medico_mayor_e(i)<<endl;
    }
    
    return 0;
}
