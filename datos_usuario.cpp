#include "datos_usuario.h"
#include <iostream>
#include <sstream>
#include "datos_registro.h"
#include "datos_paciente.h"

Datos_Usuario::Datos_Usuario()
{

}

bool Datos_Usuario::abrirB(string path){

    int rc;

    /* Open database */
    rc = sqlite3_open(path.c_str() , &_db);

    if( rc ) {
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(_db));
       return false;
    }else
        fprintf(stderr, "Opened database successfully\n");

    return true;

}


bool Datos_Usuario::almacenar( Datos_Inicio  &i){
    /* TABLE `INICIO` (
     * `Usuario` TEXT NOT NULL UNIQUE,
     * `Contrasena`TEXT NOT NULL,
     *  PRIMARY KEY (`Contrasena`))*/

    char *zErrMsg = 0;
    int rc;

    std::stringstream sql;
    /* Create SQL statement */

    sql << "INSERT INTO INICIO (Nombre, Contrasena) VALUES ('" ;

    sql << i.getUsuario() << "','" << i.getContrasena() <<"');" ;

    std::cout << sql.str() << std::endl;

    /* Execute SQL statement */

    rc = sqlite3_exec(_db, sql.str().c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
       return false;
    } else {
       //fprintf(stdout, "Records created successfully\n");
    }
    return true;
}

bool Datos_Usuario::almacenarU(Datos_Registro &u){
    /* TABLE `REGISTRO` (
     * `Nombre` TEXT NOT NULL,
     * `Apellido` TEXT NOT NULL,
     * `Documento` INTEGER NOT NULL UNIQUE,
     * `Fecha` NUMERIC NOT NULL,
     * `Edad` NUMERIC
     *  PRIMARY KEY (`Nombre`,`Documento`))*/

    char *zErrMsg = 0;
    int rc;

    std::stringstream sql;
    /* Create SQL statement */
    sql << "INSERT INTO REGISTRO (Nombre, Apellido, Documento, Fecha, Edad) VALUES ('" ;

    sql << u.getNombre() << "', '" <<  u.getApellido() << "',' " << u.getDocumento() << "',' " << u.getFecha() << "',' " << u.getEdad() << "');" ;

    std::cout << sql.str() << std::endl;

    /* Execute SQL statement */
    rc = sqlite3_exec(_db, sql.str().c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
       return false;
    } else {
       //fprintf(stdout, "Records created successfully\n");
    }
    return true;
}

bool Datos_Usuario::almacenarP(Datos_Paciente  &p){
    /* TABLE `REGISTRO_N` (
     * `Nombre` TEXT NOT NULL UNIQUE,
     * `Apellido` TEXT NOT NULL,
     * `Documento` INTEGER NOT NULL UNIQUE,
     * `Usuario` INTEGER NOT NULL,
     * `Contrasena`TEXT NOT NULL,
     * `Direccion` NUMERIC NOT NULL,
     * `Fecha_Nacimiento` NUMERIC NOT NULL,
     * `Ingresos` NUMERIC NOT NULL,
     * `Genero` TEXT NOT NULL,
     * `Raza` TEXT NOT NULL,
     *  PRIMARY KEY (`Nombre`,`Documento`))*/

    char *zErrMsg = 0;
    int rc;

    std::stringstream sql;
    /* Create SQL statement */

    sql << "INSERT INTO REGISTRO_N (Nombre, Apellido, Documento, Usuario, Contrasena, "\
           "Direccion, Fecha_Nacimiento, Ingresos, Genero, Raza) VALUES ('" ;


    sql << p.getNombre() << "', '" <<  p.getApellido() << "', '" << p.getDocumento() << "', '" << p.getUsuario() << "','" ;
    sql << p.getContrasena1() << "', '" <<  p.getDireccion() << "', '" << p.getFecha() << "', '" << p.getIngresos() << "','" ;
    sql << p.getGenero() << "' , '" << p.getRaza() <<"');" ;

     std::cout << sql.str() << std::endl;

    /* Execute SQL statement */
    rc = sqlite3_exec(_db, sql.str().c_str(), 0, 0, &zErrMsg);
    cout << rc <<endl;
    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
       return false;
    } else {
       //fprintf(stdout, "Records created successfully\n");
    }
    return true;
}



bool Datos_Usuario::cerrarB(){
    sqlite3_close( _db );
}

