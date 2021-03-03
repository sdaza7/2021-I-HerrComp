#include <iostream>
#include <cstdlib>


int main (void)
{
    float x = 0.0;
    //ii es la cantidad de veces que realizo la suma
    for(int  ii=1; ii <= 10; ++ii)
    {
        x = x+0.1;
    }
    //ASi se pone la presición en notación científica con 7 decimales
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);
    std::cout<< "EL resultado es : " << x << "\n";

    return 0;
}
