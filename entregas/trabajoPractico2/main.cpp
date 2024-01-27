#include <iostream>
#include "Gondola.h"
#include "Chango.h"

int main()
{
    Gondola gondola;

    gondola.mostrarProductos();

    gondola.cargarProductos("productos.txt");

    gondola.mostrarProductos();

    Chango chango;

    chango.buscarEnGondola(gondola, "compra.txt");

    gondola.actualizarGondola("productosActualizado.txt");

    gondola.mostrarProductos();

    chango.finalizarCompra();

    return 0;
}
