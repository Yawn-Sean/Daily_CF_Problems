#include bitsstdc++.h
using namespace std;
void fmax(int &x, int y){
    if (y  x) x = y;
}
void fmin(int &x, int y){
    if (y  x) x = y;
}

void solve(){
    int n, m;
    cin  n  m;

    vector vectorint g(n);
    vector int p(n);
    iota(p.begin(), p.end(), 0);
    for (int i = 0, u,v; i  m; ++ i){
        cin  u  v;
        u -= 1, v -= 1;
        g[u].push_back(v);
    }
    for (int i = 0; i  n; ++ i){
        auto &it = g[i];
        sort(it.begin(), it.end(), [&](int x, int y){
            return g[x].size()  g[y].size();
        });
    }
    sort(p.begin(), p.end(), [&](int x, int y){
        return g[x].size()  g[y].size();
    });

    vector int vis(n), ans;
    auto dfs = [&](auto &&f, int x)-void{
        vis[x] = 1;
        for (auto &y  g[x]){
            if (vis[y]) continue;
            f(f, y);
        }
        ans.push_back(x);
    };

    for (auto &x  p){
        if (!vis[x]){
            dfs(dfs, x);
        }
    }

    int len = ans.size();
    for (int i = 0; i  len; ++ i){
        if (i) cout   ;
        cout  ans[i]+1;
    }
    cout  n;
}
