#include "Mypointer.h"

template <typename t> My_ptr<typename t>::My_ptr(My_ptr& other) : ptr(other.ptr), count(other.count) {
	*count++;
}
template <typename t> My_ptr<typename t>::~My_ptr() {
	*count--;
	if (*count == 0) {
		delete ptr;
		delete count;
	}
}
template <typename t> t* My_ptr<typename t>::operator->() {
	return ptr;
}
template <typename t> t& My_ptr<typename t>::operator*() {
	return *ptr;
}
template <typename t> My_ptr<typename t>& My_ptr<typename t>::operator=(My_ptr& other) {
	*count--;
	if (*count == 0) {
		delete ptr;
		delete count;
	}
	ptr = other.ptr;
	count = other.count;
	*count++;
}