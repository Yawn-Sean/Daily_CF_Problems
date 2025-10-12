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

	int mod = 1e9 + 7;

	int n;
	cin >> n;

	int cur = 0, pos = 0, ans = 1;

	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;

		if (x > cur) {
			ans = 1ll * ans * (i - pos + 1) % mod;
			cur = x;
			pos = i;
		}
	}

	cout << ans;

    return 0;
}