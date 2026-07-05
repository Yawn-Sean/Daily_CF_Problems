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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n; n ++;

		int v = sqrt(n);
		if (v * v == n) {
			cout << v - 1 << '\n';
			for (int i = 1; i < v; i ++) cout << i << ' ';
			cout << '\n';
		}
		else cout << -1 << '\n';
	}

	return 0;
}