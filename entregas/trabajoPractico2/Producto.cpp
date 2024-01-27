#include <iostream>
#include "Producto.h"

Producto::Producto(std::string nombre, double precio, unsigned int descuento, unsigned int stock)
{
    this->nombre = nombre;
    this->precio = precio;
    this->descuento = descuento;
    this->stock = stock;
}

Producto::~Producto() {}

std::string Producto::obtenerNombre()
{
    return this->nombre;
}

double Producto::obtenerPrecio()
{
    return this->precio;
}

unsigned int Producto::obtenerDescuento()
{
    return this->descuento;
}

unsigned int Producto::obtenerStock()
{
    return this->stock;
}

void Producto::mostrar()
{
    std::cout << "Nombre: " << this->nombre
              << " | Precio: " << this->precio
              << " | Descuento: " << this->descuento
              << " | Stock: " << this->stock << std::endl;
}

void Producto::reducirStock(unsigned int reduccion)
{
    this->stock -= reduccion;
}