#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent * e);

private slots:
    void on_tabla_2_clicked();

    void on_tabla_3_clicked();

    void on_tabla_4_clicked();

    void on_tabla_5_clicked();

    void on_tabla_6_clicked();

    void on_tabla_7_clicked();

    void on_tabla_8_clicked();

    void on_tabla_9_clicked();

    void on_responder_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void enableUI();
    void disableUI();
};

#endif // MAINWINDOW_H
