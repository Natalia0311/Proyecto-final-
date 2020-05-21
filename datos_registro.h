#ifndef DATOS_REGISTRO_H
#define DATOS_REGISTRO_H
#include <sqlite3.h>
#include <ostream>

class Datos_Registro
{

private:
    char* _Nombre;
    char* _Apellido;
    int  _Documento;
    char*  _Fecha;
    int _Edad;


public:
    Datos_Registro();

    Datos_Registro& operator = ( const Datos_Registro &u);
    friend std::ostream& operator << (std::ostream &out, const Datos_Registro &u);

    inline void setNombre( char* Nombre) {_Nombre= Nombre;}
    inline char* getNombre() { return _Nombre;}

    inline void setApellido( char* Apellido) {_Apellido= Apellido;}
    inline char* getApellido() { return _Apellido;}

    inline void setDocumento( int Documento) {_Documento = Documento;}
    inline int  getDocumento() {return _Documento;}

    inline void setFecha (char* fecha ) {_Fecha = fecha;}
    inline char* getFecha() {return _Fecha;}

    inline void setEdad (int Edad ) {_Edad = Edad;}
    inline int getEdad() {return _Edad;}

//bool almacenarU (sqlite3 *db);
};

#endif // DATOS_REGISTRO_H



