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

	while (t --) {
		int w, l;
		cin >> w >> l;

		set<int> st = {2};

		for (auto &x: {gcd(w, l - 2), gcd(w - 2, l), gcd(w - 1, l - 1)}) {
			for (int i = 1; i <= 100000; i ++) {
				if (i * i > x) break;
				if (x % i == 0) st.insert(i), st.insert(x / i);
			}
		}

		cout << st.size();
		for (auto &v: st) cout << ' ' << v; cout << '\n';
	}

	return 0;
}