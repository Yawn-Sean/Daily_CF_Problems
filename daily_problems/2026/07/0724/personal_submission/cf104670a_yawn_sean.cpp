#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, c;
	cin >> n >> c;

	long long inf = 1e18;
	long long v1 = inf, v2 = -inf;

	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		v1 = min(v1, x - 1ll * i * c);
		v2 = max(v2, x + 1ll * i * c);
		cout << max((x - 1ll * i * c) - v1, v2 - (x + 1ll * i * c)) << ' ';
	}

	return 0;
}