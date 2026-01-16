#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

	int n, i, k;
	cin >> n >> i >> k;

	long double ans = 0;

	ans += powl((long double)(i - 1) / n, k) * i;
	for (int M = i; M <= n; M ++) 
		ans += (powl((long double)M / n, k) - powl((long double)(M - 1) / n, k)) * (M + 1) / 2;

	cout << fixed << setprecision(20) << ans;

	return 0;
}