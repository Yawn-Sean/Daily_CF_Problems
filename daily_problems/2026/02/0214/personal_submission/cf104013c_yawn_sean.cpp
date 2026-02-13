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

	auto op = [&] (int x, int y) -> void {
		cout << x << ' ' << y << endl;
		string s; cin >> s;
		if (s == "WIN") exit(0);
	};

	int n;
	cin >> n;

	for (int i = 0; i < n; i ++) {
		for (int j = 2; j <= n; j ++) op(j - 1, j);
		for (int j = n; j >= 2; j --) op(j - 1, j);
	}

	return 0;
}