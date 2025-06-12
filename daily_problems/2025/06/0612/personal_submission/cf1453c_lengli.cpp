/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

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

constexpr int inf=1e9;


void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> g(n,std::vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x;
            std::cin>>x;
            g[i][j]=x-'0';
        }
    }

    std::vector<int> res(10,0);

    auto cal=[&](){
        for(int v=0;v<10;v++){
            int mi=inf,mx=-1;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(g[i][j]==v){
                        mx=std::max(mx,i);
                        mi=std::min(mi,i);
                        break;
                    }
                }
            }
            if(mx==-1) continue;
            for(int i=mi;i<=mx;i++){
                int l=inf,r=-1;
                for(int j=0;j<n;j++){
                    if(g[i][j]==v){
                        l=std::min(l,j);
                        r=std::max(r,j);
                    }
                }
                if(r==-1) continue;

                {
                    int x=std::max(r,n-l-1);
                    int y=std::max(i-mi,mx-i);
                    res[v]=std::max(res[v],x*y);
                }

                if(l!=r){
                    int x=r-l;
                    int y=std::max(i,n-i-1);
                    res[v]=std::max(res[v],x*y);
                }
            }
        }
    };

    cal();
    g=rotate(g);
    cal();
    for(int i=0;i<10;i++) std::cout<<res[i]<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
