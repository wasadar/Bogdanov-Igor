#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream> 
#include <regex>

std::string get_str_from_user();
int** read_data_from_file(std::string name);
void print_data_to_file(int** data, std::string name);
int* find_max(int** data);
int get_elem_by_ind(int** data, int ind1, int ind2);
void get_data_to_screen(int** data);
void get_data_to_screen(int* data);
void menu();
void clean_data(int** data);