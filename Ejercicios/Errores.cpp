#include <iostream>
#include <cmath>

typedef double REAL;
REAL x = 1.0;
REAL cen = x;
REAL pot = x - cen;

REAL f1(REAL x);
REAL factorial(int N);

REAL S1 = 0.0;
REAL val = 1.0 - x;
REAL inter = 1.0 - cen;
int main (void)
{
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    //Serie de Taylor con Pows
    S1 = std::pow(pot,8) - 8*std::pow(pot,7)*x/factorial(1) + 56*std::pow(pot,6)*std::pow(x,2)/factorial(2) - 6*56*std::pow(pot,5)*std::pow(x,3)/factorial(3) + 30*56*std::pow(pot,4)*std::pow(x,4)/factorial(4) - 120*56*std::pow(pot,3)*std::pow(x,5)/factorial(5) + 360*56*std::pow(pot,2)*std::pow(x,6)/factorial(6) - 360*112*std::pow(pot,1)*std::pow(x,7)/factorial(7) + 360*112*std::pow(x,8)/factorial(8);
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
