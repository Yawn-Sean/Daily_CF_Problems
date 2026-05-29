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

	int n, k;
	cin >> n >> k;

	int c = 0;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if (x % k) c ++;
	}

	if (c == 0) cout << "Rami";
	else if (c == 2) cout << "Oussama";
	else cout << ((n & 1) ? "Rami" : "Oussama");

	return 0;
}