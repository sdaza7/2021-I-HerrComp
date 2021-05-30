#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <random>
#include <cmath>
#include <mpi.h>

int samples (int N);
double cal_pi(int N, int pid, int np);
double recopilar(double value, int pid, int np);

int main (int argc, char **argv)
{
    std::cout.precision(5);
    std::cout.setf(std::ios::scientific);

    MPI_Init(&argc, &argv); /* Mandatory */

     int pid;                 /* rank of process */
     int np;                 /* number of processes */

     MPI_Comm_size(MPI_COMM_WORLD, &np);
     MPI_Comm_rank(MPI_COMM_WORLD, &pid);

     int N = std::atoi(argv[1]);
     //Para la parte Serial
     double t0_serial = MPI_Wtime();
     double aprox_pi_serial = 4.0*samples(N)/N;
     double t1_serial = MPI_Wtime();
     double ST = t1_serial - t0_serial;
     //Para la parte Paralela
     double t0_parallel = MPI_Wtime();
     double aprox_pi_parallel= cal_pi(N, pid, np);
     double t1_parallel = MPI_Wtime();
     double PT = t1_parallel - t0_parallel;
     //Para
     //Variables para Imprimir
     double a = recopilar(aprox_pi_parallel, pid, np);
     double b = recopilar(ST, pid, np);
     double c = recopilar(PT, pid, np);
     double SU =  b/c;
     if(pid==0)
     {
         std::cout << "np:" << "\t" << np << "\t"
               << "Serial_Time:" << "\t" << b << "\t"
               << "Parallel_Time:" << "\t" << c << "\t"
               << "Speeup:" << "\t" << SU << "\t"
               << "Eficiency:" << "\t" << SU/np << "\t"
               << " Pi_Serial:" << "\t" << aprox_pi_serial << "\t"
               << " Pi_Parallel:" << "\t" << a << std::endl;
     }
     MPI_Finalize(); /* Mandatory */
    return 0;
}

int samples(int N)
{
    int count = 0;
    int seed = 1; // use pid for seed when in parallel
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dis(-1.0, 1.0);
    for (int ii = 0; ii < N; ++ii) {
    double rx = dis(gen);
    double ry = dis(gen);
    if (rx*rx + ry*ry < 1)
      count++;
  }
  return count;
}

double cal_pi(int N, int pid, int np)
{
    int separation = N/np;
    double iimin =pid*separation;
    double iimax = (pid+1)*separation;
    return 4.0*(samples(iimax)-samples(iimin))/N;
}

double recopilar(double value, int pid, int np)
{
    double result = 0.0;
  int tag = 0;
  if (pid != 0) {
    // enviar val a pid 0
    int dest = 0;
    MPI_Send(&value, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  } else { // pid ==0
    // recibir de pid 1, 2, 3, 4, 5, ... , np-1
    double total = value;
    for (int ipid = 1; ipid < np; ++ipid) {
      MPI_Recv(&value, 1, MPI_DOUBLE, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      total += value;
    }
    result=total;
    // imprimir
    //std::cout << total << std::endl;
  }
  return result;
}
