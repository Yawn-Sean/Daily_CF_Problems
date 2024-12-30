#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9, mod = 998244353, N = 100060;
vector <int> g[N], f(N);

void dfs(int u, int fa){  //定义一个i的subtree是一组去根结点路径恰好到i的结点组
    f[u] = 0;
    for (auto &x : g[u]){
        if (x == fa) continue;
        dfs(x, u);
        f[u] += f[x];
    }
    if (!f[u]) f[u] = 1;
}
void solve(){
    int n;
    cin >> n;
    for (int i = 2, x; i <= n; ++ i)
        cin >> x, g[i].push_back(x), g[x].push_back(i);
    dfs(1, 1);
    sort(f.begin()+1, f.begin()+1+n);
    for (int i = 1; i <= n; ++ i){
        cout << f[i];
        if (i != n) cout << " ";
    }
    cout << "\n";
}
