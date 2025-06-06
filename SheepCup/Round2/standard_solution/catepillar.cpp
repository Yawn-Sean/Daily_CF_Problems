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
		
		vector<int> que(n), dis(n, -1);
		int l, r;

		l = 0, r = 1;
		que[l] = 0, dis[0] = 0;

		while (l < r) {
			int u = que[l];
			l ++;
			for (auto &v: path[u]) {
				if (dis[v] == -1) {
					dis[v] = dis[u] + 1;
					que[r] = v;
					r ++;
				}
			}
		}

		int u = max_element(dis.begin(), dis.end()) - dis.begin();
		for (int i = 0; i < n; i ++)
		 	dis[i] = -1;
		
		l = 0, r = 1;
		que[l] = u, dis[u] = 0;
		vector<int> parent(n, -1);

		while (l < r) {
			int u = que[l];
			l ++;
			for (auto &v: path[u]) {
				if (dis[v] == -1) {
					dis[v] = dis[u] + 1;
					que[r] = v;
					parent[v] = u;
					r ++;
				}
			}
		}

		u = max_element(dis.begin(), dis.end()) - dis.begin();
		vector<int> vis(n, 0);
		vis[u] = 1;
		while (parent[u] >= 0) {
			u = parent[u];
			vis[u] = 1;
		}

		bool flg = true;
		for (int i = 0; i < n; i ++) {
			if (!vis[i]) {
				bool f = false;
				for (auto &j: path[i]) {
					if (vis[j]) {
						f = true;
					}
				}
				if (!f) flg = false;
			}
		}
		cout << (flg ? "YES\n" : "NO\n");
	}

    return 0;
}