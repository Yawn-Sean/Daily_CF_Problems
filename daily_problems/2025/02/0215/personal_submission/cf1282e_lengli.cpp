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
    std::vector<int> r1,r2;
    std::map<std::array<int,2>,int> q;
    int cnt=0;
    std::vector<int> rd(n+2,0),st(n+2,0);
    std::vector<std::vector<int>> eg(n+2),in(n+2);

    std::vector<std::vector<int>> pt(n+2,std::vector<int>(3,0));
    for(int i=1;i<=n-2;i++){
        for(int j=0;j<3;j++){
            auto &t=pt[i][j];
            std::cin>>t;
            rd[t]++;
            in[t].pb(i);
        }
        sort(all(pt[i]));
        for(int j=0;j<2;j++){
            for(int k=j+1;k<3;k++){
                int l=pt[i][j],r=pt[i][k];
                q[{l,r}]^=1;
            }
        }
    }

    for(int i=1;i<=n-2;i++){
        for(int j=0;j<2;j++){
            for(int k=j+1;k<3;k++){
                int l=pt[i][j],r=pt[i][k];
                if(q[{l,r}]){
                    eg[l].pb(r);
                    eg[r].pb(l);
                }
            }
        }
    }

    auto dfs=[&](auto self,int u,int fa)->void{
        r1.pb(u);
        st[u]=1;
        for(auto x:eg[u]){
            if(st[x]) continue;
            self(self,x,u);
        }
    };

    dfs(dfs,1,0);

    std::queue<int> que;
    for(int i=1;i<=n;i++){
        if(rd[i]==1) que.push(i);
    }
    std::fill(all(st),0);
    while(que.size()){
        auto t=que.front();
        que.pop();
        for(auto x:in[t]){
            if(st[x]) continue;
            st[x]=1;
            r2.pb(x);
            for(int i=0;i<3;i++){
                rd[pt[x][i]]--;
                if(rd[pt[x][i]]==1){
                    que.push(pt[x][i]);
                }
            }
        }
    }

    for(auto x:r1) std::cout<<x<<" ";std::cout<<"\n";
    for(auto x:r2) std::cout<<x<<" ";std::cout<<"\n";

}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
