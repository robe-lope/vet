#include "Cliente.h"
#include "../Funciones.h"
#include "Mascota.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
Cliente::Cliente()
{
    //ctor
}

void Cliente::cargarCliente(){
    int opc;
    this->cargarPersona();
    generarID();
    cout << "Mail: " << endl;
    cin >> _mail;
    cout << "Cantidad de mascotas: " << endl;
    cin >> _cantidadMascotas;
    cout << "Desea cargar las mascotas ahora?" << endl;
    cout << "1. Cargar ahora -- 2. Cargar mas tarde" << endl;
    cin >> opc;
    if(opc == 1){
        escribirMascotasCliente(_cantidadMascotas);
    }
    else return;
}

void Cliente::mostrarCliente(){
    cout << "------ ID CLIENTE: " << this->getId() << endl;
    cout << "Apellidos: " << this->getApellidos() << endl;
    cout << "Nombres  : " << this->getNombres() << endl;
    cout << "Telefono : " << this->getTelefono() << endl;
    cout << "------ Direccion: " << endl;
    this->getDireccion();
    cout << "------ " << endl;
    cout << "Estado   : " << this->getEstado() << endl;
    cout << "Mail     : " << _mail << endl;
    cout << "Mascotas : " << _cantidadMascotas << endl;
    cout << "____________________________________" << endl << endl;
}

