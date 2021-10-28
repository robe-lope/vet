#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H

#include "Fecha.h"


class DetalleVenta
{
    public:
        DetalleVenta();
        int getIdVenta();
        int getIdProducto();
        int getIdAtencion();
        int getCantidad();
        Fecha getFecha();
        float getPrecio();
        void setIdVenta(int idV){_idVenta=idV;}
        void setIdProducto(int idP){_idProducto=idP;}
        void setIdAtencion(int idA){_idAtencion=idA;}
        void setCantidad(int cant){_cantidad=cant;}
        void setFecha(Fecha F);
        void setPrecio(float p);

    protected:

    private:
        int _idVenta, _idProducto, _cantidad, _idAtencion;
        Fecha fecha;
        float _precio;
};

#endif // DETALLEVENTA_H
