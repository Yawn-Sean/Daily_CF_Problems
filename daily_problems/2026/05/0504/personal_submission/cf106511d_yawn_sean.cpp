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

	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < 10; i ++) {
		long long cur = (i ? i : 10);
		while (cur <= n) {
			ans ++;
			cur = cur * 10 + i;
		}
	}

	cout << ans;

	return 0;
}