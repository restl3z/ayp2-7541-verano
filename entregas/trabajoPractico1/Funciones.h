#ifndef TRABAJOPRACTICO1_FUNCIONES_H
#define TRABAJOPRACTICO1_FUNCIONES_H

#include <fstream>

using namespace std;

/*
 * pre: Recibe un puntero a un arreglo de tipo 'bool' y la longitud del mismo. Este arreglo constará de números que se asumirán inicialmente como compuestos.
 * post: El arreglo será recorrido a partir del número 2 (único primo conocido), elevado al cuadrado y desde allí, se obtendrán todos sus múltiplos hasta alcanzar la longitud del arreglo.
 *       Todos los números encontrados serán marcados, identificando el índice correspondiente en el arreglo como 'true' (compuestos).
 *       Al finalizar, aquellos índices que aún posean el valor 'false', serán los correspondientes a números primos.
 * */
void verificarPrimos(bool *&listado, unsigned int longitud);

/*
 * pre: Recibe un puntero a un arreglo de tipo 'bool' y la longitud del mismo.
 * post: Escribe en un archivo 'primos.txt' los números correspondientes a índices primos del arreglo y retorna la cantidad de veces que se ha escrito en el archivo.
 * */
unsigned int escribirArchivo(bool *&listado, unsigned int longitud);

#endif // TRABAJOPRACTICO1_FUNCIONES_H