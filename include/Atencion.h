#ifndef ATENCION_H
#define ATENCION_H
#include "Fecha.h"


class Atencion
{
    public:
        Atencion();
        int getId();
        char * getDescripcion();
        float getPrecio();
        void setId(int);
        void setIdMascota(int);
        void setDescripcion(char *);
        void setPrecio(float);
        void cargarAtencion(){}
        void mostrarAtencion();
        int generarID();
        bool escribirDisco(){}
        bool escribirDisco(int);
        bool leerDisco(int);

    protected:

    private:
        int _id;
        int _idMascota;
        char _descripcion[50];
        float _precio;
        Fecha fecha;

};

#endif // ATENCION_H
