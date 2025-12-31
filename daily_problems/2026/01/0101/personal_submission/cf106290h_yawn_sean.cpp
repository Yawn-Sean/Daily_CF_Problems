#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/lazysegtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int op(int x, int y) {return max(x, y);}

int e() {return 0;}

int mapping(int x, int y) {return x + y;}

int composition(int x, int y) {return x + y;}

int id() {return 0;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		vector<int> first_pos(n + 1, -1), last_pos(n + 1, -1), prev(n);

		for (int i = 0; i < n; i ++) {
			prev[i] = last_pos[nums[i]];
			last_pos[nums[i]] = i;

			if (first_pos[nums[i]] == -1)
				first_pos[nums[i]] = i;
		}

		int ans = 0;
		atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(n);

		for (int i = 0; i <= n; i ++) {
			if (last_pos[i] != -1) {
				ans ++;
			}
		}

		int to_add = 0;

		for (int i = 0; i < n; i ++) {
			if (last_pos[nums[i]] != i) seg.apply(prev[i] + 1, i + 1, 1);
			else {
				seg.apply(0, prev[i] + 1, -1);
				seg.apply(first_pos[nums[i]] + 1, last_pos[nums[i]] + 1, 1);
			}
			to_add = max(to_add, seg.all_prod());
		}

		cout << ans + to_add << '\n';
	}

	return 0;
}