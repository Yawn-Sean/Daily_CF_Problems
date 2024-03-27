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
	int n, m, q; cin >> n >> m >> q;

	DSU compo(n + m);
	int cnt = n + m;
	while(q--){
		int x, y; cin >> x >> y;
		x--; y--;
		if (compo.merge(x, n + y)) cnt--;
	}
	
	cout << cnt - 1 << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}