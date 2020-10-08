#include "Matriz.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
Matriz::Matriz()
{
    r = 6;
    c = 6;
    mat = new int *[r];
    for(int i = 0; i < r; i++){
        mat[i] = new int [c];
    }
}

Matriz::~Matriz()
{
    r = 0;
    c = 0;
}

int Matriz::llenar(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            mat[i][j] = 1 + rand()%(8-1+1);
        }
    }
}
void Matriz::imprimir(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
