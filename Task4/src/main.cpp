#include <iostream>
#include "Mixins.h"

int main()
{
    Number a{1};
    Number b{5};
    Number c{10};

    std::cout << std::boolalpha;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= c: " << (a <= c) << std::endl;
    std::cout << "a >= c: " << (a >= c) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << "Current count of Numbers: " << Number::get_count() << std::endl;

    return 0;
}