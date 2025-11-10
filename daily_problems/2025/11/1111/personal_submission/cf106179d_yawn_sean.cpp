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

		vector<int> v1, v2;

		for (int i = 0; i < n; i ++) {
			int x; cin >> x;
			if ((i < n / 2) != (x <= n / 2)) v1.emplace_back(x);
			else v2.emplace_back(x);
		}

		if (!v1.empty() && !v2.empty()) {
			cout << 2 << '\n';
			cout << v1.size();
			for (auto &x: v1) cout << ' ' << x;
			cout << '\n';
			cout << v2.size();
			for (auto &x: v2) cout << ' ' << x;
			cout << '\n';
		}
		else {
			cout << 1 << '\n';
			cout << n;
			for (auto &x: v1) cout << ' ' << x;
			for (auto &x: v2) cout << ' ' << x;
			cout << '\n';
		}
	}

	return 0;
}