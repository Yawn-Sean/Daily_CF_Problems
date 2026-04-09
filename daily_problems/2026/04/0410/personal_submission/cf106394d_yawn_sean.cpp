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

	while (t --) {
		int n;
		cin >> n;

		int ans = n - 1, cur = 0, v = 0;

		while (n --) {
			int x;
			cin >> x;

			if (cur < 0) {
				cur += v;
				ans ++;
			}

			v = max(v, x);
			cur --;
		}

		cout << ans << '\n';
	}

	return 0;
}