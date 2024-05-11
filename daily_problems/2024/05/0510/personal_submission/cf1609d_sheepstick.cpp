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
    int n, d; cin >> n >> d;
    DSU compo(n);
    int surplus = 0;
    for (int i = 0; i < d; i++){
    	int u, v; cin >> u >> v;
    	u--; v--;
    	if (!compo.merge(u, v)) surplus++;
    	priority_queue<int, vector<int>, greater<int>> pq;
    	int cur = 0;
    	for (int i = 0; i < n; i++) if (compo.leader(i) == i){
    		cur += compo.size(i);
    		pq.push(compo.size(i));
    		if ((int) pq.size() > surplus + 1) {
    			cur -= pq.top();
    			pq.pop();
    		}
    	}
    	cout << cur - 1 << "\n";
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}