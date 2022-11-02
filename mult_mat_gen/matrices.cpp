#include <iostream>
#include "matrices.h"
using namespace std;

template <class T>  matrices <T>:: matrices( int filas1, int columnas1)
{
    filas= filas1;
    columnas= columnas1;
    matriz= new T[filas*columnas];
}

template <class T>  matrices <T>:: ~matrices( )
{
   delete matriz;
}

template <class T> void matrices <T>:: recibeEntradas( )
{
    for ( int i = 0; i < filas; i++ )
        for ( int j = 0; j < columnas; j++ )
        {
            cout << "A[" << i + 1 << "][" << j + 1 <<"]= ";
            cin >> *(matriz+columnas*i+j);
        }
}

template <class T>  void matrices <T>:: imprimir( )
{
    cout << endl << endl<< "Esta es la matriz: " << endl;
    for ( int i = 0; i < filas; i++ )
    {
        for ( int j = 0; j < columnas; j++)
            cout << *(matriz + columnas*i+j) <<" \t";
        cout << endl;
    }
    cout << endl;
}

template <class T> void  matrices <T>:: multMat(matrices m1, matrices m2)
{
    int i,j,k;
    for (i=0; i <m1.filas*m2.columnas; i++)
        *(matriz +i )=0;

    for ( i=0; i < m1.filas; i++ )
        for(k=0; k< m2.columnas; k++)
            for( j= 0; j < m1.columnas; j++)
                *(matriz+i*columnas+k)=*(matriz+i*columnas+k) + *(m1.matriz+i*m1.columnas+j) * *(m2.matriz+j*m2.columnas+k);
}

template <class T> void  matrices <T>:: trasponer(matrices m1 )
{
    int aux;
    aux= filas;
    filas=columnas;
    columnas= aux;
    for (int i=0; i < filas; i++)
        for (int j=0; j < columnas; j++)
        *(matriz + i*columnas+j)= *(m1.matriz+j*filas+i);
}
