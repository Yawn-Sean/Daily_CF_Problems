#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
 
long long op(long long x, long long y) {return max(x, y);}
 
long long e() {return 0;}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int n, q, k;
	cin >> n >> q >> k;
 
	vector<long long> nums(n);
	for (auto &x: nums) cin >> x;
	sort(nums.begin(), nums.end());
 
	atcoder::segtree<long long, op, e> seg(k + 5);
 
	while (q --) {
		int l, r, x;
		cin >> l >> r >> x;
		l --;
		if (l) seg.set(l, seg.get(l) + x);
		seg.set(r, seg.get(r) - x);
		cout << (nums.end() - lower_bound(nums.begin(), nums.end(), seg.all_prod())) << '\n';
	}
 
	return 0;
}