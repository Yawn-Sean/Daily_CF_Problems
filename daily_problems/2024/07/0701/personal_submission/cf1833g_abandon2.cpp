#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
using PII=pair<int,int>;

std::vector<PII>e[N];


void solve(){
    int n;cin>>n;
    vector<int>siz(n+1,0);
    for(int i=1;i<=n;i++)e[i].clear();
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        e[a].push_back({b,i});
        e[b].push_back({a,i});
    }
    vector<int>ans;
    int ok=1;
    auto dfs=[&](auto&&dfs,int u,int fa,int id)->void{
        siz[u]=1;
        for(auto [v,i]:e[u]){
            if(v==fa)continue;
            dfs(dfs,v,u,i);
            siz[u]+=siz[v];
        }
        if(siz[u]==3){
            siz[u]=0;
            if(fa!=0)
            ans.push_back(id);
        }
        else if(siz[u]>3){
            ok=0;
        }
          
          
    };
    dfs(dfs,1,0,1);
    if(n%3||!ok){
        cout<<"-1\n";return;
    }
    //cout<<siz[1]<<"\n";
    //if(ans)
    cout<<ans.size()<<"\n";
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<"\n";

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--)
        solve();
    return 0;
}

