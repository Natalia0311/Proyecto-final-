#include "datos_registro.h"
#include <sqlite3.h>
#include <sstream>
#include <ostream>

Datos_Registro::Datos_Registro()
{

}



Datos_Registro& Datos_Registro::operator = (const Datos_Registro &u ){
    if(&u != this ){
        _Nombre = u._Nombre;
       _Apellido = u._Apellido;
       _Documento = u._Documento;
       _Fecha= u._Fecha;
       _Edad= u._Edad;
    }
}

