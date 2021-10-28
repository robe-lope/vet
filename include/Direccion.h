#ifndef DIRECCION_H
#define DIRECCION_H


class Direccion
{
    public:
        Direccion();
        char* getCalle(){return _calle;}
        int getAltura(){return _altura;}
        char* getCiudad(){return _ciudad;}
        void setCalle(char *);
        void setAltura(int);
        void setCiudad(char *);
        void cargarDir();
        void mostrarDir();
    protected:

    private:
        char _calle[50];
        int _altura;
        char _ciudad[50];
};


#endif // DIRECCION_H
