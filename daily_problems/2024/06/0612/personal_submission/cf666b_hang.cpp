#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u -= 1;
        v -= 1;
        g[u].push_back(v);
    }
    vector<vector<pair<int,int>>> per(n), net(n);
    
    auto add = [&](vector<pair<int,int>> & l, int dis, int x){
        l.push_back({dis,x});
    };

    auto bfs = [&](int s) {
        queue<int> q;
        q.push(s);
        vector<int> vis(n, 0), dis(n, -1);
        vis[s] = 1;
        dis[s] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v: g[u]){
                if(!vis[v]){
                    vis[v] = 1;
                    dis[v] = dis[u] + 1;
                    q.push(v);
                    add(per[v], dis[v], s);
                    add(net[s], dis[v], v);
                }
            }
        }
        return dis;
    };
    vector<vector<int>> ds;
    for(int i=0;i<n;i++){
        ds.push_back(bfs(i));
    }
    for(int i=0;i<n;i++){
        if(per[i].size() > 3){
            nth_element(per[i].begin(), per[i].begin() + 3, per[i].end(), greater<pair<int,int>>());
            per[i].erase(per[i].begin() + 3, per[i].end());
        }
        if(net[i].size() > 3){
            nth_element(net[i].begin(), net[i].begin() + 3, net[i].end(), greater<pair<int,int>>());
            net[i].erase(net[i].begin() + 3, net[i].end()); 
        }
       
    }
    vector<int> ans;
    int mx = 0;
    for(int b = 0;b <n;b++){
        auto dis = ds[b];
        for(int c = 0;c <n;c++){
            if(b == c || dis[c] == -1) continue;
            for(auto &[dis_a, a]: per[b]){
                for(auto &[dis_d, d] : net[c]){
                    int cur = dis[c] + dis_a + dis_d;
                    if(a != c && a != d && b != d && cur > mx){
                        mx = cur;
                        ans = {a, b, c, d};
                    }
                }
            }
        }
    }
    for(auto x: ans) cout<<x+1<<" ";
}