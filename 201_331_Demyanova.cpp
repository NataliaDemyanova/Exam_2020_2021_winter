#include "lab.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    int answ_task_1;
    std::vector <bool> task_1 = { 0, 0, 1, 1 };
    answ_task_1 = num_of_args(task_1);
    std::cout << answ_task_1;

    std::string read_file_name = "read_bool_vector.txt";
    std::vector <bool> answ_task_2 = read_from_file(read_file_name);
    for (auto data : answ_task_2) {
        std::cout << data << ' ';
    }

    std::string write_file_name = "";
       


    return 0;
}