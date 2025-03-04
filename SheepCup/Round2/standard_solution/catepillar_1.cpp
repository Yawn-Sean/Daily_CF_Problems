#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
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

	int t;
	cin >> t;
	
	while (t -- ) {
		int n;
		cin >> n;

		vector<vector<int>> path(n);
		for (int i = 0; i < n - 1; i ++) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		int cur = 0;
		
		for (int i = 0; i < n; i ++) {
			int v = 0;
			for (auto &j: path[i])
				v += path[j].size() >= 2;
			cur = max(cur, v);
		}

		cout << (cur >= 3 ? "NO\n" : "YES\n");
	}

    return 0;
}