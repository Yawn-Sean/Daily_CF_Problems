#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using i64 = long long;
using pi = pair<int, int>;

inline int read() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = read(), res = 0, cnt = 0;
	ve a(n, ve<int>(n));
	rep(i, 0, n) {
		rep(j, 0, n) {
			char c;
			cin >> c;
			if (c == '1') {
				cnt++;
			}
			a[i][j] = c - '0';
		}
	}
	rep(i, 0, n) {
		int k = 0, cur = 0, j = i;
		while (k < n) {
			if (a[k++][j]) {
				cur++;
			}	
			j = (j + 1) % n;
		}
		res = max(res, cur);
	}
	cout << n + cnt - res * 2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = read();
	while (t--) {
		solve();
	}

	return 0;
}
