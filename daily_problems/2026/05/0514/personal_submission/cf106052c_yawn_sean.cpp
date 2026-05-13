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

	int M = 1e6 + 5;

	vector<long long> phi(M);
	iota(phi.begin(), phi.end(), 0);

	for (int i = 2; i < M; i ++) {
		if (phi[i] == i) {
			for (int j = i; j < M; j += i) {
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}

	for (int i = 2; i < M; i ++) {
		if (i & 1) phi[i] = 2 * phi[i];
		else phi[i] = 0;
	}

	for (int i = 1; i < M; i ++) {
		phi[i] += phi[i - 1];
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		long long ans = 0;

		for (int i = 1; i <= n; i ++) {
			ans += phi[n / i];
		}

		cout << ans << '\n';
	}

	return 0;
}