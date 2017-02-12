#include "LRUCache.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
    LRUCache<int, string, 3> mycache;
    mycache.insert(make_pair(1, "pa"));
    mycache.insert(make_pair(2, "pu"));
    mycache.insert(make_pair(3, "vd"));
    mycache.show_cache(std::cout);

    mycache.insert(make_pair(4, "hy"));
    mycache.show_cache(std::cout);

    mycache.insert(make_pair(3, "xy"));
    mycache.show_cache(cout);
}