#include "lab.h"
#include <iostream>//библиотека ввода-вывода
#include <vector>
#include <string> //библиотека работы со строками
#include <fstream> //библиотека для считывания данных из файла и для записи в файл
#include <map> // В этот контейнер можно помещать сразу два значения
#include <set> //это контейнер, который автоматически сортирует добавляемые элементы в порядке возрастания

int num_of_args(std::vector<bool> f)
{
	int size = f.size(), n = 0; // size - длина вектора функции, n - количество аргументов функции
	while (size > 1) { //цикл, определяющий степень 2 числа
		size /= 2;
		n++;
	}
	return n;
}

std::vector<bool> read_from_file(std::string file_name)
{
	std::vector <bool> f;
	std::fstream fs;  //создание объекта при работе в С++
	std::string str;
	fs.open(file_name, std::fstream::in);  //открытие файла, режим: на чтение 
	getline(fs, str); // считывание строки с вектором

	for (int i = 0; i < str.length(); i += 2) {
		f.push_back((bool)str[i]);
		//cout << str[i] << endl;
	}

	fs.close();
	return f;
}


bool write_to_file(std::string file_name, std::vector<bool> f)
{
    std::fstream fs;  //создание объекта при работе в С++
    fs.open(file_name, std::fstream::out);  //открытие файла, режим: на запись
    if (fs.fail()) return false;

    for (int i = 0; i < f.size(); i++) fs << f[i] << " ";

    fs.close();

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

    table += "f\n";

    // цикл для всех значений функции 
    for (int i = 0; i < f.size(); i++)
    {
        // цикл для каждой строки таблицы
        for (int j = 0; j <= argNum; j++)
        {
            // если мы находимся на значении функции, просто выводит его в таблицу
            if (j == argNum)
                table += std::to_string(f.at(i));
            else
                /*
                 В основном переменная 'i' - это битовый набор строк таблицы,
                 поэтому мы маскируем ее текущим столбцом, который представляет j var,
                 чтобы получить полезную маску, нам нужно вычесть 'j' из arg num 
                 и pow 2 к ее значению,
                 например

                 если мы находимся в 3-й строке (i = 2), то для 3 аргументов строка будет равна 0 1 0,
                 чтобы получить переменные bool, нам нужно использовать битовую маску 'i'. Маска была бы
                j = 0 : 1 0 0 | 2 & mask == 0
                j = 1 : 0 1 0 | 2 & mask == 1
                j = 2 : 0 0 1 | 2 & mask == 0
                */
                table += std::to_string((bool)(i & (int)(pow(2, (argNum - j - 1))))) + "\t";
        }
        table += "\n";
    }

    return table;
}

std::string func_sdnf(std::vector<bool> f)
{
    std::string func("f_sdnf(");
    int argNum = num_of_args(f); // получить количество аргументов
    bool hasSFunc = false; // используется для обработки, если функция имеет SDNF

    // этот цикл печатает тело функции
    // f_sdnf(x1, x2, x3) = 
    for (int i = 1; i <= argNum; i++)
    {
        func += "x" + std::to_string(i);
        if (i != argNum)
            func += ", ";
    }

    // enclosure for body
    func += ") = ";

    // цикл через все значения функции
    for (int i = 0; i < f.size(); i++)
    {
        // SDNF строится только для истинных значений функции!
        if (f.at(i))
        {
            // уведомить о том, что функция действительно имеет sdnf
            hasSFunc = true;
            func += "(";

            // цикл через таблицу истинности
            for (int j = 0; j < argNum; j++)
            {
                // тот же метод получения значения для аргумента, который использовался выше
                bool arg = (bool)(i & (int)(pow(2, (argNum - j - 1))));

                // обрабатывать, если значение аргумента равно false
                if (!arg)
                    func += "'";

                // просто выводит элемент формулы
                func += "x" + std::to_string(j + 1);
                if (j != argNum - 1)
                    func += " & ";

            }

            func += ") v ";
        }
    }

    
    func.replace(func.length() - 3, 3, "");

    return func;
}

std::string func_sknf(std::vector<bool> f)
{
    std::string func("f_sknf(");
    int argNum = num_of_args(f);

    for (int i = 1; i <= argNum; i++)
    {
        func += "x" + std::to_string(i);
        if (i != argNum)
            func += ", ";
    }

    func += ") = ";

    for (int i = 0; i < f.size(); i++)
    {
        if (!f.at(i))
        {
            func += "(";

            for (int j = 0; j < argNum; j++)
            {
                bool arg = (bool)(i & (int)(pow(2, (argNum - j - 1))));

                if (arg)
                    func += "'";

                func += "x" + std::to_string(j + 1);
                if (j != argNum - 1)
                    func += " V ";
            }

            func += ") & ";
        }
    }

    func.replace(func.length() - 3, 3, "");

    return func;
}

std::string func_Zhegalkin(std::vector<bool> f)
{
    return std::string();
}

//ВТОРАЯ ЧАСТЬ

int roman_to_arab(std::string roman_number)
{
    char lat[100];
    int count = 0;

    std::cin.getline(lat, 100);

    for (int i = 0; i < strlen(lat); i++) {

        switch (lat[i]) {

        case 'M':
            count += 1000;
            break;
        case 'D':
            count += 500;
            break;
        case 'C':

            if (i + 1 < strlen(lat) && (lat[i + 1] == 'D' || lat[i + 1] == 'M'))
                count -= 100;
            else
                count += 100;
            break;
        case 'L':
            count += 50;
            break;
        case 'X':
            if (i + 1 < strlen(lat) && (lat[i + 1] == 'L' || lat[i + 1] == 'C' || lat[i + 1] == 'M'))
                count -= 10;
            else
                count += 10;

            break;
        case 'V':
            count += 5;
            break;
        case 'I':
            if (i + 1 < strlen(lat) && (lat[i + 1] == 'V' || lat[i + 1] == 'X' || lat[i + 1] == 'C'))
                count -= 1;
            else count += 1;

            break;

        }


    }

    std::cout << count << std::endl;

    system("pause");
    return EXIT_SUCCESS;
}


std::vector<int> func_Pascal(int k)
{
    std::vector <int> rez(k + 1, 0); //âåêòîð äëèíû k, çàïîëíåííûé 0
    rez[0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = i; j >= 1; j--)
            rez[j] = rez[j - 1] + rez[j]; // ñóììà 2 ÷èñåë íàä òåêóùèì ÷èñëîì

    return rez;

} 

int func_substr_len(std::string input_str) {
    std::set<char> letter;
    int size_set = 0, max = 0;
    for (int i = 0; i < input_str.length(); i++) {
        letter.insert(input_str[i]);
        if (letter.size() > size_set)
            size_set = letter.size();
        else {
            if (size_set > max) max = size_set;
            size_set = 0;
            letter.clear();
        }
    }
    if (size_set > max) max = size_set;

    return max;
}