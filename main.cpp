#include <allegro.h>
#include <winalleg.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

volatile int segundos=0;
volatile int minutos=0;

BITMAP *buffer;
BITMAP *menu;
BITMAP *menu4;
BITMAP *menu11;
BITMAP *menu12;
BITMAP *menu13;
BITMAP *menu21;
BITMAP *menu22;
BITMAP *menu23;
BITMAP *menu31;
BITMAP *menu32;
BITMAP *menu33;
BITMAP *cursor;
BITMAP *instrucciones;
BITMAP * AzulClaro;
BITMAP * Amarillo;
BITMAP * RosaPalo;
BITMAP * Fiusha;
BITMAP * Naranja;
BITMAP * Rojo;
BITMAP * Verde;
BITMAP * Tinto;
BITMAP * CandadoAzulClaro;
BITMAP * CandadoAmarillo;
BITMAP * CandadoRosaPalo;
BITMAP * CandadoFiusha;
BITMAP * CandadoNaranja;
BITMAP * CandadoRojo;
BITMAP * CandadoVerde;
BITMAP * CandadoTinto;
BITMAP * Tablero_1;
BITMAP * Tablero_11;
BITMAP * Tablero_12;
BITMAP * Tablero_13;
BITMAP * Tablero_14;
BITMAP * Tablero_15;
BITMAP * Tablero_16;
BITMAP * Tablero_2;
BITMAP * Tablero_21;
BITMAP * Tablero_22;
BITMAP * Tablero_23;
BITMAP * Tablero_24;
BITMAP * Tablero_25;
BITMAP * Tablero_26;
BITMAP * Tablero_3;
BITMAP * Tablero_31;
BITMAP * Tablero_32;
BITMAP * Tablero_33;
BITMAP * Tablero_34;
BITMAP * Tablero_35;
BITMAP * Tablero_36;
BITMAP * Selector;
BITMAP * Perfil;
BITMAP * Ganar;
BITMAP * Perder;


class TableroPrincipal{
    protected:
        int **tablero;
        int n;
        int i, j, moviendo, lado, puntos, cambiar;
        int modo;
    public:
        TableroPrincipal(int **, int, int);
        virtual void llenarTablero(int **, int);
        virtual void imprimirTablero(int **);
        virtual void mover_peluche(int **, int &, int &, int &, int &, int, int &, int &, int);
        void cambiar_peluche(int **, int , int , int );
        virtual void eliminar_peluche(int **, int, int &, int);
        virtual void dibujar_tablero1(int, int);
        virtual void llenar_candado(int **, int);
};

class Tablero1 : public TableroPrincipal{
    public:
        Tablero1(int **, int, int);
        void llenarTablero(int **, int);
        void imprimirTablero(int **);
        void mover_peluche(int **, int &, int &, int &, int &, int, int &, int &, int);
        void eliminar_peluche(int **, int, int &, int);
        void dibujar_tablero1(int, int);
        void llenar_candado(int **, int);
};

TableroPrincipal::TableroPrincipal(int **tablero, int n, int modo)
{
    tablero=tablero;
    n=n;
    modo=modo;

}
void TableroPrincipal::dibujar_tablero1(int puntos, int modo)
{
    if(modo==1 || modo==4 || modo==7)
    {
        if(puntos<50)
        {
            draw_sprite(buffer, Tablero_1, 0, 0);
        }else if(puntos<100)
        {
            draw_sprite(buffer, Tablero_11, 0, 0);
        }else if(puntos<150)
        {
            draw_sprite(buffer, Tablero_12, 0, 0);
        }else if(puntos<200)
        {
            draw_sprite(buffer, Tablero_13, 0, 0);
        }else if(puntos<250)
        {
            draw_sprite(buffer, Tablero_14, 0, 0);
        }else if(puntos<350)
        {
            draw_sprite(buffer, Tablero_15, 0, 0);
        }else if(puntos>=350)
        {
            draw_sprite(buffer, Tablero_16, 0, 0);
            cout<<"\n\n\Ya ganaste xD\n\n";
        }
    }
    if(modo==2 || modo==5 || modo==8)
    {
        if(puntos<50)
        {
            draw_sprite(buffer, Tablero_2, 0, 0);
        }else if(puntos<150)
        {
            draw_sprite(buffer, Tablero_21, 0, 0);
        }else if(puntos<200)
        {
            draw_sprite(buffer, Tablero_22, 0, 0);
        }else if(puntos<300)
        {
            draw_sprite(buffer, Tablero_23, 0, 0);
        }else if(puntos<375)
        {
            draw_sprite(buffer, Tablero_24, 0, 0);
        }else if(puntos<550)
        {
            draw_sprite(buffer, Tablero_25, 0, 0);
        }else if(puntos>=550)
        {
            draw_sprite(buffer, Tablero_26, 0, 0);
            cout<<"\n\n\Ya ganaste xD\n\n";
        }
    }
    if(modo==3 || modo==6 || modo==9)
    {
        if(puntos<50)
        {
            draw_sprite(buffer, Tablero_3, 0, 0);
        }else if(puntos<150)
        {
            draw_sprite(buffer, Tablero_31, 0, 0);
        }else if(puntos<300)
        {
            draw_sprite(buffer, Tablero_32, 0, 0);
        }else if(puntos<450)
        {
            draw_sprite(buffer, Tablero_33, 0, 0);
        }else if(puntos<600)
        {
            draw_sprite(buffer, Tablero_34, 0, 0);
        }else if(puntos<750)
        {
            draw_sprite(buffer, Tablero_35, 0, 0);
        }else if(puntos>=750)
        {
            draw_sprite(buffer, Tablero_36, 0, 0);
            cout<<"\n\n\Ya ganaste xD\n\n";
        }
    }
}
void TableroPrincipal::llenarTablero(int **tablero, int n){
    int i,j;
    /*
    1=Azul 2=Amarillo 3=Rosa 4=Fiusha 5=Naranja 6=Rojo 7=Verde 8=Tinto
    */
    for(i=0; i<6; i++)
        for(j=0; j<6; j++)
        {
            tablero[i][j]= 1 + rand()%((n+1)-1);
            //tablero[i][j]=30;
        }
}

