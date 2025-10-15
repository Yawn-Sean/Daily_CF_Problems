/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,m;
    std::cin>>n>>m;
    int idx=m+1;

    std::vector<std::vector<int>> eg(1000010);

    std::vector<int> v(m+2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cin>>v[j];
        }
        std::vector<std::array<int,2>> w;
        for(int j=1;j<=m;j++){
            if(v[j]!=-1){
                w.pb({v[j],j});
            }
        }
        std::sort(all(w));
        for(int j=0;j<w.size();j++){
            if(j>0 and w[j-1][0]!=w[j][0]) idx++;
            eg[idx].pb(w[j][1]);
            eg[w[j][1]].pb(idx+1);
        }
        idx+=2;
    }

    std::vector<int> st(1000010),res;

    bool flag=0;

    auto dfs=[&](auto self,int u)->void{
        st[u]=1;
        for(auto x:eg[u]){
            if(st[x]==1){
                flag=1;
                return;
            }
            if(!st[x]){
                self(self,x);
            }
        }
        st[u]=2;
        if(u<=m) res.pb(u);
    };

    for(int i=1;i<=m;i++){
        if(!st[i]){
            dfs(dfs,i);
        }
    }

    if(flag) std::cout<<"-1"<<"\n";
    else{
        std::reverse(all(res));
        for(auto x:res) std::cout<<x<<" ";
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
