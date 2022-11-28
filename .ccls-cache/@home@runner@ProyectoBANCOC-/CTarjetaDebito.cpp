#include "CTarjetaDebito.h"

CTarjetaDebito::CTarjetaDebito(int num_tarjeta, int anio_venci, int mes_venci,
                               int CVV) {
  this->num_tarjeta = num_tarjeta;
  this->anio_venci = anio_venci;
  this->mes_venci = mes_venci;
  this->CVV = CVV;
  estado = "Activo";
}

int CTarjetaDebito::get_CVV() { return this->CVV; }
int CTarjetaDebito::get_AnioVenci() { return anio_venci; }
int CTarjetaDebito::get_MesVenci() { return mes_venci; }
int CTarjetaDebito::get_numero() { return num_tarjeta; }
string CTarjetaDebito::get_estado() { return estado; }
void CTarjetaDebito::set_estado(string h){estado=h;}
