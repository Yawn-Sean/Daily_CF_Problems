#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, i, j;
	while (cin >> n) {
		vector<int64_t> a(n + 1);
		vector<int> b(n + 1), c(66);
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (i = 1; i <= n; ++i) {
			int64_t t = a[i];
			while (t && t % 2 == 0) {
				b[i]++;
				t /= 2;
			}
			c[b[i]]++;
		}
		int p = 0;
		for (i = 1; i <= 64; ++i) {
			if (c[p] < c[i]) p = i;
		}
		cout << n - c[p] << '\n';
		for (i = 1; i <= n; ++i) {
			if (b[i] != p) cout << a[i] << ' ';
		}
	}

	return 0;
}
