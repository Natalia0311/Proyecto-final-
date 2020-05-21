#ifndef DATOS_USUARIO_H
#define DATOS_USUARIO_H
#include <string>
#include <sqlite3.h>
#include "datos_inicio.h"
#include "datos_registro.h"
#include "datos_paciente.h"

using namespace std;


class Datos_Usuario
{
private:
    sqlite3 *_db;



public:
    Datos_Usuario();
    bool abrirB(string path);
    bool almacenar(Datos_Inicio  &i);
    bool almacenarU(Datos_Registro &u);
    bool almacenarP(Datos_Paciente &p);
    bool cerrarB();

};

#endif // DATOS_USUARIO_H
