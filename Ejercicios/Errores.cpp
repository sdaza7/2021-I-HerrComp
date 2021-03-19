#include <iostream>
#include <cmath>

typedef double REAL;
REAL x = 2.0;
REAL cen = 0.0;
REAL pot = x - cen;

REAL f1(REAL x);
REAL factorial(int N);

REAL S1 = 0.0;
REAL val = x - 1.0;
REAL inter = cen - 1.0;
int main (void)
{
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    //Serie de Taylor con pows
    int d = 0;
    int e = 0;
    int g = 0;
    int h = 0;
    for(int ii = 0; ii < 8; ++ii)
    {
        d = 10-ii;
        e = 9-ii;
        h = e-1;
        if (ii==0)
        {
            S1 = std::pow(inter,8);
        }
        else if (ii == 1)
        {
            S1 = S1 + 8*std::pow(inter,7)*std::pow(pot,ii)/factorial(ii);
        }
        else
        {
            g = d*e;
            S1 += g*std::pow(inter,h)*std::pow(pot,ii)/factorial(ii);
        }
    }

    std::cout << f1(x) << "\t" << S1 << "\n";
    return 0;
}

REAL f1(REAL b)
    {
        double a = b-1.0;
        double f = std::pow(a,8);
        return f;
    }
REAL factorial(int N)
{
    REAL sol = 1.0;
    int ii = 0;
    for (ii=N; ii>0; --ii)
    {
        sol *= ii;
    }
    return sol;
}
