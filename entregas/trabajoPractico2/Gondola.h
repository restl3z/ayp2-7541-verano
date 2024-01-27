#ifndef TRABAJOPRACTICO2_GONDOLA_H
#define TRABAJOPRACTICO2_GONDOLA_H

#include "Producto.h"

class Gondola
{
private:
    unsigned int capacidad;
    unsigned int cantidad;
    Producto **vectorProductos;

    // PRE: 0 <= posicion1 < cantidad && 0 <= posicion2 < cantidad.
    // POS: Cambia el producto en el índice posicion1 al índice posicion2 y viceversa.
    void cambiarPosicion(unsigned int posicion1, unsigned int posicion2);

public:
    // PRE: -.
    // POS: Crea una gondola inicialmente sin productos.
    Gondola();

    // PRE: -.
    // POS: Destructor de la clase.
    ~Gondola();

    // PRE: -.
    // POS: Imprime en terminal los productos de la góndola.
    void mostrarProductos();

    // PRE: El nombre debe corresponderse con un archivo existente y éste debe tener el formato correcto.
    // POS: Recibe el nombre de un archivo que contiene los productos que se cargarán en la góndola.
    void cargarProductos(std::string nombreArchivo);

    // PRE: -.
    // POS: Busca el producto en la góndola por nombre y retorna la posición del mismo en el arreglo, si lo encontrase; -1 en caso contrario.
    int buscarProducto(std::string nombre);

    // PRE: 0 <= posicion < cantidad.
    // POS: Retorna el producto el la posición indicada de la gondola.
    Producto *obtenerProducto(unsigned int posicion);

    // PRE: 0 <= posicion < cantidad.
    // POS: Retorna el producto el la posición indicada de la gondola.
    void quitarProducto(unsigned int posicion);

    // PRE: -.
    // POS: Crea un archivo con el nombre indicado e inserta los productos con stock existente actualizado.
    void actualizarGondola(std::string nombreArchivo);
};

#endif // TRABAJOPRACTICO2_GONDOLA_H