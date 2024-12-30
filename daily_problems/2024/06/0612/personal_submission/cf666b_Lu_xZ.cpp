#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 3e5 + 5;

int n, m;
vector<int> G[N];
vector<pii> Dist[N], dist[N];

void bfs(int st) {
	vector<int> d(n + 1, -1);
	d[st] = 0;
	queue<int> q; q.push(st);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int y : G[x]) {
			if(d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(i != st && d[i] != -1) {
			Dist[st].eb(d[i], i);
			dist[i].eb(d[i], st);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		int x, y; cin >> x >> y;
		G[x].eb(y);
	}
	for(int i = 1; i <= n; ++ i) {
		bfs(i);
	}
	for(int i = 1; i <= n; ++ i) {
		ranges::sort(Dist[i], greater<pii>());
		ranges::sort(dist[i], greater<pii>());
	}
	// a -> b -> c -> d
	vector<int> ans;
	int L = 0;
	for(int b = 1; b <= n; ++ b) {
		int cnt = 0;
		for(auto [d_ab, a] : dist[b]) {
			if(++ cnt > 4) {
				break;
			}
			set<int> se = {b, a};
			for(auto [d_bc, c] : Dist[b]) {
				if(se.count(c)) {
					continue;
				}
				for(auto [d_cd, d] : Dist[c]) {
					if(se.count(d)) {
						continue;
					}
					int tmp = d_ab + d_bc + d_cd;
					if(tmp > L) {
						ans = {a, b, c, d};
						L = tmp;
					}
					break;
				}
			}
		}
	}
	for(auto x : ans) cout << x << ' ';
	return 0;
}
