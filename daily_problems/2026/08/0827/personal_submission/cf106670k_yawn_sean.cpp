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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<long long> v1(n), v2(n);
		long long w1 = 0, w2 = 0;

		for (auto &x: v1) cin >> x, w1 += x;
		for (auto &x: v2) cin >> x, w2 += x;

		long long ans = min(w1, w2);
		ans = min(ans, min(v1[0] + v2[n - 1], v1[n - 1] + v2[0]));
		ans = min(ans, min(
			v1[0] + v1[n - 1] + *min_element(v2.begin(), v2.end()),
			v2[0] + v2[n - 1] + *min_element(v1.begin(), v1.end())
		));

		cout << ans << '\n';
	}

	return 0;
}