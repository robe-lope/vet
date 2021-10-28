#include <iostream>
#include <cstdlib>
#include "Cliente.h"
#include "Empleado.h"
#include "Mascota.h"
#include "Producto.h"
#include "Venta.h"
using namespace std;

int main()
{
    int opc;
    while(true){
    system("cls");
    cout << "Veterinaria Dr Chuche" << endl << endl;
    cout << "1. Clientes" << endl;
    cout << "2. Mascotas" << endl;
    cout << "3. Productos" << endl;
    cout << "4. Empleados" << endl;
    cout << "5. Ventas" << endl;
    cout << "0. Salir" << endl;
    cout << "Opc: ";
    cin >> opc;
    switch(opc){
        case 1: menuClientes();
        break;
        case 2: menuMascotas();
        break;
        case 3: menuProductos();
        break;
        case 4: menuEmpleados();
        break;
        case 5: menuVentas();
        break;
        case 0: return 0;
        default: cout << "Ingrese una opcion valida";
        break;
    }
    }
    return 0;
}
