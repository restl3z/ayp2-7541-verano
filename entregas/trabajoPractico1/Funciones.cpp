#include "Funciones.h"

void verificarPrimos(bool*& listado, unsigned int longitud) {
    for (int p = 2; p * p <= longitud; p++) {
        if (!listado[p]) {
            for (int i = p * p; i <= longitud; i += p) {
                listado[i] = true;
            }
        }
    }
}

unsigned int escribirArchivo(bool*& listado, unsigned int longitud) {
    ofstream archivo("primos.txt");

    unsigned int cantidadPrimos = 0;

    for (int p = 2; p <= longitud; p++){
        if (!listado[p]) {
            archivo << p << endl;
            cantidadPrimos++;
        }
    }

    archivo.close();

    return cantidadPrimos;
}