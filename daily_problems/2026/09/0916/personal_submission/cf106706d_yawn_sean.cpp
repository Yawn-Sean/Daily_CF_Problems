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

	vector<int> saved(n + 1, 0);
	int is_t = 1, is_f = 1;

	for (int i = 2; i <= n; i ++) {
		cout << "? 2 " << 1 << ' ' << i << endl;
		cin >> saved[i];

		if (saved[i] == 0) is_t = 0;
		else if (saved[i] == 2) is_f = 0;
	}

	string ans(n, ' ');

	if (is_t) {
		ans[0] = 'T';
		int f;

		for (int i = 2; i <= n; i ++) {
			if (saved[i] == 1) {
				ans[i - 1] = 'F';
				f = i;
			}
		}

		for (int i = 2; i <= n; i ++) {
			if (f != i && saved[i] == 2) {
				cout << "? 2 " << f << ' ' << i << endl;
				int x; cin >> x;
				ans[i - 1] = (x == 1 ? 'T' : 'M');
			}
		}
	}
	else {
		ans[0] = (is_f ? 'F' : 'M');
		int t;

		for (int i = 2; i <= n; i ++) {
			if (saved[i]) {
				ans[i - 1] = 'T';
				t = i;
			}
		}

		for (int i = 2; i <= n; i ++) {
			if (t != i && saved[i] == 0) {
				cout << "? 2 " << t << ' ' << i << endl;
				int x; cin >> x;
				ans[i - 1] = (x == 1 ? 'F' : 'M');
			}
		}
	}

	cout << "! " << ans << endl;

	return 0;
}