#ifndef MASCOTA_H
#define MASCOTA_H
#include <iostream>
#include <cstring>


class Mascota
{
    public:
        Mascota();
        int getId(){return _id;}
        char * getNombre() {return _nombre;}
        char * getRaza() {return _raza;}
        int getEdad() {return _edad;}
        void setId(int id) {_id = id;}
        void setNombre(char * nombre) {strcpy(_nombre, nombre);}
        void setRaza(char * raza) {strcpy(_raza, raza);}
        void setEdad(int edad) {_edad = edad;}
        void cargarMascota();
        void mostrarMascota();
        bool escribirDisco();
        bool escribirDisco(int);
        bool leerDisco(int);

    protected:

    private:
        int _id;
        char _nombre[30];
        char _raza[30];
        int _edad;
        bool estado;
};

void menuMascotas();
void cargarNueva();
void buscarMascota();
void listarMascotas();
void modificarMascota();
void bajaMascota();
#endif // MASCOTA_H
