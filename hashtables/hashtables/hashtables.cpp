//// hashtables.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000

vector<bool> criba(MAX, true);

void initCriba() {
	criba[0] = false;
	criba[1] = false;
	for (int i = 0; i < MAX; ++i) {
		if (criba[i]) {
			for (int p = i * 2; p < MAX; p += i) {
				criba[p] = false;
			}
		}
	}
}
bool isPrime(int n) {
	return criba[n];
}
int bertand(int n) {
	for (int i = n; i < 2 * n - 2; ++i) {
		if (isPrime(i)) {
			return i;
		}
	}
	return n;
}

int main() {

	//initcriba();
	//for (int i = 0;i < 500;++i) {
	//	if (isPrime(i)) {
	//		cout << i << " " <<endl;
	//	}
	//}

	initCriba();

	for (int i = 10; i < 100; i += 10) {
		cout << bertand(i) << " ";
	}
	system("pause");
	return 0;
}