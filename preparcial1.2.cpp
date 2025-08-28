#include <iostream>
#include <string>
#include "Lista.h"
#include "Vector.h"

using namespace std;

// Estructura para representar un libro
class Libro {
public:
    int id;
    string titulo;
    int idAutor;
    int idGenero;
    int numPaginas;
    double valor;
    
    /*Constructores implementados*/
    Libro() : id(-1), titulo(""), idAutor(-1), idGenero(-1), numPaginas(0), valor(0.0) {}
    
    Libro(int id, string titulo, int idAutor, int idGenero, int numPaginas, double valor) 
        : id(id), titulo(titulo), idAutor(idAutor), idGenero(idGenero), numPaginas(numPaginas), valor(valor) {}
    
    int getAutor(){
        return idAutor;
    }
    
    string getTitulo(){
        return titulo;
    }
    
    double getValor(){
        return valor;
    }
    
    string to_string(){
        return std::to_string(id)+" "+titulo+" "+std::to_string(idAutor)+" "+std::to_string(valor);
    }
};


// Clase Autor
class Autor {
    /*Atributos definidos*/
    int id;
    string nombre;
    int edad;
    LinkedList<Libro> libros;

public:
    Autor() : id(-1), nombre(""), edad(-1) {}
    Autor(int id, string nombre, int edad) : id(id), nombre(nombre), edad(edad) {}
    
    int getId(){
        return id;
    }
    
    void addLibro(Libro l){
        libros.add(l);
    }
    
    string getNombre(){
        return nombre;
    }
    
    int getNumLibros(){
        return libros.getSize();
    }
    
    string to_string(){
        return std::to_string(id)+" "+nombre+" "+std::to_string(edad)+" años, "+std::to_string(libros.getSize())+" libros";
    }
};

class ItemInventario{
    int idlibro;
    int cantidad;
public:
    ItemInventario(): idlibro(-1), cantidad(-1) {}
    ItemInventario(int idlibro, int cantidad): idlibro(idlibro), cantidad(cantidad) {}
    
    int getIdLibro(){
        return idlibro;
    }
    
    int getCantidad(){
        return cantidad;
    }
    
    string to_string(){
        return "("+std::to_string(idlibro)+","+std::to_string(cantidad)+")";
    }
    
    friend std::ostream& operator<<(std::ostream& os, ItemInventario& obj) {
        return os << obj.to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, ItemInventario obj) {
        return os << obj.to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, ItemInventario* obj) {
        return os << obj->to_string();
    }
};

// Clase Libreria
class Libreria {
public:
    int id;
    string nombre;
    LinkedList<ItemInventario> inventario; // (idLibro, numCopias)
    
    Libreria() : id(-1), nombre("") {}
    Libreria(int id, string nombre) : id(id), nombre(nombre) {}
    
    string getNombre(){
        return nombre;
    }
    
    void addLibro(int idLibro, int copias) {
        /*Añadir un nuevo ítem de inventario a la librería*/
        ItemInventario item(idLibro, copias);
        inventario.add(item);
    }
    
    void printInventario(){
        inventario.print();
    }
    
    ItemInventario getInventario(int i){
        //Retornar el i-ésimo ítem del inventario
        return inventario.get(i);
    }
    
    int getInventarioSize(){
        return inventario.getSize();
    }
    
    int getTotalLibros(){
        int tot = 0;
        /*Calcule el número total de libros en el inventario de la librería 
        (Sumatoria de las existencia de cada ítem de inventario)*/
        for(int i = 0; i < inventario.getSize(); i++){
            tot += inventario.get(i).getCantidad();
        }
        return tot;
    }
    
    string to_string(){
        return std::to_string(id)+" "+nombre;
    }
};

// Clase Editorial
class Editorial {
    Vector<Autor> autores;
    Vector<Libro> libros;
    Vector<Libreria> librerias;

public:
    
    Editorial(){}
    
