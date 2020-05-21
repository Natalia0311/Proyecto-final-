#include "registro.h"
#include "ui_registro.h"
#include "datos_registro.h"
#include "datos_usuario.h"
#include <qstring.h>
#include <iostream>

registro::registro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registro)
{
    ui->setupUi(this);
}
using namespace std;

void registro::resultadofinal(){
    boxfinal.setWindowTitle("Aviso!");


    if (time == cuente ){
      timer->stop();
      boxfinal.setText("Prueba terminada con exito!");
      boxfinal.setIcon(QMessageBox::Information);
      boxfinal.addButton(QMessageBox::Close);
      boxfinal.setDefaultButton(QMessageBox::Close);
      ui->button01->resize(51,51);
      ui->button11->resize(51,51);
      ui->button21->resize(51,51);
      ui->button31->resize(51,51);
      ui->button41->resize(51,51);
      ui->button51->resize(51,51);
      ui->button61->resize(51,51);
      ui->button71->resize(51,51);
      ui->button81->resize(51,51);
      ui->button91->resize(51,51);
      aciertosclicks();
      if(QMessageBox::Close == boxfinal.exec()){
      }
    }
}
void registro::actualizaestado(){
    time = time.addSecs(1);
    tempo += tempo;
    ui->tiempo->setText(time.toString("mm:ss"));
    ui->button51->resize(0,0);
    aciertosclicks();
    ui->button51->resize(51,51);
    _estado = 1;
    timer->setInterval( 1000 );
    timer->start();
    connect(timer, &QTimer::timeout, this, &registro::cambioestado);
}
void registro::cambioestado(){
    switch(_estado){
    case 1:
        _estado = 2;
        ui->button51->resize(51,51);
        ui->button01->resize(0,0);
        break;
    case 2:
        _estado = 3;
        ui->button01->resize(51,51);
        ui->button91->resize(0,0);
        break;
    case 3:
        _estado = 4;
        ui->button91->resize(51,51);
        ui->button61->resize(0,0);
        break;
    case 4:
        _estado = 5;
        ui->button61->resize(51,51);
        ui->button21->resize(0,0);
        break;
    case 5:
        _estado = 6;
        ui->button21->resize(51,51);
        aciertosclicks();
        ui->button71->resize(0,0);
        break;
    case 6:
        _estado = 7;
        ui->button71->resize(51,51);
        ui->button81->resize(0,0);
        break;
    case 7:
        _estado = 8;
        ui->button81->resize(51,51);
        ui->button11->resize(0,0);
        break;
    case 8:
        _estado = 9;
        ui->button11->resize(51,51);
        aciertosclicks();
        ui->button41->resize(0,0);
        break;
    case 9:
        _estado = 10;
        ui->button41->resize(51,51);
        ui->button31->resize(0,0);
        break;
    case 10:
        _estado = 11;
        ui->button31->resize(51,51);
        ui->button61->resize(0,0);
        break;
    case 11:
        _estado = 1;
        ui->button61->resize(51,51);
        ui->button51->resize(0,0);
        break;
    default:
        break;
    }
}
void registro::ejecutar_rutinas(){
    actualizaestado();
    resultadofinal();
}
void registro::iniciar(){
    aciertos = 0;
    time.setHMS(0,0,0);
    ui->tiempo->setText(time.toString());
    timer->start(1000);
    connect(timer, &QTimer::timeout, this, &registro::ejecutar_rutinas);
}
void registro::limite(){
    if(ui->time1->isChecked()){
        cuente.setHMS(00,00,30);
        _tiempoelegido = 0.30;
    }
    else if(ui->time2->isChecked()){
        cuente.setHMS(00,01,00);
        _tiempoelegido = 1.00;
    }
    else if(ui->time3->isChecked()){
        cuente.setHMS(00,01,30);
        _tiempoelegido = 1.30;
    }
    else if(ui->time4->isChecked()){
        cuente.setHMS(00,02,00);
        _tiempoelegido = 2.00;
    }
    ui->duracion_registro->setText(cuente.toString());

}

void registro::aciertosclicks(){
    ui->aciertos->setText(QString::number(aciertos));
    ui->aciertos_registro->setText(QString::number(aciertos));

}
void registro::on_iniciar_clicked()
{
    limite();
    iniciar();
}
registro::~registro()
{
    delete ui;
}
void registro::edad(){
    QDate anio;
    actu = anio.year() - ano;
    cout<< actu << endl;
    ui->edad_registro->setText(QString::number(actu));

}

void registro::nuevovalor(int v){
    ui->aciertos->setText(QString::number(v));
}

void registro::llenar_datos(){

    ui -> nom_reg->setText(QString::fromStdString(u.getNombre()));
    ui -> ape_reg ->setText(QString::fromStdString(u.getApellido()));
    ui -> id_reg ->setText(QString::number(u.getDocumento()));
    ui -> ano_reg ->setText(QString::number(ano));
    ui -> mes_reg ->setText(QString::number(mes));
    ui -> dia_reg ->setText(QString::number(dia));
    edad();
    _db.abrirB( "datos_usuarios.db");
    _db.almacenarU(u);
    _db.cerrarB();

}

void registro::on_button0_clicked()
{
    ++aciertos;

    emit botonpulsado(aciertos);
}

void registro::on_button10_clicked()
{
    ++aciertos;
    emit botonpulsado(aciertos);
}

void registro::on_button20_clicked()
{
    ++aciertos;
    emit botonpulsado(aciertos);
}

void registro::on_button30_clicked()
{

}

void registro::on_button40_clicked()
{

}

void registro::on_button50_clicked()
{
    ++aciertos;
    emit botonpulsado(aciertos);
}

void registro::on_button60_clicked()
{
    ++aciertos;
    emit botonpulsado(aciertos);
}

void registro::on_button70_clicked()
{
    ++aciertos;
    emit botonpulsado(aciertos);
}

void registro::on_button80_clicked()
{
    ++aciertos;
    emit botonpulsado(aciertos);
}

void registro::on_button90_clicked()
{
    ++aciertos;
    emit botonpulsado(aciertos);
}

void registro::on_iniciar_2_clicked()
{
    registro::close();
}
