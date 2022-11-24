#ifndef __CSERVICIOS_H__
#define __CSERVICIOS_H__
#include <iostream>
using namespace std;

class CServicios
{
protected:
    int num_tarjeta;
    int año_venci;
    int mes_venci;
    int CVV;

public:
    CServicios(int num_tarjeta, int año_venci, int mes_venci, int CVV)
    {
        this->num_tarjeta = num_tarjeta;
        this->año_venci = año_venci;
        this->mes_venci = mes_venci;
        this->CVV = CVV;
    }

    void Renovar_tarj(int mes_venci, int año_venci)
    {
        this->año_venci = año_venci;
        this->mes_venci = mes_venci;
    }

    int get_CVV() { return this->CVV; }
    int get_AñoVenci() { return año_venci; }
    int get_MesVenci() { return mes_venci; }
    virtual string get_tipo() {}
};
#endif // __CSERVICIOS_H__
