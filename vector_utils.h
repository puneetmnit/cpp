#include <vector>

template<typename T>
struct vec_type;

template<typename T>
struct vec_type<std::vector<T>> {
    using type = T;
};
    
template<typename T>
struct vec_type<std::vector<std::vector<T>>> {
    using type = typename vec_type<std::vector<T>>::type;
};


template<typename T>
auto flatten(const std::vector<T>& src) {
    return src;
}

template<typename T>
auto flatten(const std::vector<std::vector<T>>& src) {
    std::vector<typename vec_type<std::vector<T>>::type> dest;
    for (const auto& v : src) {
        const auto& x = flatten(v);
        dest.insert(dest.end(), x.cbegin(), x.cend());
    }
    return dest;
}
                      
    
