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
		int a, b, c;
		cin >> a >> b >> c;

		int mn = min({a, b, c});

		if (a == mn) {
			cout << b * c << '\n';
			for (int i = 1; i <= b; i ++) {
				for (int j = 1; j <= c; j ++) {
					cout << (i + j) % a + 1 << ' ' << i << ' ' << j << '\n';
				}
			}
		}
		else if (b == mn) {
			cout << a * c << '\n';
			for (int i = 1; i <= a; i ++) {
				for (int j = 1; j <= c; j ++) {
					cout << i << ' ' << (i + j) % b + 1 << ' ' << j << '\n';
				}
			}
		}
		else {
			cout << a * b << '\n';
			for (int i = 1; i <= a; i ++) {
				for (int j = 1; j <= b; j ++) {
					cout << i << ' ' << j << ' ' << (i + j) % c + 1 << '\n';
				}
			}
		}
	}

	return 0;
}