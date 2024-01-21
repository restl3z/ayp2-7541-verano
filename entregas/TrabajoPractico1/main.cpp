#include <iostream>
#include <ctime>
#include "Funciones.h"

using namespace std;

const unsigned int MAXIMO = 1000;

int main() {
    unsigned int ti = clock();

    bool* compuestos = new bool[MAXIMO + 1]();

    verificarPrimos(compuestos, MAXIMO);

    unsigned int cantidadPrimos = escribirArchivo(compuestos, MAXIMO);

    delete[] compuestos;

    unsigned int tf = clock();
    double tiempo_total = (double(tf - ti)) / CLOCKS_PER_SEC;

    cout << "\n" << "Total de numeros primos: " << cantidadPrimos << "." << endl;
    cout << "\n" << "Tiempo total de ejecucion: " << tiempo_total << " segundos." << endl;
    return 0;
}
