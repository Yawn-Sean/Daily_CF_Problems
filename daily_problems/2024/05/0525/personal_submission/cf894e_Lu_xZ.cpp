#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e6 + 5;

int dfn[N], timestamp, c[N], idx, low[N], ins[N], stk[N], tp;
vector<int> G[N];

struct Edge {
	int fr, to, w;
} e[N];

void Tarjan(int x) {
	low[x] = dfn[x] = ++ timestamp;
	stk[++ tp] = x;
	ins[x] = 1;
	for(int y : G[x]) {
		if(!dfn[y]) {
			Tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(ins[y]) low[x] = min(low[x], dfn[y]);
	}
	if(low[x] == dfn[x]) {
		++ idx;
		int y;
		do {
			y = stk[tp --]; 
			c[y] = idx;
			ins[y] = 0;
		} while(y != x);
	}
}

int n, m, s, d[N];
ll f[N], w[N];
vector<pair<int, int>> H[N];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		int x, y, z; cin >> x >> y >> z;
		G[x].push_back(y);
		e[i] = {x, y, z};
	}
	cin >> s;
	Tarjan(s);
	
	auto calc = [&](int x) -> ll {
		ll v = sqrt(x * 2);
		while(v * (v + 1) <= 2 * x) ++ v;
		while(v * (v + 1) > 2 * x && v) -- v;
		return (v + 1) * x - (v * v * v + 3 * v * v + 2 * v) / 6;
	};
	
	for(int i = 1; i <= m; ++ i) {
		auto [x, y, z] = e[i];
		if(!c[x] || !c[y]) continue;
		if(c[x] == c[y]) {
			w[c[x]] += calc(z);
		}
		else {
			H[c[x]].emplace_back(c[y], z);
			++ d[c[y]];
		}
	}
	s = c[s];
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		f[x] += w[x];
		for(auto [y, z] : H[x]) {
			f[y] = max(f[y], f[x] + z);
			if(!-- d[y]) {
				q.push(y);
			}
		}
	}
	cout << *max_element(f + 1, f + idx + 1);
	return 0;
}
