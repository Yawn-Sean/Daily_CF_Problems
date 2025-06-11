#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
#include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> pos(n);
	for (auto &v: pos) cin >> v, v --;

	vector<array<int, 3>> edges(k);

	for (int i = 0; i < k; i ++) {
		for (int j = 0; j < 3; j ++) {
			cin >> edges[i][j];
		}
		edges[i][0] --, edges[i][1] --;
	}

	vector<int> cnt(m, 0);
	for (auto &x: pos) cnt[x] ++;

	int l = 0, r = 1e9, inf = 100;
	while (l <= r) {
		int mid = (l + r) / 2;
		atcoder::mf_graph<int> mf(m * 250 + 2);
		int src = m * 250, dst = src + 1;

		for (int i = 0; i < m; i ++) {
			if (cnt[i]) {
				mf.add_edge(src, i, cnt[i]);
			}
		}

		for (int i = 0; i < 249; i ++) {
			for (int j = 0; j < m; j ++) {
				mf.add_edge(i * m + j, (i + 1) * m + j, inf);
			}
			for (auto &e: edges) {
				int u = e[0], v = e[1], t = e[2];
				if (t < mid - 248 + i) {
					mf.add_edge(i * m + u, (i + 1) * m + v, 1);
					mf.add_edge(i * m + v, (i + 1) * m + u, 1);
				}
			}
		}
		mf.add_edge(249 * m, dst, inf);
		if (mf.flow(src, dst) == n) r = mid - 1;
		else l = mid + 1;
	}
	cout << l;

    return 0;
}