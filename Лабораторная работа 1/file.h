#pragma once
#include <string>
#include <iostream>

class file {
private:
	int x_version; // x64/x32
	int size;
	int index;
public:
	int get_x() const;
	int get_size() const;
	int get_index() const;
	
	void change_x(const int &x);
	void change_size(const int &sz);
	void change_index(const int &in);
}; 