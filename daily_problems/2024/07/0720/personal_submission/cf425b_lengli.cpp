/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

std::vector<std::vector<int>> rotate(std::vector<std::vector<int>> &grid){
    int n=grid.size(),m=grid[0].size();
    std::vector<std::vector<int>> res(m,std::vector<int> (n));
    for(int i=0,jj=n-1;i<n;i++,jj--){
        for(int j=0,ii=0;j<m;j++,ii++){
            res[ii][jj]=grid[i][j];
        }
    }
    return res;
};


void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<std::vector<int>> g(n,std::vector<int>(m,0));
    for(auto &x:g)  for(auto &y:x) std::cin>>y;
    if(n<m) g=rotate(g),std::swap(n,m);

    if(m>k){
        int res=-1;
        for(int t=0;t<n;t++){
            int ans=0;
            for(int i=0;i<n;i++){
                int cl=0,cr=0;
                for(int j=0;j<m;j++){
                    if(g[i][j]==g[t][j]) cr++;
                    else cl++;
                }
                ans+=std::min(cl,cr);
            }
            if(ans<=k){
                if(res==-1) res=ans;
                else if(ans<res) res=ans;
            }
        }
        std::cout<<res;
    }else{
        int res=-1;
        for(int mask=0;mask<(1<<m);mask++){
            int ans=0;
            for(int i=0;i<n;i++){
                int cl=0,cr=0;
                for(int j=0;j<m;j++){
                    if(g[i][j]==(mask>>j&1)) cr++;
                    else cl++;
                }
                ans+=std::min(cl,cr);
            }
            if(ans<=k){
                if(res==-1) res=ans;
                else if(ans<res) res=ans;
            }
        }
        std::cout<<res;
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
