// 树的直径.

#include<bits/stdc++.h>

#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}

//////////////////////////////////////////////////

const int N = 3e5 + 10;
vector<PII> g[N];
vector<int> a(N), dp(N);
int ans = 0;

void dfs(int u, int fa) {
    int mx1 = 0, mx2 = 0;
    for (auto [v, w]: g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        int t = dp[v] + w;
        if (t > mx1) {
            mx2 = mx1;
            mx1 = t;
        } else if (t > mx2 ) {
            mx2 = t;
        }
    }

    ans = max(ans, mx1 + mx2 + a[u]);
    dp[u] = mx1 + a[u];
}

void solve() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i < n; i ++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, -w});
        g[v].pb({u, -w});
    }

    dfs(1, -1);

    cout << ans << endl;
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