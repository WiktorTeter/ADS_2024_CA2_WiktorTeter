#pragma once
#include "BinaryTree.h"
#include <unordered_map>
#include <stdexcept>

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
    BinaryTree<K> keySet();
    V& operator[](K key);
};
template <class K, class V>
void TreeMap<K, V>::put(K key, V value) {
    if (!values.count(key)) {
        keys.add(key);
    }
    values[key] = value;
}
template <class K, class V>
V& TreeMap<K, V>::get(K key) {
    if (!values.count(key)) {
        throw std::logic_error("Key not found");
    }
    return values[key];
}
template <class K, class V>
bool TreeMap<K, V>::containsKey(K key) {
    return values.count(key) > 0;
}
template <class K, class V>
int TreeMap<K, V>::size() {
    return values.size();
}
template <class K, class V>
void TreeMap<K, V>::clear() {
    keys.clear();
    values.clear();
}
template <class K, class V>
bool TreeMap<K, V>::removeKey(K key) {
	if (!values.count(key)) {
		return false;
	}
	keys.remove(key);
	values.erase(key);
	return true;
}
template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet() {
    return keys;
}
template <class K, class V>
V& TreeMap<K, V>::operator[](K key) {
    if (!values.count(key)) {
        throw std::logic_error("Key not found");
    }
    return values[key];
}