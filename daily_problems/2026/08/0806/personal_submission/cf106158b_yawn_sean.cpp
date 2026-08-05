#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<vector<long long>> updates(n + 1);

	while (q --) {
		int f, s, c;
		cin >> f >> s >> c;

		s = gcd(s, n);
		if (updates[s].empty())
			updates[s] = vector<long long>(s, 0);
		updates[s][(f - 1) % s] += c;
	}

	vector<long long> ans(n, 0);

	for (int i = 0; i <= n; i ++) {
		if (!updates[i].empty()) {
			for (int j = 0; j < i; j ++) {
				for (int k = j; k < n; k += i) {
					ans[k] += updates[i][j];
				}
			}
		}
	}

	cout << max_element(ans.begin(), ans.end()) - ans.begin() + 1;

	return 0;
}