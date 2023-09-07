// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva
  
// Fecha creación: 06/09/2023
  
// Fecha modificación: 07/09/2023
  
// NC:mero de ejericio: 11
  
// Problema planteado: . Realizar el típico juego del 3 en raya, donde habrá dos jugadores que tengan que
// hacer el 3 en raya, los signos serán el X y el O, cuando haya una posición vacía
// habrá un – El tablero de juego, será una matriz de 3×3 de char.
// El juego termina cuando uno de los jugadores hace 3 en raya o si no hay más
// posiciones que poner.
// El juego debe pedir las posiciones donde el jugador actual quiera poner su
// marca, esta debe ser validada y por supuesto que no haya una marca ya puesta.
// Por último mostrar la matriz del juego y muestra al ganador.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función para imprimir el tablero actual
void imprimirTablero(char tablero[3][3]) {
    cout << "Tablero actual:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
}

// Función para verificar si hay un ganador
char verificarGanador(char tablero[3][3]) {
    // Comprobar filas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != '-') {
            return tablero[i][0];
        }
    }

    // Comprobar columnas
    for (int j = 0; j < 3; j++) {
        if (tablero[0][j] == tablero[1][j] && tablero[1][j] == tablero[2][j] && tablero[0][j] != '-') {
            return tablero[0][j];
        }
    }

    // Comprobar diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != '-') {
        return tablero[0][0];
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != '-') {
        return tablero[0][2];
    }

    // Si no hay ganador
    return '-';
}

// Función para que la computadora haga un movimiento aleatorio
void movimientoComputadora(char tablero[3][3], char jugador) {
    while (true) {
        int fila = rand() % 3;
        int columna = rand() % 3;

        if (tablero[fila][columna] == '-') {
            tablero[fila][columna] = jugador;
            break;
        }
    }
}

int main() {
    char tablero[3][3] = { { '-', '-', '-' }, { '-', '-', '-' }, { '-', '-', '-' } };
    char jugadorActual = 'X';

    int fila, columna;
    int movimientos = 0;

    srand(static_cast<unsigned>(time(0))); // Inicializar la semilla para números aleatorios

    cout << "Bienvenido al juego del 3 en raya humano vs computadora" << endl;

    while (movimientos < 9) {
        if (jugadorActual == 'X') {
            imprimirTablero(tablero);
            cout << "El primer numero que ingrese sera correspondiente a la fila, el segundo a la columna" << endl;
            cout << "La fila superior sera la fila 0, la del medio sera la fila 1 y la inferior sera la fila 2" << endl;
            cout << "La columna de la derecha sera la columna 0, la del medio sera la 1, y la de la izquierda sera la 2" << endl;          
            cout << "Su turno. Ingrese la fila y columna (0 enter 2): ";
            cin >> fila >> columna;

            if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != '-') {
                cout << "Movimiento no válido. Intente de nuevo." << endl;
                continue;
            }

            tablero[fila][columna] = jugadorActual;
        } else {
            cout << "Turno de la computadora..." << endl;
            movimientoComputadora(tablero, jugadorActual);
        }

        movimientos++;

        char ganador = verificarGanador(tablero);

        if (ganador != '-') {
            imprimirTablero(tablero);
            if (ganador == 'X') {
                cout << "¡Has ganado!" << endl;
            } else {
                cout << "¡La computadora ha ganado!" << endl;
            }
            break;
        }

        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }

    if (movimientos == 9) {
        imprimirTablero(tablero);
        cout << "El juego ha terminado en empate." << endl;
    }

    return 0;
}