#ifndef __CCLIENTE_H__
#define __CCLIENTE_H__

#include "CServicios.h"
#include <iostream>
#include <vector>

using namespace std;
class CCliente{
    private:
    string nombre;
    string apellido;
    string dni;
    vector<CServicios*> Servicios;
    
    public:
    CCliente(){}
    CCliente(string _nombre, string _apellido, string _dni);
    ~CCliente(){}

    void add_servicio(CServicio*);
    void remover_servicio(CServicio*);
};
#endif // __CCLIENTE_H__
