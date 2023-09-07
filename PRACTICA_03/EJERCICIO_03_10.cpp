// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva
  
// Fecha creación: 06/09/2023
  
// Fecha modificación: 06/09/2023
  
// NC:mero de ejericio: 10
  
// Problema planteado: Queremos realizar una encuesta a 10 personas, en esta encuesta indicaremos el
// sexo (1=masculino, 2=femenino), si trabaja (1=si trabaja, 2= no trabaja) y su
// sueldo (si tiene un trabajo, sino sera un cero) estará entre 600 y 2000 (valor
// entero). Los valores pueden ser generados aleatoriamente. Calcula y muestra lo
// siguiente:
// • Porcentaje de hombres (tengan o no trabajo).
// • Porcentaje de mujeres (tengan o no trabajo).
// • Porcentaje de hombres que trabajan.
// • Porcentaje de mujeres que trabajan.
// • El sueldo promedio de las hombres que trabajan.
// • EL sueldo promedio de las mujeres que trabajan.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Inicializar la semilla para generar números aleatorios
    srand(static_cast<unsigned>(time(0)));

    int totalPersonas = 10;
    int hombres = 0;
    int mujeres = 0;
    int hombresTrabajan = 0;
    int mujeresTrabajan = 0;
    double sueldoHombresTrabajan = 0.0;
    double sueldoMujeresTrabajan = 0.0;

    for (int i = 0; i < totalPersonas; i++) {
        int sexo = rand() % 2 + 1; // 1=masculino, 2=femenino
        int trabaja = rand() % 2 + 1; // 1=si trabaja, 2=no trabaja
        int sueldo = trabaja == 1 ? rand() % 1401 + 600 : 0; // Sueldo entre 600 y 2000 si trabaja

        if (sexo == 1) {
            hombres++;
            if (trabaja == 1) {
                hombresTrabajan++;
                sueldoHombresTrabajan += sueldo;
            }
        } else {
            mujeres++;
            if (trabaja == 1) {
                mujeresTrabajan++;
                sueldoMujeresTrabajan += sueldo;
            }
        }
    }

    // Calcular porcentajes
    double porcentajeHombres = (static_cast<double>(hombres) / totalPersonas) * 100;
    double porcentajeMujeres = (static_cast<double>(mujeres) / totalPersonas) * 100;
    double porcentajeHombresTrabajan = (static_cast<double>(hombresTrabajan) / totalPersonas) * 100;
    double porcentajeMujeresTrabajan = (static_cast<double>(mujeresTrabajan) / totalPersonas) * 100;

    // Calcular sueldo promedio
    sueldoHombresTrabajan /= hombresTrabajan;
    sueldoMujeresTrabajan /= mujeresTrabajan;

    // Mostrar resultados
    cout << "Porcentaje de hombres: " << porcentajeHombres << "%" << endl;
    cout << "Porcentaje de mujeres: " << porcentajeMujeres << "%" << endl;
    cout << "Porcentaje de hombres que trabajan: " << porcentajeHombresTrabajan << "%" << endl;
    cout << "Porcentaje de mujeres que trabajan: " << porcentajeMujeresTrabajan << "%" << endl;
    cout << "Sueldo promedio de los hombres que trabajan: $" << sueldoHombresTrabajan << endl;
    cout << "Sueldo promedio de las mujeres que trabajan: $" << sueldoMujeresTrabajan << endl;

    return 0;
}