#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/fenwicktree"
#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int mod = 1e9 + 7;

int op(int x, int y) {
	return 1ll * x * y % mod;
}

int e() {return 1;}

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> revs(101);
	for (int i = 1; i <= 100; i ++)
		revs[i] = quickPow(i, mod - 2, mod);

	vector<int> nums(n), probs(n);
	atcoder::fenwick_tree<long long> vals(n);

	for (int i = 0; i < n; i ++) {
		cin >> nums[i];
		probs[i] = 1ll * (100 - nums[i]) * revs[100] % mod;
		vals.add(i, 1ll * nums[i] * revs[100 - nums[i]] % mod);
	}

	atcoder::segtree<int, op, e> seg(probs);

	while (q --) {
		int t;
		cin >> t;

		if (t == 1) {
			int idx, val;
			cin >> idx >> val;
			idx --;

			seg.set(idx, 1ll * (100 - val) * revs[100] % mod);
			vals.add(idx, 1ll * val * revs[100 - val] % mod - 1ll * nums[idx] * revs[100 - nums[idx]] % mod);

			nums[idx] = val;
		}
		else {
			int idx;
			cin >> idx;
			cout << (vals.sum(idx, n) + 1) % mod * seg.prod(idx, n) % mod << '\n';
		}
	}

	return 0;
}