/**@brief some generic helper functions and structs 
*/

#include "macros.h"
#include <type_traits>
#include <tuple>
#include <utility>
#include <initializer_list>

namespace utils {

namespace detail {
    template<typename Stream, typename Tuple, size_t ...I>
    void print_tup(Stream& os, Tuple&& tup, std::index_sequence<I...>) {
    #ifdef CPP17
    // c++17 fold expressions
        os << ... << (os << (I>0 ? ',' : ''), std::get<I>(std::forward<Tuple>(tup))));
    #else
        (void)std::initializer_list<int>{(os << std::get<I>(std::forward<Tuple>(tup)) << (I==sizeof...(I)-1?"": ","), 0)...} ;
    #endif
    }
    
    template<typename F, typename Tuple, size_t ...I>
    auto tuple_eval(F&& f, const Tuple& t, std::index_sequence<I...>) {
        return std::make_tuple(f(std::get<I>(t))... );
    }
    
    template<typename Tuple, size_t ...Is>
    auto reverse_tuple(Tuple&& tup, std::index_sequence<Is...>) {
        return std::forward_as_tuple(std::get<sizeof...(Is)-Is-1>(std::forward<Tuple>(tup)...);
    }

}  //namespace detail
    
    
//print tuple
template<typename Stream, typename ...Args>
auto& operator<<(Stream& os, const std::tuple<Args...>& tup) {
    os << "(";
    detail::print_tup(os, tup, std::make_index_sequence<sizeof...(Args)>());
    os << ")";
    return os;
}
    
template<typename ...T>
struct is_tuple : std::false_type {};

template<typename ...T>
struct is_tuple<std::tuple<T...>> : std::true_type{};
    
template<typename ...T>
constexpr auto is_tuple_v = is_tuple<T...>::value;

//apply f to each element of t and return a tuple of results
template<typename F, typename ...Args>
auto eval(F&& f, const std::tuple<Args...>& t) {
    return detail::tuple_eval(std::forward<F>(f), t, std::make_index_sequence<sizeof...(Args)>());
}

//apply f to each element of t and return a tuple of results
template<typename F, typename ...Args, 
    class = std::enable_if_t<!is_tuple<std::decay_t<Args>...>::value>>
auto eval(F&& f, Args&& ...args) {
    return eval(std::forward<F>(f), std::make_tuple(std::forward<Args>(args)...));
}

template<template Tuple, typename = std::enable_if_t<is_tuple_v<std:decay_t<Tuple>>>>
auto reverse_tuple(Tuple&& tup)
{
    return detail::reverse_tuple(std::forward<Tuple>(tup), std::make_index_sequence(std::tuple_size<std::decay_t<Tuple>>));
}
                             

    

} //namespace utils
