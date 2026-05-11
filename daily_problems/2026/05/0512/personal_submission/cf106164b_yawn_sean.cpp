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
		int n, m;
		cin >> n >> m;

		if (n == 2) {
			if (m & 1) cout << "2 1\n";
			else cout << "1 2\n";
		}
		else {
			m = min(n, m);
			for (int i = 0; i < m; i ++) cout << n - i << ' ';
			for (int i = 1; i <= n - m; i ++) cout << i << ' ';
			cout << '\n';
		}
	}

	return 0;
}