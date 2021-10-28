#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"

class Venta
{
    public:
        Venta();
        int getId();
        Fecha getFecha();
        int getIdCliente();
        int getIdEmpleado();
        int getIdMascota();
        int getFormaPago();
        void setId(int);
        void setFecha(Fecha);
        void setIdCliente(int);
        void setIdEmpleado(int);
        void setIdMascota(int);
        void setFormaPago(int);
        void cargarVenta();
        void mostrarVenta();
        int generarID();
        bool escribirDisco(){}
        bool escribirDisco(int);
        bool leerDisco(int);
    protected:

    private:
        int _id;
        Fecha fecha;
        int _idCliente, _idEmpleado, idMascota;
        int formaPago;
        bool estado;
};



void menuVentas();
void cargarNuevaVenta();
void buscarVenta();
void borrarVenta();
void modificarVenta();
void menuListados();
#endif // VENTA_H
