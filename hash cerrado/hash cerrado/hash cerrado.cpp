#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 29;
	vector<int*> buckets(n, NULL);

	auto hp = [](int k) { return k % 19; };
	int c1 = 0;
	int c2 = 1;
	auto h = [=](int k, int i) {
		return (hp(k) + c1*i + c2*i*i) % n;
	};

	vector<int> nums = { 6, 34, 67, 92, 96, 8, 53, 5, 3, 2 };
	for (auto k : nums) {
		for (int i = 0; i < n; ++i) {
			auto index = h(k, i);
			cout << index << " ";
			if (buckets[index] == nullptr) {
				buckets[index] = new int;
				(*buckets[index]) = k;
				break;
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}