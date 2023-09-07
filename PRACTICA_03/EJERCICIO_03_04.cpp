// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejericio: 4

// Problema planteado: En la segunda temporada de The Walking Dead, los personajes llegaron a una
// cárcel para refugiarse. La cárcel estaba rodeada de vallas por lo que los muertos
// vivientes no podían entrar en ella. Sin embargo, dentro de las instalaciones aun
// existían muertos vivientes que amenazaban a los personajes. Por tanto, Rick y
// otros miembros del grupo decidieron ir a investigar las instalaciones con el fin
// de determinar cuáles eran los lugares seguros. Para lograr su objetivo
// construyeron un mapa basado en una matriz que indicaba las zonas seguras.
// Después de un tiempo, tu grupo llega al mismo complejo y encuentra el mapa
// hecho por Rick. Para mantener a salvo a tus amigos decides diseñar e
// implementar un programa que te ayude a determinar las zonas seguras. 
// a) Mostrar la matriz que describe el área.
// b) Mostrar el número de filas y columnas que no tienen un muerto viviente.
// c) Determinar las coordenadas de los muertos vivientes en la matriz. Utilice vectores
// paralelos para almacenar la posición de los muertos vivientes. Un vector almacenara el
// índice de la fila y otro vector almacenara el índice de la columna.
// d) La cantidad de muertos vivientes que existen en toda la matriz.
// e) Determinar si dos o más muertos vivientes se encuentran en la primera columna. Si
// es así imprimir “no es posible entrar al complejo” de otro modo imprimir “es posible
// entrar al complejo”. 

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int FILAS = 3; // Número de filas de la matriz
const int COLUMNAS = 4; // Número de columnas de la matriz

// Función para mostrar la matriz
void mostrarMatriz(const vector<vector<char>>& matriz) {
    cout << "Matriz que describe el área:" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para contar filas y columnas sin muertos vivientes
void contarZonasSeguras(const vector<vector<char>>& matriz) {
    int filasSeguras = 0;
    int columnasSeguras = 0;

    for (int i = 0; i < FILAS; i++) {
        bool tieneMuertos = false;
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 'x') {
                tieneMuertos = true;
                break;
            }
        }
        if (!tieneMuertos) {
            filasSeguras++;
        }
    }

    for (int j = 0; j < COLUMNAS; j++) {
        bool tieneMuertos = false;
        for (int i = 0; i < FILAS; i++) {
            if (matriz[i][j] == 'x') {
                tieneMuertos = true;
                break;
            }
        }
        if (!tieneMuertos) {
            columnasSeguras++;
        }
    }

    cout << "Número de filas sin muertos vivientes: " << filasSeguras << endl;
    cout << "Número de columnas sin muertos vivientes: " << columnasSeguras << endl;
}

// Función para determinar las coordenadas de los muertos vivientes
void coordenadasMuertos(const vector<vector<char>>& matriz) {
    vector<int> filasMuertos;
    vector<int> columnasMuertos;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 'x') {
                filasMuertos.push_back(i);
                columnasMuertos.push_back(j);
            }
        }
    }

    cout << "Coordenadas de los muertos vivientes:" << endl;
    for (size_t i = 0; i < filasMuertos.size(); i++) {
        cout << "(" << filasMuertos[i] << ", " << columnasMuertos[i] << ")" << endl;
    }
}

// Función para contar la cantidad de muertos vivientes
int contarMuertos(const vector<vector<char>>& matriz) {
    int contador = 0;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 'x') {
                contador++;
            }
        }
    }

    return contador;
}

int main() {
    // Inicializar el generador de números aleatorios con una semilla
    srand(time(nullptr));

    // Generar una matriz aleatoria
    vector<vector<char>> matriz(FILAS, vector<char>(COLUMNAS));
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (rand() % 2 == 0) {
                matriz[i][j] = 'o'; // Lugar seguro
            } else {
                matriz[i][j] = 'x'; // Muerto viviente
            }
        }
    }

    mostrarMatriz(matriz);
    contarZonasSeguras(matriz);
    coordenadasMuertos(matriz);
    int cantidadMuertos = contarMuertos(matriz);
    cout << "Cantidad de muertos vivientes en toda la matriz: " << cantidadMuertos << endl;

    // Determinar si dos o más muertos vivientes se encuentran en la primera columna
    bool dosOMasEnPrimeraColumna = false;
    int contadorPrimeraColumna = 0;
    for (int i = 0; i < FILAS; i++) {
        if (matriz[i][0] == 'x') {
            contadorPrimeraColumna++;
            if (contadorPrimeraColumna >= 2) {
                dosOMasEnPrimeraColumna = true;
                break;
            }
        }
    }

    if (dosOMasEnPrimeraColumna) {
        cout << "No es posible entrar al complejo." << endl;
    } else {
        cout << "Es posible entrar al complejo." << endl;
    }

    return 0;
}