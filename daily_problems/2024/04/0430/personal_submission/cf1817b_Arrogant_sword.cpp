#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////

const int N = 2e5 + 10;
void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n+1], deg(n+1);
    for (int i = 1, u, v; i <= m; i ++ ) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u] ++; deg[v] ++;
    }

    bool ok = false;
    vector<int> path, vis(n+1);
    function<void(int , int, int)> dfs = [&](int u, int fa, int sp) {
        if (ok) return;
        path.push_back(u);
        vis[u] = 1;
        for (int v: g[u]) {
            if (ok) return;
            if (v == fa) continue;
            if (v == sp) {
                vector<int> st(n+1), cnt;
                for (int &x: path) {
                    st[x] = 1;
                }
                for (int k: g[v]) {
                    if (!st[k]) cnt.push_back(k);
                }
                if (SZ(cnt) < 2) continue;
                int ans = SZ(path);
                cout << "YES" << endl;
                cout << ans + 2 << endl;
                for (int i = ans - 1; i > 0; i -- ) {
                    cout << path[i] << ' ' << path[i-1] << endl;
                }
                cout << sp << ' ' << path.back() << endl;
                cout << sp << ' ' << cnt[0] << endl;
                cout << sp << ' ' << cnt[1] << endl;
                ok = true;
                return ;
            }
            
            if (!vis[v]) dfs(v ,u, sp);
        }
        
        path.pop_back();
    };

    for (int i = 1; i <= n && !ok; i ++ ) {
        if (deg[i] < 4) continue;
        path.clear();
        for (int j = 1; j <= n; j ++ ) vis[j] = 0;
        
        dfs(i, -1, i);
    }

    if (!ok) cout << "NO" << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}