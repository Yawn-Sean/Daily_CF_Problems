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

	int M = 1e6 + 5;
	vector<int> pr(M);
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i < M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j < M; j += i) {
				pr[j] = i;
			}
		}
	}

	auto prime_factors = [&] (int x) -> vector<int> {
		vector<int> ans;
		while (x > 1) {
			int p = pr[x];
			ans.emplace_back(p);
			while (x % p == 0) x /= p;
		}
		return ans;
	};

	int t;
	cin >> t;

	vector<int> vis(M, 0);

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		bool flg = true;
		for (auto &x: nums) {
			for (auto &p: prime_factors(x)) {
				if (vis[p] > x) flg = false;
				vis[p] = x;
			}
		}

		cout << (flg ? "SI\n" : "NO\n");

		for (auto &x: nums) {
			for (auto &p: prime_factors(x)) {
				vis[p] = 0;
			}
		}
	}

	return 0;
}