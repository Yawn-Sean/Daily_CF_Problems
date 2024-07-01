#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

int n;
const int maxn = 2e5 + 7;
vector<pair<int, int>> g[maxn];
int d[maxn];
vector<int> res;
int ok = 1;
 
void dfs(int u, int f, int id) {
    if (!ok) {
        return;
    }
    d[u] = 1;
    for (auto it : g[u]) {
        int x = it.fi, y = it.se;
        if (x == f) {
            continue;
        }
        dfs(x, u, y);
        d[u] += d[x];
    }
    if (d[u] > 3) {
        ok = false;
    }
    if (d[u] == 3) {
        d[u] = 0;
        res.push_back(id);
    }
}
 
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++ )   g[i].clear();
    for (int i = 1; i <= n - 1; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    ok = 1;
    res.clear();
    dfs(1, 1, 0);
    if (!ok || d[1]) {
        cout << -1 << '\n';
    } else {
        res.pop_back();
        cout << res.size() << '\n';
        for (auto x : res) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

  
int main() {  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = red();
    while (t--) {  
        solve();
    }  
    return 0;  
}
