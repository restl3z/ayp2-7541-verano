#include <iostream>
#include <fstream>
#include "Chango.h"

Chango::Chango()
{
    this->capacidad = 5;
    this->cantidad = 0;
    this->vectorProductos = new Producto *[this->capacidad];
}

Chango::~Chango()
{
    for (int i = 0; i < this->capacidad; ++i)
    {
        delete this->vectorProductos[i];
        this->vectorProductos[i] = nullptr;
    }
    delete[] this->vectorProductos;
    this->vectorProductos = nullptr;
}

void Chango::mostrarProductos()
{
    if (this->cantidad == 0)
    {
        std::cout << "No hay productos en el chango." << std::endl;
    }
    else
    {
        std::cout << "Actualmente hay " << this->cantidad << " productos en el CHANGO." << std::endl;
        for (unsigned int i = 0; i < this->cantidad; i++)
        {
            std::cout << i + 1 << "- ";
            this->vectorProductos[i]->mostrar();
        }
    }
}

void Chango::agregarProducto(std::string nombre, double precio, unsigned int descuento, unsigned int stock)
{
    if (this->capacidad == this->cantidad)
    {
        Producto **vectorAux = this->vectorProductos;

        this->capacidad *= 2;

        this->vectorProductos = new Producto *[this->capacidad];

        for (unsigned int i = 0; i < this->cantidad; i++)
        {
            this->vectorProductos[i] = vectorAux[i];
        }

        delete[] vectorAux;
        vectorAux = nullptr;

        this->vectorProductos[this->cantidad] = new Producto(nombre, precio, descuento, stock);

        std::cout << "Producto agregado al CHANGO correctamente -> Nombre: " << nombre << " | Cantidad: " << stock << std::endl;

        this->cantidad++;
    }
    else
    {
        this->vectorProductos[this->cantidad] = new Producto(nombre, precio, descuento, stock);

        std::cout << "Producto agregado al CHANGO correctamente -> Nombre: " << nombre << " | Cantidad: " << stock << std::endl;

        this->cantidad++;
    }
}

void Chango::buscarEnGondola(Gondola &gondola, std::string nombreArchivo)
{
    std::ifstream arCompras(nombreArchivo);

    std::string nombre;
    unsigned int cantidad;
    int posicion;

    while (arCompras >> nombre >> cantidad)
    {
        posicion = gondola.buscarProducto(nombre);
        if (posicion != -1)
        {
            unsigned int stockExistente = gondola.obtenerProducto(posicion)->obtenerStock();
            float precioDeGondola = gondola.obtenerProducto(posicion)->obtenerPrecio();
            unsigned int descuentoDeGondola = gondola.obtenerProducto(posicion)->obtenerDescuento();

            if (stockExistente > cantidad)
            {
                this->agregarProducto(nombre, precioDeGondola, descuentoDeGondola, cantidad);

                gondola.obtenerProducto(posicion)->reducirStock(cantidad);
            }
            else
            {
                this->agregarProducto(nombre, precioDeGondola, descuentoDeGondola, stockExistente);

                gondola.obtenerProducto(posicion)->reducirStock(stockExistente);

                if (stockExistente < cantidad)
                {
                    std::cout << "Del producto " << nombre << " solo hay " << stockExistente << " unidades y no las " << cantidad << " requeridas." << std::endl;
                }

                gondola.quitarProducto(posicion);
            }
        }
        else
        {
            std::cout << "El producto " << nombre << " no se encuentra en la GONDOLA." << std::endl;
        }
    }
    arCompras.close();
}

void Chango::finalizarCompra()
{
    std::cout << "Producto\t"
              << "Precio\t"
              << "Cantidad\t"
              << "Oferta(S/N)\t"
              << "Precio final\t" << std::endl;
    for (unsigned int i = 0; i < this->cantidad; i++)
    {
        if (this->vectorProductos[i]->obtenerDescuento() == 1)
        {
            std::cout << this->vectorProductos[i]->obtenerNombre() << "\t"
                      << this->vectorProductos[i]->obtenerPrecio() << "\t"
                      << this->vectorProductos[i]->obtenerStock() << "\t"
                      << "S\t"
                      << this->vectorProductos[i]->obtenerPrecio() * 0.9 << std::endl;
        }
        else
        {
            std::cout << this->vectorProductos[i]->obtenerNombre() << "\t"
                      << this->vectorProductos[i]->obtenerPrecio() << "\t"
                      << this->vectorProductos[i]->obtenerStock() << "\t"
                      << "N\t"
                      << this->vectorProductos[i]->obtenerPrecio() << std::endl;
        }
    }
}
