/**@brief some generic helper functions and structs 
*/

namespace utils {

namespace detail {
    template<typename Stream, typename Tuple, size_t ...I>
    void print_tup(Stream& os, Tuple&& tup, std::index_sequence<I...>) {
        (void)std::initializer_list<int>{(os << std::get<I>(tup) << (I==sizeof...(I)-1?"": ","), 0)...} ;
    }
    
    template<typename F, typename Tuple, size_t ...I>
    auto tuple_eval(F&& f, const Tuple& t, std::index_sequence<I...>) {
        return std::make_tuple(f(std::get<I>(t))... );
    }

}  //namespace detail
    
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

    

} //namespace utils
