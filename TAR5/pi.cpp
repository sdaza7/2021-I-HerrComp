#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <random>
#include <cmath>
#include <mpi.h>

int samples (int N);
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

     int Nlocal = N/np;

     //Para la parte Paralela
     double t0 = MPI_Wtime();
     double Nc = samples(Nlocal);
     double Total_Nc = recopilar(Nc, pid, np);
     double aprox_pi = 4.0*Total_Nc/N;
     double t1 = MPI_Wtime();
     double tlapse = t1 - t0;
     
     if(0==pid)
     {
         std::cout << "np: " << "\t" << np <<  "\t"
                   << "Time: " << "\t" << tlapse << "\t"
                   << "Pi: " << "\t" << aprox_pi <<std::endl;
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
    {
        count++;
    }
  }
  return count;
}

double recopilar(double value, int pid, int np)
{
    int tag = 0;
    double result = 0.0;
    if (pid != 0) {
    // enviar value a pid 0
    int dest = 0;
    MPI_Send(&value, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  } else { // pid ==0
    // recibir de pid 1, 2, 3, 4, 5, ... , np-1
    double total = value;
    for (int ipid = 1; ipid < np; ++ipid) {
      MPI_Recv(&value, 1, MPI_DOUBLE, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      total += value;
    }
    result = total;
    }
    return result;
}
