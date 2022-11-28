#ifndef PROYECTO_BANCO_C_CMENU_H
#define PROYECTO_BANCO_C_CMENU_H
#include "CBanco.h"
#include "CCuentaDebito.h"
#include "CTarjetaDebito.h"
#include "CCuentaCredito.h"
#include "CTarjetaCredito.h"
#include <iostream>
#include <fstream>
using namespace std;

class CMenu {
private:
  CBanco banco;
  int opcion;
  char opcion_letra;

public:
  CMenu() : opcion{} {}
  void activar();
  void imprimir_menu();
  void imprimir_menu_clientes();
  void opciones_lista();
  void opciones_cliente();
  void agregar_cliente();
  void buscar_cliente();
  void borrar_cliente();
  void ver_servis();
  void imprimir_menu_cuentas_ahorro();
  void imprimir_menu_cuentas_credito();
  void opciones_ahorro();
  void opciones_credito();
  void agregar_servicio_credito();
  void agregar_servicio_debito();
  void bloquear_tarjeta();
  void solicitar_tarjeta_debito();
  void solicitar_tarjeta_credito();
  void depositar();
  void imprimir_movimientos();
virtual ~CMenu(){};
};

#endif // PROYECTO_BANCO_C_CMENU_H