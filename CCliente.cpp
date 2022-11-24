#include "CCliente.h"

CCliente::CCliente()
{
}

CCliente::~CCliente()
{
    for (auto e : servicios)
    {
        delete e;
        e = nullptr;
    }
    servicios.clear();
}

void CCliente::set_nombre(string _nombre)
{
    nombre = _nombre;
}

void CCliente::set_clave(string _clave)
{
    if (_clave.size() == 8)
    {
        clave = _clave;
    }
}

void CCliente::add_servicio(string _servicio)
{
}

string CCliente::get_nombre()
{
    return nombre;
}

string CCliente::get_clave()
{
    return clave;
}

CServicio *CCliente::get_servicio()
{
    return Servicios;
}
