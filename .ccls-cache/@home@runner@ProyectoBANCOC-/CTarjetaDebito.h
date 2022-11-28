#ifndef PROYECTO_BANCO_C_CTARJETADEBITO_H
#define PROYECTO_BANCO_C_CTARJETADEBITO_H
#include <iostream>
using namespace std;

class CTarjetaDebito {
  int num_tarjeta;
  int anio_venci;
  int mes_venci;
  int CVV;
  string estado;

public:
CTarjetaDebito(){}
  CTarjetaDebito(int num_tarjeta, int anio_venci, int mes_venci, int CVV);
  int get_CVV();
  int get_AnioVenci();
  int get_MesVenci();
  int get_numero();
  string get_estado();
  void set_estado(string h);
virtual ~CTarjetaDebito(){}
};
#endif // PROYECTO_BANCO_C_CTARJETADEBITO_H