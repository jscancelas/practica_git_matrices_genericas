#ifndef MATRICES_H
#define MATRICES_H
#include <iostream>
using namespace std;

template <class T>  class matrices
{
public:
    matrices(int filas, int columnas);
    ~matrices();
    void recibeEntradas( );
    void imprimir( );

    void multMat(matrices &m1, matrices &m2);
//    matrices * operator * (matrices &mult);
    matrices  & operator * (matrices &mult);


    void trasponerV1(matrices &m1);
    matrices  * trasponerV2();
    matrices & trasponerV3(matrices &m1);

private:
    T *matriz_;
    int filas_,columnas_;
};


template <class T>  matrices <T>:: matrices( int filas1, int columnas1) {
    filas_= filas1;
    columnas_= columnas1;
    matriz_= new T[filas_ * columnas_];
}

template <class T>  matrices <T>:: ~matrices( ) {
    cout<<"\nSE EJECUTA UN DESTRUCTOR";
    imprimir();
    delete matriz_;
}

template <class T> void matrices <T>:: recibeEntradas( ) {
    for ( int i = 0; i < filas_; i++ )
        for ( int j = 0; j < columnas_; j++ )
        {
            cout << "A[" << i + 1 << "][" << j + 1 <<"]= ";
            cin >> *(matriz_+columnas_*i+j);
        }
}

template <class T>  void matrices <T>:: imprimir( ) {
    cout << endl << "Esta es la matriz: " <<endl;
    for ( int i = 0; i < filas_; i++ )
    {
        for ( int j = 0; j < columnas_; j++)
            cout << *(matriz_ + columnas_*i+  j) <<" \t";
        cout << endl;
    }
    cout << endl;
}

template <class T> void  matrices <T>:: multMat(matrices &m1, matrices &m2) {
    for (int i=0; i < m1.filas_*m2.columnas_; i++)
        *(matriz_ +i )=0;

    for (int i=0; i < m1.filas_; i++ )
        for(int k=0; k< m2.columnas_; k++)
            for(int j= 0; j < m1.columnas_; j++)
                *(matriz_+i*columnas_+k)=*(matriz_+i*columnas_+ k) + *(m1.matriz_+i*m1.columnas_+j) * *(m2.matriz_ + j*m2.columnas_ +k);
}

/*
template <class T>  matrices<T> *    matrices<T>::operator *( matrices &m2){
    matrices * ptrMatriz=new matrices(filas_, m2.columnas_);

    for (int i=0; i <filas_*columnas_; i++)
        *(ptrMatriz->matriz_ + i)=0;

    for ( int i=0; i < filas_; i++ )
        for(int k=0; k< m2.columnas_; k++)
            for( int j= 0; j < columnas_; j++)
                *(ptrMatriz->matriz_ + i*ptrMatriz->columnas_ +k)+= *(matriz_+i*columnas_+j) *  *(m2.matriz_+j*m2.columnas_+k);

    return ptrMatriz;
}
*/

template <class T>  matrices<T> &  matrices<T>::operator *( matrices &m2){
    matrices * ptrMatriz=new matrices(filas_, m2.columnas_);

    for (int i=0; i <filas_*columnas_; i++)
        *(ptrMatriz->matriz_ + i)=0;

    for ( int i=0; i < filas_; i++ )
        for(int k=0; k< m2.columnas_; k++)
            for( int j= 0; j < columnas_; j++)
                *(ptrMatriz->matriz_ + i*ptrMatriz->columnas_ +k)+= *(matriz_+i*columnas_+j) *  *(m2.matriz_+j*m2.columnas_+k);

    return *ptrMatriz;
}



template <class T>void  matrices <T>:: trasponerV1(matrices &m1 )
{
    filas_=m1.columnas_;
    columnas_= m1.filas_;
    for (int i=0; i < filas_; i++)
        for (int j=0; j < columnas_; j++)
            *(matriz_ + i*columnas_+j)= *(m1.matriz_ + j*filas_+i);
}

template <class T> matrices<T> *  matrices<T>::trasponerV2() {
    matrices * ptrMatriz=new matrices(this->columnas_, this->filas_);

    for (int i=0; i < columnas_; i++)
        for (int j=0; j < filas_; j++)
            *(ptrMatriz->matriz_ + i*filas_+j)= *(this->matriz_+j*columnas_+i);
    return ptrMatriz;
}

template <class T> matrices<T> &  matrices <T>:: trasponerV3(matrices &m1 )
{
    filas_=m1.columnas_;
    columnas_= m1.filas_;
    for (int i=0; i < filas_; i++)
        for (int j=0; j < columnas_; j++)
            *(matriz_ + i*columnas_+j)= *(m1.matriz_ + j*filas_+i);
    return *this;
}

#endif // MATRICES_H
