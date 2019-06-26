#pragma once
namespace tmp {

/** fibonnacci number
*/
template<int N> struct fib { 
    constexpr static int value = fib<N-1>::value+fib<N-2>::value ;
};

template<> struct fib<1> { constexpr static int value = 1; };
template<> struct fib<2> { constexpr static int value = 2; };
=========

/** is_fibonnaci
TODO: find a better impl, as it calculates fibonnacci numbers till 45 in advance, and has to 
be manually limited to that.
*/
template<int N, int i>
struct is_fib_impl {
    constexpr static int f = fib<i>::value;
    constexpr static bool value = (N == f) ? true : (N < f) ? false : is_fib_impl<N, i+1>::value;
};

// end condition
template<int N>
struct is_fib_impl<N, 46> { constexpr static bool value = false; };

template<int N> struct is_fib { 
    constexpr static bool value = is_fib_impl<N, 1>::value;
};



#ifdef __TEST_TMP_H__
int main() {
    //1,2,3,5,8,13,21,34,55,89
    
    static_assert(is_fib<1>::value, "is not fib");
    static_assert(is_fib<2>::value, "is not fib");
    static_assert(is_fib<3>::value, "is not fib");
    static_assert(!is_fib<4>::value, "is not fib");
    static_assert(is_fib<8>::value, "is not fib");
    static_assert(!is_fib<33>::value, "is fib");
    static_assert(is_fib<89>::value, "is not fib");
    
}
#endif
                        
} // namespace tmp
