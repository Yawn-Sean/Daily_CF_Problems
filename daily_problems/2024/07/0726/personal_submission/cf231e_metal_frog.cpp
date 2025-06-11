#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
const ll mod = 1000000007; // faster if const
 
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}
 
vector<int> num, st;
vector<vector<pii>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
	int me = num[at] = ++Time, top = me;
	for (auto [y, e] : ed[at]) if (e != par) {
		if (num[y]) {
			top = min(top, num[y]);
			if (num[y] < me)
				st.push_back(e);
		} else {
			int si = sz(st);
			int up = dfs(y, e, f);
			top = min(top, up);
			if (up == me) {
				st.push_back(e);
				f(vector<int>(st.begin() + si, st.end()));
				st.resize(si);
			}
			else if (up < me) st.push_back(e);
			else { /* e is a bridge */ }
		}
	}
	return top;
}
 
template<class F>
void bicomps(F f) {
	num.assign(sz(ed), 0);
	rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}
 
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
 
struct LCA {
	int T = 0;
	vector<int> time, path, ret;
	RMQ<int> rmq;
 
	LCA(vector<vector<int>>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vector<int>>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}
 
	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};
 
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    ed.resize(n);
    int eid = 0;
    vector<pii> edg;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edg.emplace_back(u, v);
        ed[u].emplace_back(v, eid);
        ed[v].emplace_back(u, eid++);
    }
    vector<int> fa(n);
    for (int i = 0; i < n; i++) fa[i] = i;
    bicomps([&](const vector<int>& edgelist){
        int minv = n;
        for (int eid : edgelist) {
            int u = edg[eid].first, v = edg[eid].second;
            minv = min(minv, min(u, v)); 
        }
        for (int eid : edgelist) {
            int u = edg[eid].first, v = edg[eid].second;
            fa[u] = fa[v] = minv;
        }
    });
 
    set<int> fas;
    for (int i = 0; i < n; i++) {
        fas.insert(fa[i]);
    }
    vector<int> pid(n);
    vector<int> cnt(n);
    int len = 0;
    for (int f : fas) {
        pid[f] = len;
        len++;
    }
    for (int i = 0; i < n; i++) {
        fa[i] = pid[fa[i]];
        cnt[fa[i]]++;
    }
 
    vector<vector<int>> ng(len);
    for (auto [u, v] : edg) {
        if (fa[u] != fa[v]) {
            ng[fa[u]].emplace_back(fa[v]);
            ng[fa[v]].emplace_back(fa[u]);
        }
    }
 
    vector<int> dis(len), vis(len); 
    auto dfs1 = [&](auto&& dfs1, int u, int pre) -> void {
        dis[u] += (cnt[u] > 1);
        vis[u] = 1;
        for (int v : ng[u]) {
            if (v == pre) continue;
            if (vis[v]) {
                cout << "Not tree" << u << " " << v << endl;
                return; 
            }
            dis[v] = dis[u];
            dfs1(dfs1, v, u);
        }
    };
    dfs1(dfs1, 0, -1);
    LCA tree(ng);
 
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        u = fa[u], v = fa[v];
        int p = tree.lca(u, v);
        ll d = dis[u] + dis[v] - dis[p] * 2 + (cnt[p] > 1);
        cout << modpow(2, d) << endl;
    }
}
