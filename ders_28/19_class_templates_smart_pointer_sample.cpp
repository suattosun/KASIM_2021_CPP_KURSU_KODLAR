#include <iostream>
#include<string>

using namespace std;
/*
templates:
	class templates:
		a simple sample for smart pointer class

*/

template<typename T>
class UniquePtr {
public:
	UniquePtr(T* p) : mp(p) {}

	// move ctor
	UniquePtr(UniquePtr&& other) : mp{ other.mp } {
		other.mp = nullptr;
	}

	UniquePtr(const UniquePtr&) = delete;				// delete copy ctor
	UniquePtr& operator=(const UniquePtr&) = delete;	// delete copy assignment

	// whichever is not called from following functions, compiler is not going to write its codes
	void reset() {
		delete mp;
		mp = nullptr;
	}

	T& operator*() {
		return *mp;
	}

	T* operator->() {
		return mp;
	}
private:
	T* mp{ nullptr };
};


