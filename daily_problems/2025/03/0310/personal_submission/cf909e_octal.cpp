#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1);
    for(int i=1; i<=n; i++)
        cin >> p[i];
    vector<vector<int>> g(n+1);
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        u ++, v ++;
        g[v].push_back(u);
    }
    vector<int> dis(n+1, -1);
    function<int(int)> dfs = [&](int u) {
        if(dis[u] != -1) return dis[u];
        dis[u] = p[u];
        for(int v: g[u]) {
            if(p[u] && !p[v]) dis[u] = max(dis[u], dfs(v)+1);
            else dis[u] = max(dis[u], dfs(v));
        }
        return dis[u];
    };
    int res = 0;
    for(int i=1; i<=n; i++) {
        res = max(res, dfs(i));
    }
    cout << res << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
