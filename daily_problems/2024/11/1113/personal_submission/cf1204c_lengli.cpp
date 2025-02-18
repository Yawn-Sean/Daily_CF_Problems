/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> dist(n+2,std::vector<int> (n+2,inf));
    for(int i=1;i<=n;i++){
        std::string s;
        std::cin>>s;
        for(int j=1;j<=n;j++){
            if(s[j-1]=='1') dist[i][j]=1;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) dist[i][j]=0;
                else dist[i][j]=std::min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int m;
    std::cin>>m;
    std::vector<int> q(m),res;
    for(auto &x:q) std::cin>>x;
    for(int i=0;i<m;i++){
        if(res.size()<2) res.pb(i);
        else{
            int v=q[i];
            int idx=res.size();
            while(idx>=2 and dist[q[res[idx-2]]][v]==dist[q[res[idx-2]]][q[res[idx-1]]]+dist[q[res[idx-1]]][v]){
                res.pop_back();
                idx=res.size();
            }
            res.pb(i);
        }
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<q[x]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
