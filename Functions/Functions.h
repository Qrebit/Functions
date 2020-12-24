#pragma once
#include <iostream>

using namespace std;

const int Rows = 5;
const int Cols = 5;

template<typename Null>
void FillRand(Null arr[], const int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}
}
void FillRand(char arr[], const int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 255;
	}
}

template<typename Null>
void FillRand(Null arr[Rows][Cols], const int rows, const int cols) {
	for (int b = 0; b < cols; b++) {
		for (int i = 0; i < rows; i++) {
			arr[i][b] = rand() % 100;
		}
	}
}
void FillRand(char arr[Rows][Cols], const int rows, const int cols) {
	for (int b = 0; b < cols; b++) {
		for (int i = 0; i < rows; i++) {
			arr[i][b] = rand() % 255;
		}
	}
}



template<typename Null>
void Print(Null arr[], const int size) {
	setlocale(LC_ALL, "C");
	for (int i = 0; i < size; i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;
	setlocale(LC_ALL, "Russian");
}
template<typename Null>
void Print(Null arr[Rows][Cols], const int rows, const int cols) {
	setlocale(LC_ALL, "C");
	for (int b = 0; b < cols; b++) {
		for (int i = 0; i < rows; i++) {
			cout << arr[i][b] << '\t';
		}
		cout << endl;
	}
	cout << endl;
	setlocale(LC_ALL, "Russian");
}

template<typename Null>
void Sum(Null arr[], const int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	cout << "Сумма элементов массива - " << sum << endl;
}
template<typename Null>
void Sum(Null arr[Rows][Cols], const int rows, const int cols) {
	int sum = 0;
	for (int b = 0; b < cols; b++) {
		for (int i = 0; i < rows; i++) {
			sum += arr[i][b];
		}
	}
	cout << "Сумма элементов массива - " << sum << endl;
}


template<typename Null>
void Avg(Null arr[], const int size) {
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	cout << "Среднее арифметическое элементов массива - " << sum / size << endl;
}
template<typename Null>
void Avg(Null arr[Rows][Cols], const int rows, const int cols) {
	float sum = 0;
	for (int b = 0; b < cols; b++) {
		for (int i = 0; i < rows; i++) {
			sum += arr[i][b];
		}
	}
	cout << "Среднее арифметическое элементов массива - " << sum / (rows * cols) << endl;
}

template<typename Null>
void MinValue(Null arr[], const int size) {
	Null Min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < Min) Min = arr[i];
	}
	cout << "Минимальное значение массива - " << Min << endl;
}
template<typename Null>
void MinValue(Null arr[Rows][Cols], const int rows, const int cols) {
	Null Min = arr[0][0];
	for (int b = 0; b < cols; b++) {
		for (int i = 0; i < rows; i++) {
			if (arr[i][b] < Min) Min = arr[i][b];
		}
	}
	cout << "Минимальное значение массива - " << Min << endl;
}

template<typename Null>
void MaxValue(Null arr[], const int size) {
	Null Max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > Max) Max = arr[i];
	}
	cout << "Максимальное значение массива - " << Max << endl;
}
template<typename Null>
void MaxValue(Null arr[Rows][Cols], const int rows, const int cols) {
	Null Max = arr[0][0];
	for (int b = 0; b < cols; b++) {
		for (int i = 0; i < rows; i++) {
			if (arr[i][b] > Max) Max = arr[i][b];
		}
	}
	cout << "Максимальное значение массива - " << Max << endl;
}

template<typename Null>
void Sort(Null arr[], const int size) {
	Null temp;
	for (int x = 0; x < size; x++) {
		for (int i = 0; i < size; i++) {
			if (arr[i] < arr[x]) {
				temp = arr[x];
				arr[x] = arr[i];
				arr[i] = temp;
			}
		}
	}
	cout << "Отсортированный Массив:" << endl;
	Print(arr, size);
}
template<typename Null>
void Sort(Null arr[Rows][Cols], const int rows, const int cols) {
	Null temp;
	for (int y = 0; y < cols; y++) {
		for (int x = 0; x < rows; x++) {
			for (int b = 0; b < cols; b++) {
				for (int i = 0; i < rows; i++) {
					if (arr[i][b] < arr[x][y]) {
						temp = arr[x][y];
						arr[x][y] = arr[i][b];
						arr[i][b] = temp;
					}
				}
			}
		}
	}
	cout << "Отсортированный Массив:" << endl;
	Print(arr, rows, cols);
}

template<typename Null>
void Shift(Null arr[], const int size) {
	int a, d;
	int temp;
	cout << "На сколько сдвинуть?:"; cin >> a;
	cout << '\n' << "Направление сдвига:" << endl;
	cout << "Влево - 1" << endl;
	cout << "Вправо - 2" << endl;
	cin >> d;
	if (d == 1) {
		for (int i = 0; i < a; i++) {
			temp = arr[0];
			for (int b = 1; b < size; b++) {
				arr[b - 1] = arr[b];
			}
			arr[9] = temp;
		}
	}
	else {
		for (int i = 0; i < a; i++) {
			temp = arr[9];
			for (int b = size - 1; b > 0; b--) {
				arr[b] = arr[b - 1];
			}
			arr[0] = temp;
		}
	}
	cout << "Сдвинутый массив:" << endl;
	Print(arr, size);
}
template<typename Null>
void Shift(Null arr[Rows][Cols], const int rows, const int cols) {
	int a, d;
	int temp;
	cout << "На сколько сдвинуть?:"; cin >> a;
	cout << '\n' << "Направление сдвига:" << endl;
	cout << "Влево - 1" << endl;
	cout << "Вправо - 2" << endl;
	cout << "Вверх - 3" << endl;
	cout << "Вниз - 4" << endl;
	cin >> d;
	if (d == 1) {
		for (int z = 0; z < a; z++) {
			for (int b = 0; b < cols; b++) {
				temp = arr[0][b];
				for (int i = 1; i < rows; i++) {
					arr[i - 1][b] = arr[i][b];
				}
				arr[4][b] = temp;
			}
		}
	}
	if (d == 2) {
		for (int z = 0; z < a; z++) {
			for (int b = 0; b < cols; b++) {
				temp = arr[4][b];
				for (int i = rows - 1; i > 0; i--) {
					arr[i][b] = arr[i - 1][b];
				}
				arr[0][b] = temp;
			}
		}
	}
	if (d == 3) {
		for (int z = 0; z < a; z++) {
			for (int i = 0; i < rows; i++) {
				temp = arr[i][0];
				for (int b = 1; b < cols; b++) {
					arr[i][b - 1] = arr[i][b];
				}
				arr[i][4] = temp;
			}
		}
	}
	if (d == 4) {
		for (int z = 0; z < a; z++) {
			for (int i = 0; i < rows; i++) {
				temp = arr[i][4];
				for (int b = cols - 1; b > 0; b--) {
					arr[i][b] = arr[i][b - 1];
				}
				arr[i][0] = temp;
			}
		}
	}
	cout << "Сдвинутый массив:" << endl;
	Print(arr, rows, cols);
}
