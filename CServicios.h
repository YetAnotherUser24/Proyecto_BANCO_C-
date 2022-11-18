class Servicios
{
protected:
    int num_tarjeta;
    int año_venci;
    int mes_venci;
    int CVV;

public:
    Servicios(int num_tarjeta, int año_venci, int mes_venci, int CVV)
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
};