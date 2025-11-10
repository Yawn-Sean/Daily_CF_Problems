#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		long long ans = 0;

		vector<vector<int>> cnt(2, vector<int>(2 * n + 5, 0));
		int cur = n + 2, msk = 0;

		while (n --) {
			cnt[msk][cur] ++;

			int x;
			cin >> x;

			if (x & 1) msk ^= 1, cur --;
			else cur ++;

			ans += cnt[msk][cur - 1] + cnt[msk ^ 1][cur + 1];
		}

		cout << ans << '\n';
	}

	return 0;
}