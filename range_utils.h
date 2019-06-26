#pragma once

#include <numeric>  //inner_product
#include <utility>  //pair

/** Zip two ranges, just like python zip function
* Fill the range starting with OutIt out
* @param InputIt1 start1, end1 : first range
* @param InputIt2 start2 : start of second range. It must be at-least as big as the first range. If not, the result is undefined.
* @param OutIt out : start of destination range.  It must be at-least as big as the first range. If not, the result is undefined.
* returns : void
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

#ifdef __TEST_ZIP__
#include <vector>
#include <list>
#include <set>
#include <iterator> //back_inserter

template<typename T, typename U>
ostream& operator<<(ostream& os, const std::pair<T, U> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

int main() {
    std::vector<int> v1 {1, 2, 3, 4};
    std::set<std::string> v2 {"asf", "wer", "vs", "easd"};
    std::list<std::pair<decltype(v1)::value_type, decltype(v2)::value_type>> x;
    zip(v1.begin(), v1.end(), v2.begin(), std::back_inserter(x));
   
    for (const auto& a : x) {
        cout << a << ", ";
    }
}
#endif
