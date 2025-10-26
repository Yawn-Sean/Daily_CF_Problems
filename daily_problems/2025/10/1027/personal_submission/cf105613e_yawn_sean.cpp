#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	if (1ll * n * (n - 1) / 2 < k) return cout << -1, 0;

	vector<int> ans;

	for (int i = 1; i <= n; i ++) {
		if (i * (i + 1) / 2 > k) {
			for (int j = 0; j < i; j ++)
				ans.emplace_back(3);
			k -= i * (i - 1) / 2;
			for (int j = 0; j < k; j ++)
				ans[j] = 6;
			if (k) ans.emplace_back(2);
			break;
		}
	}

	for (int i = 999997; i >= 0; i -= 6) {
		if (ans.size() < n) ans.emplace_back(i);
		if (ans.size() < n) ans.emplace_back(i - 2);
	}

	for (auto &x: ans) cout << x << ' ';

	return 0;
}