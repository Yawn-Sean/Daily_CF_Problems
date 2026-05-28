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

	int t;
	cin >> t;

	cout << fixed << setprecision(10);

	while (t --) {
		int n;
		cin >> n;

		vector<long long> acc(n + 1, 0);
		for (int i = 0; i < n; i ++) {
			int x;
			cin >> x;
			acc[i + 1] = acc[i] + x;
		}

		long double ans = 0;
		__int128_t cur = 0;

		for (int i = 0; i < n; i ++) {
			cur += acc[n - i] - acc[i];
			ans += (long double)cur / (i + 1);
		}

		cout << ans / n / (n + 1) * 2 << '\n';
	}

	return 0;
}