#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
    public:
        Matriz();
        virtual ~Matriz();
        int **crear();
        int llenar();
        void imprimir();
        bool checar();
    protected:
        int r, c, **mat;
    private:
};

#endif // MATRIZ_H
