#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> recs(n);
	for (auto &[x, y]: recs) {
		cin >> x >> y;
		if (x < y) swap(x, y);
	}

	sort(recs.rbegin(), recs.rend());

	int cur = 0, ans = 0;

	for (auto &[x, y]: recs) {
		cur = min(cur + y, x);
		ans = max(ans, cur);
	}

	cout << ans;

	return 0;
}