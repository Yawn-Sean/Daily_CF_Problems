#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
struct Edge {
    int to, len;
};

void solve(){
    int n;
    cin >> n;
    vector <vector<Edge>> g(2*n);
    vector <int> sz(2*n, 1);
    for (int i = 0, x,y,t; i < 2*n-1; ++ i){
        cin >> x >> y >> t;
        x -= 1, y -= 1;
        g[x].push_back({y, t});
        g[y].push_back({x, t});
    }

    int all = 2*n;
    auto dfs1 = [&](auto &&self, int x, int fa)->void{
        for (auto &it : g[x]){
            int y = it.to;
            if (y == fa) continue;
            self(self, y, x);
            sz[x] += sz[y];
        }
    };
    dfs1(dfs1, 0, -1);

    long long res1 = 0, res2 = 0;
    auto dfs2 = [&](auto &&self, int x, int fa)->void{
        for (auto &it : g[x]){
            int y = it.to, len = it.len;
            if (y == fa) continue;
            
            int sz1 = sz[y], sz2 = all-sz[y];
            if (sz1%2 && sz2%2){
                res1 += len;
            }
            res2 += 1ll * len * min(sz1, sz2);

            self(self, y, x);
        }
    };
    dfs2(dfs2, 0, -1);

    cout << res1 << " " << res2 << "\n";
}
