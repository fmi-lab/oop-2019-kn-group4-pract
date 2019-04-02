#pragma once
#include <cassert>
template<class T, class Y>
class Map
{
	Pair<T, Y> * pairs;
	size_t size, capacity;
public:
	Map() { this->pairs = nullptr; }
	Map(size_t _capacity) {
		this->capacity = _capacity;
		this->pairs = new Pair<T, Y>[this->capacity];
		this->size = 0;
	}
	const Y& findByKey(const T & key) const {
		for (size_t i = 0; i < this->size; i++) {
			if (this->pairs[i].first == key) {
				return this->pairs[i].second;
			}
		}

		cerr << "Key not found" << endl;
		assert(false);
	}
	Y& operator[](const T & key) {
		for (size_t i = 0; i < this->size; i++) {
			if (this->pairs[i].first == key) {
				return this->pairs[i].second;
			}
		}
	}
	const Y& operator[](const T & key) const {
		for (size_t i = 0; i < this->size; i++) {
			if (this->pairs[i].first == key) {
				return this->pairs[i].second;
			}
		}
	}
};
