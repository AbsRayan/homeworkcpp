#pragma once

#include <cstddef>
#include <type_traits>

template <typename... Types>
struct TypeList
{
    static constexpr std::size_t size = sizeof...(Types);
};

namespace detail 
{
    template <typename T, typename List>
    struct PushFrontImpl;

    template <typename T, typename... Types>
    struct PushFrontImpl<T, TypeList<Types...>>
    {
        using type = TypeList<T, Types...>;
    };
}

template <typename T, typename List>
struct PushFront
{
    using type = typename detail::PushFrontImpl<T, List>::type;
};

namespace detail
{
    template <typename T, typename List>
    struct PushBackImpl;

    template <typename T, typename... Types>
    struct PushBackImpl<T, TypeList<Types...>>
    {
        using type = TypeList<Types..., T>;
    };
}

template <typename T, typename List>
struct PushBack
{
    using type = typename detail::PushBackImpl<T, List>::type;
};

namespace detail
{
    template <typename T, typename List>
    struct ContainsImpl;

    template <typename T>
    struct ContainsImpl<T, TypeList<>>
    {
        static constexpr bool value = false;
    };

    template <typename T, typename Head, typename... Tail>
    struct ContainsImpl<T, TypeList<Head, Tail...>>
    {
        static constexpr bool value = std::is_same_v<T, Head> || ContainsImpl<T, TypeList<Tail...>>::value;
    };
}

template <typename T, typename List>
struct Contains
{
    static constexpr bool value = detail::ContainsImpl<T, List>::value;
};

namespace detail
{
    template <std::size_t Index, typename List>
    struct TypeAtImpl;

    template <typename Head, typename... Tail>
    struct TypeAtImpl<0, TypeList<Head, Tail...>>
    {
        using type = Head;
    };

    template <std::size_t Index>
    struct TypeAtImpl<Index, TypeList<>>
    {
        static_assert(Index != Index, "TypeAt: index out of range");
    };

    template <std::size_t Index, typename Head, typename... Tail>
    struct TypeAtImpl<Index, TypeList<Head, Tail...>>
    {
        using type = typename TypeAtImpl<Index - 1, TypeList<Tail...>>::type;
    };
}

template <std::size_t Index, typename List>
struct TypeAt
{
    using type = typename detail::TypeAtImpl<Index, List>::type;
};

namespace detail
{
    template <typename T, typename List>
    struct IndexOfImpl;

    template <typename T>
    struct IndexOfImpl<T, TypeList<>>
    {
        static_assert(!std::is_same_v<T, T>, "IndexOf: type not found in TypeList");
    };


    template <typename T, typename... Tail>
    struct IndexOfImpl<T, TypeList<T, Tail...>>
    {
        static constexpr std::size_t value = 0;
    };

    template <typename T, typename Head, typename... Tail>
    struct IndexOfImpl<T, TypeList<Head, Tail...>>
    {
        static constexpr std::size_t value = 1 + IndexOfImpl<T, TypeList<Tail...>>::value;
    };
}

template <typename T, typename List>
struct IndexOf
{
    static constexpr std::size_t value = detail::IndexOfImpl<T, List>::value;
};
