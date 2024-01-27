#ifndef TRABAJOPRACTICO2_PRODUCTO_H
#define TRABAJOPRACTICO2_PRODUCTO_H

class Producto
{
private:
    std::string nombre;
    double precio;
    unsigned int descuento;
    unsigned int stock;

public:
    // PRE: 0 > descuento > 1 && precio >= 0 && stock >= 0.
    // POS: Crea un producto con los atributos suministrados.
    Producto(std::string nombre, double precio, unsigned int descuento, unsigned int stock);

    // PRE: -.
    // POS: Destructor de la clase.
    ~Producto();

    // PRE: -.
    // POS: Retorna el nombre del producto.
    std::string obtenerNombre();

    // PRE: -.
    // POS: Retorna el precio del producto.
    double obtenerPrecio();

    // PRE: -.
    // POS: Retorna el descuento del producto.
    unsigned int obtenerDescuento();

    // PRE: -.
    // POS: Retorna el stock del producto.
    unsigned int obtenerStock();

    // PRE: -.
    // POS: Imprime en terminal los atributos del producto.
    void mostrar();

    // PRE: reduccion <= stock.
    // POS: Reduce el stock del producto en la cantidad indicada.
    void reducirStock(unsigned int reduccion);
};

#endif // TRABAJOPRACTICO2_PRODUCTO_H