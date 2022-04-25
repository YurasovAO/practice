#include<iostream>
#include <math.h>
#include <conio.h>
#include "diff.h"
#include <cstddef>
using namespace std;
void Enter1(size_t& k,size_t &Nmin, size_t &Nmax, size_t &dN,size_t &fr,size_t &sc)
{
	cout << "k=";
	cin >> k;
    cout << "Nmin=";
    cin >> Nmin;
    cout << "Nmax=";
    cin >> Nmax;
    cout << "dN=";
    cin >> dN;
    size_t frr, scc;
    cout << "enter the number of the source element and the one you want to ping:";

    cin >> frr >> scc;
    fr = frr - 1;
    sc = scc - 1;


}
void Enter(int* M, size_t& k)//ввод номеров датчиков
{
    for (size_t j = 0; j < k; j++)
    {
        cout << "enter the senser number:";
        cin >> M[j];
    }
}
void Medium(double** X, size_t k, size_t N,double *Xmed, double* Xmedfr, double* Xmedsc,size_t fr,size_t sc,size_t& i, size_t& o,size_t &a,double *Xcheck,size_t &m)//расчёт средних значений
{
    size_t p, q;
    for (p = 0; p < k; p++)
    {
        double z = 0;

        for (q = 0; q < N; q++)
        {
            z = z + X[q][p];
        }
        Xmed[p] = z / N;
        if(p==a)
        {
            Xcheck[m]=Xmed[p];
             cout<<Xcheck[m]<<"=====";
            m++;

        }
        if (p == fr)
        {
            Xmedfr[i] = Xmed[p];
            i++;

        }
        else if (p == sc)
        {
            Xmedsc[o] = Xmed[p];
            o++;

        }


    }

}
void covariance(double**X, size_t k, double* Xmed,double ** C,size_t N,size_t fr,size_t sc,double *R,size_t e)
{
    size_t b, j,y;
    for (y = 0; y < k; y++)//перемнная, с которой ищется связь
    {
        for (b = 0; b < k; b++)//переменная,связанная с той,которую взяли выше
        {
            double t = 0;
            for (j = 0; j < N; j++)
            {
                t = t + (X[j][y] - Xmed[y]) * (X[j][b] - Xmed[b]);

            }
            C[y][b] = t / N;
            if ((y == fr)&& (b == sc))
            {
                R[e]=C[y][b];

            }
        }

    }

}

void exe(double* R, size_t e, size_t Nmin, size_t dN, size_t fr, size_t sc,double *Xmedfr,double *Xmedsc)
{

    size_t x = Nmin;
    cout << " " << " " << " " << " ";
    cout << "№";
    cout << " " << " " << " " << " ";
    cout << "N";
    cout << " " << " " << " " << " ";
    cout << "C[" << fr << "][" << sc << "]";
    cout << " " << " " << " " << " ";
    cout << "Xmed[" << fr << "]";
    cout << " " << " " << " " << " ";
    cout << "Xmed[" << sc << "]" << endl;
    for (size_t j = 0; j < e; j++)
    {
        cout << " " << " " << " " << " ";
        cout << j + 1;
        cout << " " << " " << " " << " ";
        cout << x;
        cout << " " << " " << " " << " ";
        cout << R[j];
        cout << " " << " " << " " << " ";
        cout << Xmedfr[j];
        cout << " " << " " << " " << " ";
        cout << Xmedsc[j];

        cout << endl;

        x += dN;
    }

}
