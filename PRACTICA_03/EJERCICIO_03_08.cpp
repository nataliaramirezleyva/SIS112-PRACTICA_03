// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 8

// Problema planteado: Multiplique dos matrices una de N x M y la otra de M x N

#include <iostream>
#include <vector>
using namespace std;

// Función para multiplicar dos matrices
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2) {
    int n = matriz1.size();
    int m = matriz1[0].size();
    int p = matriz2[0].size();

    // Crear la matriz resultante de tamaño NxP
    vector<vector<int>> resultado(n, vector<int>(p, 0));

    // Realizar la multiplicación de matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

int main() {
    int n, m, p;

    cout << "Ingrese el número de filas (N) de la primera matriz: ";
    cin >> n;
    cout << "Ingrese el número de columnas (M) de la primera matriz: ";
    cin >> m;

    cout << "Ingrese el número de columnas (P) de la segunda matriz: ";
    cin >> p;

    if (m != p) {
        cout << "Las matrices no pueden multiplicarse debido a dimensiones incompatibles." << endl;
        return 1;
    }

    // Declarar y llenar la primera matriz de tamaño NxM
    vector<vector<int>> matriz1(n, vector<int>(m));
    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matriz1[i][j];
        }
    }

    // Declarar y llenar la segunda matriz de tamaño MxP
    vector<vector<int>> matriz2(m, vector<int>(p));
    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cin >> matriz2[i][j];
        }
    }

    // Realizar la multiplicación de matrices
    vector<vector<int>> resultado = multiplicarMatrices(matriz1, matriz2);

    // Imprimir la matriz resultante
    cout << "Matriz resultante de la multiplicación:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
