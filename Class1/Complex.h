#pragma once
#include<iostream>
using namespace std;
class Complex
{
	public:
	float re;//действительная часть числа
	float im;//мнимая часть числа

	Complex();
	~Complex();
	float Re();
	float Im();
	int Out();
	Complex(float x, float y);
	Complex Complex::operator+(Complex y);
	Complex Complex::operator-(Complex y);
	Complex Complex::operator/(Complex y);
	Complex Complex::operator/(double y);
	Complex Complex::operator*(double B);
	friend ostream& operator<<(ostream& os, const Complex &c);
	Complex Complex::operator^(int degree);
	Complex Complex::operator*(Complex B);
	void Complex::sopr();
	void Complex::Write();
};

