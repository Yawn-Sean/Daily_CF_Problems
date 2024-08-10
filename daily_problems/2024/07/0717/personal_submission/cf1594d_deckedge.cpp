#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using i64 = long long;
using pi = pair<int, int>;

void solve() {
	int n, m;
	cin >> n >> m;
	ve<ve<pi>> g(n);
	rep(i, 0, m) {
		int u, v;
		string str;
		cin >> u >> v >> str;
		u--, v--;
		g[u].emplace_back(v, str[0] == 'i');
		g[v].emplace_back(u, str[0] == 'i');
	}
	ve<int> c(n, -1);
	int res = 0;
	rep(i, 0, n) {
		if (c[i] != -1) {
			continue;
		}
		int sum = 0;
		ve<int> que(1, i);
		c[i] = 0;
		rep(j, 0, int(que.size())) {
			sum += c[que[j]];
			for (auto& p : g[que[j]]) {
				int to = p.fi;
				int col = p.se ^ c[que[j]];
				if (c[to] == -1) {
					c[to] = col;
					que.emplace_back(to);
				} else {
					if (c[to] != col) {
						res = -1;
						break;
					}
				}
			}
			if (res == -1) {
				break;
			}
		}
		if (res == -1) {
			break;
		}
		res += max(sum, int(que.size()) - sum);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}