#pragma once
#include <iostream>
using namespace std;
class PhanSo
{
private:
	int tuSo;
	int mauSo;
public:
	void input();
	void setTu(int tuso);
	void setMau(int mauso);
	int getTu();
	int getMau();
	int gcd(int a, int b);
	bool soSanh(PhanSo ps);
	void xuat();
	void swap(PhanSo& ps);
	PhanSo add(PhanSo ps);
};

