#include "Bool_functions.h"
#include <fstream> //���������� ��� ������ � fstream
#include <iostream>

/* �� ��������� ������� �������� f ������� ������� ���������� ���������� ���������� n ���� �������. ����� ������� f ���� pow(2,n). */
int num_of_args(vector<bool> f) {
	int size = f.size(), n = 0; // size - ����� ������� �������, n - ���������� ���������� �������
	while (size > 1) { //����, ������������ ������� 2 �����
		size /= 2;
		n++;
	}
	return n;
}

/* �� ��������� ������������ � ����� ����� file_name ������� ������ �������� ������� ������� vector<bool>*/
vector<bool> read_from_file(std::string file_name)
{
	vector <bool> f;
	fstream fs;  //�������� ������� ��� ������ � �++
	string str;
	fs.open(file_name, std::fstream::in);  //�������� �����, �����: �� ������ 
	getline(fs, str); // ���������� ������ � ��������

	for (int i = 0; i < str.length(); i += 2) {
		f.push_back((bool)str[i]);
		//cout << str[i] << endl;
	}

	fs.close();
	return f;
}