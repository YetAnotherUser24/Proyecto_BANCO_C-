
#include <iostream>
#include <vector>
#include "CServicios.h"

using namespace std;
class CCliente
{
private:
    string nombre;
    string clave;
    vector<CServicios *> servicios;

public:
    CCliente();
    ~CCliente();

    void set_nombre(string _nombre);
    void set_clave(string _clave);
    void add_servicio(string _servicio);

    string get_nombre();
    string get_clave();
    CServicio *get_servicio();
};