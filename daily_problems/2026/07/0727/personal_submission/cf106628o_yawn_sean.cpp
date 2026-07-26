#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		long long cur = 0;
		vector<int> ans(n, 0);

		ans[0] = 1;

		for (int i = 2; i <= n; i ++) {
			cout << "? " << i;
			for (int j = 1; j <= i; j ++) cout << ' ' << j;
			cout << endl;

			long long ncur;
			cin >> ncur;

			int v = i - (ncur - cur);

			for (int j = 0; j < i; j ++) {
				if (ans[j] >= v) {
					ans[j] ++;
				}
			}
			ans[i - 1] = v;

			cur = ncur;
		}

		cout << "!";
		for (auto &x: ans) cout << ' ' << x;
		cout << endl;
	}

	return 0;
}