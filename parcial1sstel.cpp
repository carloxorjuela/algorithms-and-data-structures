#include <iostream>
#include <ctime>  // Para srand(time(0))

using namespace std;


/*código para la matriz*/

// Función para crear una matriz dinámica
int** crear_mat(int f, int c) {
    int** m = new int*[f];
    for (int i = 0; i < f; i++) {
        m[i] = new int[c];
        for (int j = 0; j < c; j++) {
            m[i][j] = 0;
        }
    }
    return m;
}

// Función para destruir la matriz
void destruir_mat(int** m, int f) {
    for (int i = 0; i < f; i++) {
        delete[] m[i];
    }
    delete[] m;
}

// Función para imprimir la matriz
void print_mat(int** m, int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}


/*código para el arreglo*/

int* crear_arreglo(int n) {
    int* arr = new int[n];  // Crear arreglo dinámico de tamaño n
    for (int i = 0; i < n; i++) {
        arr[i] = 0;  // Inicializar con 0 (o cualquier otro valor que desees)
    }
    return arr;
}

// Función para destruir el arreglo
void destruir_arreglo(int* arr) {
    delete[] arr;  // Liberar la memoria del arreglo dinámico
}

// Función para imprimir el arreglo
void print_arreglo(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

// Función para llenar el arreglo con valores
void llenar_arreglo(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Introduce el valor para el elemento " << i << ": ";
        cin >> arr[i];
    }
}

//clase Venta

class Venta {
private:
    int cliente;
    int vendedor;
    int producto;
public:
    Venta() {
        cliente = -1; 
        vendedor = -1;
        producto = -1;
    }
    Venta(int c, int v, int p) {
        cliente = c;
        vendedor = v;
        producto = p;
    }
    
    //Getters y Setters
    int getCliente() const { 
        return cliente; 
    }
    void setCliente(int c) { 
        cliente = c; 
    }
    int getVendedor() const { 
        return vendedor; 
    }
    void setVendedor(int v) { 
        vendedor = v; 
    }

    int getProducto() const { 
        return producto; 
    }
    void setProducto(int p) { 
        producto = p; 
    }

    Venta& operator=(const Venta& f) {
        cliente = f.cliente;
        vendedor = f.vendedor;
        producto = f.producto;
        return *this;
    }

    string to_string() const {
        return std::to_string(cliente) + ", " + std::to_string(vendedor) + ", " + std::to_string(producto);
    }

    friend std::ostream& operator<<(std::ostream& os, const Venta& s) {
        return os << s.to_string();
    }
};

// Clase nodo con plantilla

//poner aquí su código de listas con los comentarios realizados en las clases



// Clase Distribuidora
class Distribuidora {
private:
   
//completar el código que corresponde a esta sección


public:
    Distribuidora(int c = 100, int v = 100, int p = 100, int s = 1000): nc(c), nv(v), np(p), ns(s) {
        matriz = crear_mat(nv, np);
        arreglo = crear_arreglo(nv);
    }

    ~Distribuidora() {
        destruir_mat(matriz, nv);
        destruir_arreglo(arreglo);
    }
    
    //crear el método init_lista()

    void init_lista() {
       
    }

    void print() {
        ventas.mostrar();
    }
    
     void generar_arreglo() {
        Nodo<Venta>* ptr = ventas.get(0);
        while (ptr != nullptr) {
            arreglo[ptr->getValor().getVendedor()]++;  // Incrementar el vendedor correspondiente en el arreglo
            ptr = ptr->getSiguiente();
        }
        cout << "Arreglo de vendedores: " << endl;
        print_arreglo(arreglo, nv);  // Imprimir el arreglo con los vendedores y sus ventas
    }
    
    
    //crear el método calcular matriz
    

   //crear el método vendedor_con_mas_ventas_por_producto
   
    
    //crear el método calcular_promedio_ventas
    
};

int main() {
    srand(time(0));  // Inicialización del generador de números aleatorios con el tiempo actual
    int c = 10;
    int v = 10;
    int p = 10;
    int s = 100;
    Distribuidora dis = Distribuidora(c, v, p, s);
    dis.init_lista();
    cout << endl;
    dis.calcular_matriz();
    for (int i = 0; i < p; i++) {
        cout << "El vendedor con más ventas en el producto " << i << " es: " 
             << dis.vendedor_con_mas_ventas_por_producto(i) << endl;
    }
    cout << "-------------datos del arreglo-------------" << endl;
    dis.generar_arreglo();
    dis.calcular_promedio_ventas();
    return 0;
}
