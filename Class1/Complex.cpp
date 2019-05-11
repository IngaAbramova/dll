
#include "Complex.h"
#include<iostream>
#include <ctime>
#include <fstream>
using namespace std;


Complex::Complex()//�������� �����������
{
	re=0;
	im=0;
}


Complex::~Complex()//�������� ����������
{
}


float Complex::Re()//����������� ����� ����� 
{
	return re;
}


float Complex::Im()//����������� ������ �����
{
	return im;
}


Complex::Complex(float x, float y)//�������� �����������
{
	re=x;
	im=y;
}


int Complex::Out()//����� �� �����
{
	cout<<re;
	if(im>0) cout<<"+";
	if(im!=0) cout<<im<<"i"<<endl;
	return 0;
}



Complex Complex::operator+(Complex y)//�������� ���� �����������
{
	Complex x;
	x.re=re+y.re;
	x.im=im+y.im;
	return x;
}

Complex Complex::operator-(Complex y)//��������� ���� �����������
{
	Complex x;
	x.re=re-y.re;
	x.im=im-y.im;
	return x;
}

Complex Complex::operator/(Complex y)//������� ������������ �� �����������
{
	Complex x;
	x.re=((re*y.re)+(im*y.im))/((y.re*y.re)+(y.im*y.im));
	x.im=((im*y.re)-(re*y.im))/((y.re*y.re)+(y.im*y.im));
	return x;
}

Complex Complex::operator/(double y)//������� ������������ �� ������������
{
	Complex x;
	x.re=(re*y)/(y*y);
	x.im=(im*y)/(y*y);
	return x;
}
Complex Complex::operator*(double B) //��������� ������������ �� ������������
{
	Complex x;
	x.re = re*B;
	x.im = im*B;
	return x;
}

ostream& operator<<(ostream& os, const Complex &c)//��������� ��������� ������ �� �����
{
	os << c.re;
	if (c.im > 0) os << " + ";
	if (c.im != 0) os << c.im << "i";
	return os;
}


Complex Complex::operator*(Complex B)//��������� ������������ �� �����������
{
	Complex X;
	X.re = (re*B.re) - (im*B.im);
	X.im = (re*B.im) + (B.re*im);
	return X;
}
Complex Complex::operator^(int degree)//���������� ������������ ����� � �������
{
	Complex X;
	X.re = re;
	X.im = im;
	for (int i = 1; i < degree; i++)
	{
		X=X*(*this);
	}
	return X;
}
void Complex::sopr()//����������
{
	std::cout << "Sopr complex:\t";
	std::cout << re;
	if (im > 0)
	{
		im = im * (-1);
	}
	else
	{
		im = im * (-1);
		std::cout << "+";
	}
	if (im != 0) std::cout << im << "i\n";
}
void Complex::Write()//������ � �����
{
ofstream f_bin("binIn.txt", ios::binary | ios::app);
ofstream f("In.txt",ios::app);
		f_bin.write((char*)&(this->re), sizeof(this->re));
		f_bin.write((char*)&(this->im), sizeof(this->im));
	    f << this->re<<" ";
		f << this->im<<" ";
		f_bin.close();
		f.close();
}



