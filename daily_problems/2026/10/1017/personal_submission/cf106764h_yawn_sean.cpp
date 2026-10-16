#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> scores(n), farthest(n, 0);

	for (auto &x: scores) cin >> x;

	for (int i = 0; i < n; i ++) {
		int radius; cin >> radius;
		int l = max(0, i - radius);
		int r = min(n - 1, i + radius);
		farthest[l] = max(farthest[l], r);
	}

	for (int i = 1; i < n; i ++) farthest[i] = max(farthest[i], farthest[i - 1]);

	int l = 1, r = 1e9 + 2e5;
	vector<int> diff(n + 1, 0);

	while (l <= r) {
		int mid = (l + r) / 2;

		int cur = 0, total = 0;
		bool flg = true;

		for (int i = 0; i < n; i ++) {
			cur += diff[i];
			int v = max(mid - (scores[i] + cur), 0);

			if (v && farthest[i] < i) {
				flg = false;
				break;
			}

			diff[farthest[i] + 1] -= v;
			cur += v, total += v;

			if (total > k) {
				flg = false;
				break;
			}
		}

		for (int i = 0; i <= n; i ++) diff[i] = 0;

		if (flg) l = mid + 1;
		else r = mid - 1;
	}

	cout << r;

	return 0;
}