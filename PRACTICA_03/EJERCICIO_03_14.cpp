// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva
  
// Fecha creación: 07/09/2023
  
// Fecha modificación: 07/09/2023
  
// Número de ejericio: 14
  
// Problema planteado: Simule una elección de nuestro país Bolivia. En ello se mostrará las elecciones
// por departamento y existirá N candidatos.
// El programa debe pedir la cantidad de votos por departamento y candidato y
// almacenarlos en una matriz.
// El programa debe calcular lo siguiente:
// • Si un candidato gana con el 50% + 1 voto es ganador absoluto.
// • Si no ningún candidato que logre el 50% + 1 voto el programa debe sacar
// los dos mas votados para una segunda vuelta.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int departamentos, candidatos;

    cout << "Ingrese la cantidad de departamentos: ";
    cin >> departamentos;

    cout << "Ingrese la cantidad de candidatos: ";
    cin >> candidatos;

    // Declarar una matriz para almacenar los votos por departamento y candidato
    vector<vector<int>> votos(departamentos, vector<int>(candidatos));

    // Leer los votos por departamento y candidato
    for (int i = 0; i < departamentos; i++) {
        cout << "Ingrese los votos del departamento " << i + 1 << " para cada candidato:" << endl;
        for (int j = 0; j < candidatos; j++) {
            cin >> votos[i][j];
        }
    }

    // Calcular el total de votos por candidato
    vector<int> totalVotosPorCandidato(candidatos, 0);
    for (int i = 0; i < departamentos; i++) {
        for (int j = 0; j < candidatos; j++) {
            totalVotosPorCandidato[j] += votos[i][j];
        }
    }

    // Encontrar el candidato más votado
    int maxVotos = *max_element(totalVotosPorCandidato.begin(), totalVotosPorCandidato.end());
    int candidatoMasVotado = distance(totalVotosPorCandidato.begin(), max_element(totalVotosPorCandidato.begin(), totalVotosPorCandidato.end()));

    // Verificar si hay un ganador absoluto (más del 50%)
    if (maxVotos > (departamentos / 2)) {
        cout << "El candidato " << candidatoMasVotado + 1 << " es el ganador absoluto con " << maxVotos << " votos." << endl;
    } else {
        // Encontrar el segundo candidato más votado
        totalVotosPorCandidato[candidatoMasVotado] = 0; // Excluir al candidato más votado
        int segundoMasVotado = distance(totalVotosPorCandidato.begin(), max_element(totalVotosPorCandidato.begin(), totalVotosPorCandidato.end()));

        cout << "Necesario una segunda vuelta entre los candidatos " << candidatoMasVotado + 1 << " y " << segundoMasVotado + 1 << "." << endl;
    }

    return 0;
}