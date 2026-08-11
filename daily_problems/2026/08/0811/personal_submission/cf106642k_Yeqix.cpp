#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	int n, m;
	cin >> n >> m;
	i64 res = 0;
	vector<string> f(n + 1);
	vector<i64> row(n + 1), col(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		f[i] = " " + f[i];
		for (int j = 1; j <= m; j++) {
			row[i] += (f[i][j] == '1');
			col[j] += (f[i][j] == '1');
			res += (f[i][j] == '1');
		}
	}

	auto get = [&](int i, int j)->i64{
		int v = f[i][j] - '0';
		return (row[i] - v) * (col[j] - v);
	};

	vector<i64> r(n + 1), c(m + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			r[i] += (f[i][j] == '1') * (col[j] - 1);
			c[j] += (f[i][j] == '1') * (row[i] - 1);
		}
	}

	i64 ans = 0, mx = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (f[i][j] == '1') {
				ans += get(i, j);
			} else {
				i64 val = get(i, j) + r[i] + c[j];
				if (val > mx) {
					mx = val, cnt = 1;
				} else if (val == mx) {
					cnt++;
				}
			}
		}
	}

	cout << mx + ans << " " << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}