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

	set<int> vis;
	vis.insert(0);

	int bound = 1e9;
	auto dfs = [&] (auto &self, int x, int y, long long cur) -> void {
		if (cur > bound) return ;
		vis.insert(cur);
		self(self, x, y, 10 * cur + x);
		self(self, x, y, 10 * cur + y);
	};

	for (int i = 1; i < 10; i ++) {
		for (int j = 0; j < 10; j ++) {
			dfs(dfs, i, j, i);
		}
	}

	int n;
	cin >> n;

	int ans = 0;
	for (auto &x: vis) {
		if (vis.find(n - x) != vis.end()) {
			ans ++;
		}
	}

	cout << (ans + 1) / 2;

	return 0;
}