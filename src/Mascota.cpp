#include "Mascota.h"
#include "../Funciones.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
Mascota::Mascota()
{
    //ctor
}

void Mascota::cargarMascota(){
    cout << "Nombre: " << endl;
    cin >> _nombre;
    cout << "Raza: " << endl;
    cin >> _raza;
    cout << "Edad: " << endl;
    cin >> _edad;

}

void Mascota::mostrarMascota(){
    cout << "ID MASCOTA: " << this->getId() << endl;
    cout << "Nombre   : " << this->getNombre() << endl;
    cout << "Raza: " << this->getRaza() << endl;
    cout << "Edad: " << this->getEdad() << endl;
}

bool Mascota::leerDisco(int pos){
    FILE *p;
    p = fopen("mascotas.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;
    fseek(p, sizeof(Mascota) * pos , 0);
    ok = fread(this, sizeof(Mascota), 1, p);
    fclose(p);
    return ok;
}

bool Mascota::escribirDisco(){
    FILE *p;
    p = fopen("mascotas.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fwrite(this, sizeof(Mascota), 1, p);
    fclose(p);
    return ok;
}

bool Mascota::escribirDisco(int pos){
    FILE *p;
    p = fopen("mascotas.dat", "rb+");
    if (p == NULL){
        return false;
    }
    bool ok;
    fseek(p, pos * sizeof(Mascota), SEEK_SET);
    ok = fwrite(this, sizeof(Mascota), 1, p);
    fclose(p);
    return ok;
}

void cargarNueva(){}
void buscarMascota(){}
void listarMascotas(){
    Mascota pet;
    int pos=0;
    while (pet.leerDisco(pos++)){
        pet.mostrarMascota();
        system("pause");
    }
}
void modificarMascota(){}
void bajaMascota(){}

void menuMascotas(){
    int opc;
    Mascota pet;
    while(true){
    system("cls");
    cout << "Veterinaria Dr Chuche" << endl << endl;
    cout << "1. Nueva Mascota" << endl;
    cout << "2. Buscar Mascota" << endl;
    cout << "3. Listar Mascotas" << endl;
    cout << "4. Modificar Mascota" << endl;
    cout << "5. Eliminar Mascota" << endl;
    cout << "0. Salir" << endl;
    cout << "Opc: ";
    cin >> opc;
    switch(opc){
        case 1: cargarNueva();
        break;
        case 2: buscarMascota();
        break;
        case 3: listarMascotas();
        break;
        case 4: modificarMascota();
        break;
        case 5: bajaMascota();
        break;
        case 0: return;
        default: cout << "Ingrese una opcion valida";
        break;
    }
    }
    return;
}


