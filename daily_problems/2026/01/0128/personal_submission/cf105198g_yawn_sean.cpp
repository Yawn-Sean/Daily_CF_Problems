#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (n == 3) {
		cout << "1 1 2\n";
		cout << "1 4 3\n";
		cout << "2 3 3\n";
	}
	else {
		vector<vector<int>> ans(n, vector<int>(n, 1));
		int v = 1024 - n;

		if (n > 2) {
			if (n & 1) {
				ans[0][0] += v;
				ans[1][n - 2] += v;
				for (int i = 2; i < n - 2; i ++)
					ans[i][i - 1] += v;
				ans[n - 2][n - 1] += v;
				ans[n - 1][n - 3] += v;
			}
			else {
				ans[0][0] += v;
				for (int i = 1; i < n - 1; i ++)
					ans[i][i + 1] += v;
				ans[n - 1][1] += v;
			}
		}

		for (auto &x: ans) {
			for (auto &y: x) cout << y << ' ';
			cout << '\n';
		}
	}

	return 0;
}