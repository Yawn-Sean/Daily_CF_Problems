#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

const long long inf = 7e18;

long long op(long long x, long long y) {return min(x, y);}

long long e() {return inf;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	long long a, b;
	cin >> n >> q >> a >> b;

	vector<array<long long, 3>> pts(n);
	for (auto &[x, y, c]: pts) cin >> x >> y >> c;

	sort(pts.begin(), pts.end());

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&] (int i, int j) {return pts[i][1] < pts[j][1];});

	vector<pair<int, int>> queries(q);
	for (auto &[x, y]: queries) cin >> x >> y;

	vector<int> solve_order(q);
	iota(solve_order.begin(), solve_order.end(), 0);
	sort(solve_order.begin(), solve_order.end(), [&] (int i, int j) {return queries[i].second < queries[j].second;});

	vector<long long> up_left(n), up_right(n);

	for (int i = 0; i < n; i ++) {
		up_left[i] = -a * pts[i][0] + b * pts[i][1] + pts[i][2];
		up_right[i] = a * pts[i][0] + b * pts[i][1] + pts[i][2];
	}

	atcoder::segtree<long long, op, e> seg_up_left(up_left), seg_up_right(up_right), seg_down_left(n), seg_down_right(n);

	vector<long long> outs(q);
	int pt = 0;

	for (auto &i: solve_order) {
		while (pt < n && pts[order[pt]][1] < queries[i].second) {
			int idx = order[pt];
			seg_up_left.set(idx, inf);
			seg_up_right.set(idx, inf);
			seg_down_left.set(idx, -a * pts[idx][0] - b * pts[idx][1] + pts[idx][2]);
			seg_down_right.set(idx, a * pts[idx][0] - b * pts[idx][1] + pts[idx][2]);
			pt ++;
		}

		int l = 0, r = n - 1;

		while (l <= r) {
			int mid = (l + r) / 2;
			if (pts[mid][0] <= queries[i].first) l = mid + 1;
			else r = mid - 1;
		}

		long long ans = inf;
		ans = min(ans, seg_up_left.prod(0, l) + a * queries[i].first - b * queries[i].second);
		ans = min(ans, seg_up_right.prod(l, n) - a * queries[i].first - b * queries[i].second);
		ans = min(ans, seg_down_left.prod(0, l) + a * queries[i].first + b * queries[i].second);
		ans = min(ans, seg_down_right.prod(l, n) - a * queries[i].first + b * queries[i].second);

		outs[i] = ans;
	}

	for (auto &x: outs) cout << x << '\n';

	return 0;
}