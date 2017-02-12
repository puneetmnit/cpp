//
// Created by puneet on 10/02/17.
//

//NOT thread safe

#ifndef LRUCACHE_LRUCACHE_H
#define LRUCACHE_LRUCACHE_H

#include <utility>
#include <unordered_map>
#include <list>
#include <iostream>

template <typename Key, typename Value, size_t SIZE>
class LRUCache {

public:
    using Key_t = Key;
    using Value_t = Value;
    using Object_t = std::pair<Key_t, Value_t>;

private:
    std::list<Key_t> last_used_list;
    std::unordered_map<Key_t, std::pair<Value_t, decltype(last_used_list.begin())>> main_cache;

public:
    //insert an element with an existing key, will silently over-write
    void insert(Object_t object) ;
    void remove(const Object_t& object);
    auto find(const Object_t& object);

    template<typename T>
    void show_cache(T&& os) {
        for (auto x : last_used_list) {
            os << x << " : " << main_cache[x].first << std::endl;
        }
    }

private:
    template <typename Itr>
    void remove_from_list(Itr&& itr, bool remove_from_main) {
        if (remove_from_main) main_cache.erase(*itr);
        last_used_list.erase(itr);
    }


};

template<typename Key, typename Value, size_t SIZE>
inline
void LRUCache<Key, Value, SIZE>::insert(Object_t object) {
    auto incache_element = main_cache.find(object.first);
    if (incache_element != main_cache.end()) {
        auto itr_to_remove = incache_element->second.second;
        remove_from_list(itr_to_remove, false);
    }
    else if (last_used_list.size() == SIZE) {
        main_cache.erase(object.first);
        last_used_list.pop_back();
    }

    last_used_list.push_front(object.first);

    main_cache[object.first] = make_pair(object.second, last_used_list.begin());
};

template<typename Key, typename Value, size_t SIZE>
inline
void LRUCache<Key, Value, SIZE>::remove(Object_t object) {
}

template<typename Key, typename Value, size_t SIZE>
inline
void LRUCache<Key, Value, SIZE>::find(Object_t object) {
}






#endif //LRUCACHE_LRUCACHE_H
