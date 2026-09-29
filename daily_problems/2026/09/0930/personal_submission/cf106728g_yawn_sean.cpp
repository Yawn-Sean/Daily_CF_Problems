#include <bits/stdc++.h>
using namespace std;

#include "atcoder/lazysegtree.hpp"
#include "atcoder/fenwicktree.hpp"

int op(int x, int y) {return max(x, y);}

int e() {return 0;}

int add(int x, int y) {return x + y;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> hs(n), vs(n);
	for (auto &x: hs) cin >> x;
	for (auto &x: vs) cin >> x;

	sort(hs.begin(), hs.end());

	vector<int> cnt(n, 0);
	for (auto &x: vs) cnt[x] ++;

	for (int i = n - 2; i >= 0; i --) cnt[i] += cnt[i + 1];
	for (int i = 0; i < n; i ++) cnt[i] -= n - i;

	if (*max_element(cnt.begin(), cnt.end()) > 0) cout << -1;
	else {
		atcoder::lazy_segtree<int, op, e, int, add, add, e> seg(cnt);
		atcoder::fenwick_tree<int> fen(n);
		for (int i = 0; i < n; i ++) fen.add(i, 1);

		for (int i = 0; i < n; i ++) {
			seg.apply(0, n - i, 1);
			int p = max(seg.min_left(n - i, [&] (int x) {return x <= 0;}) - 1, 0);
			seg.apply(0, p + 1, -1);

			int target_idx = fen.lower_bound(p + 1) - 1;
			fen.add(target_idx, -1);
			cout << hs[target_idx] << " \n"[i == n - 1];
		}
	}

	return 0;
}