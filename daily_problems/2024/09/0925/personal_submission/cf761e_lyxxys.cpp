#include <bits/stdc++.h>
using namespace std;
struct Info {
    long long x, y, cur;
    int vis[4] = {};
};

void solve(){
    int n;
    cin >> n;
    vector <vector<int>> g(n+1);
    vector <int> deg(n+1), vis(n+1);

    int id = 1;
    for (int i = 0, a,b; i < n-1; ++ i){
        cin >> a >> b;
        deg[a] += 1, deg[b] += 1;
        g[a].push_back(b);
        g[b].push_back(a);
        if (id==-1 || deg[a] > deg[id]){
            id = a;
        }
        if (id==-1 || deg[b] > deg[id]){
            id = b;
        }
    }

    bool jg = 1;
    for (int i = 1; i <= n; ++ i){
        if (deg[i] > 4){
            jg = 0;
            break;
        }
    }
    if (!jg) return cout << "NO\n", void();

    const int origin[] = {2, 3, 0, 1}, ds[] = {0, 1, 0, -1, 0};
    vector <Info> xy_o(n+1);

    auto update = [&](int x, int y)->void{
        int id = -1;
        for (int i = 0; i < 4; ++ i){
            if (xy_o[x].vis[i] == 0){
                id = i;
                break;
            }
        }
        long long len = xy_o[x].cur;
        long long ex = xy_o[x].x + ds[id]*len, ey = xy_o[x].y + ds[id+1]*len;
        xy_o[y] = {ex, ey, len/2};
        xy_o[x].vis[id] = 1, xy_o[y].vis[origin[id]] = 1;  //更新时 对于 y点 也要用 一条边
    };

    function <void(int,int)> dfs = [&](int x, int fa){
        vis[x] = 1;
        update(fa, x);
        for (auto &y : g[x]){
            if (vis[y]) continue;
            dfs(y, x);
        }
    };

    xy_o[id] = {0, 0, (long long)1e10};
    
    vis[id] = 1;
    for (auto &x : g[id]){
        if (vis[x]) continue;
        dfs(x, id);
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++ i){
        cout << xy_o[i].x << " " << xy_o[i].y << "\n";
    }
}
 
 
