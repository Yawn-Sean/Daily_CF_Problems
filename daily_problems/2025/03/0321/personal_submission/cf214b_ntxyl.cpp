#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
	int n;
	cin >> n;
	vector<int>a(n + 1), p(10);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[a[i]]++;
		ans += a[i];
	}

	if (!p[0]) {
		cout << -1 << endl;
		return;
	}
	// cout << ans << endl;
	bool st = 0;
	if (ans % 3 != 0) {
		int k = ans % 3;
		for (int i = 1; i <= 9; i++) {
			if (k == i % 3 && p[i]) {
				p[i]--;
				st = 1;
				break;
			}
		}
		if (!st) {
			for (int i = 1; i <= 9; i++) {
				if (p[i]) {
                    p[i]--;
					for (int j = 1; j <= i; j++) {
						if (p[j] && (ans - i - j) % 3 == 0) {
							p[j]--;
							st = 1;
							break;
						}
					}
                    if (st) break;
                    p[i]++;
				}
			}
		}
	}
    // cout << p[1] <<' ' << ' '<< p[4] << endl;
	bool fg = 0;
	for (int i = 9; i >= 0; i--) {
		if (p[i] && i != 0) fg = 1;
		if (!fg && i == 0) {
			cout << 0 << endl;
			break;
		}
		while (p[i] --) cout << i;
	}
}
signed main() {
	fastio;
	int T;
	T = 1;
	// cin>>T;
	while (T--) solve();

	return 0;
}
