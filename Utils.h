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

} //namespace utils
