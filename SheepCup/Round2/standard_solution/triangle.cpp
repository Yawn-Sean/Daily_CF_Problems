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
		vector<int> edges(3);
		for (auto &e: edges) cin >> e;

		int ans = 0;
		for (int i = 0; i < 3; i ++) {
			for (int j = i; j < 3; j ++) {
				for (int k = j; k < 3; k ++) {
					ans += (edges[i] + edges[j] > edges[k]);
				}
			}
		}
		
		cout << ans << '\n';
	}

    return 0;
}