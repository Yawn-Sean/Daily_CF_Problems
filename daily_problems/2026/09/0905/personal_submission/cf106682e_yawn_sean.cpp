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

	int n;
	cin >> n;

	map<int, int> mp;

	for (int i = 0; i < n; i ++) {
		int a, c;
		cin >> a >> c;
		mp[-a] = c;
	}

	for (auto &[k, v]: mp) {
		if (v) {
			int cur = -k;
			int target = -((1 << 32 - __builtin_clz(cur)) - 1 - cur);

			if (mp.find(target) == mp.end() || mp[target] < v)
				return cout << "Ana", 0;

			mp[target] -= v;
		}
	}

	cout << "Beto";

	return 0;
}