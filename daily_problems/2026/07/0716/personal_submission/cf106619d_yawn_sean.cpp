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

	int t;
	cin >> t;

	auto query = [&] (long long m, long long v) -> int {
		cout << "? " << m << ' ' << v << endl;
		int x; cin >> x; return x;
	};

	auto answer = [&] (long long a, long long b) -> void {
		cout << "! " << a << ' ' << b << endl;
	};

	while (t --) {
		long long xor_val = 0;

		for (int i = 0; i < 60; i ++) {
			if (query(1ll << i, 1ll << i)) {
				xor_val |= 1ll << i;
			}
		}

		long long tmp = xor_val & -xor_val;

		for (int i = 0; i < 60; i ++) {
			if (tmp >> i & 1) continue;
			long long ntmp = tmp | (1ll << i);
			if (query(ntmp, ntmp)) tmp = ntmp;
		}

		long long a = tmp, b = tmp ^ xor_val;
		if (a > b) swap(a, b);
		answer(a, b);
	}

	return 0;
}