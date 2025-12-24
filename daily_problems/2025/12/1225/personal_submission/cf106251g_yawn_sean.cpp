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
		int n, b;
		cin >> n >> b;

		vector<int> nums(n);
		int tot = 0;

		for (auto &v: nums) 
			cin >> v, tot = (tot + v) % (b - 1);

		if (tot) cout << "NO\n";
		else {
			cout << "YES\n";

			vector<int> res;
			int cur = 0;

			for (auto &x: nums) {
				res.emplace_back((1ll * cur * b + x) / (b - 1));
				cur = (cur + x) % (b - 1);
			}

			cout << n + 2 << '\n';
			cout << "1 0";
			for (auto &v: res) cout << ' ' << v; cout << '\n';
			cout << '1';
			for (auto &v: res) cout << ' ' << v; cout << " 0\n";
		}
	}

	return 0;
}