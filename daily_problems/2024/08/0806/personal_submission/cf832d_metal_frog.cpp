#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
 
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
	vi time, path, ret, depth;
	RMQ<int> rmq;
 
	LCA(vector<vi>& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C,0,-1, 0), ret)) {}
	void dfs(vector<vi>& C, int v, int par, int dep) {
		time[v] = T++;
        depth[v] = dep;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v, dep + 1);
		}
	}
 
	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	int dist(int a, int b) {
        return depth[a] + depth[b] - 2*depth[lca(a,b)];
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vi> G(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        G[p].emplace_back(i);
        G[i].emplace_back(p);
    }    
    LCA tree(G);
 
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        int dis_ab = tree.dist(a, b);
        int dis_ac = tree.dist(a, c);
        int dis_bc = tree.dist(b, c);
        int z = (dis_ab + dis_ac - dis_bc) / 2;
        int x = (dis_ac - z), y = (dis_ab - z);
        int ans = max(x, max(y, z));
        cout << ans + 1 << "\n";
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