void TableroPrincipal::llenar_candado(int **tablero, int modo)
{
    int candado, iguales=0, candado2, candado3;
        candado = rand()%(7-1);
        do{
            iguales=0;
             candado2 = rand()%(7-1);
             if(candado2==candado)
                iguales=1;
        }while(iguales==1);
        do{
             iguales=0;
             candado3 = rand()%(7-1);
             if(candado3==candado)
                iguales=1;
            if(candado3==candado2)
                iguales=1;
        }while(iguales==1);

        if(modo==7 || modo==8 || modo==9)
        {
            tablero[candado][candado] = 11+rand()%(18-11+1);
            if(modo==8 || modo==9)
                tablero[candado2][candado2] = 11+rand()%(18-11+1);
            if(modo==9)
                tablero[candado3][candado3] = 11+rand()%(18-11+1);
        }
}
void TableroPrincipal::imprimirTablero(int **tablero)
{
    int i, j, ren, col;
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {

            if(tablero[i][j]==1)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, AzulClaro, col, ren);
            }
            if(tablero[i][j]==2)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, Amarillo, col, ren);
            }
            if(tablero[i][j]==3)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, RosaPalo, col, ren);
            }
            if(tablero[i][j]==4)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, Fiusha, col, ren);
            }
            if(tablero[i][j]==5)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, Naranja, col, ren);
            }
            if(tablero[i][j]==6)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, Rojo, col, ren);
            }
           if(tablero[i][j]==7)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, Verde, col, ren);
            }
            if(tablero[i][j]==8)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, Tinto, col, ren);
            }
            if(tablero[i][j]==11)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, CandadoAzulClaro, col, ren);
            }
            if(tablero[i][j]==12)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, CandadoAmarillo, col, ren);
            }
            if(tablero[i][j]==13)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, CandadoRosaPalo, col, ren);
            }
            if(tablero[i][j]==14)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, CandadoFiusha, col, ren);
            }
            if(tablero[i][j]==15)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, CandadoNaranja, col, ren);
            }
            if(tablero[i][j]==16)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, CandadoRojo, col, ren);
            }
           if(tablero[i][j]==17)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, CandadoVerde, col, ren);
            }
            if(tablero[i][j]==18)
            {
                ren=i*70;
                col=j*70;
                draw_sprite(buffer, CandadoTinto, col, ren);
            }
        }
    }
}
void TableroPrincipal::mover_peluche(int **tablero, int &i, int &j, int &moviendo, int &lado, int n, int &puntos, int &cambiar, int modo)
{
    int mover;
    int k, no_mover=0;
    draw_sprite(buffer, Selector, j*70, i*70);
    blit(buffer, screen,0,0,237,82,420,420);
    if(modo==4 || modo==5 || modo==6)
    {
        int decseg, uniseg;
        decseg = segundos/10;
        uniseg = segundos%10;
        textprintf(screen, font, 90, 135, palette_color[7], "%d:%d%d", minutos, decseg, uniseg);
    }
    textprintf(screen, font, 90, 145, palette_color[9], "%d", puntos);
    readkey();
    if(key[KEY_UP] && moviendo!=1)
    {
        if(i==0)
            i=0;
        else
            i--;
    }
    if(key[KEY_DOWN] && moviendo!=1)
    {
        if(i==5)
            i=5;
        else
            i++;
    }
    if(key[KEY_RIGHT] && moviendo!=1)
    {
        if(j==5)
            j=5;
        else
            j++;
    }
    if(key[KEY_LEFT] && moviendo!=1)
    {
        if(j==0)
            j=0;
        else
            j--;
    }
    if(key[KEY_I] && (lado==1 || lado==0))
    {
        lado=1;
        //Arriba
        mover=1;
        moviendo=1;
        for(k=0; k<6; k++)
            if(tablero[k][j]==11 || tablero[k][j]==12 || tablero[k][j]==13 || tablero[k][j]==14 || tablero[k][j]==15 || tablero[k][j]==16)
            {
                no_mover=1;
                moviendo=0;
                lado=0;
            }
    }
    if(key[KEY_K] && (lado==1 || lado==0))
    {
        lado=1;
        //Abajo
        mover=2;
        moviendo=1;
        for(k=0; k<6; k++)
            if(tablero[k][j]==11 || tablero[k][j]==12 || tablero[k][j]==13 || tablero[k][j]==14 || tablero[k][j]==15 || tablero[k][j]==16)
            {
                no_mover=1;
                moviendo=0;
                lado=0;
            }
    }
    if(key[KEY_L] && (lado==2 || lado==0))
    {
        lado=2;
        //Derecha
        mover=3;
        moviendo=1;
        for(k=0; k<6; k++)
            if(tablero[i][k]==11 || tablero[i][k]==12 || tablero[i][k]==13 || tablero[i][k]==14 || tablero[i][k]==15 || tablero[i][k]==16)
            {
                no_mover=1;
                moviendo=0;
                lado=0;
            }
    }
    if(key[KEY_J] && (lado==2 || lado==0))
    {
        lado=2;
        //Izquierda
        mover=4;
        moviendo=1;
        for(k=0; k<6; k++)
            if(tablero[i][k]==11 || tablero[i][k]==12 || tablero[i][k]==13 || tablero[i][k]==14 || tablero[i][k]==15 || tablero[i][k]==16)
            {
                no_mover=1;
                moviendo=0;
                lado=0;
            }
    }
    if(key[KEY_ENTER])
    {
        moviendo=0;
        lado=0;
        eliminar_peluche(tablero, n, puntos, modo);
    }
    if(no_mover==0)
        cambiar_peluche(tablero, mover, i, j);
    clear_keybuf();
}
void TableroPrincipal::cambiar_peluche(int **tablero, int mover, int fil, int col)
{
    int i, j, aux[6][6];
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            aux[i][j]=tablero[i][j];
        }
    }
    if(mover==1)
    {
        aux[5][col]=tablero[0][col];
        for(i=0; i<5; i++)
        {
            aux[i][col]=tablero[i+1][col];
        }
    }
    if(mover==2)
    {
        aux[0][col]=tablero[5][col];
        for(i=1; i<6; i++)
        {
            aux[i][col]=tablero[i-1][col];
        }
    }
    if(mover==3)
    {
        aux[fil][0]=tablero[fil][5];
        for(i=1; i<6; i++)
        {
            aux[fil][i]=tablero[fil][i-1];
        }
    }
    if(mover==4)
    {
        aux[fil][5]=tablero[fil][0];
        for(i=0; i<5; i++)
        {
            aux[fil][i]=tablero[fil][i+1];
        }
    }
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            tablero[i][j]=aux[i][j];
        }
    }
}
void TableroPrincipal::eliminar_peluche(int **tablero, int n, int &puntos, int modo)
{
    int f, c, color, aux[6][6], i1, j1, cont, salir, contvec=0, buscar;
    int derecha=0, izquierda=0, arriba=0, abajo=0;
    int aux_i=100, aux_j=100, k, t;
    int vectorj[36], vectori[36], ceros, k_aux, mover_aux,salir_acomodar, aux_1, cont_aux=0;
    int v[6], destruyo=0, colores=0, explotar=0;

    for(f=0; f<6; f++)
        for(c=0; c<6; c++)
            aux[f][c]=0;
    for(f=0; f<36; f++)
    {
        vectori[f]=0;
        vectorj[f]=0;
    }

    for(f=0; f<6; f++)
    {
        for(c=0; c<6; c++)
        {
            if(destruyo==1)
            {
                c=0;
                f=0;
            }
            color = tablero[f][c];
            i1=f;
            j1=c;
            salir=0;
            cont=0;
            aux_i=100; aux_j=100;
            contvec=0;
            vectori[contvec]=f;
            vectorj[contvec]=c;
            buscar=0;
            ceros=0;

            if(aux[f][c]==0)
                buscar=1;
            if(buscar==1)
            {
                aux[f][c]=4;
                do{
                    derecha=0; izquierda=0; arriba=0; abajo=0;
                    if(j1+1<6) //Derecha
                    {
                        if((tablero[i1][j1+1]==color+10 || tablero[i1][j1+1]==color) && aux[i1][j1+1]==0)
                        {
                            contvec++;
                            //if(j1<5)
                            //{
                                j1++;
                                aux[i1][j1]=4;
                            //}
                            if(j1==5)
                            {
                                derecha=1;
                            }
                            vectori[contvec]=i1;
                            vectorj[contvec]=j1;
                        }else if(tablero[i1][j1+1]!=color+10 && tablero[i1][j1+1]!=color && aux[i1][j1+1]==0)
                        {
                            aux[i1][j1+1]=3;
                            derecha=1;
                        }
                        else{
                            derecha=1;
                        }
                    }else{
                            derecha=1;
                    }
                    if(derecha==1) //Abajo
                    {
                        if(i1+1<6)
                        {
                            if((tablero[i1+1][j1]==color+10 || tablero[i1+1][j1]==color) && aux[i1+1][j1]==0)
                            {
                                contvec++;
                                if(i1<5)
                                {
                                    i1++;
                                    aux[i1][j1]=4;
                                }
                                vectori[contvec]=i1;
                                vectorj[contvec]=j1;
                                if(i1==5)
                                {
                                    abajo=1;
                                }
                            }else if(tablero[i1+1][j1]!=color+10 && tablero[i1+1][j1]!=color && aux[i1+1][j1]==0)
                            {
                                aux[i1+1][j1]=3;
                                abajo=1;
                            }
                            else{
                                abajo=1;
                            }
                        }else{
                            abajo=1;
                        }
                    }
                    if(abajo==1) //Izquierda
                    {
                        if(j1-1>=0)
                        {
                            if((tablero[i1][j1-1]==color+10 || tablero[i1][j1-1]==color) && aux[i1][j1-1]==0)
                            {
                                contvec++;
                                if(j1>0)
                                {
                                    j1--;
                                    aux[i1][j1]=4;
                                }
                                vectori[contvec]=i1;
                                vectorj[contvec]=j1;
                                if(j1==0)
                                {
                                    izquierda=1;
                                }
                            }else if(tablero[i1][j1-1]!=color+10 && tablero[i1][j1-1]!=color && aux[i1][j1-1]==0)
                            {
                                aux[i1][j1-1]=3;
                                izquierda=1;
                            }
                            else{
                                izquierda=1;
                            }
                        }else{
                            izquierda=1;
                        }
                    }
                    if(izquierda==1) //Izquierda
                    {
                        if(i1-1>=0)
                        {
                            if((tablero[i1-1][j1]==color+10 || tablero[i1-1][j1]==color) && aux[i1-1][j1]==0)
                            {
                                contvec++;
                                if(j1>0)
                                {
                                    i1--;
                                    aux[i1][j1]=4;
                                }
                                vectori[contvec]=i1;
                                vectorj[contvec]=j1;
                                if(i1==0)
                                {
                                    arriba=1;
                                }
                            }else if(tablero[i1-1][j1]!=color+10 && tablero[i1-1][j1]!=color && aux[i1-1][j1]==0)
                            {
                                aux[i1-1][j1]=3;
                                arriba=1;
                            }else{
                                arriba=1;
                            }
                        }else{
                            arriba=1;
                        }
                    }
                    if(i1==aux_i && j1==aux_j && contvec!=0)
                    {
                        contvec--;
                        i1=vectori[contvec];
                        j1=vectorj[contvec];
                    }
                    if(contvec==0 && aux[f][c]!=0)
                    {
                        if(f==0 && c==0)
                        {
                            if(aux[f][c+1]!=0 && aux[f+1][c]!=0)
                                salir=1;
                        }
                        if(f==5 && c==5)
                        {
                            if(aux[f-1][c]!=0 && aux[f][c-1]!=0)
                                salir=1;
                        }
                        if(f!=0 && c!=0 && f!=5 && c!=5)
                        {
                            if(aux[f][c+1]!=0 && aux[f][c-1]!=0 && aux[f+1][c]!=0 && aux[f-1][c]!=0)
                                salir=1;
                        }
                        if(f==0 && c!=0 && c!=5)
                        {
                            if(aux[f][c+1]!=0 && aux[f][c-1]!=0 && aux[f+1][c]!=0)
                                salir=1;
                        }
                        if(f==5 && c!=0 && c!=5)
                        {
                            if(aux[f][c+1]!=0 && aux[f][c-1]!=0 && aux[f-1][c]!=0)
                                salir=1;
                        }
                        if(f==0 && c==5)
                        {
                            if(aux[f][c-1]!=0 && aux[f+1][c]!=0)
                                salir=1;
                        }
                        if(f!=5 && f!=0 && c==0)
                        {
                            if(aux[f][c+1]!=0 && aux[f-1][c]!=0 && aux[f+1][c]!=0)
                                salir=1;
                        }
                        if(f==5 && c==0)
                        {
                            if(aux[f][c+1]!=0 && aux[f-1][c]!=0)
                                salir=1;
                        }
                        if(c==5 && f!=0 && f!=5)
                        {
                            if(aux[f-1][c]!=0 && aux[f][c]!=0 && aux[f][c-1]!=0)
                                salir=1;
                        }
                    }
                    aux_i=i1;
                    aux_j=j1;
                }while(salir==0);
                destruyo=0;
                for(k=0; k<6; k++)
                {
                    for(t=0; t<6; t++)
                    {
                        if(aux[k][t]==4)
                        {
                            vectori[cont]=k;
                            vectorj[cont]=t;
                            cont++;
                            aux[k][t]=1;
                        }
                        if(aux[k][t]==3)
                            aux[k][t]=0;
                    }
                }
                if(cont>=3)
                {
                    destruyo=1;
                    for(k=0; k<cont; k++)
                    {
                        tablero[vectori[k]][vectorj[k]]=0;
                        puntos+=3;
                    }
                    for(k=0; k<6; k++)
                        v[k]=0;
                    for(k=0; k<6; k++)
                        for(t=0; t<6; t++)
                            if(tablero[k][t]==0)
                                v[t]+=1;
                    cont_aux=0;
                    salir_acomodar=0;
                    do{
                        cont_aux++;
                        for(k=5; k>=0; k--)
                            for(t=5; t>=0; t--)
                                if(tablero[t][k]==0 && t!=0)
                                {
                                    aux_1=tablero[t][k];
                                    tablero[t][k]=tablero[t-1][k];
                                    tablero[t-1][k]=aux_1;
                                }
                        if(cont_aux==6)
                            salir_acomodar=1;
                    }while(salir_acomodar!=1);
                    for(k=0; k<6; k++)
                        for(t=0; t<6; t++)
                            if(tablero[k][t]==0)
                                tablero[k][t]=1+rand()%((n+1)-1);
                    for(k=0; k<6; k++)
                        for(t=0; t<6; t++)
                                aux[k][t]=0;
                    cout<<endl<<"puntos: "<<puntos<<endl;
                }
            }

        }
    }
}
Tablero1::Tablero1(int **tablero, int n, int modo) : TableroPrincipal(tablero, n, modo){}
void Tablero1::dibujar_tablero1(int puntos, int modo)
{
    TableroPrincipal::dibujar_tablero1(puntos, modo);
}
void Tablero1::llenarTablero(int **tablero, int n){
    TableroPrincipal::llenarTablero(tablero, n);
}
void Tablero1::imprimirTablero(int **tablero){
    TableroPrincipal::imprimirTablero(tablero);
}
void Tablero1::mover_peluche(int **tablero, int &i, int &j, int &moviendo, int &lado, int n, int &puntos, int &cambiar, int modo)
{
    TableroPrincipal::mover_peluche(tablero, i, j, moviendo, lado, n, puntos, cambiar, modo);
}
void Tablero1::eliminar_peluche(int **tablero, int n, int &puntos, int modo)
{
    TableroPrincipal::eliminar_peluche(tablero, n, puntos, modo);
}
void Tablero1::llenar_candado(int **tablero, int modo)
{
    TableroPrincipal::llenar_candado(tablero, modo);
}



