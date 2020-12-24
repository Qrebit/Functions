#include <iostream>
#include <ctime>
#include "Functions.h"

using namespace std;



void main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	const int Size = 10;
	const int Rows = 5;
	const int Cols = 5;
	// ������ ������� ��� �����
	int arr[Size];
	// ��� ��� 
	int brr[Rows][Cols];
	cout << "���������� ������:" << endl;
	FillRand(arr, Size);
	Print(arr, Size);
	Sum(arr, Size);
	Avg(arr, Size);
	MinValue(arr, Size);
	MaxValue(arr, Size);
	Sort(arr, Size);
	Shift(arr, Size);
	cout << endl;
	cout << "��������� ������ ������:" << endl;
	FillRand(brr, Rows, Cols);
	Print(brr, Rows, Cols);
	Sum(brr, Rows, Cols);
	Avg(brr, Rows, Cols);
	MinValue(brr, Rows, Cols);
	MaxValue(brr, Rows, Cols);
	Sort(brr, Rows, Cols);
	Shift(brr, Rows, Cols);
}