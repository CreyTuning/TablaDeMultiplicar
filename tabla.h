#ifndef TABLA_H
#define TABLA_H

#include <QMainWindow>

class Tabla
{
private:
    int valores[10];
    int tabla = 0;
    int valorActual = 0;

public:
    Tabla();

    void initValores();
    bool isValoresClear();
    int deleteValor(int valor);

    void setTabla(int tabla);
    void setCurrentValue();

    int getTabla();
    int getCurrentValue();
};

#endif // TABLA_H
