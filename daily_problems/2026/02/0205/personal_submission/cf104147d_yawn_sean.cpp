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

	ifstream fin("dotak.in");

	int t;
	fin >> t;

	while (t --) {
		int n, k;
		fin >> n >> k;

		int v = 1ll * n * k % (k + 1);
		cout << ((v & 1) || (v == k) ? "Omda" : "Teemo") << '\n';
	}

	return 0;
}