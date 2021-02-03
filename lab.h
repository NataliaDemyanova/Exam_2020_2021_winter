#pragma once
#include <vector>
#include <string>//библиотека работы со строками

int num_of_args(std::vector<bool> f);
std::vector<bool> read_from_file(std::string file_name);
bool write_to_file(std::string file_name, std::vector<bool> f);
std::string table(std::vector<bool> f);
std::string func_sdnf(std::vector <bool> f);
std::string func_sknf(std::vector<bool> f);
std::string func_Zhegalkin(std::vector<bool> f);
//¬“ќ–јя „ј—“№
int roman_to_arab(std::string roman_number);
std::vector<int> func_Pascal(int k);
int func_substr_len(std::string input_str);