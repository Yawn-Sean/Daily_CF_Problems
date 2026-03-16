#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/segtree"
#include "atcoder/fenwicktree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int op(int x, int y) {return max(x, y);}

int e() {return 0;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, M = 5e5, mod = 998244353;
	cin >> t;

	vector<int> f(M + 1), cnt(M + 1, 2);

	f[0] = 1;
	for (int i = 1; i <= M; i ++)
		f[i] = 1ll * i * f[i - 1] % mod;
	
	cnt[1] = 0;
	cnt[2] = 0;
	cnt[10] = 3;
	cnt[11] = 3;
	cnt[12] = 3;

	for (int i = 9; i > 2; i --) cnt[i] = cnt[f[i]] + 1;

	while (t --) {
		int n, q;
		cin >> n >> q;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		auto tmp = nums;
		vector<int> op_cnt(n);
		for (int i = 0; i < n; i ++) op_cnt[i] = cnt[nums[i]];

		atcoder::fenwick_tree<long long> fen(n);
		atcoder::segtree<int, op, e> seg(op_cnt);

		for (int i = 0; i < n; i ++) fen.add(i, nums[i]);

		while (q --) {
			int o, l, r;
			cin >> o >> l >> r;

			if (o == 1) {
				l --;
				while (true) {
					int p = seg.max_right(l, [&] (int x) {return x == 0;});
					if (p >= r) break;

					op_cnt[p] --;
					if (op_cnt[p] == 0) {
						if (tmp[p]) {
							fen.add(p, -nums[p]);
							nums[p] = 0;
						}
					}
					else if (op_cnt[p] == 1) {
						if (tmp[p] == 10) {
							fen.add(p, 818355289);
							nums[p] = 821984089;
						}
						else if (tmp[p] == 11) {
							fen.add(p, 604139442);
							nums[p] = 644056242;
						}
						else if (tmp[p] == 12) {
							fen.add(p, 48654759);
							nums[p] = 527656359;
						}
						else {
							fen.add(p, f[nums[p]] - nums[p]);
							nums[p] = f[nums[p]];
						}
					}
					else {
						fen.add(p, f[nums[p]] - nums[p]);
						nums[p] = f[nums[p]];
					}
					seg.set(p, seg.get(p) - 1);
					l = p + 1;
				}
			}
			else cout << fen.sum(l - 1, r) % mod << '\n';
		}
	}

	return 0;
}