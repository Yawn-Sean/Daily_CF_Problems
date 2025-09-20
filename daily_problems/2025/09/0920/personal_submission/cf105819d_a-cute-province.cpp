#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;
struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> col(n);
    vector<vector<int>> g(n);
    vector<string> ans(n, string(n, '0')); // 最终答案矩阵

    for(int i = 0; i < n; i++) cin >> col[i];
    for(int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 外层循环，为每个起点 i 运行一次BFS
    for(int i = 0; i < n; i++) {
        queue<PII> q;
        
        // visited[v] 存储所有已经访问过节点v的掩码
        vector<set<int>> visited(n);

        // 初始化
        ans[i][i] = '1';
        q.push({i, col[i]});
        visited[i].insert(col[i]);

        while(!q.empty()){
            auto [u, val] = q.front(); q.pop();

            for(auto v : g[u]){
                int next_val = val & col[v];

                // 如果存在公共颜色，并且(v, next_val)这个状态是第一次遇到
                if (next_val != 0 && visited[v].find(next_val) == visited[v].end()) {
                    
                    // 如果v是第一次被标记为可达，更新答案
                    if (ans[i][v] == '0') {
                        ans[i][v] = '1';
                    }
                    
                    visited[v].insert(next_val);
                    q.push({v, next_val});
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << '\n';
    }
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
