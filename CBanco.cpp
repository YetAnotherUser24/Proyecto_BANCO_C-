#include "CBanco.h"

CServicios *CBanco::get_tipo_servicio(string _tiposervicio)
{
    for (auto e : servicios)
    {
        if (e->get_tipo() == _tiposervicio)
        {
            return e;
        }
    }
}

CCliente *CBanco::get_cliente(string _cliente)
{
    for (auto e : clientes)
    {
        if (e->nombre == _cliente)
        {
            return e;
        }
    }
}
