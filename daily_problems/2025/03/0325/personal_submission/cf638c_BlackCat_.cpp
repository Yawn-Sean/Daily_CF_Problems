#include <iostream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;
#define endl '\n'

void slove(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> e(n+1);
    int u,v;
    int maxn=0;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        e[u].push_back({v,i});
        e[v].push_back({u,i});
        maxn=max(maxn,max((int)e[u].size(),(int)e[v].size()));
    }
    vector<vector<int>> ans(maxn);
    vector<int> e1(n+1,0);
    map<int,map<int,int>> mp;
    auto dfs=[&](auto &&self,int u)->void{
        int w=1;
        for(auto [v,x]:e[u]){
            if(e1[x]==0){
                while(mp[u].find(w)!=mp[u].end()){
                    w++;
                }
                e1[x]=w;
                
                mp[u][w]=1;
                mp[v][w]=1;
                self(self,v);
            }
        }
    };
    dfs(dfs,1);
    for(int i=1;i<n;i++){
        ans[e1[i]-1].push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto &x:ans){
        cout<<x.size()<<" ";
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);
    int t=1;
    //cin>>t;
    while(t--){
        slove();
    }
    return 0;
}
