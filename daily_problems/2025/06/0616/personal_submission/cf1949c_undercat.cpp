#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<vector<int>>g(n+1);
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n<=4){
        cout<<"Yes\n";
        return;
    }
    int flag=0;
    vector<int>son(n+10,1),sz(n+10,1),par(n+10,1);
    auto dfs1=[&](auto&&dfs1,int u,int fa)->void{
        vector<int>t;
        for(auto&i:g[u]){
            if(i==fa)continue;
            dfs1(dfs1,i,u);
            if(son[i]==0)son[u]=0;
            t.push_back(sz[i]);
            sz[u]+=sz[i];
        }
        sort(t.begin(),t.end());
        for(int i=0,now=1;i<(int)t.size();i++){
            if(now>=t[i])now+=t[i];
            else{
                son[u]=0;
                break;
            }
        }
    };
    /*
          7 - 1 - 5 
              |
     4 -  6 - 3 - 2

     1-4-2-3-5

     4-5-6-1
         |
         2-3
    */
    auto dfs2=[&](auto&&dfs2,int u,int fa,pair<int,int>v)->void{
        if(flag)return;
        vector<pair<int,int>>t{v};
        vector<int>p,del;        
        for(auto&i:g[u]){
            if(i==fa)continue;
            t.push_back({sz[i],i});            
            if(son[i]==0)del.push_back(i);
        }
        if(del.size()>=2)return;
        sort(t.begin(),t.end());
        int now=1;
        for(int i=0;i<(int)t.size();i++){
            if(now>=t[i].first){
                now+=t[i].first;
            }else{
                p.push_back(t[i].second);
            }
        }
        if(p.size()==0&&del.size()==0){
            flag=1;
            return;
        }
        if(p.size()>1||(p.size()==1&&p[0]==fa)){
            return;
        }
        if(p.size()==1&&(del.size()==0||(del.size()==1&&del[0]==p[0])))
            dfs2(dfs2,p[0],u,{now,u});
    };
    dfs1(dfs1,1,0);
    if(son[1])flag=1;
    dfs2(dfs2,1,0,{0,0});
    if(flag)cout<<"Yes\n";
    else cout<<"No\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}