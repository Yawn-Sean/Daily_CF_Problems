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
    std::vector<std::vector<char>> g(n+2,std::vector<char> (m+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cin>>g[i][j];
        }
    }

    std::vector<std::vector<int>> use(n+2,std::vector<int> (m+2));
    std::vector<std::vector<int>> len(n+2,std::vector<int> (m+2));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) 
            if(g[i][j]=='*'){
                int cll=j-1,clr=j+1,rwu=i-1,rwd=i+1;
                while(cll>=1 and clr<=m and rwu>=1 and rwd<=n){
                    if(g[i][cll]=='*' and g[i][clr]=='*' and g[rwu][j]=='*' and g[rwd][j]=='*'){
                        use[i][j]=1;
                        use[i][cll]=1;use[i][clr]=1;
                        use[rwu][j]=1;use[rwd][j]=1;
                        len[i][j]=std::max(len[i][j],j-cll);
                        cll--,clr++,rwu--,rwd++;
                    } else break;
                }
            }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='*' and !use[i][j]){
                std::cout<<"-1"<<"\n";
                return;
            }
        }
    }

    std::vector<std::array<int,2>> res;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='*' and len[i][j]>0){
                res.pb({i,j});
            }
        }
    }

    std::cout<<res.size()<<"\n";
    for(auto [x,y]:res){
        std::cout<<x<<" "<<y<<" "<<len[x][y]<<"\n";
    }
    std::cout<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
