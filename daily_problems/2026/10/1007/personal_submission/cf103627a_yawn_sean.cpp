#include <bits/stdc++.h>
using namespace std;
#include "atcoder/segtree.hpp"

typedef array<int, 5> node;

const int inf = 1e9;

node e() {return {inf, inf, inf, inf, inf};}

node op(node x, node y) {
	return {min({x[0], y[0], x[2] + y[4], x[3] + y[1]}), min(x[1], y[1]), min(x[2], y[2]), min(x[3], y[3]), min(x[4], y[4])};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;

	vector<array<int, 4>> queries, pts;

	for (int i = 0; i < q; i ++) {
		int t, s, x, y;
		cin >> t >> s >> x >> y;
		queries.push_back({t, s, x, y});
		int diff = (s == 1 ? x - y : y - x);
		pts.push_back({diff, s, x, y});
	}

	sort(pts.begin(), pts.end());

	vector<int> cnt(q);

	atcoder::segtree<node, op, e> seg(q);

	for (auto &[t, s, x, y]: queries) {
		int diff = (s == 1 ? x - y : y - x);
		array<int, 4> tmp = {diff, s, x, y};
		int p = lower_bound(pts.begin(), pts.end(), tmp) - pts.begin();
		if (t == 1) {
			if (cnt[p] == 0) {
				if (s == 1) seg.set(p, {inf, x, y, inf, inf});
				else seg.set(p, {inf, inf, inf, x, y});
			}
			cnt[p] ++;
		}
		else {
			cnt[p] --;
			if (cnt[p] == 0) seg.set(p, e());
		}

		int ans = seg.all_prod()[0];
		cout << (ans < inf ? ans : -1) << '\n';
	}

	return 0;
}