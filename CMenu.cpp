#include "CMenu.h"
#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

enum class Opciones {
  Clientes = 1,
  Cuentas_de_ahorro = 2,
  Cuentas_de_credito = 3,
};

enum class Opciones_clie { buscar = 1, agregar = 2, borrar = 3, ver = 4 };

enum class Opciones_credito {
  agregar = 1,
  bloquear = 2,
  solicitar = 3,
};
enum class Opciones_ahorro {
  agregar = 1,
  bloquear = 2,
  solicitar = 3,
  depositar = 4
};

string a(int entero) {
  string numeroComoCadena = "";
  stringstream ss;
  ss << entero;
  ss >> numeroComoCadena;
  return numeroComoCadena;
}

void limpiar() { cout << "\033[2J\033[0;0H"; }

void CMenu::imprimir_menu() {
  limpiar();
  cout << "SERVICIOS\n";
  cout << string(9, '-') << "\n\n";
  cout << "1. Clientes\n";
  cout << "2. Cuentas de ahorro\n";
  cout << "3. Cuentas de credito\n";
  cout << "0. Salir\n\n";
}

void CMenu::activar() {
  do {
    //banco.leer_archivos_DEMANERAPRO();
    imprimir_menu();
    cout << "\nOpcion: ";
    cin >> opcion;
    opciones_lista();
  } while (opcion != 0);
  cout << "Fin del programa...\n";
}

void CMenu::opciones_lista() {
  limpiar();
  switch (Opciones(opcion)) {
  case Opciones::Clientes:
    imprimir_menu_clientes();
    cout << "\nOpcion: ";
    cin >> opcion;
    opciones_cliente();
    break;
  case Opciones::Cuentas_de_credito:
    imprimir_menu_cuentas_credito();
    cout << "\nOpcion: ";
    cin >> opcion;
    opciones_credito();
    break;
  case Opciones::Cuentas_de_ahorro:
    imprimir_menu_cuentas_ahorro();
    cout << "\nOpcion: ";
    cin >> opcion;
    opciones_ahorro();
    break;
  }
}

void CMenu::opciones_cliente() {
  limpiar();
  switch (Opciones_clie(opcion)) {
  case Opciones_clie::agregar:
    agregar_cliente();
    cout<<"\nOpcion: ";
    cin >> opcion;
    break;
  case Opciones_clie::borrar:
    borrar_cliente();
    cout<<"\nOpcion: ";
    cin >> opcion;

    break;
  case Opciones_clie::buscar:
    buscar_cliente();
    cout<<"\nOpcion: ";
    cin >> opcion;
    break;
  case Opciones_clie::ver:
    ver_servis();
    cout<<"\nOpcion: ";
    cin >> opcion;
    break;
  }
}

void CMenu::opciones_ahorro() {
  limpiar();
  switch (Opciones_ahorro(opcion)) {
  case Opciones_ahorro::agregar:
    agregar_servicio_debito();
    cout<<"\nOpcion: ";
    cin >> opcion;
    break;
  case Opciones_ahorro::bloquear:
    bloquear_tarjeta();
    cout<<"\nOpcion: ";
    cin >> opcion;
    break;
  case Opciones_ahorro::solicitar:
    solicitar_tarjeta_debito();
    cout<<"\nOpcion: ";
    cin >> opcion;
    break;
  case Opciones_ahorro::depositar:
    depositar();
    cout<<"\nOpcion: ";
    cin >> opcion;
    break;
  }
}

void CMenu::opciones_credito() {
  limpiar();
  switch (Opciones_credito(opcion)) {
  case Opciones_credito::agregar:
    agregar_servicio_credito();
    cout<<"\nOpcion: ";
    cin >> opcion;
    break;
  case Opciones_credito::bloquear:
    bloquear_tarjeta();
    cout<<"\nOpcion: ";
    cin >> opcion;
    break;
  case Opciones_credito::solicitar:
    solicitar_tarjeta_credito();
    cout<<"\nOpcion: ";
    cin >> opcion;
    break;
  }
}
void CMenu::agregar_cliente() {
  string nombre, dni, ocu;
  string e;
  cout << "Ingrese Nombre: ";
  cin >> nombre;
  cout << "Ingrese DNI: ";
  cin >> dni;
  cout << "Ingrese edad: ";
  cin >> e;
  cout << "Ingrese ocupacion: ";
  cin >> ocu;
  banco.AgregaCliente(new CCliente(nombre, dni, e, ocu));
  cout << "\n1. Regresar al menu principal" << endl;
  
}

void CMenu::agregar_servicio_debito() {
  string dni;
  cout << "Ingrese DNI: ";
  cin >> dni;
  int n_c = 100000000 + rand() % 99999999999;
  int n_t = 100000000 + rand() % 99999999999;
  int mes = 1 + rand() % 12;
  int cvv = 100 + rand() % 999;
  int anio = 2025 + rand() % 20;
  auto cuenta = new CCuentaDebito(n_c, new CTarjetaDebito(n_t, anio, mes, cvv));
  banco.agregar_servicio_(dni, cuenta);
  cout << "Se creo la cuenta de ahorros\n";
  cout << "\n1. Regresar al menu principal" << endl;
}

