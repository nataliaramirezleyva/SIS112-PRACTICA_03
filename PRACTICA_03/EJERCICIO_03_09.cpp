// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 9

// Problema planteado: Traspones una matriz de N x M

#include <iostream>
#include <vector>
using namespace std;

// Función para transponer una matriz
vector<vector<int>> transponerMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    int m = matriz[0].size();

    // Crear la matriz transpuesta de tamaño MxN
    vector<vector<int>> matrizTranspuesta(m, vector<int>(n));

    // Llenar la matriz transpuesta
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrizTranspuesta[j][i] = matriz[i][j];
        }
    }

    return matrizTranspuesta;
}

int main() {
    int n, m;

    cout << "Ingrese el número de filas (N) de la matriz original: ";
    cin >> n;
    cout << "Ingrese el número de columnas (M) de la matriz original: ";
    cin >> m;

    // Declarar y llenar la matriz original de tamaño NxM
    vector<vector<int>> matrizOriginal(n, vector<int>(m));
    cout << "Ingrese los elementos de la matriz original:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrizOriginal[i][j];
        }
    }

    // Obtener la matriz transpuesta
    vector<vector<int>> matrizTranspuesta = transponerMatriz(matrizOriginal);

    // Imprimir la matriz transpuesta
    cout << "Matriz transpuesta de tamaño MxN:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrizTranspuesta[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
