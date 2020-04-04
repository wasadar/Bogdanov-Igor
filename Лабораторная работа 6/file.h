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
	virtual bool get_exe() const;
	file();
	file(const file&);
	file(x_version*, const size_t_t&, const size_t_t&, const bool&, const bool&, const std::string&);
	~file();
};
class system_file final : public file {
private: 
	bool is_executable;
public:
	virtual bool get_exe() const override final;
	virtual void change_exe(const bool&) final;
	system_file();
	system_file(const system_file&);
	system_file(x_version*, const size_t_t&, const size_t_t&, const bool&, const bool&, const std::string&, const bool&);
	~system_file();
};