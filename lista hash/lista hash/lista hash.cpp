#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <functional>
#include <math.h>

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

typedef unsigned long ulong;
template <typename K, typename T, T NOTHING = 0>
class OpenHashTable {
	vector< list< pair<K, T>* > > buckets;
	int cap; // capacidad del arregl
	int len; // # de elementos insertados

	function<ulong(K)> hashFunc;

public:
	OpenHashTable(int cap = 100,
		function<ulong(K)> hashFunc = [](K key) {
		int n = key.size();
		ulong sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += (key[i] - 96)*pow(26, n - 1 - i);
		}
		return sum;
	})
		: cap(bertand(cap)), len(0), hashFunc(hashFunc),
		buckets(vector< list< pair<K, T>* > >(cap, list< pair<K, T>* >())) {}

	int size() {
		return len;
	}
	void add(K key, T elem) {
		auto index = hashFunc(key) % cap;
		for (auto p : buckets[index]) {
			if (p->first == key) {
				p->second = elem;
				return;
			}
		}
		buckets[index].push_front(new pair<K, T>(key, elem));
		++len;
	}
	T get(K key) {
		auto index = hashFunc(key) % cap;
		for (auto p : buckets[index]) {
			if (p->first == key) {
				return p->second;
			}
		}
		return NOTHING;
	}
	bool exists(K key) {
		auto index = hashFunc(key) % cap;
		for (auto p : buckets[index]) {
			if (p->first == key) {
				return true;
			}
		}
		return false;
	}
};

// https://repl.it/repls/RectangularBogusArrays
int main() {
	initCriba();

	OpenHashTable<string, int> ht;

	ht.add("hola", 1981);
	ht.add("chao", 1987);

	cout << ht.size() << endl;
	cout << ht.exists("chao") << endl;
	cout << ht.exists("hola") << endl;
	cout << ht.exists("noexiste") << endl;
	cout << ht.get("chao") << endl;
	cout << ht.get("hola") << endl;

	ht.add("chao", 2000);
	cout << ht.get("chao") << endl;

	system("pause");
	return 0;
}