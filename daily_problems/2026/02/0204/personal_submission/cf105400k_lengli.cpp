#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int n;
    vector<int> parent, rankv;
    UnionFind(int n) : n(n), parent(n), rankv(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool merge(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return false;
        if(rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if(rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    UnionFind uf(n + m);
    vector<vector<int>> path(n + m);

    for(int i = 0; i < n; ++i){
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j){
            int idx;
            cin >> idx;
            idx--;             
            if(uf.merge(idx, m + i)){
                path[idx].push_back(m + i);
                path[m + i].push_back(idx);
            }
        }
    }

    vector<int> parent(n + m, -1), depth(n + m, 0);
    for(int i = 0; i < n + m; ++i){
        if(parent[i] == -1){
            queue<int> q;
            q.push(i);
            parent[i] = i; 
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v : path[u]){
                    if(parent[v] == -1){
                        parent[v] = u;
                        depth[v] = depth[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    vector<string> outs;

    while(q--){
        int u, v;
        cin >> u >> v;
        u--; v--;  // 0-index

        if(uf.find(u) != uf.find(v)){
            outs.push_back("-1");
        } else {
            vector<int> path_u{u}, path_v{v};
            while(path_u.back() != path_v.back()){
                if(depth[path_u.back()] > depth[path_v.back()]){
                    path_u.push_back(parent[path_u.back()]);
                } else {
                    path_v.push_back(parent[path_v.back()]);
                }
            }

            reverse(path_v.begin(), path_v.end());
            path_u.insert(path_u.end(), path_v.begin() + 1, path_v.end());

            outs.push_back(to_string((int)path_u.size() / 2 + 1));
            string line;
            for(int x : path_u){
                int outv = (x < m ? x + 1 : x - m + 1);
                line += to_string(outv) + " ";
            }
            if(!line.empty()) line.pop_back();
            outs.push_back(line);
        }
    }

    for(auto &s : outs) cout << s << "\n";
    return 0;
}
