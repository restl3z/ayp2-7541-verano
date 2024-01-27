#ifndef TRABAJOPRACTICO2_CHANGO_H
#define TRABAJOPRACTICO2_CHANGO_H

#include "Producto.h"
#include "Gondola.h"

class Chango
{
private:
    unsigned int capacidad;
    unsigned int cantidad;
    Producto **vectorProductos;

public:
    // PRE: -.
    // POS: Crea una chango inicialmente sin productos.
    Chango();

    // PRE: -.
    // POS: Destructor de la clase.
    ~Chango();

    // PRE: -.
    // POS: Imprime en terminal los productos del chango.
    void mostrarProductos();

    // PRE: -.
    // POS: Agrega el producto indicado al chango.
    void agregarProducto(std::string nombre, double precio, unsigned int descuento, unsigned int stock);

    // PRE: El nombre debe corresponderse con un archivo existente y éste debe tener el formato correcto.
    // POS: Busca los productos indicados en gondola segun el archivo con el nombre suministrado; agrega los mismos al chango si cuenta con stock.
    void buscarEnGondola(Gondola &gondola, std::string nombreArchivo);

    // PRE: -.
    // POS: Imprime por terminal el detalle de la compra realizada.
    void finalizarCompra();
};

#endif // TRABAJOPRACTICO2_CHANGO_H