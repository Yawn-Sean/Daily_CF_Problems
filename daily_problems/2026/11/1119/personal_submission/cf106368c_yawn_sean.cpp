#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, D, t;
	cin >> n >> D >> t;

	vector<pair<int, int>> items(n);
	for (auto &[x, y]: items) cin >> x >> y;

	vector<int> to_use(n, 1);
	priority_queue<pair<int, int>> pq;

	for (int i = n - 1; i >= 0; i --) {
		auto [x, y] = items[i];
		pq.push({-y, i});

		while (D - x + 1 < pq.size()) {
			to_use[pq.top().second] = 0;
			pq.pop();
		}
	}

	long long ans = 0;

	for (int i = 0; i < n; i ++) {
		if (to_use[i]) {
			ans += items[i].second;
		}
	}

	cout << ans << '\n';

	if (t == 2) {
		for (int i = n - 1; i > 0; i --) to_use[i - 1] += to_use[i];
		for (int i = 0; i < n; i ++) to_use[i] = min(D - to_use[i] + 1, D);
		for (int i = 0; i < n; i ++) cout << to_use[i] << " \n"[i == n - 1];
	}

	return 0;
}