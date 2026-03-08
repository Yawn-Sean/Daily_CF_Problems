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

	int t;
	cin >> t;

	while (t --) {
		int n, m, k;
		cin >> n >> m >> k;

		if (k == 1) cout << ((n * m & 1) ? "Munir" : "Matthew");
		else if ((n & 1) || (m & 1) || k >= 4) cout << "Munir";
		else cout << "Matthew";

		cout << '\n';
	}

	return 0;
}