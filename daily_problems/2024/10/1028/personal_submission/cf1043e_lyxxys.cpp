#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
struct Node {
    int x, y;
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector<int>> gs(n+1);
    vector <Node> nodes(n+1);
    for (int i = 1; i <= n; ++ i){
        cin >> nodes[i].x >> nodes[i].y;
    }
    for (int i = 0, x,y; i < m; ++ i){
        cin >> x >> y;
        gs[x].push_back(y);
        gs[y].push_back(x);
    }
    vector <int> p(n+1);
    iota(p.begin(), p.end(), 0);
    sort(p.begin()+1, p.end(), [&](int u, int v){
        return nodes[u].x-nodes[u].y < nodes[v].x-nodes[v].y;
    });
    vector <int> vis(n+1);
    vector <long long> ans(n+1);

    long long cur = 0;
    for (int i = 1; i <= n; ++ i){
        int u = p[i], cnt = i-1;
        long long all = cur;
        for (auto &v : gs[u]){
            if (vis[v]){
                cnt -= 1;
                all -= nodes[v].x;
            }
        }
        ans[u] += all + 1ll * cnt * nodes[u].y;
        cur += nodes[u].x;
        vis[u] = 1;
    }

    fill(vis.begin(), vis.end(), 0);
    cur = 0;
    for (int i = n; i >= 1; -- i){
        int u = p[i], cnt = n-i;
        long long all = cur;
        for (auto &v : gs[u]){
            if (vis[v]){
                cnt -= 1;
                all -= nodes[v].y;
            }
        }
        ans[u] += all + 1ll * cnt * nodes[u].x;
        cur += nodes[u].y;
        vis[u] = 1;
    }
  
    for (int i = 1; i <= n; ++ i){
        if (i > 1) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
