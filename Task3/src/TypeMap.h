#pragma once

#include <tuple>
#include <optional>
#include <stdexcept>

#include "Task2/src/TypeList.h"

template <typename... Types>
struct IsUnique : std::true_type {};

template <typename T>
struct IsUnique<T> : std::true_type {};

template <typename T, typename... Rest>
struct IsUnique<T, Rest...>
    : std::bool_constant<
          !Contains<T, TypeList<Rest...>>::value &&
          IsUnique<Rest...>::value> {};


template <typename... Types>
class TypeMap
{
private:
    static_assert(IsUnique<Types...>::value, "TypeMap keys must be unique");

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
        static_assert(Contains<T, TList>::value, "Type not in TypeMap");
        return std::get<IndexOf<T, TList>::value>(data).has_value();
    }

    template <typename T>
    void RemoveValue()
    {
        static_assert(Contains<T, TList>::value, "Type not in TypeMsp");
        std::get<IndexOf<T, TList>::value>(data) = std::nullopt;
    }
};

