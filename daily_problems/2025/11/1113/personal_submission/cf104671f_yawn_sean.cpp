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

int op(int x, int y) {return x & y;}
int e() {return -1;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, q;
	cin >> n >> k >> q;

	vector<int> nums(n);
	for (auto &x: nums) {
		cin >> x;
		if ((x & k) == k) x -= k;
		else x = -1;
	}

	atcoder::segtree<int, op, e> seg(nums);

	while (q --) {
		int l, r;
		cin >> l >> r;
		cout << (seg.prod(l - 1, r) ? "NO" : "YES") << '\n';
	}

	return 0;
}