#include "CBanco.h"
#include "CCuentaCredito.h"
#include "CCuentaDebito.h"
#include "CTarjetaCredito.h"
#include "CTarjetaDebito.h"
#include <fstream>
#include <sstream>
#include <string>

void CBanco::bloquear_tarjeta(string _dni, int p) {
  for (auto e : Clientes) {
    if (e->getdni() == _dni) {
      e->bloquear(p - 1);
      cout << "\nTarjeta bloqueada exitosamente\n";
    }
  }
}

void CBanco::solicitar_tarjeta_d(string _dni, int p, CTarjetaDebito *t) {
  for (auto e : Clientes) {
    if (e->getdni() == _dni) {
      e->solicitar_td(p - 1, t);
      cout << "\nTarjeta solicitada exitosamente\n";
    }
  }
}

void CBanco::solicitar_tarjeta_c(string _dni, int p, CTarjetaCredito *t) {
  for (auto e : Clientes) {
    if (e->getdni() == _dni) {
      e->solicitar_tc(p - 1, t);
      cout << "\nTarjeta solicitada exitosamente\n";
    }
  }
}
int CBanco::depositar(string _dni, int p, int monto) {
  int n;
  for (auto e : Clientes) {
    if (e->getdni() == _dni) {
      n = e->depositar(p - 1, monto);
      cout << "\nDeposito realizado exitosamente\n";
    }
  }
  return n;
}
void CBanco::agregar_movimiento(string _dni, int p, vector<string> mo) {
  for (auto e : Clientes) {
    if (e->getdni() == _dni) {
      e->agregar_movimiento(p - 1, mo);
    }
  }
}

void CBanco::agregar_servicio_(string _dni, CServicios *r) {
  for (auto e : Clientes) {
    if (e->getdni() == _dni) {
      e->AgregarServicio(r);
    }
  }
}

void CBanco::BuscarCliente(string _dni) {
  int r = 1;
  for (auto e : Clientes) {
    if (e->getdni() == _dni) {
      e->imprimir_datos();
      r = 0;
      break;
    }
  }
  if (r == 1) {
    cout << "No se encontró cliente";
  }
}

void CBanco::servicios_cliente(string _dni) {
  cout << "\nServicios: ";
  cout << endl;
  for (auto e : Clientes) {
    if (e->getdni() == _dni) {
      e->getservicios();
      string dni = e->getdni();
    }
  }
}

void CBanco::AgregaCliente(CCliente *_cliente) {
  Clientes.emplace_back(_cliente);
  string dni = _cliente->getdni();
  fstream registro_banco("clientes.txt",
                         ios::out); // txt del vector clientes del banco
  for (auto cliente : Clientes) {
    registro_banco << cliente->getnombre() << " ";
    registro_banco << cliente->getdni() << " ";
    registro_banco << cliente->getedad() << " ";
    registro_banco << cliente->getocupacion() << endl;
  }
  fstream archivo(dni + ".txt", ios::out); // txt del cliente
  archivo << dni << endl;
  archivo.close();
  registro_banco.close();
  // registro_banco.close();
  cout << "Se agrego al cliente";
}

int contar_palabras() {
  ifstream entrada("clientes.txt");
  string palabra;
  int contador = 0;
  while (!entrada.eof()) {
    entrada >> palabra;
    contador++;
  }
  entrada.close();
  return contador;
}
void CBanco::EliminarCliente(string _dni) {
  int n = Clientes.size();
  for (int i = 0; i < Clientes.size(); i++) {
    if (Clientes[i]->getdni() == _dni) {
      Clientes.erase(begin(Clientes) + i);
    }
  }
  if (Clientes.size() == n) {
    cout << "No se encontro el cliente";
  } else {
    cout << "Cliente borrado exitosamente";
  }
}

void CBanco::leer_archivos_clientes() {
  ifstream entrada("clientes.txt");
  string palabra, nombre, dni, e, ocu;
  int c = contar_palabras();
  int regresar = 1;
  for (int i = 0; i < c; i++) {
    entrada >> palabra;
    if (regresar == 1) {
      nombre = palabra;
      regresar++;
    } else if (regresar == 2) {
      dni = palabra;
      regresar++;
    } else if (regresar == 3) {
      e = palabra;
      regresar++;
    } else if (regresar == 4) {
      ocu = palabra;
      regresar++;
    } else {
      regresar = 0;
      AgregaCliente(new CCliente(nombre, dni, e, ocu));
    }
  }
  entrada.close();
}

void CBanco::leer_archivos_DEMANERAPRO() {
  fstream a_clientes("clientes.txt", ios::in);
  fstream datos_cliente;

  vector<string> datos;
  string dni;
  string linea;
  string linea2;
  string temp;
  int p = -1;
  int q = -1;

  while (getline(a_clientes, linea, ' ')) {
    string _nombre;
    string _dni;
    string _edad;
    string _ocupacion;

    p++;
    switch (p) {
    case 0:
      _nombre = linea;
      break;
    case 1:
      _dni = linea;
      dni = _dni;
      break;
    case 2:
      _edad = linea;
      break;
    case 3:
      _ocupacion = linea;
      auto client = new CCliente(_nombre, _dni, _edad, _ocupacion);
      Clientes.emplace_back(client);
      p = 0;

      datos_cliente.open(dni + ".txt", ios::in);
      while (getline(datos_cliente, linea2, ' ')) {
        datos.emplace_back(linea2);
      }
      datos_cliente.close();

      if (datos[3] == "credito") {
        auto tcredito = new CTarjetaCredito(stoi(datos[6]), stoi(datos[7]),
                                            stoi(datos[8]), stoi(datos[9]),
                                            stoi(datos[10]), stoi(datos[11]));
        auto ccredito = new CCuentaCredito(stoi(datos[4]), tcredito);
        client->AgregarServicio(ccredito);

      } else {
        auto tdebito = new CTarjetaDebito(stoi(datos[6]), stoi(datos[7]),
                                          stoi(datos[8]), stoi(datos[9]));
        auto cdebito = new CCuentaDebito(stoi(datos[4]), tdebito);
        client->AgregarServicio(cdebito);
      }
      datos.clear();
      break;
    }
    // CREDITO tipo , no cuenta, saldo, no tarjeta, anio tarjeta, mes tarjeta,
    // cvv,monto , fecha,  estado tarjeta DEBITO tipo , no cuenta, saldo, no
    // tarjeta, anio tarjeta, mes tarjeta, cvv, estado tarjeta
  }
  a_clientes.close();
}