#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int N = 2005;

int in[N], out[N], n, dfn, w[N], c[N], mp[N];
vector<int> g[N];

void dfs(int x) {
	mp[in[x] = ++ dfn] = x;
	for(int y : g[x]) {
		dfs(y);
	}
	out[x] = dfn;
	if(out[x] - in[x] < c[x]) {
		cout << "NO\n";
		exit(0);
	}
	vector<pair<int, int>> a;
	for(int i = out[x]; i > in[x]; -- i) {
		int y = mp[i];
		a.eb(w[y], y);
	}
	ranges::sort(a);
	int i = 0;
	if(i == c[x]) {
		w[x] = ++ i;
	}
	for(auto [v, y] : a) {
		w[y] = ++ i;
		if(i == c[x]) {
			w[x] = ++ i;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		int x; cin >> x;
		g[x].eb(i);
		cin >> c[i];
	}
	for(int rt : g[0]) {
		dfs(rt);
	}
	cout << "YES\n";
	for(int i = 1; i <= n; ++ i) {
		cout << w[i] << ' ';
	}
	return 0;
}