    Vector<Autor>& getAutores(){
        return autores;
    }
    Vector<Libreria>& getLibrerias(){
        return librerias;
    }
    Vector<Libro>& getLibros(){
        return libros;
    }
    
    void addAutor(int id, string nombre, int edad) {
        autores.add(Autor(id, nombre, edad));
    }

    void addLibro(int id, string titulo, int idAutor, int idGenero, int numPaginas, double valorVenta) {
        /*Crear y añadir un libro a la lista de libros de la editorial, y a la lista de libros
        del autor, siempre y cuando este exista.*/
        
        Libro nuevoLibro(id, titulo, idAutor, idGenero, numPaginas, valorVenta);
        libros.add(nuevoLibro);
        
        // Buscar el autor y añadir el libro a su lista
        bool autorEncontrado = false;
        for(int i = 0; i < autores.getSize(); i++){
            if(autores[i].getId() == idAutor){
                autores[i].addLibro(nuevoLibro);
                autorEncontrado = true;
                break;
            }
        }
        
        if(!autorEncontrado){
            cout << "Error: Autor no encontrado." << endl;
        }
    }
    
    void addLibroInventario(int libreria, int idLibro, int cant){
        /*Añada un libro al inventario de una librería*/
        if(libreria >= 0 && libreria < librerias.getSize()){
            librerias[libreria].addLibro(idLibro, cant);
        }
    }

    void addLibreria(int id, string nombre) {
        librerias.add(Libreria(id, nombre));
    }
    
    void printLibrerias(){
        /*Imprima la lista de librerías, y su inventario*/
        for(int i = 0; i < librerias.getSize(); i++){
            cout << "Inventario Librería " << librerias[i].getNombre() << ":" << endl;
            librerias[i].printInventario();
        }
    }
    
    string printLibros(){
        string s = "";
        /*Imprima el número de libros y la lista de libros de la editorial*/
        s += "Size: " + std::to_string(libros.getSize()) + " libros.\n";
        for(int i = 0; i < libros.getSize(); i++){
            s += libros[i].to_string() + "\n";
        }
        return s;
    }
    
    void autorMasLibrosInventario(){
        /*Calcule el autor con más libros en inventario entre todas las librerías.*/
        Vector<int> invent;
        
        // Inicializar vector de inventario por autor
        for(int i = 0; i < autores.getSize(); i++){
            invent.add(0);
        }
        
        // Recorrer todas las librerías y su inventario
        for(int i = 0; i < librerias.getSize(); i++){
            for(int j = 0; j < librerias[i].getInventarioSize(); j++){
                ItemInventario item = librerias[i].getInventario(j);
                int idLibro = item.getIdLibro();
                int cantidad = item.getCantidad();
                
                // Buscar el autor de este libro
                for(int k = 0; k < libros.getSize(); k++){
                    if(libros[k].id == idLibro){
                        int idAutor = libros[k].getAutor();
                        // Acumular en el vector de inventario por autor (id-1 porque los id empiezan en 1)
                        invent[idAutor-1] += cantidad;
                        break;
                    }
                }
            }
        }
        
        /*Con base en el inventario total por autor, encuentre el mayor elemento.*/
        int mayAut = 0;
        int mayInv = invent[0];
        
        for(int i = 1; i < invent.getSize(); i++){
            if(invent[i] > mayInv){
                mayInv = invent[i];
                mayAut = i;
            }
        }
        
        cout<<"El autor con mayor inventario de libros es: "+autores[mayAut].getNombre()<<endl;
    }
    
    void libreriaMasInventario(){
        /*Recorra todas las librerías, calculando el número total de libros y verificando cuál tiene 
        el mayor número de libros totales*/
        
        int maxLibros = 0;
        int libreriaMax = 0;
        
        for(int i = 0; i < librerias.getSize(); i++){
            int totalLibros = librerias[i].getTotalLibros();
            if(totalLibros > maxLibros){
                maxLibros = totalLibros;
                libreriaMax = i;
            }
        }
        
        cout << "La librería con mayor número de libros es " << librerias[libreriaMax].getNombre() 
             << " con " << maxLibros << " libros." << endl;
    }
    
