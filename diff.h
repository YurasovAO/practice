#ifndef DIFF_H_INCLUDED
#define DIFF_H_INCLUDED
#include <cstddef>
void Enter1(size_t& k,size_t &Nmin,size_t &Nmax,size_t &dN,size_t &fr,size_t &sc);
void Enter(int* M, size_t& k);
void Medium(double** X, size_t k, size_t N,double*Xmed, double* Xmedfr, double* Xmedsc,size_t fr,size_t sc,size_t &i,size_t &o,size_t &a,double *Xcheck,size_t &m);
void covariance(double** X, size_t k, double* Xmed, double** C, size_t N, size_t fr, size_t sc, double* R, size_t e);
void exe(double* R, size_t H, size_t Nmin, size_t n,size_t fr,size_t sc, double* Xmedfr, double* Xmedsc);

#endif // DIFF_H_INCLUDED
