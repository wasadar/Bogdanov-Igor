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
bool file::get_sys() const {
	return is_system;
}
bool file::get_hid() const {
	return is_hidden;
}
std::string file::get_name() const {
	return name;
}
void file::change_x(const int &x) {
	x_version = x;
}
void file::change_size(const int& sz) {
	size = sz;
}
void file::change_index(const int &in) {
	index = in;
}
void file::change_sys(const bool &sys) {
	is_system = sys;
}
void file::change_hid(const bool &hid) {
	is_hidden = hid;
}
void file::change_name(const std::string &nm) {
	name = nm;
}
file::file() {
	x_version = 32;
	size = 100;
	index = 0;
	is_system = false;
	is_hidden = false;
	name = "file";
	std::cout << "Файл создан при помощи конструктора поумолчанию." << "\n";
}
file::file(const file &f) {
	x_version = f.get_x();
	size = f.get_size();
	index = f.get_index();
	is_system = f.get_sys();
	is_hidden = f.get_hid();
	name = f.get_name();
}
file::file(const int &ver, const int &sz, const int &ind, const bool &sys, const bool &hid, const std::string &nm) {
	x_version = ver;
	size = sz;
	index = ind;
	is_system = sys;
	is_hidden = hid;
	name = nm;
	std::cout << "Файл создан при помощи конструктора с аргументами." << "\n";
}
file::~file() {
	std::cout << "Файл уничтожен при помощи деструктора поумолчанию." << "\n";
} 