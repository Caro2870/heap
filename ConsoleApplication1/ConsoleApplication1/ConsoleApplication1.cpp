// ConsoleApplication1.cpp: archivo de proyecto principal.
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace System;
using namespace std;

typedef vector<float> vflt;

int left(int i) { return i * 2 + 1; }
int right(int i) { return left(i) + 1; }
int parent(int i) { return (i - 1) / 2; }

void maxHeapify(vflt& A, int i) {
	int l = left(i);
	int r = right(i);
	int largest;
	if (l < A.size() && A[l] > A[i]) {
		largest = l;
	}
	else {
		largest = i;
	}
	if (r < A.size() && A[r] > A[largest]) {
		largest = r;
	}
	if (largest != i) {
		float temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxHeapify(A, largest);
	}
}

float front(vflt& A) { // heapMaximum
	return A[0];
}
float pop(vflt& A) { // heapExtractMax
	if (A.size() < 1) {
		return 0.f; // Manejar error
	}
	float max = A[0];
	A[0] = A[A.size() - 1];
	A.pop_back();
	maxHeapify(A, 0);
	return max;
}
void heapIncreaseKey(vflt& A, int i, float key) {
	if (key < A[i]) {
		return;
	}
	A[i] = key;
	while (i > 0 && A[parent(i)] < A[i]) {
		float temp = A[i];
		A[i] = A[parent(i)];
		A[parent(i)] = temp;
		i = parent(i);
	}
}
void push(vflt& A, float key) { // maxHeapInsert
	A.push_back(-1e20);
	heapIncreaseKey(A, A.size() - 1, key);
}

int main() {

	vflt X;
	int dato;
	Random aleatorio;
	
	/*cout << "Ingresa dato: " << endl;
	do {
		cin >> dato;
		push(X, dato);
	}
	while (dato != 0);*/

	for (int i = 0;i < 100;i++) {
		dato = aleatorio.Next(1, 10000)/10;
		push(X, dato);
	}
	
	while (X.size() > 0) {
		cout << pop(X) << endl;
	}
	system("pause");
	return 0;
}