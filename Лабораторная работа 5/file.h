#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <cstddef>

typedef size_t size_t_t;

class x_version {
private:
	int ver;
public:
	int get_ver() const;
	void change_ver(const int&);
};
class options {
private:
	bool issystem;
	bool ishidden;
public:
	bool get_sys() const;
	bool get_hid() const;
	void change_sys(const bool&);
	void change_hid(const bool&);
};
class file {
private:
	x_version* x;
	size_t_t size;
	size_t_t index;
	options opt;
	std::string name;
public:
	size_t_t get_x() const;
	size_t_t get_size() const;
	size_t_t get_index() const;
	bool get_sys() const;
	bool get_hid() const;
	std::string get_name() const;
	void change_x(x_version*);
	void change_size(const size_t_t&);
	void change_index(const size_t_t&);
	void change_sys(const bool&);
	void change_hid(const bool&);
	void change_name(const std::string&);
	file();
	file(const file&);
	file(x_version*, const size_t_t&, const size_t_t&, const bool&, const bool&, const std::string&);
	~file();
};