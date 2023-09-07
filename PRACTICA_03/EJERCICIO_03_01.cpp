// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 1

// Problema planteado: Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por
// la fila n

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Ingrese el tamaño de la matriz (n): ";
    cin >> n;

    char terminar;

    do {
        // Declarar la matriz de orden n x n
        int matriz[n][n];

        // Leer la matriz del usuario
        cout << "Ingrese los elementos de la matriz (Ingrese los números de forma" << endl;
        cout << "horizontal presionando enter despues de cada numero):" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matriz[i][j];
            }
        }

        // Intercambiar la fila 1 por la fila n (índices 0 y n-1)
        for (int j = 0; j < n; j++) {
            int temp = matriz[0][j];
            matriz[0][j] = matriz[n - 1][j];
            matriz[n - 1][j] = temp;
        }

        // Imprimir la matriz resultante
        cout << "La matriz resultante es:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }

        cout << "¿Desea ingresar otra matriz? (s/n): ";
        cin >> terminar;

    } while (terminar == 's' || terminar == 'S');

    return 0;
}