void CMenu::agregar_servicio_credito() {
  string dni;
  int monto;
  srand(time(0));
  cout << "Ingrese DNI: ";
  cin >> dni;
  int n_c = 100000000 + rand() % 99999999999;
  int n_t = 100000000 + rand() % 99999999999;
  int mes = 1 + rand() % 12;
  int cvv = 100 + rand() % 999;
  int anio = 2025 + rand() % 20;
  int fecha_p = 1 + rand() % 30;
  cout << endl << "\nIngrese monto limite: ";
  cin >> monto;
  auto cuenta = new CCuentaCredito(
      n_c, new CTarjetaCredito(n_t, anio, mes, cvv, monto, fecha_p));
  banco.agregar_servicio_(dni, cuenta);
  cout << "Se creo la cuenta de credito\n";
  cout << "\n1. Regresar al menu principal" << endl;
}

void CMenu::buscar_cliente() {
  string _dni;
  cout << "\nIngrese DNI: ";
  cin >> _dni;
  banco.BuscarCliente(_dni);
  cout << "\n1. Regresar al menu principal" << endl;
}

void CMenu::borrar_cliente() {
  string _dni;
  cout << "\nIngrese DNI: ";
  cin >> _dni;
  banco.EliminarCliente(_dni);
  cout << "\n1. Regresar al menu principal" << endl;
}
void CMenu::ver_servis() {
  string _dni;
  cout << "\nIngrese DNI: ";
  cin >> _dni;
  banco.servicios_cliente(_dni);
  cout << "1. Regresar al menu principal" << endl;
}

void CMenu::imprimir_menu_clientes() {
  limpiar();
  cout << "CLIENTES\n";
  cout << string(9, '-') << "\n\n";
  cout << "1. Buscar cliente\n";
  cout << "2. Agregar cliente\n";
  cout << "3. Borrar cliente\n";
  cout << "4. Listar servicios del cliente\n";
  cout << "0. Salir\n\n";
}

void CMenu::imprimir_menu_cuentas_credito() {
  limpiar();
  cout << "CUENTAS DE CREDITO\n";
  cout << string(9, '-') << "\n\n";
  cout << "1. Agregar servico/Crear cuenta \n";
  cout << "2. Bloquear tarjeta\n";
  cout << "3. Solicitar tarjeta\n";
  cout << "0. Salir\n\n";
}

void CMenu::imprimir_menu_cuentas_ahorro() {
  limpiar();
  cout << "CUENTAS DE AHORRO\n";
  cout << string(9, '-') << "\n\n";
  cout << "1. Agregar servicio/Crear cuenta\n";
  cout << "2. Bloquear tarjeta\n";
  cout << "3. Solicitar tarjeta\n";
  cout << "4. Depositar en la cuenta\n";
  cout << "0. Salir\n\n";
}

void CMenu::bloquear_tarjeta() {
  string _dni;
  int p;
  cout << "\nIngrese DNI: ";
  cin >> _dni;
  banco.servicios_cliente(_dni);
  cout << endl << "\nSeleccionar cuenta de la tarjeta a bloquear: ";
  cin >> p;
  banco.bloquear_tarjeta(_dni, p);
  cout << "\n1. Regresar al menu principal" << endl;
}

void CMenu::solicitar_tarjeta_debito() {
  string _dni;
  int p;
  int n_t = 100000000 + rand() % 99999999999;
  int mes = 1 + rand() % 12;
  int cvv = 100 + rand() % 999;
  int anio = 2025 + rand() % 20;
  cout << "\nIngrese DNI: ";
  cin >> _dni;
  banco.servicios_cliente(_dni);
  cout << endl << "\nSeleccionar cuenta de la tarjeta de debito a solicitar: ";
  cin >> p;
  banco.solicitar_tarjeta_d(_dni, p, new CTarjetaDebito(n_t, anio, mes, cvv));
  cout << "\n1. Regresar al menu principal" << endl;
}

void CMenu::solicitar_tarjeta_credito() {
  string _dni;
  int p, monto;
  int n_t = 100000000 + rand() % 99999999999;
  int fecha_p = 1 + rand() % 30;
  int mes = 1 + rand() % 12;
  int cvv = 100 + rand() % 999;
  int anio = 2025 + rand() % 20;
  cout << "\nIngrese DNI: ";
  cin >> _dni;
  banco.servicios_cliente(_dni);
  cout << endl << "\nSeleccionar cuenta de la tarjeta de credito a solicitar: ";
  cin >> p;
  cout << endl << "\nIngrese monto limite: ";
  cin >> monto;
  banco.solicitar_tarjeta_c(
      _dni, p, new CTarjetaCredito(n_t, anio, mes, cvv, monto, fecha_p));
  cout << "\n1. Regresar al menu principal" << endl;
}

void CMenu::depositar() {
  string _dni;
  int cuenta;
  int p, monto;
  int n_t = 100000000 + rand() % 99999999999;
  int mes = 1 + rand() % 12;
  int cvv = 100 + rand() % 999;
  int anio = 2025 + rand() % 20;
  cout << "\nIngrese DNI: ";
  cin >> _dni;
  banco.servicios_cliente(_dni);
  cout << endl << "\nSeleccionar cuenta a depositar: ";
  cin >> p;
  cout << "Monto: ";
  cin >> monto;
  cout << endl;
  cuenta = banco.depositar(_dni, p, monto);
  string convertido = a(cuenta);
  vector<string> m = {convertido, a(monto)};
  banco.agregar_movimiento(_dni, p, m);
  cout << "\nDATOS DEL MOVIMENTO" << endl;
  cout << string(20, '-') << "\n\n";
  cout << "Cuenta: Cuenta de debito\n";
  cout << "Numero de cuenta:" << cuenta << endl;
  cout << "Monto: " << monto << endl;
  // cout << "Fecha del movimiento: "<<fecha<<endl;
  cout << "\n1. Regresar al menu principal" << endl;
}
