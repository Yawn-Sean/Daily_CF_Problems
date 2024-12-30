#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <queue>
using namespace std;
using ll = long long;
struct Graph {
	vector<int> h;
	vector<int> ne;
	vector<int> to;
	vector<ll> wt;
	int cnt = 1;
	int m;
	Graph(int n,int m): m(m),h(n+1),ne(m+1),to(m+1),wt(m+1){}

	void add(int u, int v, ll l) {
		to[cnt] = v;
		wt[cnt] = l;
		ne[cnt] = h[u];
		h[u] = cnt++;
	}

};


void dij(Graph& g,int s,vector<ll> &dp) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> q;
	dp[s] = 0;
	q.push({ 0,s });
	while (!q.empty()) {
		auto [w,pt] = q.top();q.pop();
		if (w != dp[pt]) {
			continue;
		}
		for (int i = g.h[pt];i;i = g.ne[i]) {
			int v = g.to[i];
			if (dp[v] > w + g.wt[i]) {
				dp[v] = w + g.wt[i];
				q.push({dp[v],v});
			}
		}
	}
}


int id = 0;
const int N = 1e5 + 7;
int dfn[N], low[N],bri[N];
void tarjan(int rt, Graph &g,int eg) {
	dfn[rt] = low[rt] = ++id;

	for (int i = g.h[rt];i;i = g.ne[i]) {
		int v = g.to[i];
		if (!dfn[v]) {
			tarjan(v, g, i);
			low[rt] = min(low[rt], low[v]);
			if (low[v] > dfn[rt]) {
				bri[g.wt[i]] = 1;
			}
		}
		else if(g.wt[i] != g.wt[eg]){
			low[rt] = min(low[rt], dfn[v]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	
	int n,m,s,t;
	cin >> n >> m >> s >> t;
	Graph g(n,m);
	Graph g_rev(n,m);
	vector<int> u(m);
	vector<int> v(m);
	vector<ll> l(m);
	for (int i = 0;i < m;++i) {
		cin >> u[i] >> v[i] >> l[i];
		g.add(u[i], v[i], l[i]);
		g_rev.add(v[i], u[i], l[i]);
	}
	vector<ll> dp(n + 1,1e18);
	vector<ll> dp_rev(n + 1,1e18);
	dij(g, s, dp);
	dij(g_rev, t, dp_rev);

	Graph g_reduce(n, m*2);
	for (int i = 0;i < m;++i) {
		if (l[i] + dp[u[i]] + dp_rev[v[i]] == dp[t]) {
			g_reduce.add(u[i],v[i], i);
			g_reduce.add(v[i],u[i], i);
		}
	}

	tarjan(s,g_reduce,0);

	for (int i = 0;i < m;++i) {
		if (bri[i]) {
			cout << "YES" << endl;
		}
		else if(dp[u[i]] + dp_rev[v[i]] + 1 < dp[t]) {
			cout << "CAN" << " ";
			cout << (l[i] - (dp[t] - 1 - dp[u[i]] - dp_rev[v[i]])) << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	

	return 0;
}