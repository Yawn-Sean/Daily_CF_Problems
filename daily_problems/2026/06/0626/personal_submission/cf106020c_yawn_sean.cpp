#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

long long op(long long x, long long y) {return gcd(x, y);}

long long e() {return 0;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> nums(n);
	for (auto &x: nums) cin >> x;

	vector<int> deg(n, 0);
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		deg[u] ++, deg[v] ++;
	}

	vector<int> tmp;
	for (int i = 0; i < n; i ++) if (deg[i] == 1) tmp.emplace_back(i);
	for (int i = 0; i < n; i ++) if (deg[i] > 1) tmp.emplace_back(i);

	vector<long long> vals(n, 0);
	vector<int> pos(n, 0);

	for (int i = 0; i < n; i ++) {
		vals[i] = nums[tmp[i]];
		pos[tmp[i]] = i;
	}

	atcoder::segtree<long long, op, e> seg(vals);

	int q;
	cin >> q;

	while (q --) {
		int idx;
		long long val;
		cin >> idx >> val; idx --;

		vals[pos[idx]] = val;
		seg.set(pos[idx], val);

		int k = min(16, n);
		long long cur = seg.prod(k, n);

		vector<long long> pref = {0};
		for (int i = 0; i < k - 1; i ++) pref.emplace_back(gcd(pref.back(), vals[i]));

		bool flg = false;
		for (int i = k - 1; i >= 0; i --) {
			if (deg[tmp[i]] == 1 && gcd(pref[i], cur) == 1) flg = true;
			cur = gcd(cur, vals[i]);
		}

		cout << (flg ? "Yes" : "No") << '\n';
	}

	return 0;
}