#include <iostream>

//typedef sirve para renombrar el tipo de variable que se tiene
typedef float REAL;

int main(void)
{
    REAL under =1.0;
    REAL  over =1.0;
    int ii=1;
    do
    {
        under = under/2;
        over = over*2;
        ii=ii+1;
        std::cout << ii << "  " << under << "  y  " << over << "\n";
    }
    while (ii<200);
    std::cout << under << "\n";
    std::cout << over << "\n";


    return 0;
}
