#include <iostream>
#include <random>
#include <cstdlib>
#include <cmath>
#include "mpi.h"

int samples (int N);
double results(double val, int pid, int np);

int main(int argc, char **argv)
{

  std::cout.precision(4);
  std::cout.setf(std::ios::scientific);
  MPI_Init(&argc, &argv); /* Mandatory */

  int pid;                 /* rank of process */
  int np;                 /* number of processes */

  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  int N = std::atoi(argv[1]);

  double Nlocal = N/np;
  double t0 = MPI_Wtime();
  double Nc = samples (Nlocal);
  double TNc = results(Nc, pid, np);
  double pi_1 = 4.0*TNc/N;
  double t1 = MPI_Wtime();
  //Parallel time
  double PT = t1 - t0;
  ///
  double t2 = MPI_Wtime();
  double pi_2 = 4.0*samples(N)/N;
  double t3 = MPI_Wtime();
  // Serial time
  double ST;

  if (np==1) {

    ST = PT;

  } else {

    ST = t3 - t2;
  }

  double SU = ST/PT;

  if (pid==0) {
    std::cout << "# de procesos: " << "\t" << np << "\t"
              << "Tiempo: " << "\t" << PT << "\t"
              << "SpeedUp: " << "\t" << SU << "\t"
              << "Eficiencia: " << "\t" << SU/np << "\t"
              << "Pi: " << "\t" << pi_1 << std::endl;
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


double results(double val, int pid, int np)
{
  double result;
  int tag = 0;
  if (pid != 0) {
    // enviar val a pid 0
    int dest = 0;
    MPI_Send(&val, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  } else { // pid ==0
    // recibir de pid 1, 2, 3, 4, 5, ... , np-1
    double total = val;
    for (int ipid = 1; ipid < np; ++ipid) {
      MPI_Recv(&val, 1, MPI_DOUBLE, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      total += val;
    }
    result = total;
  }
  return result;
}
