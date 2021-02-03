#include "lab.h"
#include <iostream>//библиотека ввода-вывода
#include <vector>
#include <string>//библиотека работы со строками





int main()
{
	std::vector<bool> f = { 1 , 0, 1, 1, 0, 0 };
	std::cout << num_of_args(f) << std::endl;

	std::vector <bool> f1 = read_from_file("D:\\vector.txt");
	int size = read_from_file("D:\\vector.txt").size();
	for (int i = 0; i < size; i++) std::cout << f1[i] << std::endl;

    if (write_to_file("D:\\vector_w.txt", f));

    std::string fTable = table(f);
    printf_s("Table:\n%s\n", fTable.c_str());

    printf_s("%s\n", func_sdnf(f).c_str());
    printf_s("%s\n", func_sknf(f).c_str());

    //ВТОРАЯ ЧАСТЬ

    std::string roman("MCMLXXXIV");
    printf_s("Roman (%s) to arabic: %d\n", roman.c_str(), roman_to_arab(roman));

	setlocale(LC_ALL, "rus");
	std::cout << "5 строка треугольника Паскаля: ";
	std::vector<int> z = func_Pascal(4);
	for (int i = 0; i < 6; i++)
		std::cout << z[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Строка 'bbbbb': " << func_substr_len("bbbbb") << std::endl;
	std::cout << "Строка 'pwwkew': " << func_substr_len("pwwkew") << std::endl;

    return 0;
}