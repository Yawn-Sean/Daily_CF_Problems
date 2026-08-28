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

	int k;
	cin >> k;

	int n = 1;
	for (int i = 0; i < k; i ++) n *= 3;

	vector<int> v1(n), v2(n);
	for (auto &x: v1) cin >> x;
	for (auto &x: v2) cin >> x;

	auto solve = [&] (auto &self, vector<int> &x1, vector<int> &x2) -> vector<long long> {
		int cur_len = x1.size(), ncur_len = cur_len / 3;

		if (cur_len == 1) return {1ll * x1[0] * x2[0]};

		vector<long long> ans(cur_len, 0);
		vector<int> w1(ncur_len), w2(ncur_len);

		{
			for (int i = 0; i < ncur_len; i ++) {
				w1[i] = x1[ncur_len + i] + x1[2 * ncur_len + i];
				w2[i] = x2[ncur_len + i] + x2[2 * ncur_len + i];
			}

			auto res = self(self, w1, w2);

			for (int i = 0; i < ncur_len; i ++) ans[i] += res[i];
		}

		{
			for (int i = 0; i < ncur_len; i ++) {
				w1[i] = x1[i];
				w2[i] = x2[i] + x2[2 * ncur_len + i];
			}

			auto res = self(self, w1, w2);

			for (int i = 0; i < ncur_len; i ++) ans[ncur_len + i] += res[i];
		}

		{
			for (int i = 0; i < ncur_len; i ++) {
				w1[i] = x1[2 * ncur_len + i];
				w2[i] = x2[i];
			}

			auto res = self(self, w1, w2);

			for (int i = 0; i < ncur_len; i ++) ans[ncur_len + i] += res[i];
		}

		{
			for (int i = 0; i < ncur_len; i ++) {
				w1[i] = x1[i] + x1[ncur_len + i] + x1[2 * ncur_len + i];
				w2[i] = x2[i] + x2[ncur_len + i] + x2[2 * ncur_len + i];
			}

			auto res = self(self, w1, w2);

			for (int i = 0; i < ncur_len; i ++)
				ans[2 * ncur_len + i] = res[i] - ans[ncur_len + i] - ans[i];
		}

		return ans;
	};

	for (auto &v: solve(solve, v1, v2)) cout << v << ' ';

	return 0;
}