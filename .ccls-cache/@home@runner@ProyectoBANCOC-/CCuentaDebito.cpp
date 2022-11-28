#include "CCuentaDebito.h"

void CCuentaDebito::info_cuentas() {
  cout << "Datos de la cuenta:\n";
  cout << "Numero de cuenta: " << numero_cuenta;
  cout << "\nSaldo: " << saldo << endl;
  cout << "Datos de la tarjeta:\n";
  cout << "Estado: " << tarjeta->get_estado() << endl;
  cout << "Numero de tarjeta: " << tarjeta->get_numero() << endl;
  cout << "Año de vencimiento: " << tarjeta->get_AnioVenci() << endl;
  cout << "Mes de vencimiento: " << tarjeta->get_MesVenci() << endl;
  cout << "CVV: " << tarjeta->get_CVV() << endl << endl;
}
void CCuentaDebito::bloquear_tarjeta() { tarjeta->set_estado("Bloqueada"); }
void CCuentaDebito::set_tarjetas_d(CTarjetaDebito *t) { tarjeta = t; }
void CCuentaDebito::set_tarjetas_c(CTarjetaCredito *t) {}
void CCuentaDebito::set_saldo(int monto) { saldo += monto; }

void CCuentaDebito::agregar_movimiento(vector<string> mo) {
  string n = mo[0];
  string m = mo[1];
  movimientos.emplace_back(n);
  movimientos.emplace_back(m);
}
string Cadena(int entero) {
  string numeroComoCadena = "";
  stringstream ss;
  ss << entero;
  ss >> numeroComoCadena;
  return numeroComoCadena;
}
void CCuentaDebito::guardar_movimientos() {
  int c = 1;
  ofstream archivo(Cadena(numero_cuenta) + ".txt");
  for (int i = 0; i < movimientos.size(); i++) {
    archivo << movimientos[i] << endl;
    c++;
  }
  archivo.close();
}
int CCuentaDebito::get_CVV() { return tarjeta->get_CVV(); }
int CCuentaDebito::get_AnioVenci() { return tarjeta->get_AnioVenci(); }
int CCuentaDebito::get_MesVenci() { return tarjeta->get_MesVenci(); }
int CCuentaDebito::get_numero_t() { return tarjeta->get_numero(); }
int CCuentaDebito::get_limite() {return 0;}
int CCuentaDebito::get_fecha() {return 0;}
string CCuentaDebito::get_estado() { return tarjeta->get_estado(); }