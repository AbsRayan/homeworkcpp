#include "TypeList.h"
#include <type_traits>

using MyList = TypeList<int, double, char>;
using EmptyList = TypeList<>;

static_assert(MyList::size == 3, "MyList should contain 3 types");
static_assert(EmptyList::size == 0, "EmptyList should contain 0 types");
static_assert(std::is_same_v<PushFront<float, MyList>::type, TypeList<float, int, double, char>>, "PushFront should add float to the front of MyList");
static_assert(std::is_same_v<PushBack<float, MyList>::type, TypeList<int, double, char, float>>, "PushBack should add float to the back of MyList");

int main()
{
    return 0;
}