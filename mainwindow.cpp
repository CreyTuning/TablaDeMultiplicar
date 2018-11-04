#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabla.h"
#include "score.h"
#include "qstring.h"

static Tabla * tabla = new Tabla();
static bool isUiEnable = false;
static Score * score = new Score();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->disableUI();

    score->update();
    ui->score->display(score->getScore());
    ui->completed->display(score->getCompleted());

    titleScoreUpdate();
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
    isUiEnable = true;
    ui->responder_pushButton->setEnabled(true);
    updateStatus_botonAyuda();
    ui->respuesta_SpinBox->setEnabled(true);
    ui->estado_label->setText("responde");
    ui->progressBar->setEnabled(true);
}

void MainWindow::disableUI()
{
    ui->responder_pushButton->setEnabled(false);
    ui->respuesta_SpinBox->setEnabled(false);
    ui->estado_label->setText("seleccione una tabla");
    ui->ayuda_pushButton->setEnabled(false);
    ui->progressBar->setEnabled(false);
    isUiEnable = false;
}

void MainWindow::on_tabla_2_clicked()
{
    enableUI();
    tabla->setTabla(2);
    tabla->initValores();
    tabla->setCurrentValue();
    ui->progressBar->setValue(0);
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
    ui->progressBar->setValue(0);
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
    ui->progressBar->setValue(0);
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
    ui->progressBar->setValue(0);
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
    ui->progressBar->setValue(0);
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
    ui->progressBar->setValue(0);
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
    ui->progressBar->setValue(0);
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
    ui->progressBar->setValue(0);
    ui->estado_label->setText("TABLA DEL 9");
    ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
    ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
}

void MainWindow::on_responder_pushButton_clicked()
{

    if(ui->respuesta_SpinBox->text() == "")
    {
        ui->estado_label->setText("Debes responder primero!");
        return;
    }

    if(ui->respuesta_SpinBox->text().toInt() == (tabla->getCurrentValue() * tabla->getTabla()))
    {
        // Respuesta correcta
        ui->estado_label->setText("CORRECTO");
        tabla->deleteValor(tabla->getCurrentValue());
        tabla->setCurrentValue();
        ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
        ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
        ui->progressBar->setValue(ui->progressBar->value() + 10);
        score->setScore(score->getScore() + 10);
        score->save();
        ui->score->display(score->getScore());
        ui->progressBar->setStyleSheet("QProgressBar {border-radius: 10px;outline: none;background-color: #f1f3f4;}"
                                       "QProgressBar::chunk {border-radius: 10px;background-color: #AA00FF;}"
                                       "QProgressBar:disabled {background-color: #ebebeb;color: #ebebeb;}");


        //FIN de la tabla
        if(tabla->isValoresClear())
        {
            disableUI();
            ui->estado_label->setText("COMPLETADO, EXCELENTE!");
            ui->valorLeft_lcdNumber->display("0");
            ui->valorRight_lcdNumber->display("0");
            score->setCompleted(score->getCompleted() + 1);
            score->save();
            ui->completed->display(score->getCompleted());
        }
    }
    else //Respuesta erronea
    {
        auto mensaje = QString("Auch! vuelte a intentarlo (-10 pts)");

        ui->estado_label->setText(mensaje);
//        tabla->setCurrentValue();
//        ui->valorLeft_lcdNumber->display(QString::number(tabla->getTabla()));
//        ui->valorRight_lcdNumber->display(QString::number(tabla->getCurrentValue()));
        ui->progressBar->setStyleSheet("QProgressBar {border-radius: 10px;outline: none;background-color: #f1f3f4;}"
                                       "QProgressBar::chunk {border-radius: 10px;background-color: #C51162;}"
                                       "QProgressBar:disabled {background-color: #ebebeb;color: #ebebeb;}");

        score->setScore(score->getScore() - 10);
        score->save();
        ui->score->display(score->getScore());
    }

    ui->respuesta_SpinBox->clear();
    ui->respuesta_SpinBox->focusWidget();

    updateStatus_botonAyuda();
    titleScoreUpdate();

}

