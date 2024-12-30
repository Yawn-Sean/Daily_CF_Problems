#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int a, b, w;
    bool operator < (const Edge &t) const{
        return w < t.w;
    }
};

void solve(){
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector <string> s(1);
    vector <vector<int>> g(k+1), dist(k+1, vector<int>(k+1));
    vector <int> p(k+1);
    iota(p.begin(), p.end(), 0);

    for (int i = 0; i < k; ++ i){
        string str;
        for (int j = 0; j < n; ++ j){
            string c;
            cin >> c;
            str += c;       
        }
        s.push_back(str);
    }

    function<int(int)> find = [&](int x)->int{
        return p[x] = p[x]==x ? p[x] : find(p[x]);
    };
    auto merge = [&](int x, int y)->void{
        x = find(x), y = find(y);
        if (x != y){
            p[y] = x;
        }
    };
    auto call = [&](string a, string b)->int{
        int res = 0;
        for (int i = 0; i < n*m; ++ i){
            res += (a[i] != b[i]);
        }
        return res;
    };

    vector <Edge> edge;
    for (int i = 1; i <= k; ++ i){
        edge.push_back({0, i, n*m});
    }
    for (int i = 1; i <= k; ++ i){
        for (int j = i+1; j <= k; ++ j){
            int d = call(s[i], s[j]);
            dist[i][j] = dist[j][i] = d;
        }
    }
    for (int i = 1; i <= k; ++ i){
        for (int j = 1; j <= k; ++ j){
            if (i == j) continue;
            int d = dist[i][j];
            edge.push_back({i, j, d*w});
            edge.push_back({j, i, d*w});
        }
    }

    long long res = 0;
    sort(edge.begin(), edge.end());
    for (auto &it : edge){
        int a = it.a, b = it.b, w = it.w;
        int pa = find(a), pb = find(b);
        if (pa != pb){
            res += w;
            merge(a, b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    vector <int> vis(k+1);
    vector <array<int,2>> ans;
    function<void(int,int)> dfs = [&](int x, int fa){
        ans.push_back({x, fa});
        vis[x] = 1;
        for (auto &y : g[x]){
            if (vis[y]) continue;
            dfs(y, x);
        }
    };

    vis[0] = 1;
    for (auto &x : g[0]){
        dfs(x, 0);
    }

    cout << res << "\n";
    for (auto &it : ans){
        cout << it[0] << " " << it[1] << "\n";
    }
}
 
