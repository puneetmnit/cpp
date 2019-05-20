#include <vector>
namespace utils {

/** gets the underlying type in a series of nested vectors
*/
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

/** flatten out a vector of vector of vector of ... T to a vector<T>
*/
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
                      
} //namespace utils    

if #UNIT_TEST
#include <iostream>
#include <type_traits>
int main() {
    //vector<vector<int>> v { {9,10}, {11} } ;
    //vector<vector<vector<int>>> v { { {1,2,3}, {4,5,6}, {7,8} }, { {9,10}, {11} } };
    vector<vector<vector<vector<int>>>> v { { { {1,2,3}, {4,5,6}, {7,8} }, { {9,10}, {11} } }, { { {1,2,3}, {4,5,6}, {7,8} }, { {9,10}, {11} } } };
    static_assert(is_same<int, vec_type<decltype(v)>::type>::value, "not same");
    auto v2 = flatten(v);
    for (const auto& i : v2) std::cout << i << ", ";
    }
#endif
