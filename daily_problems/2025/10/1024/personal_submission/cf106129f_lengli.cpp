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
    std::vector<std::vector<int>> g(n+2,std::vector<int> (m+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            std::cin>>c;
            g[i][j]=(c=='#' ? 1 : 0);
        }
    }

    auto check=[&](int len)->bool{
        auto q=g;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(q[i][j]==1){
                    if(i+len-1>n or j+len-1>m) return 0;
                    for(int ii=i;ii<=i+len-1;ii++){
                        for(int jj=j;jj<=j+len-1;jj++){
                            if(!q[ii][jj]) return 0;
                            q[ii][jj]=0;
                        }
                    }
                }
            }
        }
        return 1;
    };

    int mxlen=0;
    for(int i=1;i<=n and !mxlen;i++){
        for(int j=1,t=0;j<=m;j++){
            if(g[i][j]==1) t++;
            else t=0;
            mxlen=std::max(mxlen,t);
        }
        
    }

    for(int i=mxlen;i>=1;i--){
        if(mxlen%i==0 and check(i)){
            std::cout<<i<<"\n";
            return;
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
