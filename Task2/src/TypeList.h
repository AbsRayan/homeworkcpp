#pragma once

#include <cstddef>
#include <type_traits>

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

template <typename T, typename List>
struct Contains;

template <typename T>
struct Contains<T, TypeList<>>
{
    static constexpr bool value = false;
};

template <typename T, typename Head, typename... Tail>
struct Contains<T, TypeList<Head, Tail...>>
{
    static constexpr bool value = std::is_same_v<T, Head> || Contains<T, TypeList<Tail...>>::value;
};

template <std::size_t Index, typename List>
struct TypeAt;

template <typename Head, typename... Tail>
struct TypeAt<0, TypeList<Head, Tail...>>
{
    using type = Head;
};

template <std::size_t Index>
struct TypeAt<Index, TypeList<>>
{
    static_assert(Index != Index, "TypeAt: index out of range");
};

template <std::size_t Index, typename Head, typename... Tail>
struct TypeAt<Index, TypeList<Head, Tail...>>
{
    using type = typename TypeAt<Index - 1, TypeList<Tail...>>::type;
};

template <typename T, typename List>
struct IndexOf;

template <typename T>
struct IndexOf<T, TypeList<>>
{
    static_assert(!std::is_same_v<T, T>, "IndexOf: type not found in TypeList");
};


template <typename T, typename... Tail>
struct IndexOf<T, TypeList<T, Tail...>>
{
    static constexpr std::size_t value = 0;
};

template <typename T, typename Head, typename... Tail>
struct IndexOf<T, TypeList<Head, Tail...>>
{
    static constexpr std::size_t value = 1 + IndexOf<T, TypeList<Tail...>>::value;
};