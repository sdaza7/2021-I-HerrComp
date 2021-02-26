#include <iostream>
#include <cstdlib>
int main(int argc, char **argv)
{
    // ./a.out -> argc = 1, argv = ["./a.out"]
    // ./a.out 10 -> argc = 2, argv = ["./a.out", "10"]
    int a = std::atoi(argv[1]);
    a=2*a;
    std::cout << "Hello World" << "\n";
    std::cout << "2*a= " << a << "\n";
    return 0;
}
