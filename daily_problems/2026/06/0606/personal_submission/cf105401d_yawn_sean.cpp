#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long cur = 1;
	int l = 1, r = 2 * n + 1;
	cout << 1;
	for (int i = 1; i < n + 2; i ++) {
		if (i & 1) cur += r, r -= 2;
		else cur -= l, l += 2;
		cout << ' ' << cur;
	}

	return 0;
}