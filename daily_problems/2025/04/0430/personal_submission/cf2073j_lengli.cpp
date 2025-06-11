/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> idx(n+2);
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        idx[x]=i;
    }

    std::vector<std::vector<int>> f(n+2,std::vector<int> (n+2,inf));

    for(int i=1;i<=n;i++) f[i][i]=0;

    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            for(int pos=i;pos<j;pos++){
                f[i][j]=std::min(f[i][j],f[i][pos]+f[pos+1][j]+std::abs(idx[i]-idx[pos+1]));
            }
        }
    }

    std::cout<<f[1][n]<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
