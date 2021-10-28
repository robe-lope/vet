#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <Persona.h>
#include "Fecha.h"

class Empleado : public Persona
{
    public:
        Empleado();
        float getSueldo();
        char* getCategoria();
        Fecha getIngreso();
        void setSueldo(float);
        void setCategoria(char*);
        void setIngreso(Fecha);
        void cargarEmpleado();
        void mostrarEmpleado();
        int generarID();
        bool escribirDisco();
        bool escribirDisco(int);
        bool leerDisco(int);

    protected:

    private:
        float _sueldo;
        char _categoria[30];
        Fecha _ingreso;
};


void menuEmpleados();
#endif // EMPLEADO_H
