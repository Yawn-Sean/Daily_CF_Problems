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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<char>>s(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> s[i][j];
	}

	vector<vector<int>>ans(n + 1, vector<int>(m + 1)), st(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] <= 'Z' && s[i][j] >= 'A') {
				int t = (s[i][j] - 'A' + 1) * a;
				vector<PII>p;
				queue<array<int, 3>>q;
				q.push({i, j, t});
				st[i][j] = 1;
				ans[i][j] += t;
				p.push_back({i, j});
				while (!q.empty()) {
					auto [x, y, w] = q.front();
					// cout<<x<<' '<<y<<' '<<w<<endl;
					q.pop();
					for (int k = 0; k <= 3; k++) {
						int xx = dx[k] + x, yy = dy[k] + y;
						if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
						if (s[xx][yy] == '*') continue;
						if (st[xx][yy]) continue;
						st[xx][yy] = 1;
						// if(xx==2&&yy==1) cout<<w/2<<endl;
						ans[xx][yy] += w / 2;
						p.push_back({xx, yy});
						if(w / 2) q.push({xx, yy, w / 2});
					}
				}
				for (auto &[x, y] : p) st[x][y] = 0;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// cout<<ans[i][j]<<' ';
			if (ans[i][j] > b) res++;
		}
		// cout<<endl;
	}
	cout << res << endl;
}
signed main() {
	fastio;
	int T;
	T = 1;
	// cin>>T;
	while (T--) solve();

	return 0;
}
