#include "set.h"

#include <iostream>

int main()
{
    Set s1;
    Set s2;

    s1.add(10);
    s1.add(20);
    s1.add(10);

    s2.add(20);
    s2.add(30);

    Set s3 = s2.unionWith(s1);
    Set s4 = s2.intersectionWith(s1);

    std::cout << "Union of s1 and s2: ";
    for (int element : s3.getElements())
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Intersection of s1 and s2: ";
    for (int element : s4.getElements())
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}