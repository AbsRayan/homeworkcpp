#pragma once

#include <tuple>
#include <optional>
#include <stdexcept>

#include "Task2/src/TypeList.h"

template <typename... Types>
class TypeMap
{
private:
    using TList = TypeList<Types...>;
    std::tuple<std::optional<Types>...> data;
public:
    template <typename T>
    void AddValue(const T& value) 
    {
        static_assert(Contains<T, TList>::value, "Type not in TypeMap");
        std::get<IndexOf<T, TList>::value>(data) = value;
    }

    template <typename T>
    T& GetValue() 
    {
        static_assert(Contains<T, TList>::value, "Type not in TypeMap");
        auto& optValue = std::get<IndexOf<T, TList>::value>(data);
        if (!optValue.has_value()) 
        {
            throw std::runtime_error("value is not set");
        }

        return optValue.value();
    }

    template <typename T>
    bool HasValue() const
    {
        static_assert(Contains<T, TList>::value, "Type not in TypeMsp");
        return std::get<IndexOf<T, TList>::value>(data).has_value();
    }

    template <typename T>
    void RemoveValue()
    {
        static_assert(Contains<T, TList>::value, "Type not in TypeMsp");
        std::get<IndexOf<T, TList>::value>(data) = std::nullopt;
    }
};

