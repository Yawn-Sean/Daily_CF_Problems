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

	int M = 1e6 + 5, mod = 1e9 + 7;

	vector<int> pr(M), phi(M, 1);
	iota(pr.begin(), pr.end(), 0);
	phi[0] = 0;

	for (int i = 2; i < M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j < M; j += i) {
				pr[j] = i;
				if (j % i == 0 && j / i % i == 0) phi[j] = 0;
				else phi[j] = -phi[j];
			}
		}
	}

	vector<int> ans(M, 0);

	int cur = 1;
	for (int i = 1; i < M; i ++) {
		cur = 2ll * cur % mod;
		for (int j = i * 2; j < M; j += i) {
			ans[j] += (-phi[j / i]) * cur % mod;
			if (ans[j] >= mod) ans[j] -= mod;
			if (ans[j] < 0) ans[j] += mod;
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int x; cin >> x;
		cout << ans[x] << '\n';
	}

	return 0;
}