bool Cliente::leerDisco(int pos){
    FILE *p;
    p = fopen("clientes.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;
    fseek(p, sizeof(Cliente) * pos , 0);
    ok = fread(this, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

bool Cliente::escribirDisco(){
    FILE *p;
    p = fopen("clientes.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fwrite(this, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

bool Cliente::escribirDisco(int pos){
    FILE *p;
    p = fopen("clientes.dat", "rb+");
    if (p == NULL){
        return false;
    }
    bool ok;
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    ok = fwrite(this, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}



int Cliente::generarID(){
    int id = cantidadRegistros(1);
    system("pause");
    if(id==0){
        this->setId(1);
    }
    else if(id==ultimoID(1)){
        this->setId(id+1);
    }
    else this->setId(id);
}

void menuClientes(){
    int opc;
    Cliente cli;
    while(true){
    system("cls");
    cout << "Veterinaria Dr Chuche" << endl << endl;
    cout << "1. Nuevo Cliente" << endl;
    cout << "2. Buscar Cliente" << endl;
    cout << "3. Listar Clientes" << endl;
    cout << "4. Modificar Cliente" << endl;
    cout << "5. Eliminar Cliente" << endl;
    cout << "0. Salir" << endl;
    cout << "Opc: ";
    cin >> opc;
    cout << endl << endl;
    switch(opc){
        case 1: cargarNuevo();
        break;
        case 2: buscarCliente();
        break;
        case 3: menuListados();
        break;
        case 4: modificarCliente();
        break;
        case 5: bajaCliente();
        break;
        case 0: return;
        default: cout << "Ingrese una opcion valida";
        break;
    }
    }
    return;
}

void cargarNuevo(){
    Cliente cli;
    cli.cargarCliente();
    cli.escribirDisco();
}



void buscarCliente(){
    int cant = cantidadRegistros(1);
    int idBuscado;
    bool found = false;

    //Pido memoria
    Cliente *reg;
    reg = new Cliente[cant];

    //Leo el archivo
    for(int i=0; i<cant; i++){
        reg[i].leerDisco(i);
    }
    cout << "Ingrese ID de cliente: ";
    cin >> idBuscado;
    for(int i=0; i<cant; i++){
        if(reg[i].getId()==idBuscado){
            reg[i].mostrarCliente();
            found = true;
            system("pause");
        }
    }
    if(found==false) cout <<"ID no encontrado en registro de clientes..." << endl;
    system("pause");

}
void bajaCliente(){
    int cant = cantidadRegistros(1);
    int idBuscado, pos=0, opc=0;
    bool found = false;

    //Pido memoria
    Cliente *reg;
    reg = new Cliente[cant];

    //Leo el archivo
    for(int i=0; i<cant; i++){
        reg[i].leerDisco(i);
    }
    cout << "Ingrese ID de cliente: ";
    cin >> idBuscado;
    for(int i=0; i<cant; i++){
        if(reg[i].getId()==idBuscado){
            pos = i;
            found = true;
        }
    }
    if(found==false) {
            cout <<"ID no encontrado en registro de clientes..." << endl;
            return;
    }
    cout << "Esta seguro que desea dar de baja el siguiente cliente?" << endl;
    reg[pos].mostrarCliente();
    cout << "1. Eliminar -- 2. Volver" << endl;
    cin >> opc;
    switch(opc){
    case 1:
        reg[pos].setEstado(0);
        reg[pos].escribirDisco(pos);
        system("pause");
        return;
    case 2:
        return;
    }

    system("pause");
}
void modificarCliente(){
    int cant = cantidadRegistros(1);
    int idBuscado, opc, pos, nuevaCant;
    char nuevoDato[50];
    bool found = false;

    //Pido memoria
    Cliente *reg;
    reg = new Cliente[cant];

    //Leo el archivo
    for(int i=0; i<cant; i++){
        reg[i].leerDisco(i);
    }
    cout << "Ingrese ID de cliente: ";
    cin >> idBuscado;
    for(int i=0; i<cant; i++){
        if(reg[i].getId()==idBuscado){
            reg[i].mostrarCliente();
            pos = i;
            found = true;
            system("pause");
        }
    }
    if(found==false){
            cout <<"ID no encontrado en registro de clientes..." << endl;
            return;
            }
    cout << "Ingrese campo que desea modificar: " << endl;
    cout << "1. Apellido" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Cantidad de mascotas" << endl;
    cin >> opc;
    cout << endl << endl;
    switch (opc){
    case 1:
        cout << "Ingrese nuevo apellido: ";
        cin >> nuevoDato;
        reg[pos].setApellidos(nuevoDato);
        cout << "El registro quedo de la siguiente manera..." << endl;
        reg[pos].mostrarCliente();
        reg[pos].escribirDisco(pos);
        system("pause");
        return;
    case 2:
        cout << "Ingrese nuevo nombre: ";
        cin >> nuevoDato;
        reg[pos].setNombres(nuevoDato);
        cout << "El registro quedo de la siguiente manera..." << endl;
        reg[pos].mostrarCliente();
        reg[pos].escribirDisco(pos);
        system("pause");
        return;
    case 3:
        cout << "Ingrese nueva cantidad de mascotas: ";
        cin >> nuevaCant;
        reg[pos].setCantidadMascotas(nuevaCant);
        cout << "El registro quedo de la siguiente manera..." << endl;
        reg[pos].mostrarCliente();
        reg[pos].escribirDisco();
        system("pause");
        return;
    }

}
void menuListados(){
    int opc, pos=0, cant=0, i=0, j=0;
    Cliente cli;
    Cliente *reg;
    cant = cantidadRegistros(1);
    //Pido memoria

    reg = new Cliente[cant];

    //Leo el archivo y lo cargo en el vector
    for(i=0; i<cant; i++){
        reg[i].leerDisco(i);
    }
    while(true){
    system("cls");
    cout << "Veterinaria Dr Chuche" << endl << endl;
    cout << "1. Listar todos los clientes activos" << endl;
    cout << "2. Listar clientes por cantidad de mascotas" << endl;
    cout << "3. Listar clientes dados de baja " << endl;
    cout << "4. " << endl;
    cout << "5. " << endl;
    cout << "0. Salir" << endl;
    cin >> opc;
    switch(opc){
case 1:
    for(i=0; i<cant; i++){
        if(reg[i].getEstado()!=0){
            reg[i].mostrarCliente();
        }
    }
    system("pause");
    return;
case 2:
    //Ordeno por cantidad de mascotas
    for(i=0; i<cant; i++){
        pos=i;
        for(j=i+1; j<cant; j++){
            if(reg[j].getCantidadMascotas()>reg[pos].getCantidadMascotas()){
                pos=j;
            }
        }
        cli = reg[i];
        reg[i]=reg[pos];
        reg[pos]=cli;
    }
    for(i=0; i<cant; i++){
        reg[i].mostrarCliente();
    }
    system("pause");
    return;
case 3:
    for(i=0; i<cant; i++){
        if(reg[i].getEstado()==0){
            reg[i].mostrarCliente();
        }
    }
    }

    system("pause");
}
}

Cliente cargarVectorCli(){

    int cant = cantidadRegistros(1);
    //Pido memoria
    Cliente *reg;
    reg = new Cliente[cant];

    //Leo el archivo
    for(int i=0; i<cant; i++){
        reg[i].leerDisco(i);
    }

}
/*
    int cant = cantidadClientes();
    //Pido memoria
    Cliente *reg;
    reg = new Cliente[cant];

    //Leo el archivo
    for(int i=0; i<cant; i++){
        reg[i].leerDisco(i);
    }
*/

