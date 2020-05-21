#include "datos_inicio.h"
#include <sqlite3.h>
#include <sstream>
#include <iostream>

Datos_Inicio::Datos_Inicio()
{

}

Datos_Inicio& Datos_Inicio::operator = (const Datos_Inicio &i ){
    if(&i != this ){
        _Usuario = i._Usuario;
       _Contrasena = i._Contrasena;

    }
}

