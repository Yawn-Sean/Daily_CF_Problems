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

	cout << -1 << ' ' << 2 << '\n';
	cout << 0 << ' ' << 2 << '\n';
	cout << n - 1 << ' ' << 1 << '\n';
	cout << n << ' ' << 0 << '\n';
	cout << n - 1 << ' ' << 0 << '\n';
	cout << 0 << ' ' << 1 << '\n';

	return 0;
}