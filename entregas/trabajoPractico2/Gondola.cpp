#include <iostream>
#include <fstream>
#include "Gondola.h"

Gondola::Gondola()
{
    this->capacidad = 5;
    this->cantidad = 0;
    this->vectorProductos = new Producto *[this->capacidad];
}

Gondola::~Gondola()
{
    for (int i = 0; i < this->capacidad; ++i)
    {
        delete this->vectorProductos[i];
        this->vectorProductos[i] = nullptr;
    }
    delete[] this->vectorProductos;
    this->vectorProductos = nullptr;
}

void Gondola::mostrarProductos()
{
    if (this->cantidad == 0)
    {
        std::cout << "No hay productos en la gondola. La capacidad de la misma es " << this->capacidad << "." << std::endl;
    }
    else
    {
        std::cout << "Actualmente hay " << this->cantidad << " productos en la GONDOLA. La capacidad de la misma es " << this->capacidad << "." << std::endl;
        for (unsigned int i = 0; i < this->cantidad; i++)
        {
            std::cout << i + 1 << "- ";
            this->vectorProductos[i]->mostrar();
        }
    }
}

void Gondola::cargarProductos(std::string nombreArchivo)
{
    std::ifstream arProductos(nombreArchivo);

    std::string nombre;
    double precio;
    unsigned int descuento;
    unsigned int stock;

    while (arProductos >> nombre >> precio >> descuento >> stock)
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

            std::cout << "Producto agregado a la GONDOLA correctamente -> ";
            this->vectorProductos[this->cantidad]->mostrar();

            this->cantidad++;
        }
        else
        {
            this->vectorProductos[this->cantidad] = new Producto(nombre, precio, descuento, stock);

            std::cout << "Producto agregado a la GONDOLA correctamente -> ";
            this->vectorProductos[this->cantidad]->mostrar();

            this->cantidad++;
        }
    }

    arProductos.close();
}

int Gondola::buscarProducto(std::string nombre)
{
    int posicion = -1;

    for (unsigned int i = 0; i < this->cantidad; i++)
    {
        if (this->vectorProductos[i]->obtenerNombre() == nombre)
        {
            posicion = i;
        }
    }

    return posicion;
}

Producto *Gondola::obtenerProducto(unsigned int posicion)
{
    return this->vectorProductos[posicion];
}

void Gondola::quitarProducto(unsigned int posicion)
{
    this->cantidad--;

    std::cout << "Producto " << this->vectorProductos[posicion]->obtenerNombre() << " sera eliminado de la GONDOLA dado que no posee stock." << std::endl;

    this->cambiarPosicion(posicion, this->cantidad);

    Producto **vectorAux = this->vectorProductos;

    if (this->cantidad == this->capacidad / 2)
    {
        this->capacidad /= 2;
        this->vectorProductos = new Producto *[this->capacidad];
        for (unsigned int i = 0; i < this->cantidad; i++)
        {
            this->vectorProductos[i] = vectorAux[i];
        }
    }
    else
    {
        this->vectorProductos = new Producto *[this->capacidad];
        for (unsigned int i = 0; i < this->cantidad; i++)
        {
            this->vectorProductos[i] = vectorAux[i];
        }
    }

    std::cout << "Producto eliminado de la GONDOLA correctamente." << std::endl;

    delete[] vectorAux;
    vectorAux = nullptr;
}

void Gondola::actualizarGondola(std::string nombreArchivo)
{
    std::ofstream arProductosActualizados(nombreArchivo);

    for (unsigned int i = 0; i < this->cantidad; i++)
    {
        arProductosActualizados << this->vectorProductos[i]->obtenerNombre() << "\t"
                                << this->vectorProductos[i]->obtenerPrecio() << "\t"
                                << this->vectorProductos[i]->obtenerDescuento() << "\t"
                                << this->vectorProductos[i]->obtenerStock() << std::endl;
    }

    arProductosActualizados.close();
}

void Gondola::cambiarPosicion(unsigned int posicion1, unsigned int posicion2)
{
    Producto *aux = this->vectorProductos[posicion1];
    this->vectorProductos[posicion1] = this->vectorProductos[posicion2];
    this->vectorProductos[posicion2] = aux;
    delete aux;
    aux = nullptr;
}