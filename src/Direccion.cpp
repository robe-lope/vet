#include <iostream>
#include <cstdlib>
using namespace std;
#include "Direccion.h"

Direccion::Direccion()
{
    //ctor
}

void Direccion::cargarDir(){
    cout << "Ciudad: " << endl;
    cin >> _ciudad;
    cout << "Calle: " << endl;
    cin >> _calle;
    cout << "Altura: " << endl;
    cin >> _altura;
}

void Direccion::mostrarDir(){
    cout << "Ciudad   : " << _ciudad << endl;
    cout << "Calle    : " << _calle << endl;
    cout << "Altura   : " << _altura << endl;
}
