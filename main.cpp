#include "plant.h"
#include "diff.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <cstddef>
#include <discpp.h>
using namespace std;
int main()
{

    size_t k,Nmin,Nmax,dN,fr,sc,N,i,o,H,m,a;

    i = 0;
    o = 0;
    m=0;
     const size_t l=10;
    cout<<"a=";
    cin>>a;//элемент,среднеее значение которого нужно от 0 до k
    Enter1(k, Nmin, Nmax, dN,fr,sc);//ввод k и N,Nmin,Nmax и dn
    int* M = new int[k];
    Enter(M, k);//ввод номеров датчиков
    double** C = new double* [k];
    for (size_t i = 0; i < k; i++)
    {
        C[i] = new double[k];
    }
    double* R = new double[Nmax-Nmin/dN];
    double* Xmed = new double[k];
    double* Xmedfr = new double[Nmax - Nmin / dN];
    double* Xmedsc = new double[Nmax - Nmin / dN];
    double* Xcheck = new double[l];
    double* L = new double [l];
    size_t e = 0;
    for (size_t y = Nmin; y < Nmax+1; y += dN)
    {
        Plant plant;
        plant_init(plant);
        size_t n = y;
        double** X = new double* [n];
        for (size_t i = 0; i < n; i++)
        {
            X[i] = new double[k];
        }
        for (size_t j = 0 ; j < n; j++)//получение измеренных значений
        {
            for (size_t u = 0 ; u < k; u++)
            {
                X[j][u] = plant_measure(M[u], plant);
                //cout << X[j][u] << endl;

            }
        }
        N = y;
       Medium(X, k, N, Xmed,Xmedfr,Xmedsc,fr,sc,i,o,a,Xcheck,m);//расчёт средних значений
       covariance(X, k, Xmed, C, N, fr, sc, R, e);
        cout << "------" << endl;
        e++;

    }
    //exe(R, e, Nmin, dN, fr, sc,Xmedfr,Xmedsc);
    H=Nmin;
  for(size_t p=0;p<Nmax;p+=dN)
  {
      L[p]=H;
      H=H+dN;
      cout<<L[p]<<"____"<<endl;
  }
  double max=Xcheck[0];
  double min=Xcheck[0];
       for(size_t u=0;u<10;u++)
       {
           if(Xcheck[u]>max)
           {
               max=Xcheck[u];
           }
           if (Xcheck[u]<min)
           {
               min=Xcheck[u];
           }
           cout<<Xcheck[u]<<"++++"<<endl;
       }
size_t d=(size_t)(max-min);
    Dislin g;
g.metafl("cons");
g.scrmod("revers");
g.disini();
g.name("Measurement no.", "x");
g.name("Medium Value", "y");
g.labdig(-4, "y");
g.labdig(-1, "x");
g.ticks(10, "x");
g.ticks(10, "y");
g.titlin("Medium parameter plot", 1);
const int background_color = g.intrgb(0.95, 0.95, 0.95);
g.axsbgd(background_color);
g.graf(0,Nmax,0,Nmin,40,43.1,40,0.5);
g.setrgb(0.7, 0.7, 0.7);
g.grid(1,1);
g.color("fore");
g.title();
g.color("red");
g.curve(L[0],Xcheck[0],l);

g.disfin();

}

