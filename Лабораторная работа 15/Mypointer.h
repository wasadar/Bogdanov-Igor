#pragma once
#include "file.h"

template <typename t> class My_ptr{
private:
	t* ptr;
	int* count;
public:
	My_ptr(t* obj) : ptr(obj), count(new int = 1) {};
	My_ptr(My_ptr& other);
	~My_ptr();
	t* operator->();
	t& operator*();
	My_ptr& operator=(My_ptr& other);
};