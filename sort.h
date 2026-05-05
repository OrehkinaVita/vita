#pragma once
#include "cstdlib"
#include "Student.h"


 
//пузырьком 
template <class T>
void booblesort(T* a, int n) {
	int flag = 1;
	T h;
	while (flag) {
		flag = 0;
		for (int i = 1; i < n; i++) {
			if (a[i - 1].groupNumber > a[i].groupNumber) { 
				h = a[i - 1];
				a[i - 1] = a[i];
				a[i] = h;
				flag = 1;

			}
		}
	}
}
//вставками
template <class T>
void insert(T* a, int n) {
	T t;
	for (int i = 1; i < n; i++) {
		t = a[i];
		int j = i - 1;
		while (j >= 0 && a[j].groupNumber > t.groupNumber) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
}

//сортировка выбором 
template <class T>
void select(T* a, int n) {
	int min;
	T t;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j].groupNumber < a[min].groupNumber)
				min = j;
		}
		if (min != i) {
			t = a[i];
			a[i] = a[min];
			a[min] = t;
		}
	}
}

//сортировка Шелла 
template <class T>
void shell(T* a, int n) {
	int steps[5] = { 121, 40, 13, 4, 1 };
	int j;
	T t;
	for (int k = 0; k < 5; k++) {
		int step = steps[k];
		for (int i = step; i < n; i++) {
			t = a[i];
			for (j = i - step; j >= 0 && t.groupNumber < a[j].groupNumber; j -= step) {
				a[j + step] = a[j];
			}
			a[j + step] = t;
		}
	}
}

//qsort быстрая сортировка 
template <class T>
void qsort(T* arr, int left, int right) {
	int i = left;
	int j = right;
	T x = arr[(left + right) / 2];
	while (i <= j) {
		while (i <= right && arr[i].groupNumber < x.groupNumber) i++;
		while (j >= left && arr[j].groupNumber < x.groupNumber) j++;
		if (i <= j) {
			T h = arr[i];
			arr[i] = arr[j];
			arr[j] = h;
			i++;
			j++;
		}
	}
	if (j > left) qsort(arr, left, j);
	if (i < right) qsort(arr, i, right);
}


