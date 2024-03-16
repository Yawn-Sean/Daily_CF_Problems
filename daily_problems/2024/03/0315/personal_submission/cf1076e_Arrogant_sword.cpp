// 离线 + 树上差分的思想。
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////

void solve() 
{
    int n;
    cin >> n;
    vector<int> g[n+1];
    for (int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int m;
    cin >> m;
    vector<PII> op[n+1];
    for (int i = 0; i < m; i ++ ) {
        int v, d, x;
        cin >> v >> d >> x;
        op[v].pb({d, x});
    }

    vector<int> add(n+1), ans(n+1);
    function<void(int, int, int, int)> dfs = [&](int u, int fa, int h, int sum) {
        for (auto [d, x]: op[u]) {
            add[h] += x;
            if (h + 1 + d <= n) {
                add[h+d+1] -= x;
            }
        }
        sum += add[h];
        ans[u] = sum;

        for (int v: g[u]) {
            if (v == fa) continue;
            dfs(v ,u, h+1, sum);
        }

        for (auto [d, x]: op[u]) {
            add[h] -= x;
            if (h+d+1 <= n) {
                add[h+d+1] += x;
            }
        }
    };

    dfs(1, -1, 0, 0);
    for (int i = 1; i <= n; i ++ ) cout << ans[i] << ' ';

} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}