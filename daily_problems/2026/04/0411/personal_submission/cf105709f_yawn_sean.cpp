#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/fenwicktree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> bs(n), ws(n), vs(n);
	for (auto &x: bs) cin >> x;
	for (auto &x: ws) cin >> x;
	for (auto &x: vs) cin >> x;

	vector<vector<int>> tmp(k);
	for (int i = 0; i < n; i ++) {
		if (bs[i] + ws[i] <= k) {
			tmp[bs[i]].emplace_back(i);
		}
	}

	atcoder::fenwick_tree<long long> fen(k);
	long long ans = 0;

	for (int i = 1; i < k; i ++) {
		for (auto &idx: tmp[i]) fen.add(ws[idx], vs[idx]);
		ans = max(ans, fen.sum(0, k - i + 1));
	}

	cout << ans;

	return 0;
}