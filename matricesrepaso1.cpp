#include <iostream>
#include <cstdlib> // para rand
#include <cmath> // para la raiz
using namespace std;
int main(){
    srand(1234);
    int n, m;
    cout << "ingrese el numero de filas (n):  ";
    cin >> n;
    cout << "ingrese el numero de filas (m):  ";
    cin >> m;
//ahora hay q almacenar la matriz con aleatorios
int a[n][m];
for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
        a[i][j] = rand()%100;
    }
//imprimir la matriz
cout<<"la matriz es n";
for(int i=0; i<n ;i++){
    for(int j=0; j<m ;j++){
        cout<<a[i][j]<<"t";
    }
    cout<<endl;
    
}


    
}
    return 0;
    
}
