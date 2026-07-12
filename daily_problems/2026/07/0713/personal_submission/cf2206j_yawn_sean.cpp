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

	int n, q;
	cin >> n >> q;

	vector<int> p1(n), p2(n), pos1(n), pos2(n);

	for (int i = 0; i < n; i ++) {
		cin >> p1[i]; p1[i] --;
		pos1[p1[i]] = i;
	}

	for (int i = 0; i < n; i ++) {
		cin >> p2[i]; p2[i] --;
		pos2[p2[i]] = i;
	}

	auto cost = [&] (int idx) -> int {
		if (idx <= 0 || idx >= n) return 0;
		int x = p2[idx - 1], y = p2[idx];
		int px = pos1[x], py = pos1[y];
		return (py - px + n) % n - 1;
	};

	auto calc = [&] (int idx1, int idx2) -> int {
		if (idx1 > idx2) swap(idx1, idx2);
		int ans = 0;
		ans += cost(idx1);
		ans += cost(idx1 + 1);
		if (idx1 + 1 != idx2) ans += cost(idx2);
		ans += cost(idx2 + 1);
		return ans;
	};

	long long ans = 0;
	for (int i = 1; i < n; i ++) ans += cost(i);

	q --;
	cout << ans + pos1[p2[0]] << '\n';

	while (q --) {
		int c, x, y;
		cin >> c >> x >> y;
		x --, y --;

		if (c == 1) {
			ans -= calc(pos2[p1[x]], pos2[p1[y]]);

			swap(p1[x], p1[y]);
			swap(pos1[p1[x]], pos1[p1[y]]);

			ans += calc(pos2[p1[x]], pos2[p1[y]]);
		}
		else {
			ans -= calc(x, y);

			swap(p2[x], p2[y]);
			swap(pos2[p2[x]], pos2[p2[y]]);

			ans += calc(x, y);
		}

		cout << ans + pos1[p2[0]] << '\n';
	}

	return 0;
}