#include "file.h"
 
size_t_t file::get_x() const {
	return x->get_ver();
}
size_t_t file::get_size() const {
	return size;
}
size_t_t file::get_index() const {
	return index;
}
bool file::get_sys() const {
	return opt.get_sys();
}
bool file::get_hid() const {
	return opt.get_hid();
}
std::string file::get_name() const {
	return name;
}
void file::change_x(x_version* new_x) {
	x = new_x;
}
void file::change_size(const size_t_t& sz) {
	size = sz;
}
void file::change_index(const size_t_t&in) {
	index = in;
}
void file::change_sys(const bool &sys) {
	opt.change_sys(sys);
}
void file::change_hid(const bool &hid) {
	opt.change_hid(hid);
}
void file::change_name(const std::string &nm) {
	name = nm;
}
file::file() {
	x = 0;
	size = 100;
	index = 0;
	opt.change_hid(false);
	opt.change_sys(false);
	name = "File";
	std::cout << "Файл создан при помощи конструктора поумолчанию." << "\n";
}
file::file(const file &f) {
	x = f.x;
	size = f.size;
	index = f.index;
	opt = f.opt;
	name = f.name;
}
file::file(x_version* ver, const size_t_t &sz, const size_t_t &ind, const bool &sys, const bool &hid, const std::string &nm) {
	x = ver;
	size = sz;
	index = ind;
	opt.change_sys(sys);
	opt.change_hid(hid);
	name = nm;
	std::cout << "Файл создан при помощи конструктора с аргументами." << "\n";
}
file::~file() {
	std::cout << "Файл уничтожен при помощи деструктора поумолчанию." << "\n";
} 
int x_version::get_ver() const {
	return ver;
}
void x_version::change_ver(const int& x) {
	ver = x;
}
bool options::get_sys() const {
	return issystem;
}
bool options::get_hid() const {
	return ishidden;
}
void options::change_sys(const bool& sys) {
	issystem = sys;
}
void options::change_hid(const bool& hid) {
	ishidden = hid;
}