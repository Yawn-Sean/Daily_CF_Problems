#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

long long bound = 2e18;

long long op(long long x, long long y) {
	return min(x + y, bound);
}

long long e() {return 0;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		long long p;
		cin >> n >> p;

		vector<pair<long long, long long>> stalls(n);
		for (auto &[x, y]: stalls) cin >> x >> y;

		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&] (int i, int j) {return stalls[i].first > stalls[j].first;});

		long long ans = -1;
		int chosen_threshold = -1;

		atcoder::segtree<long long, op, e> seg(n), seg_happiness(n);

		for (int i = 0; i < n; i ++) {
			seg.set(order[i], stalls[order[i]].second);
			seg_happiness.set(order[i], stalls[order[i]].first);

			if (i == n - 1 || stalls[order[i]].first != stalls[order[i + 1]].first) {
				int cur_pos = 0;
				long long cur_p = p, res = 0;

				while (true) {
					int l = cur_pos, r = n - 1;

					while (l <= r) {
						int mid = (l + r) / 2;
						if (stalls[mid].second > cur_p) l = mid + 1;
						else r = mid - 1;
					}

					cur_pos = l;
					if (cur_pos == n) break;

					int n_cur_pos = seg.max_right(cur_pos, [&] (long long x) {return x <= cur_p;});
					cur_p -= seg.prod(cur_pos, n_cur_pos);
					res += seg_happiness.prod(cur_pos, n_cur_pos);

					cur_pos = n_cur_pos;
				}

				if (res >= ans) {
					ans = res;
					chosen_threshold = (i != n - 1 ? stalls[order[i + 1]].first : 0);
				}
			}
		}

		cout << ans << ' ' << chosen_threshold << '\n';
	}

	return 0;
}