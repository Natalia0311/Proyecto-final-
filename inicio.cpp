#include "inicio.h"
#include "ui_inicio.h"

#include "datos_inicio.h"
#include "datos_usuario.h"
#include "datos_paciente.h"


Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);

}

Inicio::~Inicio()
{
    delete ui;
}


void Inicio::Llenar_Datos()
{


   ui ->nom_usu ->setText(QString::fromStdString(i.getUsuario()) );
   ui-> contra -> setText(QString::fromStdString(i.getContrasena()) );
   _db.abrirB( "datos_usuarios.db");
   _db.almacenar(i);
   _db.cerrarB();
}

void Inicio::on_go_regis_clicked()
{
    Registro_new *vi = new Registro_new(0);
    vi->show();
}

void Inicio::on_go_entrar_clicked( )
{
    registro *r = new registro(0);
    r->show();
}
void Inicio::acceso(){
    char x = QString::compare(i.getContrasena(),p.getContrasena1(), Qt::CaseInsensitive);

  if(x == 0){
     }// Si son iguales NO mostrar
     else{
     ui->label_4->setText("Usuario o contraseña incorrecta");
    }
}



