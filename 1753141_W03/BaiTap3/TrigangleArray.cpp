#include "TrigangleArray.h"
#include <fstream>
#include <iostream>
using namespace std;

void TrigangleArray::TriangleType() {
	int acute = 0;
	int right = 0;
	int obtuse = 0;
	int remove = 0;
	for (int i = 0; i < n; i++) {
		switch (a[i].checkTriangle())
		{
		case 1:
			right++;
			break;
		case 2:
		case 3:
			acute++;
			break;
		case 4:
		case 5:
			obtuse++;
			break;
		case -1:
			remove--;
		default:
			break;
		}
	}
	cout << "Acute triangle : " << acute << endl;
	cout << "Right triangle : " << right << endl;
	cout << "Obtuse triangle : " << obtuse << endl;
	cout << "You have to remove : " << remove << "Triangle" << endl;
}

bool TrigangleArray::LoadTriangleArray(const char* path)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open() == false) {
		fin.close();
		return false;
	}
	fin >> this->n;
	this->a = new Triangle[n];
	for (int i = 0; i < n; i++) {
		int c, d, e, f, g, h;
		fin >> c;
		fin >> d;
		fin >> e;
		fin >> f;
		fin >> g;
		fin >> h;
		this->a[i].setcanh(c, d, e, f, g, h);
	}
	fin.close();
	return true;
}

TrigangleArray::TrigangleArray()
{
	this->n = 0;
	this->a = NULL;
}

TrigangleArray::TrigangleArray(Triangle*& a, int& n) {
	this->n = n;
	this->a = a;
}

TrigangleArray::TrigangleArray(const TrigangleArray& t)
{
	this->n = t.n;
	this->a = new Triangle[n];
	for (int i = 0; i < n; i++) {
		this->a[i] = t.a[i];
	}
}

TrigangleArray::~TrigangleArray()
{
}
