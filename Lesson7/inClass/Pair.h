#pragma once
template<class T, class Y>
struct Pair
{
	T first;
	Y second;
public:
	Pair() {}
	Pair(const T & _first, const Y & _second) {
		this->first = _first;
		this->second = _second;
	}
	bool operator==(const Pair & other) {
		return this->first == other.first && this->second = other.second;
	}
};
