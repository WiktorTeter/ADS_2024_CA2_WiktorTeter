#pragma once
#include "BinaryTree.h"

template <class K, class V>
class TreeMap {
private:
    BinaryTree<K> keys;
    std::unordered_map<K, V> values;

public:
    void put(K key, V value);
    bool containsKey(K key);
    V& get(K key);
    int size();
    void clear();
    bool removeKey(K key);
    V& operator[](K key);
};