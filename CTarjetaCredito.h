#ifndef PROYECTO_BANCO_C_CTARJETACREDITO_H
#define PROYECTO_BANCO_C_CTARJETACREDITO_H
#include <iostream>

using namespace std;
class CTarjetaCredito {
  int num_tarjeta;
  int anio_venci;
  int mes_venci;
  int CVV;
  int monto_limite;
  int fecha_pago;
  string estado;

public:
  CTarjetaCredito(){};
  CTarjetaCredito(int num_tarjeta, int anio_venci, int mes_venci, int CVV, int monto_limite, int fecha_pago);
  int get_CVV();
  int get_AnioVenci();
  int get_MesVenci();
  int get_numero();
int get_limite();
int get_fecha();
  string get_estado();
  void set_estado(string h);
virtual ~CTarjetaCredito(){};
};
#endif // PROYECTO_BANCO_C_CTARJETACREDITO_H