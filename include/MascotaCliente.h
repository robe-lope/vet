#ifndef MASCOTACLIENTE_H
#define MASCOTACLIENTE_H


class MascotaCliente
{
    public:
        MascotaCliente();
        int getIdCliente();
        int getIdMascota();
        void setIdCliente(int);
        void setIdMascota(int);
        void cargarMascotaCliente();
        void mostrarMascotaCliente();
        int escribirDisco(int);
        int leerDisco(int);

    protected:

    private:
        int _idcliente;
        int _idmascota;
};

#endif // MASCOTACLIENTE_H
