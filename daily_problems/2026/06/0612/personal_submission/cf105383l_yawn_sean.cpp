#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

typedef pair<vector<int>, vector<int>> node;

node init(int x) {
	node ans;
	ans.first = vector<int>(x, -1);
	ans.second = vector<int>(x, 0);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, s, t, x, k, mod = 1e9 + 7, inf = 1e9;
	cin >> n >> m >> s >> t >> x >> k;
	s --, t --;

	auto f = [&] (int x, int y) {return x * n + y;};

	auto merge_info = [&] (node info1, node info2, int pw) -> node {
		node ans = init(n * n);
		vector<pair<int, int>> notes(n * n, {inf, inf});

		auto &[msk1, order1] = info1;
		auto &[msk2, order2] = info2;

		for (int u = 0; u < n; u ++) {
			for (int v = 0; v < n; v ++) {
				for (int w = 0; w < n; w ++) {
					if (msk1[f(u, v)] == -1 || msk2[f(v, w)] == -1) continue;
					
					pair<int, int> new_path = {order1[f(u, v)], order2[f(v, w)]};
					if (new_path < notes[f(u, w)]) {
						notes[f(u, w)] = new_path;
						ans.first[f(u, w)] = (1ll * msk1[f(u, v)] * pw + msk2[f(v, w)]) % mod;
					}
				}
			}
		}

		vector<int> order(n * n);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&] (int i, int j) {return notes[i] < notes[j];});

		for (int i = 1; i < n * n; i ++) {
			if (notes[order[i]] == notes[order[i - 1]])
				ans.second[order[i]] = ans.second[order[i - 1]];
			else
				ans.second[order[i]] = ans.second[order[i - 1]] + 1;
		}

		return ans;
	};

	node ans = init(n * n);
	ans.first[f(s, s)] = 0;

	node tmp = init(n * n);

	vector<array<int, 3>> edges(m);
	for (auto &[u, v, w]: edges) {
		cin >> u >> v >> w;
		u --, v --;
	}

	sort(edges.begin(), edges.end(), [&] (array<int, 3> x, array<int, 3> y) {return x[2] < y[2];});

	for (auto &[u, v, w]: edges) tmp.first[f(u, v)] = w;

	for (int i = 1; i < m; i ++) {
		auto [u1, v1, w1] = edges[i - 1];
		auto [u2, v2, w2] = edges[i];

		if (w1 < w2) tmp.second[f(u2, v2)] = tmp.second[f(u1, v1)] + 1;
		else tmp.second[f(u2, v2)] = tmp.second[f(u1, v1)];
	}

	int pw = x;
	for (int i = 0; i < 30; i ++) {
		if (k >> i & 1) ans = merge_info(ans, tmp, pw);
		tmp = merge_info(tmp, tmp, pw);
		pw = 1ll * pw * pw % mod;
	}

	cout << ans.first[f(s, t)];

	return 0;
}