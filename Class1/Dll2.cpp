// Dll2.cpp : Определяет экспортированные функции для приложения DLL.
//
#include "stdafx.h"
#include<iostream>
#include <ctime>
#include <fstream>
using namespace std;
extern "C" _declspec(dllexport)
void Read()
{
	float s, g, h, k;
	cout << "Usual file" << endl;
	//Открываем файлы
	ifstream f_bin_in("binIn.txt", ios::binary);
	ifstream f_in("In.txt");
	//Считываем данные из обычного файла
	for (int i = 0; i < 5; i++)
	{
		f_in >> s;
		f_in >> g;
		cout << s;
		if (g > 0) cout << "+";
		if (g != 0) cout << g << "i" << endl;
	}
	cout << "Binary file" << endl;
	//Считываем данные из двоичного файла
	for (int i = 0; i < 5; i++)
	{
		f_bin_in.read((char*)&h, sizeof(h));
		f_bin_in.read((char*)&k, sizeof(k));
		cout << h;
		if (k > 0) cout << "+";
		if (k != 0) cout << k << "i" << endl;
	}
}

