#pragma once
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>

using namespace std; 

void swap(int* a, int* b) {
	int* x = a;
	a = b;
	b = x;
}

void bubblesort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void bubblesort2(double* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void t2() {
	cout << "Введите размер массива." << endl;
	int n;
	cin >> n;
	int* arr = new int[n];
	cout << "Введите элемент массива." << endl;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int* pa = &arr[0];
	int* pla = &arr[n - 1];
	swap(*pa, *pla);
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < n; ++i) cout << arr[i] << " ";
	delete[] arr; //освобождаем память, которую выделяли для динамического массива
	arr = nullptr;
	cout << endl;
	cout << endl;
}

void t4() {
	int array[12];
	srand(time(NULL));
	int temp;
	int k = 0;
	cout << "Неотсортированный массив:" << endl;
	for (int i = 0; i < 12; i++)
	{
		array[i] = rand() % 100;
		cout << array[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 12 - 1; i++)
	{
		for (int j = i + 1; j < 12; j++)
		{
			if (array[i] < array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				k++;
			}
		}
	}
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < 12; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	cout << "Количество перестановок = " << k << endl;
	cout << endl;
}

void t5() {
	const int size1(8);
	int a1[size1] = { 1, -2, -3, 4, 5, -6, 7, -8 }, b1[size1], i, j, k;
	for (i = 0, j = 0, k = size1 - 1; i < size1; ++i) {
		if (a1[i] < 0)
			b1[j++] = a1[i];
		else
			b1[k--] = a1[i];
	}
	for (i = k + 1, j = size1 - 1; i < j; ++i, --j)
		swap(b1[i], b1[j]);
	cout << "Первый массив: ";
	copy(a1, a1 + size1, ostream_iterator<int>(cout, " "));
	cout << "\nПервый отсортированный массив: ";
	copy(b1, b1 + size1, ostream_iterator<int>(cout, " "));
	cout << endl;

	const int size2(6);
	int a2[size2] = { -31, 2, -11, 4, 8, -2 }, b2[size2];
	for (i = 0, j = 0, k = size2 - 1; i < size2; ++i) {
		if (a2[i] < 0)
			b2[j++] = a2[i];
		else
			b2[k--] = a2[i];
	}
	for (i = k + 1, j = size2 - 1; i < j; ++i, --j)
		swap(b2[i], b2[j]);
	cout << "Второй массив: ";
	copy(a2, a2 + size2, ostream_iterator<int>(cout, " "));
	cout << "\nВторой отсортированный массив: ";
	copy(b2, b2 + size2, ostream_iterator<int>(cout, " "));
	cout << endl;

	const int size3(4);
	int a3[size3] = { -1, 2, -13, 33 }, b3[size3];
	for (i = 0, j = 0, k = size3 - 1; i < size3; ++i) {
		if (a3[i] < 0)
			b3[j++] = a3[i];
		else
			b3[k--] = a3[i];
	}
	for (i = k + 1, j = size3 - 1; i < j; ++i, --j)
		swap(b3[i], b3[j]);
	cout << "Третий массив: ";
	copy(a3, a3 + size3, ostream_iterator<int>(cout, " "));
	cout << "\nТретий отсортированный массив: ";
	copy(b3, b3 + size3, ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << endl;
}

void t6() {
	const int size = 14;
	int array[size];
	srand(time(NULL));
	int temp;
	int k = 0;
	cout << "Неотсортированный массив:" << endl;
	for (int i = 0; i < 14; i++)
	{
		array[i] = rand() % 50;
		cout << array[i] << " ";
	}
	cout << endl;
	int leng = size / 2;
	for (int i = 0; i < leng; i++)
	{
		int t = array[i];
		array[i] = array[leng + i];
		array[leng + i] = t;
		k++;
	}
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < 14; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	cout << "Количество перестановок = " << k << endl;
	cout << endl;
}

void t7() {
	const int size = 10;
	int array[size], k = 0;
	srand(time(NULL));
	cout << "Заданный массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 99 + 1;
		cout << array[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (i == 0 && array[i] < array[i + 1]) k++;
		else if (i > 0 && i < size - 1 && array[i] < array[i - 1] && array[i] < array[i + 1]) k++;
		else if (i == size - 1 && array[i] < array[i - 1]) k++;
	}
	cout << "Количество локальных минимумов: " << k << endl;
	cout << endl;
}

int funct(int* arr, int a) {
	int s = 0;
	int f1 = 0;
	int f2 = 0;
	for (int i = 0; i < a; i++) {
		if (arr[i] == 0) {
			f1 = i;
			break;
		}
	}
	for (int i = a; i > 0; i--) {
		if (arr[i] == 0) {
			f2 = i;
			break;
		}
	}
	for (int k = f1; k < f2; k++) {
		s = s + arr[k];
	}
	cout << "Сумма элементов между двумя нолями в строке равна " << s << endl;
	return s;
}

void t8() {
	const int c = 3;
	const int k = 5;
	int array[c][k] =
	{
		{1, 2, 0, 4, 0},
		{8, 0, 3, 2, 0},
		{12, 0, 2, 0, 6}
	};
	for (int i = 0; i < c; i++)
		funct(array[i], k);
	cout << endl;
}

void t12() {
	const int c = 3;
	const int k = 5;
	int max = -100000;
	int min = 999999;
	int* s = new int();
	int array[c][k] =
	{
		{1, 2, 0, 4, 0},
		{8, 0, 3, 2, 0},
		{12, 0, 2, 0, 6}
	};
	for (int j = 0; j < c; j++) {
		for (int i = 0; i < k; i++)
			s[j] = s[j] + array[j][i];
	}
	for (int i = 0; i < c; i++) {
		if (s[i] > max) {
			max = s[i];
		}
		if (s[i] < min) {
			min = s[i];
		}
	}
	for (int i = 0; i < c; i++) {
		if (s[i] == min) {
			cout << i << " максимальная строчка матрицы" << endl;
		}
		if (s[i] == max) {
			cout << i << " минимальная строчка матрицы" << endl;
		}
	}
	cout << endl;
}

void t9() {
	const int size(15);
	int* o = new int();
	int* p = new int();
	int k = 0;
	int arr[size] = { 1, -2, -3, 4, 5, -6, 7, -8, 10, 12, -22, 32, 55, -15, 6 }, b[size];
	bubblesort(arr, size);
	for (int i = 0; i < size; i++) {
		if (arr[i] >= 0) {
			k = i - 1;
			break;
		}
	}
	cout << endl;
	for (int i = k; i < size - 1; i++) {
		for (int j = k + 1; j < size - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << endl;
}

void t10() {
	cout << "Введите размер 1 массива." << endl;
	int n1;
	cin >> n1;
	double* arr1 = new double[n1];
	cout << "Введите элемент 1 массива." << endl;
	for (int i = 0; i < n1; i++) cin >> arr1[i];
	cout << "Введите размер 2 массива." << endl;
	int n2;
	cin >> n2;
	double* arr2 = new double[n2];
	cout << "Введите элемент 2 массива." << endl;
	for (int i = 0; i < n2; i++) cin >> arr2[i];
	bubblesort2(arr1, n1);
	bubblesort2(arr2, n2);
	cout << endl;
	double* ptr1 = &arr1[n1];
	double* ptr2 = &arr2[n2];
	for (int i = 0; i < n1; i++) cout << arr1[i] << " ";
	cout << endl;
	for (int i = 0; i < n2; i++) cout << arr2[i] << " ";
}