void instruc();
int **crearTablero();
void pantalla_completa();
void pantalla_tablero();

int **crearTablero()
{
    int i, **aux= new int *[6];
    for(i=0; i<6; i++)
        aux[i] = new int [6];
    return aux;
}
void pantalla_completa()
{
    blit(buffer,screen,0,0,0,0,720,563);
}
void pantalla_tablero()
{
    blit(buffer,screen,0,0,237,82,420,420);
}
void cronometro()
{
     segundos++;
     if(segundos==60)
     {
         segundos=0;
         minutos++;
     }
}
END_OF_FUNCTION(cronometro)


int main(){
    srand(time(0));
    MIDI *musicafondo;
    allegro_init(); //inicia allegro
    install_keyboard(); //funcion teclado
    install_mouse(); //funcion puntero
    install_timer();
    set_window_title("\t\tCHUZZLE");
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }
    set_color_depth(32);
    set_volume(230, 200);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 720, 563, 0, 0);//tamaño de nuestra ventana
    musicafondo  = load_midi("Bomberman2-Powerup.mid");
    play_midi(musicafondo, 1);
    LOCK_VARIABLE(segundos);
    LOCK_VARIABLE(minutos);
    LOCK_FUNCTION(cronometro);
    buffer = create_bitmap(SCREEN_W, SCREEN_H); //pantalla
    menu = load_bitmap("menu.bmp", NULL); // imagen menu(pantalla menu)
    menu4 = load_bitmap("menu4.bmp", NULL);
    menu11 = load_bitmap("menu11.bmp", NULL);
    menu12 = load_bitmap("menu12.bmp", NULL);
    menu13 = load_bitmap("menu13.bmp", NULL);
    menu21 = load_bitmap("menu21.bmp", NULL);
    menu22 = load_bitmap("menu22.bmp", NULL);
    menu23 = load_bitmap("menu23.bmp", NULL);
    menu31 = load_bitmap("menu31.bmp", NULL);
    menu32 = load_bitmap("menu32.bmp", NULL);
    menu33 = load_bitmap("menu33.bmp", NULL);
    cursor = load_bitmap("cursor.bmp", NULL);
    instrucciones = load_bitmap("instrucciones.bmp", NULL);
    AzulClaro = load_bitmap("AzulClaro.bmp", NULL);
    Amarillo = load_bitmap("Amarillo.bmp", NULL);
    RosaPalo = load_bitmap("RosaPalo.bmp", NULL);
    Fiusha = load_bitmap("Fiusha.bmp", NULL);
    Naranja = load_bitmap("Naranja.bmp", NULL);
    Rojo = load_bitmap("Rojo.bmp", NULL);
    Verde = load_bitmap("Verde.bmp", NULL);
    Tinto = load_bitmap("Tinto.bmp", NULL);
    CandadoAzulClaro = load_bitmap("candadoazul.bmp", NULL);
    CandadoAmarillo = load_bitmap("candadoamarillo.bmp", NULL);
    CandadoRosaPalo = load_bitmap("candadorosa.bmp", NULL);
    CandadoFiusha = load_bitmap("candadomorado.bmp", NULL);
    CandadoNaranja = load_bitmap("candadonaranja.bmp", NULL);
    CandadoRojo = load_bitmap("candadorojo.bmp", NULL);
    CandadoVerde = load_bitmap("candadoverde.bmp", NULL);
    CandadoTinto = load_bitmap("candadoguinda.bmp", NULL);
    Tablero_1 = load_bitmap("Tablero_1.bmp", NULL);
    Tablero_11 = load_bitmap("Tablero_11.bmp", NULL);
    Tablero_12 = load_bitmap("Tablero_12.bmp", NULL);
    Tablero_13 = load_bitmap("Tablero_13.bmp", NULL);
    Tablero_14 = load_bitmap("Tablero_14.bmp", NULL);
    Tablero_15 = load_bitmap("Tablero_15.bmp", NULL);
    Tablero_16 = load_bitmap("Tablero_16.bmp", NULL);
    Tablero_2 = load_bitmap("Tablero_2.bmp", NULL);
    Tablero_21 = load_bitmap("Tablero_21.bmp", NULL);
    Tablero_22 = load_bitmap("Tablero_22.bmp", NULL);
    Tablero_23 = load_bitmap("Tablero_23.bmp", NULL);
    Tablero_24 = load_bitmap("Tablero_24.bmp", NULL);
    Tablero_25 = load_bitmap("Tablero_25.bmp", NULL);
    Tablero_26 = load_bitmap("Tablero_26.bmp", NULL);
    Tablero_3 = load_bitmap("Tablero_3.bmp", NULL);
    Tablero_31 = load_bitmap("Tablero_31.bmp", NULL);
    Tablero_32 = load_bitmap("Tablero_32.bmp", NULL);
    Tablero_33 = load_bitmap("Tablero_33.bmp", NULL);
    Tablero_34 = load_bitmap("Tablero_34.bmp", NULL);
    Tablero_35 = load_bitmap("Tablero_35.bmp", NULL);
    Tablero_36 = load_bitmap("Tablero_36.bmp", NULL);
    Selector = load_bitmap("Selector.bmp", NULL);
    Perfil = load_bitmap("Perfil.bmp", NULL);
    Ganar = load_bitmap("Ganar.bmp", NULL);
    Perder = load_bitmap("Perder.bmp", NULL);
    int i=0, j=0, moviendo=0, lado=0, cont=0, puntos=0, cambiar=0;
    int **tablero=crearTablero(), n=4, tecla=0, modo=9;
    Tablero1 Tablero11(tablero, 6, 1);
    Tablero1 Tablero12(tablero, 7, 2);
    Tablero1 Tablero13(tablero, 8, 3);
    Tablero1 Tablero21(tablero, 8, 4);
    Tablero1 Tablero22(tablero, 8, 5);
    Tablero1 Tablero23(tablero, 8, 6);
    Tablero1 Tablero31(tablero, 8, 7);
    Tablero1 Tablero32(tablero, 8, 8);
    Tablero1 Tablero33(tablero, 8, 9);
        while(!key[KEY_ESC]){ // iniciamos ciclo
            tecla=0;
        if(mouse_x > 233 && mouse_x < 479 && mouse_y > 490 && mouse_y < 540){ //Instruccioines
            blit(menu4,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
            if(mouse_b & 1){
                    instruc();

            }
        }
        //350 550 750
        else if(mouse_x > 6 && mouse_x < 238 && mouse_y > 345 && mouse_y < 374){//nivel 1 clasico
                blit(menu11,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                if(mouse_b & 1){
                        tecla=1;
                        rest(200);
                        i=0; j=0; moviendo=0; lado=0; cont=0;
                        puntos=0; cambiar=0; n=6; modo=1;
                        Tablero11.llenarTablero(tablero, n);
                        while(tecla==1)
                        {
                            cont++;
                            Tablero11.dibujar_tablero1(puntos, modo);
                            pantalla_completa();
                            Tablero11.imprimirTablero(tablero);
                            pantalla_tablero();
                            if(cont==1)
                                Tablero11.eliminar_peluche(tablero, n, puntos, modo);
                            Tablero11.mover_peluche(tablero, i, j, moviendo, lado, n, puntos, cambiar, modo);
                            while(puntos>=350)
                            {
                                draw_sprite(buffer, Ganar, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                            }
                        }
                }
        }
       else if (mouse_x > 6 && mouse_x < 238 && mouse_y > 386 && mouse_y < 422){//nivel 2 clasico
                 blit(menu12,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                 if(mouse_b & 1){
                        tecla=1;
                        rest(200);
                        i=0; j=0; moviendo=0; lado=0; cont=0;
                        puntos=0; cambiar=0; n=7; modo=2;
                        Tablero12.llenarTablero(tablero, n);
                        while(tecla==1)
                        {
                            cont++;
                            Tablero12.dibujar_tablero1(puntos, modo);
                            pantalla_completa();
                            Tablero12.imprimirTablero(tablero);
                            pantalla_tablero();
                            if(cont==1)
                                Tablero12.eliminar_peluche(tablero, n, puntos, modo);
                            Tablero12.mover_peluche(tablero, i, j, moviendo, lado, n, puntos, cambiar, modo);
                            while(puntos>=550)
                            {
                                draw_sprite(buffer, Ganar, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                            }
                        }
                }
        }
        else if (mouse_x > 6 && mouse_x < 238 && mouse_y > 428 && mouse_y < 465){//nivel 3 clasico
                 blit(menu13,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                 if(mouse_b & 1){
                        tecla=1;
                        rest(200);
                        i=0; j=0; moviendo=0; lado=0; cont=0;
                        puntos=0; cambiar=0; n=8; modo=3;
                        Tablero13.llenarTablero(tablero, n);
                        while(tecla==1)
                        {
                            cont++;
                            Tablero13.dibujar_tablero1(puntos, modo);
                            pantalla_completa();
                            Tablero13.imprimirTablero(tablero);
                            pantalla_tablero();
                            if(cont==1)
                                Tablero13.eliminar_peluche(tablero, n, puntos, modo);
                            Tablero13.mover_peluche(tablero, i, j, moviendo, lado, n, puntos, cambiar, modo);
                            while(puntos>=750)
                            {
                                draw_sprite(buffer, Ganar, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                            }
                        }
                }
        }
        else if(mouse_x > 240 && mouse_x < 480 && mouse_y > 341 && mouse_y < 380){//nivel 1 ccontrareloj
                blit(menu21,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                if(mouse_b & 1){
                        tecla=1;
                        rest(200);
                        i=0; j=0; moviendo=0; lado=0; cont=0;
                        puntos=0; cambiar=0; n=8; modo=4;
                        Tablero21.llenarTablero(tablero, n);
                        while(tecla==1)
                        {
                            install_int_ex(cronometro, SECS_TO_TIMER(1));
                            cont++;
                            Tablero21.dibujar_tablero1(puntos, modo);
                            pantalla_completa();
                            Tablero21.imprimirTablero(tablero);
                            pantalla_tablero();
                            if(cont==1)
                                Tablero21.eliminar_peluche(tablero, n, puntos, modo);
                            Tablero21.mover_peluche(tablero, i, j, moviendo, lado, n, puntos, cambiar, modo);
                            while(puntos>=350)
                            {
                                draw_sprite(buffer, Ganar, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                                segundos=0;
                                minutos=0;
                            }
                            while(minutos>=1 && segundos>=30)
                            {
                                draw_sprite(buffer, Perder, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                                segundos=0;
                                minutos=0;
                            }
                        }
                }
        }
       else if (mouse_x > 240 && mouse_x < 480 && mouse_y > 386 && mouse_y < 422){//nivel 2 contrareloj
                 blit(menu22,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                 if(mouse_b & 1){
                        install_int_ex(cronometro, SECS_TO_TIMER(1));
                        tecla=1;
                        rest(200);
                        i=0; j=0; moviendo=0; lado=0; cont=0;
                        puntos=0; cambiar=0; n=8; modo=5;
                        Tablero22.llenarTablero(tablero, n);
                        while(tecla==1)
                        {
                            cont++;
                            Tablero22.dibujar_tablero1(puntos, modo);
                            pantalla_completa();
                            Tablero22.imprimirTablero(tablero);
                            pantalla_tablero();
                            if(cont==1)
                                Tablero22.eliminar_peluche(tablero, n, puntos, modo);
                            Tablero22.mover_peluche(tablero, i, j, moviendo, lado, n, puntos, cambiar, modo);
                            while(puntos>=550)
                            {
                                draw_sprite(buffer, Ganar, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                                segundos=0;
                                minutos=0;
                            }
                            while(minutos>=2)
                            {
                                draw_sprite(buffer, Perder, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                                segundos=0;
                                minutos=0;
                            }
                        }
                }
        }
        else if (mouse_x > 240 && mouse_x < 480 && mouse_y > 428 && mouse_y < 465){//nivel 3 contrareloj
                 blit(menu23,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                 if(mouse_b & 1){
                        install_int_ex(cronometro, SECS_TO_TIMER(1));
                        tecla=1;
                        rest(200);
                        i=0; j=0; moviendo=0; lado=0; cont=0;
                        puntos=0; cambiar=0; n=8; modo=6;
                        Tablero23.llenarTablero(tablero, n);
                        while(tecla==1)
                        {
                            cont++;
                            Tablero23.dibujar_tablero1(puntos, modo);
                            pantalla_completa();
                            Tablero23.imprimirTablero(tablero);
                            pantalla_tablero();
                            if(cont==1)
                                Tablero23.eliminar_peluche(tablero, n, puntos, modo);
                            Tablero23.mover_peluche(tablero, i, j, moviendo, lado, n, puntos, cambiar, modo);
                            while(puntos>=750)
                            {
                                draw_sprite(buffer, Ganar, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                                segundos=0;
                                minutos=0;
                            }
                            while(minutos>=3 && segundos>=30)
                            {
                                draw_sprite(buffer, Perder, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                                segundos=0;
                                minutos=0;
                            }
                        }
                        segundos=0; minutos=0;
                }
        }
        else if(mouse_x > 483 && mouse_x < 709 && mouse_y > 345 && mouse_y < 374){//nivel 1 demonio
                blit(menu31,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                if(mouse_b & 1){
                        tecla=1;
                        rest(200);
                        i=0; j=0; moviendo=0; lado=0; cont=0;
                        puntos=0; cambiar=0; n=8; modo=7;
                        Tablero31.llenarTablero(tablero, n);
                        Tablero31.llenar_candado(tablero, modo);
                        while(tecla==1)
                        {
                            cont++;
                            Tablero31.dibujar_tablero1(puntos, modo);
                            pantalla_completa();
                            Tablero31.imprimirTablero(tablero);
                            pantalla_tablero();
                            if(cont==1)
                                Tablero31.eliminar_peluche(tablero, n, puntos, modo);
                            Tablero31.mover_peluche(tablero, i, j, moviendo, lado, n, puntos, cambiar, modo);
                            while(puntos>=350)
                            {
                                draw_sprite(buffer, Ganar, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                            }
                        }
                }
        }
       else if (mouse_x > 483 && mouse_x < 709 && mouse_y > 386 && mouse_y < 422){//nivel 2 demonio
                 blit(menu32,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                 if(mouse_b & 1){
                        tecla=1;
                        rest(200);
                        i=0; j=0; moviendo=0; lado=0; cont=0;
                        puntos=0; cambiar=0; n=8; modo=8;
                        Tablero32.llenarTablero(tablero, n);
                        Tablero32.llenar_candado(tablero, modo);
                        while(tecla==1)
                        {
                            cont++;
                            Tablero32.dibujar_tablero1(puntos, modo);
                            pantalla_completa();
                            Tablero32.imprimirTablero(tablero);
                            pantalla_tablero();
                            if(cont==1)
                                Tablero32.eliminar_peluche(tablero, n, puntos, modo);
                            Tablero32.mover_peluche(tablero, i, j, moviendo, lado, n, puntos, cambiar, modo);
                            while(puntos>=550)
                            {
                                draw_sprite(buffer, Ganar, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                            }
                        }
                 }
        }
        else if (mouse_x > 483 && mouse_x < 709 && mouse_y > 428 && mouse_y < 465){//nivel 3 demonio
                 blit(menu33,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                 if(mouse_b & 1){
                        tecla=1;
                        rest(200);
                        i=0; j=0; moviendo=0; lado=0; cont=0;
                        puntos=0; cambiar=0; n=8; modo=9;
                        Tablero33.llenarTablero(tablero, n);
                        Tablero33.llenar_candado(tablero, modo);
                        while(tecla==1)
                        {
                            cont++;
                            Tablero33.dibujar_tablero1(puntos, modo);
                            pantalla_completa();
                            Tablero33.imprimirTablero(tablero);
                            pantalla_tablero();
                            if(cont==1)
                                Tablero33.eliminar_peluche(tablero, n, puntos, modo);
                            Tablero33.mover_peluche(tablero, i, j, moviendo, lado, n, puntos, cambiar, modo);
                            while(puntos>=750)
                            {
                                draw_sprite(buffer, Ganar, 0, 0);
                                pantalla_completa();
                                textprintf(screen, font, 0, 0, palette_color[7], "Presiona una tecla para continuar... ");
                                textprintf(screen, font, 0,50, palette_color[9], "Puntos: %d", puntos);
                                readkey();
                                puntos=0;
                                tecla=0;
                            }
                        }
                }
        }
        else
            blit(menu,buffer,0,0,0,0,SCREEN_W,SCREEN_H); //si no se cumplen las condiciones anteriores muestra la pantalla menu
        masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22);//13 22
        blit(buffer, screen, 0, 0, 0, 0, 720, 563);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H); // graficos de la pantalla menu
    }

    return 0;
}
END_OF_MAIN ();

void instruc(){
    int clic = 1;
    blit(instrucciones,buffer,0,0,0,0,720,563);
        if (mouse_b & 1){
            do{
                masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
                blit(buffer,screen,0,0,0,0,720,563);
                blit(instrucciones,buffer,0,0,0,0,720,563);
                if(mouse_x > 18 && mouse_x < 88 && mouse_y > 14 && mouse_y < 53){
                    if(mouse_b & 1){
                        clic=0;
                    }
                }
            }while(clic==1);
        }
}
