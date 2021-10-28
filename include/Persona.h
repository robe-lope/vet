#ifndef PERSONA_H
#define PERSONA_H
#include <cstring>
#include "Direccion.h"

class Persona
{
    public:
        Persona();

        char * getApellidos(){return _apellidos;}
        char * getNombres(){return _nombres;}
        char * getTelefono(){return _telefono;}
        bool getEstado(){return estado;}
        Direccion getDireccion();

        void setApellidos(char*a){strcpy(_apellidos, a);}
        void setNombres(char*n){strcpy(_nombres, n);}
        void setTelefono(char*);
        void setEstado(bool s){estado=s;}
        void setDireccion(Direccion);
        void cargarPersona();
        void mostrarPersona();
        int escribirDisco(int);
        int leerDisco(int);

    protected:

    private:
        bool estado;
        char _nombres[50];
        char _apellidos[50];
        char _telefono[20];
        Direccion _direccion;

};

#endif // PERSONA_H
