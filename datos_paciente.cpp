#include "datos_paciente.h"
#include <sqlite3.h>
#include <sstream>
#include <iostream>

Datos_Paciente::Datos_Paciente()
{

}


Datos_Paciente& Datos_Paciente::operator = (const Datos_Paciente &p ){
    if(&p != this ){
        _Nombre = p._Nombre;
       _Apellido = p._Apellido;
       _Documento = p._Documento;
       _Fecha = p._Fecha;
       _Usuario = p._Usuario;
       _Contrasena1 = p._Contrasena1;
       _Genero = p._Genero;
       _Raza = p._Raza;
       _Direccion = p. _Direccion;
       _Ingresos = p._Ingresos;

    }
}




