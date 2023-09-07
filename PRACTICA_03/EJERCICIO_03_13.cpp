// Materia: Programación I, Paralelo 1

// Autor: Natalia Nicole Ramirez Leyva
  
// Fecha creación: 07/09/2023
  
// Fecha modificación: 07/09/2023
  
// Número de ejericio: 13
  
// Problema planteado: La farmacia FARMACARP tiene N sucursales, leer sus ventas por mes de un
// año entero de cada sucursal y calcule:
// a. Total, de ventas
// b. Total, de ventas por sucursal.
// c. Sucursal que más ha vendido.
// d. Sucursal que menos ha vendido.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // Número de sucursales
    int meses = 12; // Cantidad de meses en un año

    cout << "Ingrese el número de sucursales: ";
    cin >> n;

    // Declarar una matriz para almacenar las ventas de cada sucursal
    vector<vector<double>> ventas(n, vector<double>(meses));

    // Leer las ventas de cada sucursal
    for (int i = 0; i < n; i++) {
        cout << "Ingrese las ventas de la sucursal " << i + 1 << " por cada mes:" << endl;
        for (int j = 0; j < meses; j++) {
            cin >> ventas[i][j];
        }
    }

    // Calcular el total de ventas
    double totalVentas = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < meses; j++) {
            totalVentas += ventas[i][j];
        }
    }

    // Calcular el total de ventas por sucursal
    vector<double> totalVentasPorSucursal(n, 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < meses; j++) {
            totalVentasPorSucursal[i] += ventas[i][j];
        }
    }

    // Encontrar la sucursal que más ha vendido
    int sucursalMasVendio = 0;
    for (int i = 1; i < n; i++) {
        if (totalVentasPorSucursal[i] > totalVentasPorSucursal[sucursalMasVendio]) {
            sucursalMasVendio = i;
        }
    }

    // Encontrar la sucursal que menos ha vendido
    int sucursalMenosVendio = 0;
    for (int i = 1; i < n; i++) {
        if (totalVentasPorSucursal[i] < totalVentasPorSucursal[sucursalMenosVendio]) {
            sucursalMenosVendio = i;
        }
    }

    // Mostrar resultados
    cout << "a. Total de ventas: $" << totalVentas << endl;
    cout << "b. Total de ventas por sucursal:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "   Sucursal " << i + 1 << ": $" << totalVentasPorSucursal[i] << endl;
    }
    cout << "c. Sucursal que más ha vendido: Sucursal " << sucursalMasVendio + 1 << endl;
    cout << "d. Sucursal que menos ha vendido: Sucursal " << sucursalMenosVendio + 1 << endl;

    return 0;
}