#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabla.h"

static Tabla * tabla = new Tabla();
static bool isUiEnable = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->disableUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * e)
{
    if(!isUiEnable)
        return;

    int key = e->key();
    QString temp;

    //NUMPAD
    if(key == 48) { ui->respuesta_SpinBox->setText(ui->respuesta_SpinBox->text() + "0"); }
    else if(key == 49) { ui->respuesta_SpinBox->setText(ui->respuesta_SpinBox->text() + "1"); }
    else if(key == 50) { ui->respuesta_SpinBox->setText(ui->respuesta_SpinBox->text() + "2"); }
    else if(key == 51) { ui->respuesta_SpinBox->setText(ui->respuesta_SpinBox->text() + "3"); }
    else if(key == 52) { ui->respuesta_SpinBox->setText(ui->respuesta_SpinBox->text() + "4"); }
    else if(key == 53) { ui->respuesta_SpinBox->setText(ui->respuesta_SpinBox->text() + "5"); }
    else if(key == 54) { ui->respuesta_SpinBox->setText(ui->respuesta_SpinBox->text() + "6"); }
    else if(key == 55) { ui->respuesta_SpinBox->setText(ui->respuesta_SpinBox->text() + "7"); }
    else if(key == 56) { ui->respuesta_SpinBox->setText(ui->respuesta_SpinBox->text() + "8"); }
    else if(key == 57) { ui->respuesta_SpinBox->setText(ui->respuesta_SpinBox->text() + "9"); }

    //BACKSPACE
    temp =  ui->respuesta_SpinBox->text();
    temp.chop(1);
    if(key == 16777219) {  ui->respuesta_SpinBox->setText(temp); }

    //ENTER
    if(key == 16777221 || key == 16777220) {on_responder_pushButton_clicked(); }

    //SCAPE
    if(key == 16777216) { ui->respuesta_SpinBox->clear(); }
}

void MainWindow::enableUI()
{
    ui->responder_pushButton->setEnabled(true);
    ui->respuesta_SpinBox->setEnabled(true);
    ui->estado_label->setText("responde");
    isUiEnable = true;
}

void MainWindow::disableUI()
{
    ui->responder_pushButton->setEnabled(false);
    ui->respuesta_SpinBox->setEnabled(false);
    ui->estado_label->setText("seleccione una tabla");
    isUiEnable = false;
}

void MainWindow::on_tabla_2_clicked()
{
    enableUI();
    tabla->setTabla(2);
    tabla->initValores();
    tabla->setCurrentValue();
    ui->estado_label->setText("TABLA DEL 2");
    ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
    ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
}

void MainWindow::on_tabla_3_clicked()
{
    enableUI();
    tabla->setTabla(3);
    tabla->initValores();
    tabla->setCurrentValue();
    ui->estado_label->setText("TABLA DEL 3");
    ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
    ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
}

void MainWindow::on_tabla_4_clicked()
{
    enableUI();
    tabla->setTabla(4);
    tabla->initValores();
    tabla->setCurrentValue();
    ui->estado_label->setText("TABLA DEL 4");
    ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
    ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
}

void MainWindow::on_tabla_5_clicked()
{
    enableUI();
    tabla->setTabla(5);
    tabla->initValores();
    tabla->setCurrentValue();
    ui->estado_label->setText("TABLA DEL 5");
    ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
    ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
}

void MainWindow::on_tabla_6_clicked()
{
    enableUI();
    tabla->setTabla(6);
    tabla->initValores();
    tabla->setCurrentValue();
    ui->estado_label->setText("TABLA DEL 6");
    ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
    ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
}

void MainWindow::on_tabla_7_clicked()
{
    enableUI();
    tabla->setTabla(7);
    tabla->initValores();
    tabla->setCurrentValue();
    ui->estado_label->setText("TABLA DEL 7");
    ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
    ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
}

void MainWindow::on_tabla_8_clicked()
{
    enableUI();
    tabla->setTabla(8);
    tabla->initValores();
    tabla->setCurrentValue();
    ui->estado_label->setText("TABLA DEL 8");
    ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
    ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
}

void MainWindow::on_tabla_9_clicked()
{
    enableUI();
    tabla->setTabla(9);
    tabla->initValores();
    tabla->setCurrentValue();
    ui->estado_label->setText("TABLA DEL 9");
    ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
    ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
}

void MainWindow::on_responder_pushButton_clicked()
{
    if(ui->respuesta_SpinBox->text().toInt() == (tabla->getCurrentValue() * tabla->getTabla()))
    {
        // Respuesta correcta
        ui->estado_label->setText("CORRECTO");
        tabla->deleteValor(tabla->getCurrentValue());
        tabla->setCurrentValue();
        ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
        ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));

        //FIN de la tabla
        if(tabla->isValoresClear())
        {
            disableUI();
            ui->estado_label->setText("HAS TERMINADO LA TABLA, EXCELENTE :D");
            ui->valorLeft_lcdNumber->display("0");
            ui->valorRight_lcdNumber->display("0");
        }
    }
    else //Respuesta erronea
    {
        ui->estado_label->setText("ERROR... vuelve a intentarlo");
    }

    ui->respuesta_SpinBox->clear();
    ui->respuesta_SpinBox->focusWidget();
}
