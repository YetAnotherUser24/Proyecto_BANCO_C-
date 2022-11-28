#ifndef PROYECTO_BANCO_C_CCUENTACREDITO_H
#define PROYECTO_BANCO_C_CCUENTACREDITO_H
#include "CServicios.h"
#include "CTarjetaCredito.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class CCuentaCredito : public CServicios {
private:
  CTarjetaCredito *tarjeta;
  double deudas; // hipotecas y prestamos
public:
CCuentaCredito(){}
  vector<string> movimientos;
  CCuentaCredito(int n, CTarjetaCredito *t) : tarjeta(t) {
    tipo = " Cuenta de credito";
    saldo = tarjeta->get_limite();
    numero_cuenta = n;
  }
  double getSaldo() { return saldo; };
  double getDeudas() { return saldo; };
  void info_cuentas();
  void bloquear_tarjeta();
  void set_tarjetas_c(CTarjetaCredito *t);
  void set_tarjetas_d(CTarjetaDebito *t);
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
virtual ~CCuentaCredito(){}
};
#endif // PROYECTO_BANCO_C_CCUENTACREDITO_H