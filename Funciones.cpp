#include "Funciones.h"
#include "Cliente.h"
#include "Mascota.h"
#include "DetalleVenta.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int escribirMascotasCliente(int _cantidadMascotas){
        Mascota *pet;
        pet = new Mascota[_cantidadMascotas];
        for(int i=0; i<_cantidadMascotas; i++){
            pet[i].cargarMascota();
            pet[i].escribirDisco();
        }
}

int cargarDetalleVenta(int idEmpleado, int idCliente, int formaPago){
    DetalleVenta reg;
}

int cantidadRegistros(int tipo){
    int bytes, cant;
    FILE *p;
    switch (tipo){
    case 1:

        p = fopen("clientes.dat", "rb");
        if (p == NULL){
            return 0;
        }
        fseek(p, 0, SEEK_END);
        bytes = ftell(p);
        fclose(p);
        cant = bytes / sizeof(Cliente);
        return cant;
    case 2:
        p = fopen("mascotas.dat", "rb");
        if (p==NULL){
            return 0;
        }
        fseek(p, 0, SEEK_END);
        bytes = ftell(p);
        cant = bytes / sizeof(Mascota);
        return cant;
}
}

int ultimoID(int tipo){
    int ultimo, cant;
    Mascota pet;
    Cliente cli;
    switch(tipo){
    case 1:

        cant = cantidadRegistros(1);
        if (cant==0) return 0;
        cli.leerDisco(cant-1);
        ultimo = cli.getId();
            return ultimo;
            break;
    case 2:

        cant = cantidadRegistros(2);
        if (cant==0) return 0;
        pet.leerDisco(cant-1);
        ultimo = pet.getId();
            return ultimo;
    }
}
