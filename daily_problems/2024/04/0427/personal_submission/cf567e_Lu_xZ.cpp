#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 5, P[2] = {998244353, 114514191};

vector<vector<pair<int, int>>> G(N), H(N);


auto dijkstra(int st, auto &g) {
	vector<ll> d(N, 1e18);
	vector<vector<ll>> f(2, vector<ll>(N, 0));
	d[st] = 0;
	f[0][st] = f[1][st] = 1;
	
	typedef pair<ll, int> T;
	priority_queue<T, vector<T>, greater<T>> q;
	
	q.push({0, st});
	vector<bool> v(N, 0);
	
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		if(v[x]) continue;
		v[x] = 1;
		for(auto [y, z] : g[x]) {
			if(d[y] > d[x] + z) {
				f[0][y] = f[1][y] = 0;
			}
			if(d[y] >= d[x] + z) {
				d[y] = d[x] + z;
				for(auto i : {0, 1}) {
					f[i][y] = (f[i][y] + f[i][x]) % P[i];
				}
				q.push({d[y], y});
			}
		}
	}
	return make_pair(d, f);
}

int n, m, s, t;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m >> s >> t;
	
	vector<tuple<int, int, int>> e; 
	
	for(int i = 1; i <= m; ++ i) {
		int x, y, z; cin >> x >> y >> z;
		G[x].push_back({y, z});
		H[y].push_back({x, z});	
		e.push_back(make_tuple(x, y, z));
	}
	
	auto [ds, fs] = dijkstra(s, G);
	auto [dt, ft] = dijkstra(t, H);
	
	
	for(auto [x, y, z] : e) {
		if(ds[x] + dt[y] + z == ds[t]) {
			int ok = 1;
			for(auto i : {0, 1}) {
				if(fs[i][x] * ft[i][y] % P[i] != fs[i][t]) {
					ok = 0;
				}
			}
			if(ok) {
				cout << "YES\n";
			}
			else if(z > 1){
				cout << "CAN 1\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			if(ds[x] + dt[y] + 1 >= ds[t]) {
				cout << "NO\n";
			}
			else {
				cout << "CAN " << z - (ds[t] - 1 - ds[x] - dt[y]) << '\n';
			}
		}
	}
	
	return 0;
}
