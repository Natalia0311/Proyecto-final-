#ifndef INICIO_H
#define INICIO_H
#include "datos_inicio.h"
#include "datos_paciente.h"
#include "datos_usuario.h"
#include "registro.h"
#include "registro_new.h"
#include <QMainWindow>
#include <QWidget>

namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = 0);
    ~Inicio();
    char x;

private slots:
    void Llenar_Datos();
    void acceso();
    void on_go_regis_clicked();

    void on_go_entrar_clicked();

private:
    Ui::Inicio *ui;
    Datos_Inicio i;
    Datos_Paciente p;
    Datos_Usuario  _db;
};

#endif // INICIO_H
