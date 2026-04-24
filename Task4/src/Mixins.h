#pragma once

#include <cstddef>

template <typename Derived>
class less_than_comparable
{
    friend bool operator>(const Derived& left, const Derived& right)
    {
        return right < left;
    }

    friend bool operator<=(const Derived& left, const Derived& right)
    {
        return !(right < left);
    }

    friend bool operator>=(const Derived& left, const Derived& right)
    {
        return !(left < right);
    }

    friend bool operator==(const Derived& left, const Derived& right)
    {
        return !(left < right) && !(right < left);
    }

    friend bool operator!=(const Derived& left, const Derived& right)
    {
        return (left < right) || (right < left);
    }
};

template <typename Derived>
class counter
{
private:
    inline static std::size_t count = 0;
public:
    counter()
    {
        ++count;
    }

    counter(const counter&)
    {
        ++count;
    }

    counter(counter&&)
    {
        ++count;
    }

    ~counter()
    {
        --count;
    }

    static std::size_t get_count()
    {
        return count;
    }
};

class Number : public less_than_comparable<Number>, public counter<Number>
{
private:
    int value;
public:
    Number(int value) : value(value) {}

    bool operator<(const Number& other) const
    {
        return value < other.value;
    }
};