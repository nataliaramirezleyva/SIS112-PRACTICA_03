// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 2

// Problema planteado: Generar la matriz espiral para un orden n :
// Sea n=3:
// 1 2 3
// 8 9 4
// 7 6 5

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el orden de la matriz espiral (n): ";
    cin >> n;

    int matriz[n][n];
    int valor = 1;
    int inicioFila = 0, finFila = n - 1;
    int inicioColumna = 0, finColumna = n - 1;

    while (valor <= n * n) {
        // Llena la fila superior de izquierda a derecha
        for (int j = inicioColumna; j <= finColumna; j++) {
            matriz[inicioFila][j] = valor++;
        }
        inicioFila++;

        // Llena la columna derecha de arriba hacia abajo
        for (int i = inicioFila; i <= finFila; i++) {
            matriz[i][finColumna] = valor++;
        }
        finColumna--;

        // Llena la fila inferior de derecha a izquierda
        for (int j = finColumna; j >= inicioColumna; j--) {
            matriz[finFila][j] = valor++;
        }
        finFila--;

        // Llena la columna izquierda de abajo hacia arriba
        for (int i = finFila; i >= inicioFila; i--) {
            matriz[i][inicioColumna] = valor++;
        }
        inicioColumna++;
    }

    // Imprime la matriz espiral
    cout << "La matriz espiral para n=" << n << " es:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