void MainWindow::on_ayuda_pushButton_clicked()
{
    if(ui->estado_label->text() == QString::number(tabla->getCurrentValue() * tabla->getTabla()) ||
            ui->estado_label->text() == QString::number(tabla->getCurrentValue() * tabla->getTabla()) + " AQUI!!")
    {
        if(ui->estado_label->text() == QString::number(tabla->getCurrentValue() * tabla->getTabla()) + " AQUI!!")
        {
            ui->ayuda_pushButton->setEnabled(false);
            return;
        }

        ui->estado_label->setText(ui->estado_label->text() + " AQUI!!");
        return;
    }

    if(score->getScore() >= 100)
    {
        ui->estado_label->setText(QString::number(tabla->getCurrentValue() * tabla->getTabla()));
        score->setScore(score->getScore() - 100);
        score->save();
        ui->score->display(score->getScore());
    }

    else
         ui->estado_label->setText("Necesitas tener 100 puntos!");

    updateStatus_botonAyuda();
    titleScoreUpdate();
}

void MainWindow::updateStatus_botonAyuda()
{
    // ACTIVAR O DESABILITAR BOTON AYUDA
    if(score->getScore() >= 100 && isUiEnable == true)
        ui->ayuda_pushButton->setEnabled(true);
    else
        ui->ayuda_pushButton->setEnabled(false);
}

void MainWindow::titleScoreUpdate()
{
    if(score->getScore() > 10000)
        ui->title->setText("YA GANASTE!!!");

    else if(score->getScore() > 9000)
        ui->title->setText("Concentrate!");

    else if(score->getScore() > 8000)
        ui->title->setText("... shhh!!");

    else if(score->getScore() > 7000)
        ui->title->setText("Nadie ha podido!");

    else if(score->getScore() > 6000)
        ui->title->setText("Record mundial!");

    else if(score->getScore() > 5000)
        ui->title->setText("Insuperable");

    else if(score->getScore() > 4000)
        ui->title->setText("Profesional!");

    else if(score->getScore() > 3000)
        ui->title->setText("OMG!! :O");

    else if(score->getScore() > 2000)
        ui->title->setText("INCREIBLE!! 20");

    else if(score->getScore() > 1900)
        ui->title->setText("Muy ALTO! 19");

    else if(score->getScore() > 1800)
        ui->title->setText("Imposible! 18");

    else if(score->getScore() > 1700)
        ui->title->setText("No puede ser! 17");

    else if(score->getScore() > 1600)
        ui->title->setText("Grandee! Nivel 16");

    else if(score->getScore() > 1500)
        ui->title->setText("Sorprendente! 15");

    else if(score->getScore() > 1400)
        ui->title->setText("Bien! Nivel 14");

    else if(score->getScore() > 1300)
        ui->title->setText("Buen trabajo! 13");

    else if(score->getScore() > 1200)
        ui->title->setText("Wow! Nivel 12");

    else if(score->getScore() > 1100)
        ui->title->setText("Eres Nivel 11");

    else if(score->getScore() > 1000)
        ui->title->setText("Maravilloso! 10");

    else if(score->getScore() > 900)
        ui->title->setText("Muy ALTO! 9");

    else if(score->getScore() > 800)
        ui->title->setText("Imposible! 8");

    else if(score->getScore() > 700)
        ui->title->setText("No puede ser! 7");

    else if(score->getScore() > 600)
        ui->title->setText("Grandee!!! 6");

    else if(score->getScore() > 500)
        ui->title->setText("Sorprendente! 5");

    else if(score->getScore() > 400)
        ui->title->setText("Muy Bien! Nivel 4");

    else if(score->getScore() > 300)
        ui->title->setText("Buen trabajo! 3");

    else if(score->getScore() > 200)
        ui->title->setText("Wow! Nivel 2");

    else if(score->getScore() > 100)
        ui->title->setText("Eres Nivel 1");

    else if(score->getScore() <= 100)
        ui->title->setText("Tabla de Multiplicar");
}
