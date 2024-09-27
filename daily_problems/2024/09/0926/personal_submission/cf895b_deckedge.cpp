#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;
using i64 = long long;

inline int read() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	i64 res = 0;
	int n = read(), x = read(), k = read();
	ve<int> a(n);
	generate(all(a), read);
	sort(all(a));
	rep(i, 0, n) {
		i64 bg = a[i] / x + (a[i] % x != 0);
		i64 low = (bg + k - 1) * x;
		i64 high = low + x;
		if (!k) {
			low = a[i];
			high = bg * x;
		}
		res += lower_bound(all(a), high) - lower_bound(all(a), low);
	}
	cout << res << '\n';
}	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
