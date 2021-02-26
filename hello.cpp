#include <iostream>
#include <cstdlib>
int main(int argc, char **argv)
{
    int a = std::atoi(argv[1]);
    a=2*a;
    std::cout << "Hello World" << "\n";
    std::cout << "2*a= " << a << "\n";
    return 0;
}
