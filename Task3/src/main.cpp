#include <iostream>
#include <string>

#include "TypeMap.h"

int main()
{
    TypeMap<int, std::string, double> map;

    map.AddValue<int>(42);
    map.AddValue<std::string>("hello");

    std::cout << map.HasValue<int>() << '\n';
    std::cout << map.GetValue<int>() << '\n';

    map.RemoveValue<int>();

    std::cout << map.HasValue<int>() << '\n';

    try 
    {
        std::cout << map.GetValue<int>() << '\n';
    }
    catch (const std::runtime_error& e) 
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}