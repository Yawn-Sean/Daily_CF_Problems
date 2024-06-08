
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
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
void solve(int _) 
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<array<int, 2>> sources, others;
    for (int i = 0; i < m; i ++ ) {
        int u, v;
        cin >> u >> v;
        u --; v --;
        if (u > v) swap(u, v);
        if (u == 0) sources.push_back({u, v});
        else others.push_back({u, v});
    }

    DSU componet(n);
    for (auto &[u, v]: others) {
        componet.merge(u, v);
    }

    vector<int> visited(n), f(n);
    vector<array<int, 2>> ans;
    
    for (int i = 0; i < n; i ++ ) {
        f[i] = componet.leader(i);
    }
    
    int deg = 0;
    DSU last(n);

    // 从每个联通分量中选一个与节点1相连，这是1度数最小的情况。
    for (auto &[u, v]: sources) {
        int id = f[v];
        // 当前连通块已经选过一个点了。
        if (visited[id]) continue;
        // 选择当前这条边
        ans.push_back({u, v});
        visited[id] = 1;
        deg ++;
        // 在最后构造的答案中，选了这条边。
        last.merge(u, v);
    }
    
    // 1的度数不够，加边。
    for (auto &[u, v]: sources) {
        if (deg == d) break;
        if (last.merge(u, v)) {
            ans.push_back({u, v});
            deg ++;
        }
    }

    if (deg != d) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    // 构造生成树。
    for (auto &[u, v]:others) {
        if (last.merge(u, v)) {
            ans.push_back({u, v});
        }
    }

    for (auto &[u, v]: ans) {
        cout << u+1 << ' ' << v+1 << endl;
    }
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}