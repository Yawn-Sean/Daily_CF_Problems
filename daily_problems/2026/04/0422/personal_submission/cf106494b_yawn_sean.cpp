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

	vector<int> ls(n), rs(n);
	for (auto &x: ls) cin >> x;
	for (auto &x: rs) cin >> x;

	int idx = max_element(ls.begin(), ls.end()) - ls.begin();
	long long total = 0;

	for (int i = 0; i < n; i ++) {
		if (i != idx) {
			total += min(rs[i], ls[idx]);
		}
	}

	if (total < ls[idx]) cout << -1;
	else {
		for (int i = 0; i < n; i ++) {
			cout << min(rs[i], ls[idx]) << "\n "[i < n - 1];
		}
	}

	return 0;
}