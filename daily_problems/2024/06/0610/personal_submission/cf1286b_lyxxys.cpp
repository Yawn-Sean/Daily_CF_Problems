#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e18, mod = 998244353, N = 2050;
struct Node {
    int fa, v1, v2, sz = 1;
};
vector <Node> node(N);
vector <int> g[N], seq[N];

bool flg;
void dfs(int u){
    if (flg) return;
    for (auto &x : g[u]){
        dfs(x);
        node[u].sz += node[x].sz;
        for (auto &y : seq[x]) seq[u].push_back(y);
    }
    if (flg || node[u].sz <= node[u].v1) return flg = 1, void();
    seq[u].push_back(u);
    for (int i = node[u].sz-1; i > node[u].v1; -- i) swap(seq[u][i], seq[u][i-1]);
    // 直接插入到对于node[seq[i]].v1 的升序数组seq中
}

void solve(){
    int n, rt;
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        cin >> node[i].fa >> node[i].v1;
        if (!node[i].fa) rt = i;
        else g[node[i].fa].push_back(i);
    }
    dfs(rt);
    if (flg) return cout << "NO\n", void();
    cout << "YES\n";
    for (int i = 0; i < n; ++ i) node[seq[rt][i]].v2 = i+1;
    for (int i = 1; i <= n; ++ i) cout << node[i].v2 << "\n "[i < n];
}
