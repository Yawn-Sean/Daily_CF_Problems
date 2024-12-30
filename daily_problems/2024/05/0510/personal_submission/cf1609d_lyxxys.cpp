#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector <int> p, sz, add;
    dsu(){}
    dsu(int n): p(n+1), sz(n+1, 1){
        iota(p.begin(), p.end(), 0);
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
    }
};

void solve(){ 
    int n, m;
    cin >> n >> m;
    dsu contain(n);
    int cnt = 0;
    while (m--){
        int a, b;
        cin >> a >> b;
        if (contain.same(a, b)) ++ cnt;
        else contain.merge(a, b);
        vector <int> q;
        for (int i = 1; i <= n; ++ i)
            if (contain.root(i)==i)
                q.push_back(contain.sz[i]);
        sort(q.begin(), q.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < min(int(q.size()), cnt+1); ++ i)
            res += q[i];
        cout << res-1 << "\n";
    }
}
