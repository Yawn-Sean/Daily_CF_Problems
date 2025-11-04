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

	string n;
	cin >> n;

	int k = n.size();

	long double ans = 0, val = 0, cur = 1;

	for (int i = 0; i < k - 1; i ++) {
		val += (n[i] - '0') * cur;
		ans += val;
		cur /= 10;
	}

	val += (n.back() - '0') * cur;

	cout << fixed << setprecision(15) << ans * 0.9 + val;

	return 0;
}