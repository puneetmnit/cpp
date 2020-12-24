#include "macros.h"

namespace type_utils {

//helper function to print type of given Ts...
template<class Stream, typename ...T>
#ifdef CPP17
[[maybe_unused]]
#endif
Stream& print_type (Stream& os, T&&... ) {
    os << __PRETTY_FUNCTION__ << "\n";
    return os;
}

template<class Stream, typename ...T>
#ifdef CPP17
[[maybe_unused]]
#endif
Stream& print_type (Stream& os) {
    os << __PRETTY_FUNCTION__ << "\n";
    return os;
}

} //namespace type_utils
