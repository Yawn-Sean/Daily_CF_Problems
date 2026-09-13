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
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		string ans;
		for (auto &c: s) {
			if (k & 1) k -= (c == '+' ? 1 : -1), ans += '#';
			else ans += '.';
			k >>= 1;
		}

		cout << (k == 0 ? ans : "-1") << '\n';
	}

	return 0;
}