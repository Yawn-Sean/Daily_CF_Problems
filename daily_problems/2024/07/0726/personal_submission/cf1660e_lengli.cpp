/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> g(n*2+2,std::vector<int> (n*2+2));
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            std::cin>>c;
            g[i][j]=c-'0';
            g[i][j+n]=g[i][j];
            cnt+=g[i][j];
        }
        g[i+n]=g[i];
    }
    std::vector<std::vector<int>> f(n*2+2,std::vector<int> (n*2+2,0));
    int mx=0;
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=n*2;j++){
            f[i][j]=f[i-1][j-1]+(g[i][j]==1);
            if(i>n and j>n){
                if(g[i-n][j-n]==1) f[i][j]--;
            }
            mx=std::max(f[i][j],mx);
        }
    }
    
    std::cout<<cnt-mx+(n-mx)<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
