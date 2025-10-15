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
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> q(2);
    int m1,m2;
    std::cin>>m1;
    for(int i=1;i<=m1;i++){
        int x;
        std::cin>>x;
        q[0].pb(x);
    }
    std::cin>>m2;
    for(int i=1;i<=m2;i++){
        int x;
        std::cin>>x;
        q[1].pb(x);
    }

    std::vector<std::vector<int>> f(2,std::vector<int> (n+2,-1));
    std::vector<std::vector<int>> win(2,std::vector<int> (n+2,0));

    auto dfs=[&](auto self,int v,int idx)->void{
        if(!f[v][idx]){
            for(auto x:q[v^1]){
                int pre=(idx-x+n)%n;
                if(f[v^1][pre]!=-1) continue;
                f[v^1][pre]=1;
                self(self,v^1,pre);
            }
        }else{
            for(auto x:q[v^1]){
                int pre=(idx-x+n)%n;
                if(f[v^1][pre]!=-1) continue;
                win[v^1][pre]++;
                if(win[v^1][pre]==q[v^1].size()){
                    f[v^1][pre]=0;
                    self(self,v^1,pre);
                }
            }
        }
    };
    
    f[0][0]=0,f[1][0]=0;
    dfs(dfs,0,0),dfs(dfs,1,0);

    for(int i=0;i<2;i++){
        for(int j=1;j<n;j++){
            std::cout<<(f[i][j]==0 ? "Lose" : f[i][j]==1 ? "Win" : "Loop")<<" ";
        }std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
