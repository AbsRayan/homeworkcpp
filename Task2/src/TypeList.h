#pragma once

#include <cstddef>

template <typename... Types>
struct TypeList
{
    static constexpr std::size_t size = sizeof...(Types);
};

template <typename T, typename List>
struct PushFront;

template <typename T, typename... Types>
struct PushFront<T, TypeList<Types...>>
{
    using type = TypeList<T, Types...>;
};

template <typename T, typename List>
struct PushBack;

template <typename T, typename... Types>
struct PushBack<T, TypeList<Types...>>
{
    using type = TypeList<Types..., T>;
};