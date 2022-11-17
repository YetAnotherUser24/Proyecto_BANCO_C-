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