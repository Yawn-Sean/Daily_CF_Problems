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

	int t;
	cin >> t;

	vector<int> saved = {1, 3, 5, 2, 4};

	while (t --) {
		int n;
		cin >> n;

		if (n == 2 || n == 3) cout << "-1\n";
		else {
			vector<int> ans;
			for (int x = 0; x < n / 5; x ++) {
				for (int i = 0; i < 5; i ++) {
					ans.emplace_back(x * 5 + saved[i]);
				}
			}

			if (n % 5 == 1) ans.emplace_back(n);
			else if (n % 5 == 2) {
				ans.back() = n;
				ans.emplace_back(n - 3);
				ans.emplace_back(n - 1);
			}
			else if (n % 5 == 3) {
				ans.back() = n - 1;
				ans.emplace_back(n - 4);
				ans.emplace_back(n - 2);
				ans.emplace_back(n);
			}
			else if (n % 5 == 4) {
				ans.emplace_back(n - 2);
				ans.emplace_back(n);
				ans.emplace_back(n - 3);
				ans.emplace_back(n - 1);
			}

			for (int i = 0; i < n; i ++)
				cout << ans[i] << (i < n - 1 ? ' ' : '\n');
		}
	}

	return 0;
}