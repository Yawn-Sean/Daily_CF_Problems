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

	map<int, int> mp;
	int bound = 1e9;

	for (int i = 100000; i >= 0; i --) {
		long long val = 1;
		for (int j = 0; j <= i; j ++) {
			if (val > bound) break;
			mp[val] = i + 1;
			val = val * (i - j) / (j + 1);
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int x;
		cin >> x;
		auto pt = mp.find(x);

		if (pt != mp.end()) cout << pt->second << '\n';
		else cout << x + 1 << '\n';
	}

	return 0;
}