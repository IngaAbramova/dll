
#include<Windows.h>
#include<iostream>
#include "Complex.h"
#include <ctime>
#include <fstream>
/*#include "Dll2.h"
#pragma comment (lib, "Dll2.lib")*/
using namespace std;
int main()
{
	//Указатель на Dll 
	HINSTANCE hmodule = NULL;
	hmodule = LoadLibrary(L"Dll2.dll");
	setlocale(LC_ALL, "Russian");
	int comand=-1;
	ofstream f_bin("binIn.txt", ios::binary);
	ofstream f("In.txt");
	f_bin.close();
	f.close();
	cout << "Введите комплексное число."<<endl;
	cout << "Re: ";
	float a, b;
	cin>>a;
	cout << "Im: ";
	cin>>b;
	Complex W(a,b);
	W.Out();
	W.Write();
	cout<<endl;
	cout << "Введите комплексное число."<<endl;
	cout << "Re: ";
	cin>>a;
	cout << "Im: ";
	cin>>b;
	Complex U(a,b);
	U.Out();
	U.Write();
	Complex A,B,C;
	A=W+U;
	B=W-U;
	C=W*U;
	A.Write();
	B.Write();
	C.Write();
	cout<<endl;
	typedef void(*Read)();
	Read ReadFunction = (Read)GetProcAddress(hmodule, "Read");
	ReadFunction();
	//Read();
	system("pause");

}
