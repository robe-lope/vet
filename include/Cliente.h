#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <Persona.h>


class Cliente : public Persona
{
    public:
        Cliente();
        char* getMail();
        int getCantidadMascotas(){return _cantidadMascotas;}
        int getId(){return _id;}
        void setId(int id) {_id = id;}
        void setMail(char*);
        void setCantidadMascotas(int cant){_cantidadMascotas = cant;}
        void cargarCliente();
        void mostrarCliente();
        int generarID();
        bool escribirDisco();
        bool escribirDisco(int);
        bool leerDisco(int);

    protected:

    private:
        int _id;
        char _mail[30];
        int _cantidadMascotas;
};


void menuClientes();
void cargarNuevo();
void buscarCliente();
void bajaCliente();
void modificarCliente();
void menuListados();
#endif // CLIENTE_H
