// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva
  
// Fecha creación: 07/09/2023
  
// Fecha modificación: 07/09/2023
  
// NC:mero de ejericio: 12
  
// Problema planteado: . Ingresa una matriz de NxN y a continuación:
// a. Elimine una fila ingresada por el usuario.
// b. Elimine una columna ingresada por el usuario.
// c. Inserte una fila por un valor determinado por el usuario.
// d. Inserte una columna por un valor determinado por el usuario.

#include <iostream>
#include <vector>
using namespace std;

// Función para imprimir la matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para eliminar una fila de la matriz
vector<vector<int>> eliminarFila(const vector<vector<int>>& matriz, int fila) {
    vector<vector<int>> nuevaMatriz = matriz;
    nuevaMatriz.erase(nuevaMatriz.begin() + fila);
    return nuevaMatriz;
}

// Función para eliminar una columna de la matriz
vector<vector<int>> eliminarColumna(const vector<vector<int>>& matriz, int columna) {
    int n = matriz.size();
    vector<vector<int>> nuevaMatriz = matriz;
    for (int i = 0; i < n; i++) {
        nuevaMatriz[i].erase(nuevaMatriz[i].begin() + columna);
    }
    return nuevaMatriz;
}

// Función para insertar una fila en la matriz
vector<vector<int>> insertarFila(const vector<vector<int>>& matriz, int valor) {
    int n = matriz.size();
    vector<int> nuevaFila(n, valor);
    vector<vector<int>> nuevaMatriz = matriz;
    nuevaMatriz.push_back(nuevaFila);
    return nuevaMatriz;
}

// Función para insertar una columna en la matriz
vector<vector<int>> insertarColumna(const vector<vector<int>>& matriz, int valor) {
    int n = matriz.size();
    vector<vector<int>> nuevaMatriz = matriz;
    for (int i = 0; i < n; i++) {
        nuevaMatriz[i].push_back(valor);
    }
    return nuevaMatriz;
}

int main() {
    int n;

    cout << "Ingrese el tamaño de la matriz (N): ";
    cin >> n;

    // Declarar y llenar la matriz original con valores aleatorios
    vector<vector<int>> matriz(n, vector<int>(n));
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    // Imprimir la matriz original
    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);

    // a. Eliminar una fila ingresada por el usuario
    int filaEliminar;
    cout << "Ingrese la fila que desea eliminar (0-" << n - 1 << "): ";
    cin >> filaEliminar;
    if (filaEliminar >= 0 && filaEliminar < n) {
        matriz = eliminarFila(matriz, filaEliminar);
        cout << "Matriz después de eliminar la fila:" << endl;
        imprimirMatriz(matriz);
    } else {
        cout << "Fila no válida." << endl;
    }

    // b. Eliminar una columna ingresada por el usuario
    int columnaEliminar;
    cout << "Ingrese la columna que desea eliminar (0-" << n - 1 << "): ";
    cin >> columnaEliminar;
    if (columnaEliminar >= 0 && columnaEliminar < n) {
        matriz = eliminarColumna(matriz, columnaEliminar);
        cout << "Matriz después de eliminar la columna:" << endl;
        imprimirMatriz(matriz);
    } else {
        cout << "Columna no válida." << endl;
    }

    // c. Insertar una fila con un valor determinado por el usuario
    int valorFila;
    cout << "Ingrese el valor para la nueva fila: ";
    cin >> valorFila;
    matriz = insertarFila(matriz, valorFila);
    cout << "Matriz después de insertar la fila:" << endl;
    imprimirMatriz(matriz);

    // d. Insertar una columna con un valor determinado por el usuario
    int valorColumna;
    cout << "Ingrese el valor para la nueva columna: ";
    cin >> valorColumna;
    matriz = insertarColumna(matriz, valorColumna);
    cout << "Matriz después de insertar la columna:" << endl;
    imprimirMatriz(matriz);

    return 0;
}