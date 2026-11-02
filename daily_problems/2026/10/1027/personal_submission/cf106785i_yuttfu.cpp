#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> g(n+1);
    vector<int> d(n+1,-1);
    vector<int> pre(n+1,-1);
    int x,y;
    for(int i = 1;i < n;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    auto bfs = [&](int s) -> int{
        fill(d.begin(),d.end(),-1);
        fill(pre.begin(),pre.end(),-1);
        
        queue<int> q;
        d[s] = 0;
        q.push(s);

        int ans = s;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(d[u] > d[ans]){
                ans = u;
            }
            for(auto v : g[u]){
                if(d[v] != -1) continue;
                d[v] = d[u] + 1;
                pre[v] = u;
                q.push(v);
            }
        }
        return ans;
    };
    int s = bfs(1);
    int t = bfs(s);
    int D = d[t];
    vector<int> path;
    for(int u = t;u != -1;u = pre[u]){
        path.push_back(u);
    }
    if(D % 2){
        cout << "Alice\n";
    }else{
        if(k == path[D/2]) cout << "Bob\n";
        else cout << "Alice\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
