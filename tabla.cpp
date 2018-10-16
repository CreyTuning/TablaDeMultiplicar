#include "tabla.h"

Tabla::Tabla()
{
    //clear tabla in 0
    for(int i = 0; i < 10; i++)
        valores[i] = 0;
}

void Tabla::setTabla(int tabla)
{
    this->tabla = tabla;
}

void Tabla::initValores()
{
    for(int i = 0; i < 10; i++)
        valores[i] = i + 1;
}

int Tabla::deleteValor(int valor)
{
    // return 0 success or if -1 error
    for(int i = 0; i < 10; i++)
    {
        if(valores[i] == valor)
        {
            valores[i] = 0;
            return 0;
        }
    }
    return -1;
}

int Tabla::getTabla()
{
    return this->tabla;
}

bool Tabla::isValoresClear()
{
    for(int i = 0; i < 10; i++)
        if(this->valores[i] != 0)
            return false;
    return true;
}

void Tabla:: setCurrentValue()
{
    //Veificar que la tabla no este limpia
    if(this->isValoresClear())
        return;

    //Buscar valores
    int valor = 0;

    while (true)
    {
        valor = qrand() % ((10 + 1) - 1) + 1;
        for(int i = 0; i < 10; i++)
        {
            if(this->valores[i] == valor)
            {
                this->valorActual = valor;
                return;
            }
        }
    }
}

int Tabla:: getCurrentValue()
{
    return this->valorActual;
}
