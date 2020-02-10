#pragma once
#include <string>
#include <iostream>

class file {
private:
	std::string name;
	std::string file_extension;
	int size;
	int index;
public:
	std::string get_name() {
		return name;
	}
	std::string get_extension() {
		return file_extension;
	}
	std::string get_full_name() {
		return name + "." + file_extension;
	}
	int get_size() {
		return size;
	}
	int get_index() {
		return index;
	}
	void change_name(std::string str) {
		name = str;
	}
	void change_size(int sz) {
		size = sz;
	}
	void change_extension(std::string ex) {
		file_extension = ex;
	}
	void change_index(int in) {
		index = in;
	}
}; 
 
class dir {
private:
	file files[100];
	int next_ind = 0;
public:
	void add_file(file f) {
		files[next_ind] = f;
		next_ind++;
	}
	void del_file(int index) {
		for (int i = index; i < next_ind; i++) {
			files[i] = files[i + 1];
		}
		next_ind--;
	}
	void get_file_to_screen(int index) {
		std::cout << files[index].get_full_name() << " " << files[index].get_size() << "\n";
	}
	void print_all() {
		for (int i = 0; i < next_ind; i++) {
			std::cout << i << " ";
			get_file_to_screen(i);
		}
	}
	dir() {

	}
}; 
 
void menu();