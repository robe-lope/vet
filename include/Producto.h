#ifndef PRODUCTO_H
#define PRODUCTO_H


class Producto
{
    public:
        Producto();

    protected:

    private:
        int _id;
        float _precio;
        char nombre[50];
        int stock;
        bool estado;
};

void menuProductos();
#endif // PRODUCTO_H
