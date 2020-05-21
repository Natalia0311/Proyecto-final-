#include "registro_new.h"
#include "ui_registro_new.h"
#include "inicio.h"
#include "datos_paciente.h"
#include "datos_usuario.h"
#include "inicio.h"

Registro_new::Registro_new(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registro_new)
{
    ui->setupUi(this);
}

Registro_new::~Registro_new()
{
    delete ui;
}

void Registro_new::Llenar_Datos()
{
    _db.abrirB( "Datos_Usuario");
    _db.almacenarP(p);
    ui -> Nom_new->setText(QString::fromStdString(p.getNombre()));
    ui -> ape_new ->setText(QString::fromStdString(p.getApellido()));
    ui -> Usuario ->setText(QString::fromStdString(p.getUsuario()));
    ui -> id_new ->setText(QString::number(p.getDocumento()));
    ui -> con_new ->setText(QString::fromStdString(p.getContrasena1()));
    ui -> dir_new ->setText(QString::number(p.getDireccion()));
    ui -> fecha_new ->setText(QString::fromStdString(p.getFecha()) );
    ui -> ingr_new ->setText(QString::number(p.getIngresos()) );
    ui -> gen_new -> setCurrentText(QString::fromStdString(p.getGenero()));
    ui -> raza_new -> setCurrentText(QString::fromStdString(p.getRaza()));

   _db.cerrarB();
}

void Registro_new::on_guardar_new_clicked()
{
    Llenar_Datos();
    Registro_new::close();

}
