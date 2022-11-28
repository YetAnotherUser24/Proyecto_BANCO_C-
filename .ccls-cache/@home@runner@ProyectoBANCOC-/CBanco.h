#ifndef PROYECTO_BANCO_C_CBANCO_H
#define PROYECTO_BANCO_C_CBANCO_H
#include "CCliente.h"
#include "CServicios.h"
#include <vector>

using namespace std;

class CBanco {
private:
  vector<CServicios *> servicios;
  vector<CCliente *> Clientes;

public:
CBanco(){}
  void BuscarCliente(string _dni);
  void AgregaCliente(CCliente *_cliente);
  void EliminarCliente(string _dni);
  void servicios_cliente(string _dni);
  void agregar_servicio_(string dni, CServicios *r);
  void bloquear_tarjeta(string _dni, int p);
  void solicitar_tarjeta_d(string _dni, int p, CTarjetaDebito *t);
  void solicitar_tarjeta_c(string _dni, int p, CTarjetaCredito *t);
  int depositar(string _dni, int p, int monto);
  void agregar_movimiento(string _dni, int p, vector<string> mo);
  void leer_archivos_clientes();
  void leer_archivos_propios();
  void leer_archivos_DEMANERAPRO();
virtual ~CBanco(){}
};
#endif // PROYECTO_BANCO_C_CBANCO_H