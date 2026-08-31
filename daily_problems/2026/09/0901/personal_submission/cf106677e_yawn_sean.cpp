#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int n;
		cin >> n;

		if (!n) break;

		vector<pair<int, int>> items(n);
		int must_buy = n;

		for (auto &[a, b]: items) {
			cin >> a >> b;
			must_buy = max(must_buy - b, 1);
		}

		sort(items.begin(), items.end());

		int chosen = -1;
		long long ans = 0;

		for (int i = 0; i < n; i ++) {
			auto [a, b] = items[i];
			if (b) {
				chosen = i;
				must_buy --;
				ans += a;
				break;
			}
		}

		for (int i = 0; i < n; i ++) {
			auto [a, b] = items[i];
			if (must_buy && i != chosen) {
				must_buy --;
				ans += a;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}