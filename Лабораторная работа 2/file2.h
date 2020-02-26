#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

class file {
private:
	int x_version; // x64/x32
	int size;
	int index;
	bool is_system;
	bool is_hidden;
	const char* name;
public:
	int get_x() const;
	int get_size() const;
	int get_index() const;
	bool get_sys() const;
	bool get_hid() const;
	const char* get_name() const;
	void change_x(const int&);
	void change_size(const int&);
	void change_index(const int&);
	void change_sys(const bool&);
	void change_hid(const bool&);
	void change_name(const char*);
	file();
	file(const file&);
	file(const int&, const int&, const int&, const bool&, const bool&, const char*);
	~file();
}; 