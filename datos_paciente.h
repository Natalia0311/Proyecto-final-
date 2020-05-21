#ifndef DATOS_PACIENTE_H
#define DATOS_PACIENTE_H
#include <sqlite3.h>
#include <ostream>
#include <string>

class Datos_Paciente
{
private:
    char* _Nombre;
    char* _Apellido;
    char* _Usuario;
    char* _Contrasena1;
    char* _Genero;
    char* _Raza;
    int  _Direccion;
    int  _Ingresos;
    int  _Documento;
    char* _Fecha;

public:
    Datos_Paciente();

    Datos_Paciente& operator = ( const Datos_Paciente &p);
    friend std::ostream& operator << (std::ostream &out, const Datos_Paciente &p);

    inline void setNombre( char* Nombre) {_Nombre= Nombre;}
    inline char* getNombre() { return _Nombre;}

    inline void setApellido( char* Apellido) {_Apellido= Apellido;}
    inline char* getApellido() { return _Apellido;}

    inline void setUsuario( char* Usuario) {_Usuario= Usuario;}
    inline char* getUsuario() { return _Usuario;}

    inline void setGenero( char* Genero) {_Genero= Genero;}
    inline char* getGenero() { return _Genero;}

    inline void setRaza( char* Raza) {_Raza= Raza;}
    inline char* getRaza() { return _Raza;}

    inline void setContrasena1( char* Contrasena1) {_Contrasena1 = Contrasena1;}
    inline char* getContrasena1() {return _Contrasena1;}

    inline void setDocumento( int Documento) {_Documento= Documento;}
    inline int getDocumento() { return _Documento;}

    inline void setIngresos( int Ingresos) {_Ingresos= Ingresos;}
    inline int getIngresos() { return _Ingresos;}

    inline void setDireccion( int Direccion) {_Direccion= Direccion;}
    inline int getDireccion() { return _Direccion;}


    inline void setFecha (char* Fecha) {_Fecha= Fecha ;}
    inline char* getFecha() {return _Fecha;}

    //bool almacenarP (sqlite3 *db);
};

#endif // DATOS_PACIENTE_H



