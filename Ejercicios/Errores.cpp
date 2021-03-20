#include <iostream>
#include <cmath>
#include <cstdlib>

typedef double REAL;

REAL f1(REAL b);
REAL factorial(int N);

int main (int argc, char **argv)
{
    //X se da por el Usuario en el Copilador
    REAL x = std::atof(argv[1]) ;
    //Al ser una serie de Taylor, está centrada en Cero, por lo tanto:
    REAL cen = 0.0;
    //Pot corresponde al termino (1-cen), que se repite en las derivadas a reemplazar el valor de CEN en estas.
    REAL pot = 1 - cen;
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    //Serie de Taylor con Pows
    REAL S1 = 0.0;
    S1 = std::pow(pot,8) - 8*std::pow(pot,7)*x/factorial(1) + 56*std::pow(pot,6)*std::pow(x,2)/factorial(2) - 6*56*std::pow(pot,5)*std::pow(x,3)/factorial(3) + 30*56*std::pow(pot,4)*std::pow(x,4)/factorial(4) - 120*56*std::pow(pot,3)*std::pow(x,5)/factorial(5) + 360*56*std::pow(pot,2)*std::pow(x,6)/factorial(6) - 360*112*std::pow(pot,1)*std::pow(x,7)/factorial(7) + 360*112*std::pow(x,8)/factorial(8);
    //Serie de TAylor con productos
    REAL S2 = 0.0;
    S2 = 1 - 1*x/factorial(1) + 56*x*x/factorial(2) - 6*56*x*x*x/factorial(3) + 30*56*x*x*x*x/factorial(4) - 120*56*x*x*x*x*x/factorial(5) + 360*56*x*x*x*x*x*x/factorial(6) - 360*112*x*x*x*x*x*x*x/factorial(7) + 360*112*x*x*x*x*x*x*x*x/factorial(8);
    std::cout << "X" << "\t" << "Pow" << "S Taylor" << "S Taylor Pow" << "\n";
    std::cout << x <<  "\t" << f1(x) << "\t" << S1 << "\t" << S2 << "\n";
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
