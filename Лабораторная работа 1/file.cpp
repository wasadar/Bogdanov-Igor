#include "file.h"
 
int file::get_x() const {
	return x_version;
}
int file::get_size() const {
	return size;
}
int file::get_index() const {
	return index;
}
void file::change_x(const int &x) {
	x_version = x;
}
void file::change_size(const int &sz) {
	size = sz;
}

void file::change_index(const int &in) {
	index = in;
}