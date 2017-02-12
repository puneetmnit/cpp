//
// Created by puneet on 10/02/17.
//


#ifndef LRUCACHE_LRUCACHE_H
#define LRUCACHE_LRUCACHE_H

#include <utility>
#include <unordered_map>
#include <list>
#include <iostream>

/** @brief it is a simple implementation of an LRU cache with constant time complexity.
 * This uses 'number of elements and not size' as it's bounded type
 * It uses an unordered_map and a doubly link-list to achieve the desired behavior.
 * Please note that this implementation is not thread-safe, and user is supposed to use write-locks, before
 * doing any operation (including find) on this cache
 */
template <typename Key, typename Value, size_t SIZE>
class LRUCache {

public:
    using key_type = Key;
    using mapped_type = Value;
    using value_type = std::pair<const key_type, mapped_type>;

private:
    using last_used_list_t = std::list<const key_type* const>;
    using main_cache_t = std::unordered_map<key_type, std::pair<mapped_type, typename last_used_list_t::const_iterator>> ;

    last_used_list_t last_used_list_;
    main_cache_t main_cache_;

public:
    /** @brief insert a element in cache
     * @param in object pair<key, value> to insert
     * @param out none
     */
    void insert(value_type object) ;

    /** @brief remove an entry corresponding to a given key
     * @param in key key to remove
     */
    void remove(const key_type& key);

    /** @brief find an entry corresponding to a given key
     * @param in key key
     * @param out value value
     * @return true if found, false otherwise
     */
    bool find(const key_type& key, value_type& value);

    /** @todo should be debug only
     * show the content sorted by the LRU
     */
    template<typename T>
    void show_cache(T&& os) {
        for (const auto& x : last_used_list_) {
            os << *x << " : " << main_cache_[*x].first << std::endl;
        }
    }

private:
    template <typename Itr>
    void remove_from_list(Itr&& itr, bool remove_from_main) {
        if (remove_from_main) main_cache_.erase(**itr);
        last_used_list_.erase(itr);
    }


};

template<typename Key, typename Value, size_t SIZE>
inline
void LRUCache<Key, Value, SIZE>::insert(value_type object) {
    //add new element in the main cache and at the end of list
    auto inserted = main_cache_.emplace(object.first, make_pair(object.second, last_used_list_.cend()));
    auto& incache_element = inserted.first;
    last_used_list_.push_back(&incache_element->first);

    //duplicate entry.
    //remove the previous one
    if (!inserted.second) {
        remove_from_list(incache_element->second.second, false/*remove_from_main*/);
    }

    // if size is full, kick out the one at the front (oldest) from cache
    if (last_used_list_.size() > SIZE) {
        remove_from_list(last_used_list_.cbegin(), true/*remove_from_main*/);
    }

    //update the mapped_type with correct value and iterator address
    incache_element->second.first = object.second;
    incache_element->second.second = prev(last_used_list_.cend());

};

template<typename Key, typename Value, size_t SIZE>
inline
void LRUCache<Key, Value, SIZE>::remove(const key_type& key) {
}

template<typename Key, typename Value, size_t SIZE>
inline
bool LRUCache<Key, Value, SIZE>::find(const key_type& key, value_type& value) {
}






#endif //LRUCACHE_LRUCACHE_H
