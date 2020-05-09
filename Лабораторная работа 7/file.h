#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>

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
	int type_of_file = 0;
	virtual size_t_t get_x() const;
	virtual size_t_t get_size() const;
	virtual size_t_t get_index() const;
	virtual bool get_sys() const;
	virtual bool get_hid() const;
	virtual std::string get_name() const;
	virtual void change_x(x_version*);
	virtual void change_size(const size_t_t&);
	virtual void change_index(const size_t_t&);
	virtual void change_sys(const bool&);
	virtual void change_hid(const bool&);
	virtual void change_name(const std::string&);
	virtual std::string get_info() const = 0;
	file();
	file(const file&);
	file(x_version*, const size_t_t&, const size_t_t&, const bool&, const bool&, const std::string&);
	~file();
};
class executable_file final : public file { 
private: 
	size_t_t runningtime;
public:
	virtual size_t_t get_time() const final;
	virtual void change_time(const size_t_t&) final;
	executable_file();
	executable_file(const executable_file&);
	executable_file(x_version*, const size_t_t&, const size_t_t&, const bool&, const bool&, const std::string&, const size_t_t&);
	~executable_file();
	virtual std::string get_info() const final;
};
class non_executable_file final : public file {
private:
	bool is_text;
public:
	virtual bool get_text() const final;
	virtual void change_text(const bool&) final;
	non_executable_file();
	non_executable_file(const non_executable_file&);
	non_executable_file(x_version*, const size_t_t&, const size_t_t&, const bool&, const bool&, const std::string&, const  bool&);
	~non_executable_file();
	virtual std::string get_info() const final;
};