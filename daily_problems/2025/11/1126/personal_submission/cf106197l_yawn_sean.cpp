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

		vector<string> ans(n, string(n, '1'));

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < i; j ++) {
				ans[i][j] = '3';
			}
		}

		for (int i = 0; i < n / 2; i ++) {
			ans[n - i - 1][i * 2] ++;
			ans[n - i - 1][i * 2 + 1] ++;
		}

		if (n & 1) ans[n - 1][n - 1] ++;

		for (auto &s: ans) cout << s << '\n';
	}

	return 0;
}