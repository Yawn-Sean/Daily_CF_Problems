#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")
#include "atcoder/fenwicktree.hpp"

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> v1(n), v2(n);
	for (auto &x: v1) cin >> x;
	for (auto &x: v2) cin >> x;

	vector<array<int, 3>> queries(q);
	for (auto &[l, r, k]: queries) cin >> l >> r >> k, l --;

	int B = 320;

	vector<int> order(q);

	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&] (int i, int j) {
		int l1 = queries[i][0] / B, r1 = queries[i][1];
		int l2 = queries[j][0] / B, r2 = queries[j][1];

		if (l1 != l2) return l1 < l2;
		if (l1 % 2) return r1 < r2;
		else return r1 > r2;
	});

	int M = 1e5 + 1;
	vector<int> cnt1(M, 0), cnt2(M, 0);
	atcoder::fenwick_tree<int> fen1(M), fen2(M);

	vector<long long> outs(q);

	int pl = 0, pr = 0;

	for (auto &qidx: order) {
		auto [l, r, k] = queries[qidx];

		while (pl > l) {
			pl --;
			if (v1[pl] < M) {
				cnt1[v1[pl]] ++;
				fen1.add(v1[pl], 1);
			}
			if (v2[pl] < M) {
				cnt2[v2[pl]] ++;
				fen2.add(v2[pl], 1);
			}
		}

		while (pr < r) {
			if (v1[pr] < M) {
				cnt1[v1[pr]] ++;
				fen1.add(v1[pr], 1);
			}
			if (v2[pr] < M) {
				cnt2[v2[pr]] ++;
				fen2.add(v2[pr], 1);
			}
			pr ++;
		}

		while (pl < l) {
			if (v1[pl] < M) {
				cnt1[v1[pl]] --;
				fen1.add(v1[pl], -1);
			}
			if (v2[pl] < M) {
				cnt2[v2[pl]] --;
				fen2.add(v2[pl], -1);
			}
			pl ++;
		}

		while (pr > r) {
			pr --;
			if (v1[pr] < M) {
				cnt1[v1[pr]] --;
				fen1.add(v1[pr], -1);
			}
			if (v2[pr] < M) {
				cnt2[v2[pr]] --;
				fen2.add(v2[pr], -1);
			}
		}

		long long ans = 0;
		int w1 = 0, w2 = 0;

		for (int i = 1; i * i <= k; i ++) {
			ans += 1ll * cnt1[i] * fen2.sum(0, k / i + 1);
			ans += 1ll * cnt2[i] * fen1.sum(0, k / i + 1);
			w1 += cnt1[i], w2 += cnt2[i];
		}

		ans -= 1ll * w1 * w2;
		outs[qidx] = ans;
	}

	for (auto &v: outs) cout << v << '\n';

	return 0;
}