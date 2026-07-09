#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long ans = 0;
	vector<int> cnt(n, 0);

	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		x = (x + i) % n;
		cnt[x] ++;
		ans += cnt[x];
	}

	cout << 2 * ans - n;

	return 0;
}