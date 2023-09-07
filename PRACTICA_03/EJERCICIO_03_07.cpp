// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 7

// Problema planteado: Efectuar la suma de una matriz tridimensional de orden n x n x n

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Ingrese el valor de n para el tamaño de la matriz tridimensional: ";
    cin >> n;

    // Declarar y crear una matriz tridimensional de orden n x n x n
    int matriz[n][n][n];

    // Llenar la matriz con valores (esto es solo un ejemplo, puedes ingresar tus propios valores)
    cout << "Ingrese los elementos de la matriz tridimensional:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> matriz[i][j][k];
            }
        }
    }

    // Calcular la suma de todos los elementos de la matriz
    int suma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                suma += matriz[i][j][k];
            }
        }
    }

    // Imprimir la suma
    cout << "La suma de todos los elementos de la matriz tridimensional es: " << suma << endl;

    return 0;
}
