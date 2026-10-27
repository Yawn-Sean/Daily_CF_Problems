#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<int> p(n), q(m);
		for (auto &x: p) cin >> x;
		for (auto &x: q) cin >> x;

		int l = 0, r = min(n, m);

		while (l <= r) {
			int mid = (l + r) / 2;
			vector<int> v1, v2;

			for (auto &x: p) if (x <= mid) v1.emplace_back(x);
			for (auto &x: q) if (x <= mid) v2.emplace_back(x);

			if (v1 == v2) l = mid + 1;
			else r = mid - 1;
		}

		cout << n + m - r * 2 << '\n';
	}

	return 0;
}