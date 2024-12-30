/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long 

constexpr int inf=1e18;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> f(n+2,std::vector<int> (10,-inf));
    f[0][0]=0;
    for(int i=0;i<n;i++){
        int k;
        std::cin>>k;
        std::vector<int> a[4];
        for(int i=0;i<k;i++){
            int c,v;
            std::cin>>c>>v;
            a[c].pb(v);
        }
        for(int i=1;i<=3;i++) sort(all(a[i]));
        for(int j=0;j<10;j++) f[i+1][j]=f[i][j];
        for(int j=0;j<10;j++){
            if(f[i][j]==-inf) continue;
            {
                if(a[3].size()){
                    auto t=a[3].back();
                    f[i+1][(j+1)%10]=std::max(f[i][j]+t*(j==9 ? 2 : 1),f[i+1][(j+1)%10]);
                }
            }
            {
                if(a[2].size()){
                    auto t=a[2].back();
                    f[i+1][(j+1)%10]=std::max(f[i][j]+t*(j==9 ? 2 : 1),f[i+1][(j+1)%10]);
                } 
            }
            {
                if(a[2].size() and a[1].size()){
                    auto t=a[2].back(),tt=a[1].back();
                    if(t<tt) std::swap(t,tt);
                    f[i+1][(j+2)%10]=std::max(f[i][j]+t*(j>=8 ? 2 : 1)+tt,f[i+1][(j+2)%10]);
                } 
            }
            {
                if(a[1].size()){
                    auto t=a[1].back();
                    f[i+1][(j+1)%10]=std::max(f[i][j]+t*(j==9 ? 2 : 1),f[i+1][(j+1)%10]);
                } 
            }
            {
                if(a[1].size()>=2){
                    int len=a[1].size();
                    std::vector<int> t;
                    for(int k=len-1;k>=len-2;k--) t.pb(a[1][k]);
                    sort(all(t));
                    f[i+1][(j+2)%10]=std::max(f[i][j]+t[1]*(j>=8 ? 2 : 1)+t[0],f[i+1][(j+2)%10]);
                } 
            }
            {
                if(a[1].size()>=3){
                    int len=a[1].size();
                    std::vector<int> t;
                    for(int k=len-1;k>=len-3;k--) t.pb(a[1][k]);
                    sort(all(t));
                    f[i+1][(j+3)%10]=std::max(f[i][j]+t[2]*(j>=7 ? 2 : 1)+t[0]+t[1],f[i+1][(j+3)%10]);
                } 
            }
        }
    }
    int res=0;
    for(int i=0;i<10;i++) res=std::max(res,f[n][i]);
    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
