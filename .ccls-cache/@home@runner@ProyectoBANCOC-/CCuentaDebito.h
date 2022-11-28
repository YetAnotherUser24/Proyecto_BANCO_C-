#ifndef PROYECTO_BANCO_C_CCUENTADEBITO_H
#define PROYECTO_BANCO_C_CCUENTADEBITO_H

#include "CServicios.h"
#include "CTarjetaDebito.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class CCuentaDebito : public CServicios {
public:
CCuentaDebito(){}
  CTarjetaDebito *tarjeta;
  vector<string> movimientos;
  CCuentaDebito(int n, CTarjetaDebito *t) : tarjeta(t) {
    tipo = " Cuenta de debito";
    saldo = 0;
    numero_cuenta = n;
  }
  double getSaldo() { return saldo; };
  void set_saldo(double depo) { saldo += depo; }
  void info_cuentas();
  void bloquear_tarjeta();
  void set_tarjetas_d(CTarjetaDebito *t);
  void set_tarjetas_c(CTarjetaCredito *t);
  void set_saldo(int monto);
  void agregar_movimiento(vector<string> mo);
  void guardar_movimientos();
  int get_CVV();
  int get_AnioVenci();
  int get_MesVenci();
  int get_numero_t();
  int get_limite();
  int get_fecha();
  string get_estado();
virtual ~CCuentaDebito(){}
};

#endif // PROYECTO_BANCO_C_CCUENTADEBITO_H