#include "lab.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int num_of_args(std::vector<bool> f)
{
	int len = f.size();
	int n;
	while (len / 2 > 1) {
		len /= 2;
		n = len;
	}
	return n;
}

std::vector<bool> read_from_file(std::string file_name)
{
	
	std::ifstream file;
	std::vector <bool> output;
	char buff[16];
	file.open(file_name);
	file >> buff;
	output.push_back(buff);
	file.close();
	return output;
}

bool write_to_file(std::string file_name, std::vector<bool> f)
{
	std::ofstream file;
	file.open(file_name);
	if (!file.is_open) {
		return false;
	}
	for (auto data : f) {
		file << data << ' ';
	}
	file.close();
	return true;
}

std::string table(std::vector<bool> f)
{
	std::string table;

	int argNum = num_of_args(f);

	// print table header
	for (int i = 1; i <= argNum; i++)
	{
		table += "x" + std::to_string(i) + "\t";
	}

	return table;
}
/*std::string func_sdnf(std::vector<bool> f)
{
    return string();
}

std::string func_sknf(std::vector<bool> f)
{
    return string();
}

std::string func_Zhegalkin(std::vector<bool> f)
{
    return string();
}*/
