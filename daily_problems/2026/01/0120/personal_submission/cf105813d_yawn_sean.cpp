#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

#include "atcoder/fenwicktree"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> vis(1 << 20, 0);
	while (n --) {
		int x;
		cin >> x;
		vis[x] ++;
	}

	vector<atcoder::fenwick_tree<int>> fens(21);

	for (int i = 0; i <= 20; i ++) {
		fens[i] = atcoder::fenwick_tree<int>(1 << i + 1);
		for (int j = 0; j < 1 << i + 1; j ++) {
			for (int k = j; k < 1 << 20; k += 1 << i + 1) {
				fens[i].add(j, vis[k]);
			}
		}
	}

	while (q --) {
		int t, x;
		cin >> t >> x;

		if (t == 1) {
			int dx = vis[x] ? -1 : 1;
			for (int i = 0; i <= 20; i ++)
				fens[i].add(x & ((1 << i + 1) - 1), dx);
			vis[x] ^= 1;
		}
		else {
			int ans = 0;
			for (int i = 0; i <= 20; i ++) {
				int l = ((3 << i) - x) & ((1 << i + 1) - 1);
				int r = l + (1 << i);

				if (r <= 1 << i + 1) ans += (fens[i].sum(l, r) & 1) ? 1 << i : 0;
				else ans += ((fens[i].sum(l, 1 << i + 1) + fens[i].sum(0, r - (1 << i + 1))) & 1) ? 1 << i : 0;
			}
			cout << ans << '\n';
		}
	}

	return 0;
}