    void libreriaMasValorInventario(){
        /*Similar a autorMasLibrosInventario, pero calcule el valor en dinero del inventario, con base en el valor del libro.*/
        
        double maxValor = 0;
        int libreriaMax = 0;
        
        for(int i = 0; i < librerias.getSize(); i++){
            double valorTotal = 0;
            
            for(int j = 0; j < librerias[i].getInventarioSize(); j++){
                ItemInventario item = librerias[i].getInventario(j);
                int idLibro = item.getIdLibro();
                int cantidad = item.getCantidad();
                
                // Buscar el valor de este libro
                for(int k = 0; k < libros.getSize(); k++){
                    if(libros[k].id == idLibro){
                        valorTotal += libros[k].getValor() * cantidad;
                        break;
                    }
                }
            }
            
            if(valorTotal > maxValor){
                maxValor = valorTotal;
                libreriaMax = i;
            }
        }
        
        cout << "La librería con mayor valor total de libros es " << librerias[libreriaMax].getNombre() 
             << " con " << (int)maxValor << " pesos." << endl;
    }
    
    void autorMasTitulos(){
        /*Recorra todos los autores, calculando el número total de libros que tiene y verificando cuál tiene 
        el mayor número de títulos*/
        
        int maxTitulos = 0;
        int autorMax = 0;
        
        for(int i = 0; i < autores.getSize(); i++){
            int numTitulos = autores[i].getNumLibros();
            if(numTitulos > maxTitulos){
                maxTitulos = numTitulos;
                autorMax = i;
            }
        }
        
        cout << "El autor con más libros es " << autores[autorMax].getNombre() 
             << " con " << maxTitulos << " libros escritos." << endl;
    }
    
};

int main() {
    //srand(time(0));
    srand(1234);
    Editorial editorial;
    
    // Nombres de libros
    string titulos[23] = {"Red Sorghum", "The Three-Body Problem", "Wild Grass", "Legends of the Condor Heroes", "Fortress Besieged", "Moonlight Mirage", "Quantum Sands", "Silent Echoes", "Whispering Bamboo", "The Infinite Bridge", "Dragon's Curse", "Nebula Chronicles", "Tales of the Fallen Empire", "Celestial Labyrinth", "The Golden Era", "Shadow Puppets", "The Fractal Mind", "Phantom Blossoms", "Sword of Destiny", "Echoes of the Past", "Parallel Horizons", "Singularity Rift", "Eternal Lanterns"};
    
    // Agregar autores
    editorial.addAutor(1, "Mo Yan", 68);
    editorial.addAutor(2, "Liu Cixin", 60);
    editorial.addAutor(3, "Lu Xun", 56);
    editorial.addAutor(4, "Jin Yong", 72);
    editorial.addAutor(5, "Qian Zhongshu", 85);
    
    // Agregar libros: id, título, autor, género, número de páginas, valor
    for (int i = 1; i <= 23; i++) {
        editorial.addLibro(i, titulos[i-1], (rand() % 5) + 1, (rand() % 6) +1, rand()%200 + 1, (rand()%100000)+1);
    }
    
    editorial.addLibreria(1, "Librería Central");
    editorial.addLibreria(2, "Casa del Libro");
    editorial.addLibreria(3, "Lectura China");
    
    // Agregar libros a librerías: librería, id del libro, cantidad
    for (int i = 1; i <= 23; i++) {
        editorial.addLibroInventario(rand() % 3, i, (rand() % 5) + 1);
    }
    
    //Mostrar lista de autores
    cout<<editorial.getAutores()<<endl;
    
    //Mostrar lista de libros
    cout<<editorial.printLibros()<<endl;
    
    //Mostrar inventario de librerías
    editorial.printLibrerias();
    
    editorial.autorMasTitulos();
    
    editorial.autorMasLibrosInventario();
    
    editorial.libreriaMasInventario();
    
    editorial.libreriaMasValorInventario();
    
    return 0;
}
