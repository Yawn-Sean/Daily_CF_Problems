
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
    vector<PII> g[n+1];
    for (int i = 0; i < n-1; i ++ ) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    vector<int> sz(n+1, 1), de(n+1);
    int ans = 1;
    function<void(int, int)> dfs = [&](int u, int fa) -> void {
        if (!ans) return;
        int f = n;
        for (auto [v, id]: g[u]) {
            if (v == fa) {
                f = id;
                continue; 
            }
            dfs(v, u);
            sz[u] += sz[v];
        }

        if (sz[u] == 3) {
            sz[u] = 0;
            de[f] = 1;
        } else if (sz[u] > 3) {
            ans = 0;
        }
    };

    dfs(1, 0);
    if (!ans || n % 3) {
        cout << -1 << endl;
    } else {
        cout << n/3 - 1 << endl;
        for (int i = 0; i < n; i ++ ) {
            if (de[i]) {
                cout << i+1 << " ";
            }
        }
        cout << endl;
    }
    
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