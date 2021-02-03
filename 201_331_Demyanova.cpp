#include "lab.h"
#include <iostream>
#include <vector>
#include <string>




int main()
{
	std::vector<bool> f = { 1 , 0, 1, 1, 0, 0 };
	std::cout << num_of_args(f) << std::endl;

	std::vector <bool> f1 = read_from_file("D:\\vector.txt");
	int size = read_from_file("D:\\vector.txt").size();
	for (int i = 0; i < size; i++) std::cout << f1[i] << std::endl;

    std::string filePathOut("D:\\vector.txt");
    printf_s("Writing vector to: %s\n", filePathOut.c_str());
    bool result = write_to_file(filePathOut, f);
    printf_s("Write result: %d (%s)\n", result, result ? "success" : "error");

    std::string fTable = table(f);
    printf_s("Table:\n%s\n", fTable.c_str());

    printf_s("%s\n", func_sdnf(f).c_str());
    printf_s("%s\n", func_sknf(f).c_str());



       


    return 0;
}