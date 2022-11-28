
#include "CTarjetaCredito.h"

CTarjetaCredito::CTarjetaCredito(int num_tarjeta, int anio_venci, int mes_venci,
                                 int CVV, int monto_limite,
                                 int fecha_pago) {
  this->num_tarjeta = num_tarjeta;
  this->anio_venci = anio_venci;
  this->mes_venci = mes_venci;
  this->CVV = CVV;
  this->monto_limite = monto_limite;
  this->fecha_pago = fecha_pago;
  estado = "Activo";
}

int CTarjetaCredito::get_CVV() { return this->CVV; }
int CTarjetaCredito::get_AnioVenci() { return anio_venci; }
int CTarjetaCredito::get_MesVenci() { return mes_venci; }
int CTarjetaCredito::get_numero() { return num_tarjeta; }
string CTarjetaCredito::get_estado() { return estado; }
void CTarjetaCredito::set_estado(string h) { estado = h; }
int CTarjetaCredito::get_limite() { return monto_limite; }
int CTarjetaCredito::get_fecha() { return fecha_pago; };
