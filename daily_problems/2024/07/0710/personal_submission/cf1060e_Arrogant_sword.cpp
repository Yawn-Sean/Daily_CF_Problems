
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
    int n;
    cin >> n;
    vector<int> g[n+1];

    for (int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> sz(n+1, 1), color(n+1);
    int cnt = 0;
    function<void(int, int)> dfs = [&](int u, int fa) -> void {
        cnt += color[u];
        for (int v: g[u]) {
            if (v == fa) continue;
            color[v] = color[u] ^ 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    };

    dfs(1, -1);
    int ans = (n - cnt) * cnt;
    rep(i, n) {
        ans += sz[i] * (n - sz[i]);
    }
    cout << ans/2 << endl;
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