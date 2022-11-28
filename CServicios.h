#ifndef PROYECTO_BANCO_C_CSERVICIOS_H
#define PROYECTO_BANCO_C_CSERVICIOS_H
#include "CTarjetaCredito.h"
#include "CTarjetaDebito.h"
#include <iostream>
#include <vector>
using namespace std;

class CServicios {
protected:
  string tipo;
  string propietario;
  int numero_cuenta;
  double saldo;

public:
  string get_tipo();
  int get_numero();
  int get_saldo();
  virtual void bloquear_tarjeta() = 0;
  virtual void info_cuentas() = 0;
  virtual void set_tarjetas_d(CTarjetaDebito *t) = 0;
  virtual void set_tarjetas_c(CTarjetaCredito *t) = 0;
  virtual void set_saldo(int monto) = 0;
  virtual void agregar_movimiento(vector<string> mo) = 0;
  virtual void guardar_movimientos() = 0;
  virtual int get_CVV()=0;
  virtual int get_AnioVenci()=0;
  virtual int get_MesVenci()=0;
  virtual int get_numero_t()=0;
  virtual int get_limite()=0;
  virtual int get_fecha()=0;
  virtual string get_estado()=0;
virtual ~CServicios(){}
};

#endif // PROYECTO_BANCO_C_CSERVICIOS_H