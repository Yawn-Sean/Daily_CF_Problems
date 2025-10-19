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

	int n;
	cin >> n;

	auto solve = [&] (auto &self, int x) -> vector<int> {
		if (x == 1) return {1};
		vector<int> ans;
		for (auto &v: self(self, x / 2)) ans.emplace_back(2 * v);
		for (auto &v: self(self, x - x / 2)) ans.emplace_back(2 * v - 1);
		return ans;
	};

	for (auto &v: solve(solve, n)) cout << v << ' ';

	return 0;
}