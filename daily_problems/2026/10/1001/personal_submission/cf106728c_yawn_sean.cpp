#include <bits/stdc++.h>
#include "atcoder/segtree.hpp"
using namespace std;

long long op(long long x, long long y) {return min(x, y);}

long long e() {return 4e18;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k, l, n;
	cin >> k >> l >> n;

	vector<int> ws(n);
	for (auto &x: ws) cin >> x;

	if (k == 1) {
		long long total = 0;
		for (auto &x: ws) total += x;
		cout << total * (l - 1);
	}
	else {
		vector<vector<atcoder::segtree<long long, op, e>>> segs(l - 1);
		vector<vector<long long>> tags(l - 1);
		vector<long long> tmp(k, 0);

		int cur = 1;
		for (int i = 0; i < l - 1; i ++) {
			for (int j = 0; j < cur; j ++) {
				segs[i].push_back(atcoder::segtree<long long, op, e>(tmp));
				tags[i].push_back(0);
			}
			cur *= k;
		}

		for (auto &w: ws) {
			int idx = 0, pos;

			for (int i = 0; i < l - 1; i ++) {
				auto v = segs[i][idx].all_prod();
				idx = idx * k + segs[i][idx].max_right(0, [&] (long long x) {return x > v;});
			}

			long long delta = 0;

			for (int i = l - 2; i >= 0; i --) {
				pos = idx % k, idx /= k;
				long long old = segs[i][idx].all_prod();
				segs[i][idx].set(pos, segs[i][idx].get(pos) + w + delta);
				delta = segs[i][idx].all_prod() - old;
			}
		}

		cout << segs[0][0].all_prod();
	}

	return 0;
}