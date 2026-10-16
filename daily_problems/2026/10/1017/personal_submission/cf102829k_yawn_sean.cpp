#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> pts(n);
	for (auto &[x, y]: pts) cin >> x >> y;

	int mod = 1e9 + 7;

	vector<int> pw2(n + 1);	pw2[0] = 1;
	for (int i = 1; i <= n; i ++) pw2[i] = pw2[i - 1] * 2 % mod;

	int ans = n;

	for (int i = 0; i < n; i ++) {
		vector<int> pos, neg;

		for (int j = 0; j < n; j ++) {
			if (i == j) continue;
			int dx = pts[j].first - pts[i].first;
			int dy = pts[j].second - pts[i].second;
			if (dy > 0 || (dy == 0 && dx > 0)) pos.emplace_back(j);
			else neg.emplace_back(j);
		}

		auto cmp = [&] (int x, int y) -> bool {
			int dx1 = pts[x].first - pts[i].first;
			int dy1 = pts[x].second - pts[i].second;
			int dx2 = pts[y].first - pts[i].first;
			int dy2 = pts[y].second - pts[i].second;
			return 1ll * dx1 * dy2 > 1ll * dx2 * dy1;
		};

		sort(pos.begin(), pos.end(), cmp);
		sort(neg.begin(), neg.end(), cmp);

		vector<int> total;
		total.insert(total.end(), pos.begin(), pos.end());
		total.insert(total.end(), neg.begin(), neg.end());

		for (int i = 0; i < n - 1; i ++) total.emplace_back(total[i]);

		int r = 0;

		for (int l = 0; l < n - 1; l ++) {
			r = max(r, l + 1);

			while (r < l + n - 1) {
				int dx1 = pts[total[l]].first - pts[i].first;
				int dy1 = pts[total[l]].second - pts[i].second;
				int dx2 = pts[total[r]].first - pts[i].first;
				int dy2 = pts[total[r]].second - pts[i].second;

				if (1ll * dx1 * dy2 > 1ll * dx2 * dy1) r ++;
				else break;
			}

			ans += pw2[r - l - 1];
			ans %= mod;
		}
	}

	cout << ans;

	return 0;
}