#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) std::swap(x, y);
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve() {
	int n, m, d; cin >> n >> m >> d;
	vector<array<int,2>> source, others;
	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		if (u > v) swap(u, v);
		if (u == 0) source.push_back({u, v});
		else others.push_back({u, v});
	}
	DSU compo(n);
	for (auto &[u, v] : others){
		compo.merge(u, v);
	}

	vector<int> visited(n, 0), f(n, 0);
	for (int i = 0; i < n; i++){
		f[i] = compo.leader(i);
	}
	vector<array<int,2>> res;

	int deg = 0;
	DSU zero(n);

	//choose at least 1 from each component
	for (auto &[u, v] : source){
		int fa = f[v];
		if (visited[fa]) continue;
		res.push_back({u, v});
		visited[fa] = 1;
		deg++;
		zero.merge(u, v);
	}

	//deg not enough
	for (auto &[u, v] : source){
		if (deg == d) break;
		if (zero.merge(u, v)){
			deg++;
			res.push_back({u, v});
		}
	}
	if (deg != d){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

	//add others
	for (auto &[u, v] : others){
		if (zero.merge(u, v)){
			res.push_back({u, v});
		}
	}
	for (auto &[u, v] : res){
		cout << u + 1 <<" "<< v + 1 << "\n";
	}
	cout << "\n";




}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}