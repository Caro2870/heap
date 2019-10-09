// ConsoleApplication1.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <iostream>
#include <vector>



using namespace std;
using namespace System;

typedef vector<float> vflt;

float heapMaxi(vflt A) {
	return A[0];
}

int left(int i) {
	return i * 2 + 1;
}
int izquierdo(int i) {
	return left(i)+ 1;
}
float maxheapifi(vflt A, int i) {
	int I = left(i);
	int R = izquierdo(i);
	int largest;
	if (I <= A.size() && A[I] > A[i]) {
		largest = I;

	}
	else {
		largest = i;
	}
	if (R<A.size() && A[R] >A[largest]) {
		largest = R;
	}
	if (largest!=i)
	{
		float temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxheapifi(A, largest);
	}

}
float heapExtraMax(vflt A) {

	if (A.size() < 1) {
		return 0.f;
	}
	float max = A[0];
	A[0] = A[A.size() - 1];
	A.pop_back();
	maxheapifi(A, 0);
	return max;
}

int main() {

}