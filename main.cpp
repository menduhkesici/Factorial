#include "include/factorial.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc > 1)
        std::cout << factorial(atoi(argv[1])) << std::endl;

    return 0;
}
