#pragma once
#include "file.h"

template <typename t> class My_ptr{
private:
	t* ptr;
	int* count;
public:
	My_ptr(t* ptr) {
		this->ptr = ptr;
		count = new int;
		*count = 1;
	}
	My_ptr(My_ptr& other) : ptr(other.ptr), count(other.count) {
		*count += 1;
	}
	~My_ptr() {
		*count -= 1;
		if (*count == 0) {
			delete ptr;
			delete count;
		}
	}
	t* operator->() {
		return ptr;
	}
	t& operator*() {
		return *ptr;
	}
	My_ptr<t>& operator=(My_ptr& other) {
		*count -= 1;
		if (*count == 0) {
			delete ptr;
			delete count;
		}
		ptr = other.ptr;
		count = other.count;
		*count += 1;
		return *this;
	}
};