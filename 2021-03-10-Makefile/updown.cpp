#include <iostream>
#include <cmath>
#include <cstdlib>

float sumup (int Nmax);
float sumdown (int Nmax);
int main (int argc, char **argv)
{
    std::cout.precision(8);
    std::cout.setf(std::ios::scientific);
    const int NMAX = std::atoi(argv[1]);
    for (int nmax = 1; nmax < NMAX; nmax++)
    {
        float s1 = sumup(nmax);
        float s2 = sumdown(nmax);
        std::cout << nmax << "\t"
        << s1 << "\t" << s2 << "\t"
        << std::fabs(s1-s2)/s2 << "\t"
        << "\n";;
    }
    return 0;
}

float sumup (int Nmax)
{
    float sum = 0;
    for (int ii=1; ii<=Nmax; ++ii)
    {
        sum += 1.0/ii;
    }
    return sum;
}
float sumdown (int Nmax)
{
    float suma =0;
    for (int ii=Nmax; ii>=1; --ii)
    {
        suma += 1.0/ii;
    }
    return suma;
}
