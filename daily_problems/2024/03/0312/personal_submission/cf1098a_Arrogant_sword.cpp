
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
const int inf = 1e12;
void solve() 
{
    int n;
    cin >> n;

    vector<int> g[n+1];
    vector<int> father(n+1);
    for (int i = 2; i <= n; i ++ ) {
        int fa;
        cin >> fa;
        g[fa].pb(i);
        father[i] = fa;
    }

    vector<int> s(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> s[i];
        if (s[i] == -1) s[i] = inf;
    }

    function<void(int)> dfs = [&](int u) {
        s[father[u]] = min(s[father[u]], s[u]);
        for (int v: g[u]) {
            dfs(v);
        }
    };

    int ans = 0;
    bool ok = true;
    function<void(int)> dfs1 = [&](int u) {
        if (s[u] < s[father[u]]) {
            cout << -1 << endl;
            exit(0);
        }
        if (s[u] != inf) {
            ans += s[u] - s[father[u]];
        }

        for (int v: g[u]) {
            dfs1(v);
        }
    };

    dfs(1); dfs1(1);
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