#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include <queue>
#include <stack>

template <typename T>
class fifo {
	
	std::queue<T> s;
	
public:

	void put(const T& val) {
		s.push(val);
	}
	
	T get() {
		T val = s.front();
		s.pop();
		return val;
	}
	
	bool empty () const {
		return s.empty();
	}
};


template <typename T>
class lifo {
	
	std::stack<T> s;
	
public:
	
	void put(const T& val) {
		s.push(val);
	}
	
	T get() {
		T val = s.top();
		s.pop();
		return val;
	}
	
	bool empty() const {
		return s.empty();
	}
};

#endif