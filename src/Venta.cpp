#include "Venta.h"
#include "Atencion.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Venta::Venta()
{
    //ctor
}

void Venta::cargarVenta(){
    cout << "Ingrese ID Empleado: ";
    cin >> _idEmpleado;
    cout << "Ingrese ID de cliente: ";
    cin >> _idCliente;
    cout << "Ingrese Forma de Pago: " << endl;
    cout << "1. Efectivo ---- 2. Debito ---- 3. Credito" << endl;
    cin >> formaPago;
}

void menuVentas(){
int opc;
    Venta reg;
    while(true){
    system("cls");
    cout << "Veterinaria Dr Chuche" << endl << endl;
    cout << "1. Nueva Venta" << endl;
    cout << "2. Buscar Venta" << endl;
    cout << "3. Listar Ventas" << endl;
    cout << "4. Modificar Venta" << endl;
    cout << "5. Eliminar Venta" << endl;
    cout << "0. Salir" << endl;
    cout << "Opc: ";
    cin >> opc;
    cout << endl << endl;
    switch(opc){
        case 1: cargarNuevaVenta();
        break;
        case 2: buscarVenta();
        break;
        case 3: menuListados();
        break;
        case 4: modificarVenta();
        break;
        case 5: borrarVenta();
        break;
        case 0: return;
        default: cout << "Ingrese una opcion valida";
        break;
    }
    }
    return;
}

void cargarNuevaVenta(){
    Atencion atn;
    Venta reg;
    int opc;
    cout << "1. Venta de producto ------- 2. Atencion Veterinaria" << endl;
    cin >> opc;
    switch(opc){
    case 1:

        reg.cargarVenta();
        reg.escribirDisco();
        return;

    case 2:

        atn.cargarAtencion();
        atn.escribirDisco();

}
}
void buscarVenta(){}
void borrarVenta(){}
void modificarVenta(){}
void menuListadosVentas(){}
