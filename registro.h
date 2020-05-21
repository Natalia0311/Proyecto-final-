#ifndef REGISTRO_H
#define REGISTRO_H
#include <QWidget>
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QDate>
#include <QString>
#include <QMessageBox>
#include <QPushButton>
#include "datos_registro.h"
#include "datos_usuario.h"
#include "datos_paciente.h"

namespace Ui {
class registro;
}

class registro : public QMainWindow
{
    Q_OBJECT

public:
    explicit registro(QWidget *parent = 0);
    ~registro();
    QTimer *timer = new QTimer(); //cada segundo llame metodo para cambiar casilla;
    QTime time; //cuenteme cada segundo
    QTime cuente;
    QDate fecha;
    QDate nacimiento;
    int aciertos;
    int contaci;
    int tempo;
    int a0;
    int a1;
    int dia;
    int mes;
    int ano;
    int anio;
    int actu;
    char _estado;
    float _tiempoelegido;
    bool t1;
    bool t2;
    bool t3;
    bool t4;
    QMessageBox boxfinal;
    QPushButton* clicki;
signals:
    void botonpulsado(int);

public slots:
    void nuevovalor(int v);
    //slots -> metodos
    //signals -> eventos

private slots:
    void on_iniciar_clicked();
    void llenar_datos();
    void iniciar();
    void ejecutar_rutinas();
    void limite();
    void edad();
    void actualizaestado();
    void cambioestado();
    void aciertosclicks();
    void resultadofinal();

    void on_button0_clicked();

    void on_button10_clicked();

    void on_button20_clicked();

    void on_button30_clicked();

    void on_button40_clicked();

    void on_button50_clicked();

    void on_button60_clicked();

    void on_button70_clicked();

    void on_button80_clicked();

    void on_button90_clicked();

    void on_iniciar_2_clicked();

private:
    Ui::registro *ui;
    Datos_Usuario  _db;
    Datos_Registro  u;
};

#endif // REGISTRO_H
