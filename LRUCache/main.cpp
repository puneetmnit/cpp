#include "LRUCache.h"
#include <iostream>
#include <string>

using namespace std;

void test_insert() {
    LRUCache<int, string, 3> mycache;
    mycache.insert(make_pair(1, "pa"));
    mycache.insert(make_pair(2, "pu"));
    mycache.insert(make_pair(3, "vd"));
    cout << "Initial values: \n";
    mycache.show_cache(std::cout);

    cout << "inserting 4->hy: \n";
    mycache.insert(make_pair(4, "hy"));
    mycache.show_cache(std::cout);

    cout << "modifying 3->xy: \n";
    mycache.insert(make_pair(3, "xy"));
    mycache.show_cache(cout);
}

int main() {
    test_insert();
    return 0;
}