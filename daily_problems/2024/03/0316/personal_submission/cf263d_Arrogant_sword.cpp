
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

const int N = 1e5 + 10;
vector<int> g[N];
int n, m, k;
vector<int> vis(N);
int pos = -1;
void dfs(int u, int tim) {
    vis[u] = tim;
    for (int v: g[u]) {
        if (vis[v] == 0) {
            dfs(v, tim+1);
            break;
        }
        if (vis[u] - vis[v] >= k) {
            cout << vis[u] - vis[v] + 1 << endl;
            cout << u << ' ';
            pos = v;
            return;
        }
    }
    if (pos == -1) cout << u << ' ';
    if (pos == u) pos = -1;
}

void solve() 
{
    
    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++ ) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 1);
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