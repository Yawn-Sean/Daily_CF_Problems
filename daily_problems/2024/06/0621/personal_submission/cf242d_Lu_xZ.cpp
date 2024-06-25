#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 5;

int n, m, a[N];
vector<int> g[N], ans;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		int x, y;
		cin >> x >> y;
		g[x].eb(y);
		g[y].eb(x);
	}
	queue<int> q;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		if(!a[i])
			q.push(i);
	}
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if(a[x] != 0) continue;
		-- a[x];
		ans.eb(x);
		for(int y : g[x]) {
			if(-- a[y] == 0) {
				q.push(y);
			}
		}
	}
	cout << ans.size() << '\n';
	for(int x : ans) cout << x << ' ';
	return 0;
}
