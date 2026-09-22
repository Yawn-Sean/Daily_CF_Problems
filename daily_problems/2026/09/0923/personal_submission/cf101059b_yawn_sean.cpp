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

	int n, M = 1e5 + 5;
	cin >> n;

	vector<int> first_pos(M, -1), last_pos(M, -1), res(M);

	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;

		if (first_pos[x] == -1) first_pos[x] = i;
		else res[x] = max(res[x], i - last_pos[x] - 1);

		last_pos[x] = i;
	}

	int ans = n;

	for (int i = 0; i < M; i ++) {
		if (first_pos[i] != -1) {
			res[i] = max(res[i], first_pos[i] + n - 1 - last_pos[i]);
			ans = min(ans, res[i]);
		}
	}

	cout << ans + n;

	return 0;
}