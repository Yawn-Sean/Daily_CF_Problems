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

inline i64 read() {
	i64 x;
	cin >> x;
	return x;
}

void solve() {
	i64 res = 0;
	int n = read();
	ve<i64> a(n), b(n);
	map<i64, int> c;
	set<i64> vis;
	generate(all(a), read);
	generate(all(b), read);
	rep(i, 0, n) {
		c[a[i]]++;
	}
	for (auto it : c) {
		if (it.se > 1) {
			rep(i, 0, n) {
				if ((it.fi | a[i]) == it.fi) {
					vis.insert(i);
				}
			}
		}
	}
	for (auto it : vis) {
		res += b[it];
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
