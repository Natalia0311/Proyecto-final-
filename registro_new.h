#ifndef REGISTRO_NEW_H
#define REGISTRO_NEW_H

#include <QMainWindow>
#include "datos_paciente.h"
#include "datos_usuario.h"
#include <QPushButton>


namespace Ui {
class Registro_new;
}

class Registro_new : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registro_new(QWidget *parent = 0);
    ~Registro_new();

private slots:
    void Llenar_Datos();
    void on_guardar_new_clicked();

private:
    Ui::Registro_new *ui;
    Datos_Paciente p;
    Datos_Usuario  _db;

};

#endif // REGISTRO_NEW_H
