#include "TypeList.h"
#include <type_traits>
#include <iostream>

using MyList = TypeList<int, double, char>;
using EmptyList = TypeList<>;

static_assert(MyList::size == 3);
static_assert(EmptyList::size == 0);

static_assert(std::is_same_v<PushFront<bool, MyList>::type, TypeList<bool, int, double, char>>);
static_assert(std::is_same_v<PushBack<bool, MyList>::type, TypeList<int, double, char, bool>>);

static_assert(Contains<int, MyList>::value);
static_assert(Contains<double, MyList>::value);
static_assert(!Contains<float, MyList>::value);

static_assert(std::is_same_v<TypeAt<0, MyList>::type, int>);
static_assert(std::is_same_v<TypeAt<1, MyList>::type, double>);
static_assert(std::is_same_v<TypeAt<2, MyList>::type, char>);

static_assert(IndexOf<int, MyList>::value == 0);
static_assert(IndexOf<double, MyList>::value == 1);
static_assert(IndexOf<char, MyList>::value == 2);

// should fail to compile
// using Bad1 = TypeAt<3, MyList>::type;              
// static_assert(IndexOf<float, MyList>::value == 0);

int main()
{
    std::cout << "All static assertions passed!" << std::endl;
    return 0;
}