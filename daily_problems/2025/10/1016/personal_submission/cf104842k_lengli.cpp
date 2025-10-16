#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if(!(cin >> n)) return 0;

    vector<vector<pair<int,int>>> g(n); // {to, edge_id}
    vector<pair<int,int>> edges(n);     // 1..n-1
    for (int i = 1; i <= n-1; ++i) {
        int a,b; cin >> a >> b; --a; --b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
        edges[i] = {a,b};
    }

    auto bfs = [&](int s, vector<int>& par, vector<int>& paredge){
        vector<int> dist(n,-1);
        par.assign(n,-1);
        paredge.assign(n,-1);
        queue<int> q; dist[s]=0; q.push(s);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto [v,id]: g[u]){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    par[v]=u; paredge[v]=id;
                    q.push(v);
                }
            }
        }
        int far = s;
        for(int i=0;i<n;i++) if(dist[i]>dist[far]) far=i;
        return tuple<int,vector<int>,vector<int>,vector<int>>(far, dist, par, paredge);
    };

    vector<int> par, pedge, dist;
    int A; tie(A, dist, par, pedge) = bfs(0, par, pedge);         // 1st BFS
    int B; tie(B, dist, par, pedge) = bfs(A, par, pedge);         // 2nd BFS from A
    int L = dist[B];

    // 还原直径路径 A -> ... -> B
    vector<int> path; path.reserve(L+1);
    for(int x=B; x!=-1; x=par[x]) path.push_back(x);
    reverse(path.begin(), path.end()); // path[0]=A, path[L]=B

    vector<int> choose(n, -1);
    int answer = L/2; // floor(L/2) 正解

    if(L % 2 == 0) {
        // 以中点结点为根
        int center = path[L/2];
        auto dfs_build = [&](auto&& self, int u, int p)->void{
            for(auto [v,id]: g[u]) if(v!=p){
                choose[v] = id;      // v -> u 免费
                self(self, v, u);
            }
        };
        dfs_build(dfs_build, center, -1);
        // center 维持 -1
    } else {
        // 以中点边 (x, y) 为中心，双向免费
        int x = path[L/2], y = path[L/2 + 1];

        // 找到这条边的编号（在 BFS 的 pedge 上也能得到，此处直接枚举邻接）
        int mid_id = -1;
        for(auto [v,id]: g[x]) if(v==y) { mid_id=id; break; }

        choose[x] = choose[y] = mid_id; // 这条边两向免费

        auto dfs_side = [&](auto&& self, int u, int p)->void{
            for(auto [v,id]: g[u]) if(v!=p){
                choose[v] = id;      // v -> u 免费
                self(self, v, u);
            }
        };
        dfs_side(dfs_side, x, y); // x 这一侧
        dfs_side(dfs_side, y, x); // y 这一侧
    }

    cout << answer << '\n';
    for(int i=0;i<n;i++){
        if(i) cout << ' ';
        cout << choose[i];
    }
    cout << '\n';
    return 0;
}
