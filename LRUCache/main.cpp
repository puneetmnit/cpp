#include "LRUCache.h"
#include <iostream>
#include <string>

using namespace std;

/* @todo use gtest
 */

void test_insert() {
    cout << endl << "======" << endl;
    cout << __PRETTY_FUNCTION__ << endl;
    cout << "======" << endl;
    LRU::LRUCache<int, string, 5> mycache;
    mycache.insert(make_pair(1, "pa"));
    mycache.insert(make_pair(2, "pu"));
    mycache.insert(make_pair(3, "vd"));
    mycache.insert(make_pair(4, "hy"));
    mycache.insert(make_pair(5, "dm"));
    cout << "Initial values: \n";
    mycache.show_cache(std::cout);

    cout << "inserting 6->six: \n";
    mycache.insert(make_pair(6, "six"));
    mycache.show_cache(std::cout);

    cout << "modifying 3->xy: \n";
    mycache.insert(make_pair(3, "xy"));
    mycache.show_cache(cout);
}

void test_remove() {
    cout << endl << "======" << endl;
    cout << __PRETTY_FUNCTION__ << endl;
    cout << "======" << endl;
    LRU::LRUCache<int, string, 5> mycache;
    mycache.insert(make_pair(1, "pa"));
    mycache.insert(make_pair(2, "pu"));
    mycache.insert(make_pair(3, "vd"));
    mycache.insert(make_pair(4, "hy"));
    mycache.insert(make_pair(5, "dm"));
    cout << "Initial values: \n";
    mycache.show_cache(std::cout);

    cout << "removing 6->six: \n";
    mycache.remove(6);
    mycache.show_cache(std::cout);

    cout << "removing 3: \n";
    mycache.remove(3);
    mycache.show_cache(cout);

    cout << "inserting 3->three: \n";
    mycache.insert(make_pair(3, "three"));
    mycache.show_cache(std::cout);
}

void test_find() {
    cout << endl << "======" << endl;
    cout << __PRETTY_FUNCTION__ << endl;
    cout << "======" << endl;
    LRU::LRUCache<int, string, 5> mycache;
    mycache.insert(make_pair(1, "pa"));
    mycache.insert(make_pair(2, "pu"));
    mycache.insert(make_pair(3, "vd"));
    mycache.insert(make_pair(4, "hy"));
    mycache.insert(make_pair(5, "dm"));
    cout << "Initial values: \n";
    mycache.show_cache(std::cout);

    decltype(mycache)::value_type value;
    if (mycache.find(2, value)) {
        cout << "found: " << value.first << ":" << value.second << endl;
    }
    else
        cout << "2 not found" << endl;
    mycache.show_cache(std::cout);

    if (mycache.find(6, value)) {
        cout << "found: " << value.first << ":" << value.second << endl;
    }
    else
        cout << "6 not found" << endl;
    mycache.show_cache(cout);

    if (mycache.find(2, value)) {
        cout << "found: " << value.first << ":" << value.second << endl;
    }
    else
        cout << "2 not found" << endl;
    mycache.show_cache(cout);

}

int main() {
    test_insert();
    test_remove();
    test_find();
    return 0;
}