#include "Samsonov_Aleksey_201-331_TEST.h"// ���������� h.file

int num_of_args(std::vector<bool> f)
{
	return (int)log2(f.size());//����� �������� �� ���������� ��������, 0 1 0 1 size=4 log2_2=4
}