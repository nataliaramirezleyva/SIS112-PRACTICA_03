// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 5

// Problema planteado: Generar la matriz para un orden NxN
// Sea n=5
// 1 2 3 4 5
// 3 4 5 6 7
// 5 6 7 8 9
// 7 8 9 10 11
// 9 10 11 12 13

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Ingrese el valor de n para el tamaño de la matriz: ";
    cin >> n;

    int valor = 1; // Valor inicial para llenar la matriz

    // Declarar una matriz de orden NxN
    int matriz[n][n];

    // Llenar la matriz con valores consecutivos
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = valor++;
        }
    }

    // Imprimir la matriz resultante
    cout << "Matriz generada de orden " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j];
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
