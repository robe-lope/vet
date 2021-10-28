#include <iostream>
#include <cstdlib>
using namespace std;
#include "Persona.h"

Persona::Persona()
{
    //ctor
}
Direccion Persona::getDireccion(){
    cout <<"Ciudad   : " << _direccion.getCiudad() << endl;
    cout <<"Calle    : " <<_direccion.getCalle() << endl;
    cout <<"Altura   : " << _direccion.getAltura() << endl;
}

void Persona::cargarPersona(){
    cout << "Apellidos: " << endl;
    cin >> _apellidos;
    cout << "Nombres: " << endl;
    cin >> _nombres;
    cout << "Telefono: " << endl;
    cin >> _telefono;
    cout << "Direccion: " << endl;
    _direccion.cargarDir();
    estado = 1;

}
