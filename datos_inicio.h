#ifndef DATOS_INICIO_H
#define DATOS_INICIO_H
#include <sqlite3.h>
#include <ostream>


class Datos_Inicio
{
private:
    char* _Usuario;
    char* _Contrasena;

public:
    Datos_Inicio();

    Datos_Inicio& operator = ( const Datos_Inicio &i);
    friend std::ostream& operator << (std::ostream &out, const Datos_Inicio &i );

    inline void setUsuario( char* Usuario) {_Usuario= Usuario;}
    inline char* getUsuario() { return _Usuario;}

    inline void setContrasena(char* Contrasena) {_Contrasena = Contrasena;}
    inline char* getContrasena() { return _Contrasena;}

//bool almacenar(sqlite3 *db);

};

#endif // DATOS_INICIO_H
