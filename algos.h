#include <numeric>  //inner_product
#include <utility>  //make_pair

namespace algos {

/** Zip two ranges, similar to python's zip
* returns a new range of pair
* typical STL algos' iterators requirements
*/
template<typename InputIt1, typename InputIt2, typename OutIt>
void zip(InputIt1 start1, InputIt1 end1, InputIt2 start2, OutIt out)  {
    std::inner_product(start1, end1, start2, out, 
    [](auto& x, const auto& y){
        *x++ = y;
        return x;
    }, 
    [](const auto&x, const auto& y){
        return make_pair(x, y);
    }
    );
}

#ifdef __TEST_ALGOS_ZIP__
#include <vector>
#include <set>
#include <string>
#include <iterator>

int main() {
    std::vector<int> v1 {1, 2, 3, 4};
    std::set<string> v2 {"asf", "wer", "vs", "easd"};
    
    std::vector<std::pair<decltype(v1)::value_type, decltype(v2)::value_type>> x;
    zip(v1.begin(), v1.end(), v2.begin(), std::back_inserter(x));
}
#endif
} //namespace algos
