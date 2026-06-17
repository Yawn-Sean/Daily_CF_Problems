#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	priority_queue<long long> pq;
	long long total = 0, lazy = 0;

	for (int i = 0; i < n; i ++) {
		long long x;
		cin >> x;
		total += x;
		pq.push(x);
	}

	for (int i = 0; i < n; i ++) {
		long long x;
		cin >> x;
		lazy += x;

		auto v = pq.top() + lazy; pq.pop();
		total += x * n - v / 2;
		v -= v / 2;
		pq.push(v - lazy);
	}

	cout << total;

	return 0;
}