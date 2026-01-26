#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

	vector<int> digits = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	vector<int> ans(22, 1000);

	for (int i = 0; i < 10; i ++) ans[digits[i]] = min(ans[digits[i]], i);

	for (int i = 1; i < 10; i ++) {
		for (int j = 0; j < 10; j ++) {
			int d = digits[i] + digits[j];
			ans[d] = min(ans[d], i * 10 + j);
		}
	}

	for (int i = 1; i < 10; i ++) {
		for (int j = 0; j < 10; j ++) {
			for (int k = 0; k < 10; k ++) {
				int d = digits[i] + digits[j] + digits[k];
				ans[d] = min(ans[d], i * 100 + j * 10 + k);
			}
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		if (n <= 21) cout << ans[n] << '\n';
		else {
			int v = (n - 15) % 7 + 15;
			cout << ans[v] << string((n - v) / 7, '8') << '\n';
		}
	}

	return 0;
}