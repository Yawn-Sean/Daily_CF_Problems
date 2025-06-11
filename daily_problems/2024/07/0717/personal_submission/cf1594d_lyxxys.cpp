#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2050, mod = 1070777777, inf = 1e9;
struct dsu {
    vector <int> p, sz;
    int n;
    dsu(){}
    dsu(int n): p(2*n+1), sz(2*n+1){
        this->n = n;
        iota(p.begin(), p.end(), 0);
        for (int i = 1; i <= n; ++ i) sz[i] = 1;
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    int root(int x){
        return p[x] = x==p[x] ? x : root(p[x]);
    }
    int size(int x){
        return sz[root(x)];
    }
    void merge(int x, int y){
        x = root(x), y = root(y);
        if (x == y) return;
        if (size(x) < size(y)) swap(x, y);
        sz[x] += sz[y], p[y] = x;
        return;
    }
    int count(){
        int ans = 0;
        for (int i = 1; i <= n; ++ i){
            ans += max(size(i), size(i+n));
            sz[root(i)] = sz[root(i+n)] = 0;
        }
        return ans;
    }
};
/*
    扩展域并查集：
        1.判断矛盾
        2.求最大解
*/
void solve(){
    int n, m;
    cin >> n >> m;
    dsu unis(n);
    auto ext = []()->void{
        cout << -1 << "\n";
    };

    while (m--){
        int x, y;
        string ops;
        cin >> x >> y >> ops;
        if (ops == "imposter"){
            unis.merge(x, y+n);
            unis.merge(y, x+n);
        } else {
            unis.merge(x, y);
            unis.merge(x+n, y+n);
        }
    }

    for (int i = 1; i <= n; ++ i) {
        if (unis.same(i, i+n)) return ext();
    }

    cout << unis.count() << "\n";
}
