#pragma once
#include <string>
#include <iostream>

class file {
private:
	int x_version; // x64/x32
	int size;
	int index;
public:
	int get_x();
	int get_size();
	int get_index();
	
	void change_x(int x);
	void change_size(int sz);
	void change_index(int in);
}; 
 
class dir {
private:
	file* files;
	file* copy;
	int next_ind = 0;
	int new_ind = 1;
public:
	void add_file(file f);
	void del_file(int index);
	void del_all();
	void get_file_to_screen(int index);
	void print_all();
}; 
 
void menu();