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

	vector<string> names(n);
	vector<int> cur(n), adds(n);

	int total = 0, total_other = 0;
	for (int i = 0; i < n; i ++) {
		cin >> names[i] >> cur[i];

		if (cur[i] == 0) adds[i] = 49;
		else if (cur[i] == 100) cur[i] = 9950, adds[i] = 50;
		else cur[i] = cur[i] * 100 - 50, adds[i] = 99;

		total += cur[i];
		total_other += adds[i];
	}

	if (total > 10000 || total + total_other < 10000) cout << "IMPOSSIBLE\n";
	else {
		int resid = 10000 - total;
		for (int i = 0; i < n; i ++) {
			int mi = cur[i] + max(0, resid - (total_other - adds[i]));
			int ma = cur[i] + min(adds[i], resid);

			cout << names[i];
			cout << ' ' << mi / 100 << (mi % 100 < 10 ? ".0" : ".") << mi % 100; 
			cout << ' ' << ma / 100 << (ma % 100 < 10 ? ".0" : ".") << ma % 100;
			cout << '\n';
		}
	}

	return 0;
}