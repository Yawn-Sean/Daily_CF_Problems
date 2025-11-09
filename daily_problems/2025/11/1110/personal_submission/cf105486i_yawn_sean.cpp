#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

#include "atcoder/segtree"

int op(int x, int y) {return gcd(x, y);}

int e() {return 0;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, M = 2e5;
	cin >> t;

	vector<int> f(M + 1, 0);
	for (int i = 1; i <= M; i ++) {
		for (int j = i; j <= M; j += i) {
			f[j] ++;
		}
	}

	while (t --) {
		int n, q;
		cin >> n >> q;

		f[0] = n;

		vector<int> nums(n), vals(n, 0);

		for (auto &x: nums) cin >> x;
		for (int i = 1; i < n; i ++) {
			if (nums[i] < nums[i - 1]) {
				vals[i] = i;
			}
		}

		atcoder::segtree<int, op, e> seg(vals);

		cout << f[seg.all_prod()] << '\n';

		while (q --) {
			int idx, val;
			cin >> idx >> val;
			idx --;

			nums[idx] = val;

			if (idx) {
				vals[idx] = (nums[idx] < nums[idx - 1] ? idx : 0);
				seg.set(idx, vals[idx]);
			}
			if (idx + 1 < n) {
				vals[idx + 1] = (nums[idx + 1] < nums[idx] ? idx + 1 : 0);
				seg.set(idx + 1, vals[idx + 1]);
			}
			cout << f[seg.all_prod()] << '\n';
		}
	}

	return 0;
}