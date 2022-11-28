#include "CCliente.h"
#include <fstream>
void CCliente::AgregarServicio(CServicios *_cliente) {
  Servicios.push_back(_cliente);
  actualizar_txt();
}
string CCliente::getnombre() { return nombre; }
string CCliente::getdni() { return dni; }
string CCliente::getocupacion() { return ocupacion; }
string CCliente::getedad() { return edad; }

void CCliente::getservicios() {
  int c = 1;
  if (Servicios.size() == 0) {
    cout << "No tiene servicios contratados" << endl;
  }
  for (auto se : Servicios) {
    cout << c;
    cout << se->get_tipo() << endl;
    cout << string(20, '-') << "\n";
    se->info_cuentas();
    c++;
  }
}

void CCliente::bloquear(int posicion) {
  Servicios[posicion]->bloquear_tarjeta();
  actualizar_txt();
}
void CCliente::imprimir_datos() {
  cout << "\nDATOS DEL CLIENTE:\n";
  cout << string(20, '-') << "\n\n";
  cout << "Nombre: " << nombre << endl;
  cout << "DNI: " << dni << endl;
  cout << "Edad: " << edad << endl;
  cout << "Ocupacion: " << ocupacion << endl;
}
void CCliente::solicitar_td(int posicion, CTarjetaDebito *t) {
  Servicios[posicion]->set_tarjetas_d(t);
  actualizar_txt();
}
void CCliente::solicitar_tc(int posicion, CTarjetaCredito *t) {
  Servicios[posicion]->set_tarjetas_c(t);
  actualizar_txt();
}
int CCliente::depositar(int posicion, int monto) {
  Servicios[posicion]->set_saldo(monto);
  actualizar_txt();

  return Servicios[posicion]->get_numero();
}
void CCliente::agregar_movimiento(int posicion, vector<string> mo) {
  Servicios[posicion]->agregar_movimiento(mo);
  Servicios[posicion]->guardar_movimientos();
}
void CCliente::actualizar_txt() {
  fstream archivo(dni + ".txt", ios::out);
  for (auto e : Servicios) {
    archivo << e->get_tipo() << " ";
    archivo << e->get_numero() << " ";
    archivo << e->get_saldo() << " ";
    archivo << e->get_numero_t() << " ";
    archivo << e->get_AnioVenci() << " ";
    archivo << e->get_MesVenci() << " ";
    archivo << e->get_CVV() << " ";
    if (e->get_tipo() == " Cuenta de credito") {
      archivo << e->get_limite() << " ";
      archivo << e->get_fecha() << " ";
    } else {
    }
    archivo << e->get_estado() << endl;
  }
  archivo.close();
}