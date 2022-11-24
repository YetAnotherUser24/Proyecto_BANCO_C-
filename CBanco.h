#ifndef __CBANCO_H__
#define __CBANCO_H__

#include <vector>
#include "CServicios.h"
#include "CCliente.h"

using namespace std;

class CBanco
{
private:
    vector<CServicios *> servicios;
    vector<CCliente *> clientes;

public:
    CServicios *get_tipo_servicio(string _tiposervicio);
    CCliente *get_cliente(string _cliente);
}
#endif // __CBANCO_H__