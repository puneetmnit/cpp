#include "macros.h"

namespace type_utils {

//helper function to print type of given Ts...
template<class Stream, typename ...T>
__MAYBE_UNUSED__
Stream& print_type (Stream& os, T&&... ) {
    os << __PRETTY_FUNCTION__ << "\n";
    return os;
}

template<class Stream, typename ...T>
__MAYBE_UNUSED__
Stream& print_type (Stream& os) {
    os << __PRETTY_FUNCTION__ << "\n";
    return os;
}

/** 
  * metafunction to transform a Type (or type-list) to another type (or type-list) after applying the provided MetaFunction.
  *
  * something like what std::transform do to values
  */
template<template<class...>typename MetaF, typename T>
struct transform {
    using type = typename MetaF<T>::type;
};

template<template<class...>typename MetaF, template<class...> typename TypeCont, typename ...Types>
struct transform<MetaF, TypeCont<Types...>> {
    using type = TypeCont<typename MetaF<Types>::type...>;
};

template<template<class...>typename MetaF, typename TypeCont>
using transform_t = typename transform<MetaF, TypeCont>::type;


} //namespace type_utils
