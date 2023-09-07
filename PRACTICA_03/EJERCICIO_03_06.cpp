// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 6

// Problema planteado: Generar una matriz NxN, que se llene con la serie de Fibonacci.

#include <iostream>
using namespace std;

void llenarMatrizFibonacci(int matriz[][100], int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = a;
            int temp = a;
            a = b;
            b = temp + b;
        }
    }
}

int main() {
    int n;

    cout << "Ingrese el valor de n para el tamaño de la matriz: ";
    cin >> n;

    int matriz[100][100]; // Declarar una matriz suficientemente grande

    llenarMatrizFibonacci(matriz, n);

    // Imprimir la matriz resultante
    cout << "Matriz generada de orden " << n << "x" << n << " con la serie de Fibonacci:" << endl;
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