/**@brief some generic helper functions and structs 
*/

namespace utils {

//helper function to print type of give T
template<class Stream, typename ...T>
void print_type (Stream&& os, T&&... ) {
    os << __PRETTY_FUNCTION__ << "\n";
}

template<class Stream, typename ...T>
void print_type (Stream&& os) {
    os << __PRETTY_FUNCTION__ << "\n";
}

//print tuple
namespace detail {
    template<typename Stream, typename Tuple, size_t ...I>
    void print_tup(Stream& os, Tuple&& tup, std::index_sequence<I...>) {
        (void)std::initializer_list<int>{(os << std::get<I>(tup) << (I==sizeof...(I)-1?"": ","), 0)...} ;
    }
}   //namespace detail

template<typename Stream, typename ...Args>
auto& operator<<(Stream& os, const std::tuple<Args...>& tup) {
    os << "(";
    print_tup(os, tup, std::make_index_sequence<sizeof...(Args)>());
    os << ")";
    return os;
};

} //namespace utils
