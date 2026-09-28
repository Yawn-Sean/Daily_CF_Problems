#include <bits/stdc++.h>
#include "atcoder/fenwicktree.hpp"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 1e6 + 5, mod = 1e9 + 7;

	vector<int> pr(M);
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i < M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j < M; j += i) {
				pr[j] = i;
			}
		}
	}

	auto factors = [&] (int x) -> vector<int> {
		vector<int> ans = {1};
		while (x > 1) {
			int p = pr[x], c = 0, l = ans.size();
			while (x % p == 0) x /= p, c ++;
			for (int i = 0; i < c * l; i ++) ans.emplace_back(ans[i] * p);
		}
		return ans;
	};

	int n;
	cin >> n;

	vector<int> v1(n), v2(n);
	for (auto &x: v1) cin >> x;
	for (auto &x: v2) cin >> x;

	vector<int> sorted_v1 = v1;
	sort(sorted_v1.begin(), sorted_v1.end());

	for (int i = 0; i < n; i ++)
		v1[i] = lower_bound(sorted_v1.begin(), sorted_v1.end(), v1[i]) - sorted_v1.begin();

	vector<vector<int>> pos(M);
	for (int i = 0; i < n; i ++) {
		for (auto &x: factors(v2[i])) {
			pos[x].emplace_back(i);
		}
	}

	atcoder::fenwick_tree<long long> fen(n);
	vector<int> tmp(n, 0), cnt(M, 0);

	for (int i = 0; i < M; i ++) {
		for (auto &p: pos[i]) {
			tmp[p] = (fen.sum(0, v1[p]) + 1) % mod;
			cnt[i] = (cnt[i] + tmp[p]) % mod;
			fen.add(v1[p], tmp[p]);
		}
		for (auto &p: pos[i]) {
			fen.add(v1[p], -tmp[p]);
		}
	}

	int ans = 0;

	for (int i = M - 1; i >= 1; i --) {
		for (int j = 2 * i; j < M; j += i) {
			cnt[i] += mod - cnt[j];
			cnt[i] %= mod;
		}
		ans = (ans + 1ll * i * cnt[i]) % mod;
	}

	cout << ans;

	return 0;
}