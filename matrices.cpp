#include <iostream>
#include <cstdlib> // para rand
#include <cmath> // para la raiz
using namespace std;
int main()
{
    const int n = 10;
    const int m = 5;
    double notas[n][m];
    srand(1234);
//enteros los transformo a decimales 
for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
        int aleatorio = rand()%100;
        notas[i][j]=1.0+(aleatorio/99.9)*4.0;
    }
    
}
//imprimo la matriz
cout<<"la matriz de tamano 10*5 es : ";
for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<notas[i][j]<<"\t";
        }
        cout<<endl;
    }
//promedio general
double suma_total = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        suma_total = suma_total + notas[i][j];
    }
}
double promedio_general = suma_total / (n * m);
cout << "el promedio general es : " << promedio_general << endl;
//promedio por estudiante y contar aprobados
double suma_estudiante;
int aprobados = 0;
for (int i = 0; i < n; i++) {
    suma_estudiante = 0;
    for (int j = 0; j < m; j++) {
        suma_estudiante = suma_estudiante + notas[i][j];
    }
    double promedio_estudiante = suma_estudiante / (m);

    cout << "el promedio del estudiante "<< i+1 <<" es : " << promedio_estudiante << endl;
    if (promedio_estudiante >= 3) {
        cout << "El estudiante " << i+1 << " APROBÓ con promedio " << promedio_estudiante << endl;
    } else {
        cout << "El estudiante " << i+1 << " NO aprobó con promedio " << promedio_estudiante << endl;
    }

}
//promedio por asignatura
double suma_asignatura;
for (int j = 0; j < m; j++) {
    suma_asignatura = 0;
    for (int i = 0; i < n; i++) {
        suma_asignatura = suma_asignatura + notas[i][j];
    }
    double promedio_asignatura = suma_asignatura / (n);

    cout << "el promedio de la asignatura "<< j+1 <<" es : " << promedio_asignatura << endl;


}
int notas_aprobadas = 0;
int total_notas = n * m; // Total de notas en la matriz

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (notas[i][j] >= 3.0) {
            notas_aprobadas++;
        }
    }
}

double porcentaje_aprobadas = (double)notas_aprobadas / total_notas * 100.0;
cout << "el porcentaje de notas aprobadas (>= 3.0) es: " << porcentaje_aprobadas << "%" << endl;

    

    return 0;        

    
    
}






