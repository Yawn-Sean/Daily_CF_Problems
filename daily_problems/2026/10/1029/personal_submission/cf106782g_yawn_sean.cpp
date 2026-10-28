#include <bits/stdc++.h>
using namespace std;

#include "atcoder/segtree.hpp"

const long long inf = 1e18;

long long e() {return inf;}

long long op(long long x, long long y) {return min(x, y);}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int total, gas, n;
	cin >> total >> gas >> n;

	vector<pair<int, int>> stations;
	stations.emplace_back(0, 0);

	for (int i = 0; i < n; i ++) {
		int p, d;
		cin >> p >> d;

		while (2 * p + d <= 2 * stations.back().first + stations.back().second)
			stations.pop_back();

		stations.emplace_back(p, d);
	}

	n = stations.size();

	long long ans = inf;
	atcoder::segtree<long long, op, e> seg(n);

	seg.set(0, 0);

	for (int i = 0; i < n; i ++) {
		auto v = seg.prod(i, n);

		if (v < inf) {
			long long nv = v + stations[i].second;

			if (2 * (total - stations[i].first) + stations[i].second <= 2 * gas)
				ans = min(ans, total + nv);

			int l = i, r = n - 1;

			while (l <= r) {
				int mid = (l + r) / 2;

				auto [p1, d1] = stations[i];
				auto [p2, d2] = stations[mid];

				if (2 * (p2 - p1) + d1 + d2 <= 2 * gas) l = mid + 1;
				else r = mid - 1;
			}

			seg.set(r, min(seg.get(r), nv));
		}
	}

	cout << (ans < inf ? ans : -1);

	return 0;
}