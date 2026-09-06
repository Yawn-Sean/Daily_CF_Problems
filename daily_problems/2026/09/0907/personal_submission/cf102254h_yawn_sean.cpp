#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 1e6 + 5;
	vector<int> phi(M);

	iota(phi.begin(), phi.end(), 0);
	for (int i = 2; i < M; i ++) {
		if (phi[i] == i) {
			for (int j = i; j < M; j += i) {
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		if (gcd(n, m) == 1) cout << phi[m] << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}