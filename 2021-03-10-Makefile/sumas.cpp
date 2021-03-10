#include <iostream>
#include <cmath>
#include <cstdlib>

double sumup (int Nmax);
double sumdown (int Nmax);
int main (int argc, char **argv)
{
    std::cout.precision(8);
    std::cout.setf(std::ios::scientific);
    for (int nmax = 1; nmax < std::atoi(argv[1]); ++nmax)
    {
        float s1 = sumup(nmax);
        float s2 = sumdown(nmax);
        std::cout << nmax << "\t"
        << s1 << "\t" << s2 << "t"
        << std::fabs(s1-s2/s2) << "\t"
        << "\n";;
    }
    return 0;
}

double sumup (int Nmax)
{
    double sum = 0.0;
    for (int ii=1; ii<=Nmax; ++ii)
    {
        sum += 1.0/ii;
    }
    return sum;
}
double sumdown (int Nmax)
{
    double sum =0.0;
    for (int ii=Nmax; ii>=1; --ii)
    {
        sum += 1.0/ii;
    }
    return sum;
}
