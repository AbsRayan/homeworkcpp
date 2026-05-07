#include <iostream>
#include "Mixins.h"

int main()
{
    Number one{1};
    Number five{5};
    Number ten{10};
    Number d = one;
    Number e = std::move(five);

    std::cout << std::boolalpha;
    std::cout << "one < five: " << (one < five) << std::endl;
    std::cout << "one > five: " << (one > five) << std::endl;
    std::cout << "one <= ten: " << (one <= ten) << std::endl;
    std::cout << "one >= ten: " << (one >= ten) << std::endl;
    std::cout << "one == five: " << (one == five) << std::endl;
    std::cout << "one != five: " << (one != five) << std::endl;

    std::cout << "Current count of Numbers: " << Number::get_count() << std::endl;

    return 0;
}