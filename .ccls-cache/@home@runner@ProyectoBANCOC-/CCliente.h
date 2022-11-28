#ifndef PROYECTO_BANCO_C_CCLIENTE_H
#define PROYECTO_BANCO_C_CCLIENTE_H
#include "CServicios.h"
#include "CTarjetaCredito.h"
#include "CTarjetaDebito.h"
#include <iostream>
#include <vector>
using namespace std;

class CCliente {
private:
  string nombre;
  string dni;
  string edad;
  string ocupacion;
  vector<CServicios *> Servicios;

public:
CCliente(){}
  CCliente(string _n, string dn, string e, string ocu)
      : nombre(_n), dni(dn), edad(e), ocupacion(ocu) {}
  void AgregarServicio(CServicios *_cliente);
  string getnombre();
  string getdni();
  string getocupacion();
  string getedad();
  void getservicios();
  void imprimir_datos();
  void bloquear(int posicion);
  void solicitar_td(int posicion, CTarjetaDebito *t);
  void solicitar_tc(int posicion, CTarjetaCredito *t);
  int depositar(int posicion, int monto);
  void agregar_movimiento(int posicion, vector<string> mo);
  void actualizar_txt();
virtual ~CCliente(){}
};

#endif // PROYECTO_BANCO_C_CCLIENTE_H