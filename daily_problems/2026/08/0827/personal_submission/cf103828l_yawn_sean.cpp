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

	auto f = [&] (auto &self, int n) -> vector<int> {
		if (n == 1) return {0};
		vector<int> ans;
		for (auto &x: self(self, n - n / 2)) ans.emplace_back(2 * x);
		for (auto &x: self(self, n / 2)) ans.emplace_back(2 * x + 1);
		return ans;
	};

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		auto res = f(f, n);

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				cout << res[i] * n + res[j] + 1 << " \n"[j == n - 1];
			}
		}
	}

	return 0;
}