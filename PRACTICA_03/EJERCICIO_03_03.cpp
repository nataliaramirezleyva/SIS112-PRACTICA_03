// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 3

// Problema planteado: Generar una matriz de N x N con números al azar entre A y B, y determinar:
// • La suma de la última columna
// • El producto total de la última fila
// • Obtener el mayor valor y su posición
// • Obtener la desviación estándar de todos los elementos de la matriz

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
    int N, A, B;

    cout << "Ingrese el tamaño de la matriz (N): ";
    cin >> N;

    cout << "Ingrese el valor mínimo (A): ";
    cin >> A;

    cout << "Ingrese el valor máximo (B): ";
    cin >> B;

    // Inicializar el generador de números aleatorios con una semilla
    srand(time(nullptr));

    // Declarar y llenar la matriz con números aleatorios entre A y B
    vector<vector<int>> matriz(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % (B - A + 1) + A;
        }
    }

    // Imprimir la matriz
    cout << "Matriz generada:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Calcular la suma de la última columna
    int sumaUltimaColumna = 0;
    for (int i = 0; i < N; i++) {
        sumaUltimaColumna += matriz[i][N - 1];
    }

    // Calcular el producto total de la última fila
    int productoUltimaFila = 1;
    for (int j = 0; j < N; j++) {
        productoUltimaFila *= matriz[N - 1][j];
    }

    // Encontrar el mayor valor y su posición
    int mayorValor = matriz[0][0];
    int filaMayor, columnaMayor;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] > mayorValor) {
                mayorValor = matriz[i][j];
                filaMayor = i;
                columnaMayor = j;
            }
        }
    }

    // Calcular la desviación estándar
    double media = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            media += matriz[i][j];
        }
    }
    media /= (N * N);

    double sumaCuadrados = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sumaCuadrados += pow(matriz[i][j] - media, 2);
        }
    }

    double desviacionEstandar = sqrt(sumaCuadrados / (N * N));

    // Mostrar resultados
    cout << "Suma de la última columna: " << sumaUltimaColumna << endl;
    cout << "Producto total de la última fila: " << productoUltimaFila << endl;
    cout << "Mayor valor: " << mayorValor << " (Fila: " << filaMayor << ", Columna: " << columnaMayor << ")" << endl;
    cout << "Desviación estándar de la matriz: " << fixed << setprecision(2) << desviacionEstandar << endl;

    return 0;
}
