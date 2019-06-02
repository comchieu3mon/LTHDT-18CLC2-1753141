#include "Fraction.h"


Fraction::Fraction()
{
	this->numerator = 0;
	this->denominator = 1;
}

Fraction::Fraction(int a, int b)
{
	this->numerator = a;
	if (b == 0 && a != 0) {
		cout << "Mau so khong the bang 0";
	}
	else {
		this->denominator = b;
	}
}

Fraction::Fraction(const Fraction& p)
{
	this->numerator = p.numerator;
	this -> denominator = p.denominator;
}

Fraction::~Fraction()
{
}

void Fraction::Input() {
	cout << "Nhap tu so : " << endl;
	cin >> numerator;
	cout << "Nhap mau so : " << endl;
	cin >> denominator;
}

int Fraction::GetNumerator() {
	return numerator;
}

int Fraction::GetDenominator() {
	return denominator;
}

void Fraction::SetDenominator(int denominator) {
	this->denominator = denominator;
}

void Fraction::SetNumerator(int numerator) {
	this->numerator = numerator;
}

int Fraction::Gcd(int a, int b) {
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


void Fraction::Output() {
	cout << this->numerator << "/" << this->denominator << endl;
}


bool Fraction::Compare(Fraction ps) {
	int a = this->numerator;
	int b = this->denominator;
	int rutgon = Gcd(a, b);
	a /= rutgon;
	b /= rutgon;
	int c = ps.numerator;
	int d = ps.denominator;
	int rutgon2 = Gcd(c, d);
	c /= rutgon2;
	d /= rutgon2;

	int compare = a * d - b * c;

	if (compare > 0) {
		return 1;
	}
	else {
		return 0;
	}
}


Fraction Fraction::Add(Fraction ps) {
	if (denominator == 0 && numerator == 0)
	{
		denominator = ps.denominator;
		numerator = ps.numerator;
		return *this;
	}
	else 
	{
		numerator = numerator * ps.denominator + ps.numerator * denominator;
		denominator = denominator * ps.denominator;
		return *this;
	}
}

void Fraction::Swap(Fraction& ps) {
	Fraction temp;
	temp = *this;
	numerator = ps.numerator;
	denominator = ps.denominator;
	ps.numerator = temp.numerator;
	ps.denominator = temp.denominator;
}

