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

	auto query = [&] (long long x, long long y) -> long long {
		cout << "? " << x << ' ' << y << endl;
		char c; long long v;
		cin >> c >> v;
		return v;
	};

	auto answer = [&] (long long x) -> void {
		cout << "! " << x << endl;
		char c; cin >> c;
	};

	auto solve = [&] (auto &self, long long x) -> long long {
		if ((x & -x) == x) return query(x, x) / 2;
		long long v = 1ll << 64 - __builtin_clzll(x);
		return query(v - x, x) - self(self, v - x);
	};

	int n;
	cin >> n;

	vector<long long> vals(n);
	for (auto &v: vals) cin >> v;
	for (auto &v: vals) answer(solve(solve, v));

	return 0;
}