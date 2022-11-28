#include "CCuentaCredito.h"

void CCuentaCredito::info_cuentas() {
  cout << "Datos de la cuenta:\n";
  cout << "Numero de cuenta: " << numero_cuenta;
  cout << "\nSaldo: " << saldo << endl;
  cout << "Fecha de pago: " << tarjeta->get_fecha() <<" de cada mes "<< endl;
  cout << "Datos de la tarjeta asociada:\n";
  cout << "Estado: " << tarjeta->get_estado() << endl;
  cout << "Numero de tarjeta: " << tarjeta->get_numero() << endl;
  cout << "Monto limite: " << tarjeta->get_limite() << endl;
  cout << "Año de vencimiento: " << tarjeta->get_AnioVenci() << endl;
  cout << "Mes de vencimiento: " << tarjeta->get_MesVenci() << endl;
  cout << "CVV: " << tarjeta->get_CVV() << endl<<endl;
}
void CCuentaCredito::bloquear_tarjeta(){
  tarjeta->set_estado("Bloqueada");
}
void CCuentaCredito::set_tarjetas_c(CTarjetaCredito* t){
  tarjeta= t;
}
void CCuentaCredito::set_tarjetas_d(CTarjetaDebito* t){
}
  void CCuentaCredito::set_saldo(int monto){
    saldo+=monto;
  }
void CCuentaCredito::agregar_movimiento(vector<string> mo){
  string n= mo[0];
  string m= mo[1];
  movimientos.emplace_back(n);
  movimientos.emplace_back(m);
}

string entero(int entero)
{
    string numeroComoCadena = "";
    stringstream ss;
    ss << entero;
    ss >> numeroComoCadena;
    return numeroComoCadena;
}
void CCuentaCredito::guardar_movimientos(){
  int c=1;
  ofstream archivo(entero(numero_cuenta)+".txt");
  for (int i=0;i<movimientos.size();i++){
    archivo<< movimientos[i]<<endl;
    c++;
  }
  archivo.close();
}
int CCuentaCredito::get_CVV() { return tarjeta->get_CVV(); }
int CCuentaCredito::get_AnioVenci() { return tarjeta->get_AnioVenci(); }
int CCuentaCredito::get_MesVenci() { return tarjeta->get_MesVenci(); }
int CCuentaCredito::get_numero_t() { return tarjeta->get_numero(); }
int CCuentaCredito::get_limite() {return tarjeta->get_limite();}
int CCuentaCredito::get_fecha() {return tarjeta->get_fecha();}
string CCuentaCredito::get_estado() { return tarjeta->get_estado(); }