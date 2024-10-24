#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    vector<int> vis(n,0);
    vector<int> ans;
    
    auto dfs = [&](auto self,int u)->void{
        if(vis[u])  return;
        vis[u] = 1;
        for(auto v:g[u]){
            self(self,v);
        }
        ans.push_back(u);
    };
    for(int i=0;i<n;i++){
        dfs(dfs,i);
    }
    for(auto x:ans){
        cout << x+1 << " ";
    }
}