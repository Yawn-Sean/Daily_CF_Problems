/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#define f128 long double

constexpr f128 inf=1e18;

void solve(){
    int n,d;
    std::cin>>n>>d;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<std::vector<f128>> f(n+2,std::vector<f128> (10,-inf));
    std::vector<std::vector<int>> la(n+2,std::vector<int> (10,0));
    std::vector<std::vector<int>> use(n+2,std::vector<int> (10,0));
    for(int i=0;i<=n;i++) f[i][1]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            f128 v=f[i][j]+std::log2(a[i+1]);
            int ne=(j*a[i+1])%10;
            if(f[i+1][ne]<=v){
                f[i+1][ne]=v;
                use[i+1][ne]=1;
                la[i+1][ne]=j;
            }
            if(f[i+1][j]<=f[i][j]){
                f[i+1][j]=f[i][j];
                use[i+1][j]=0;
                la[i+1][j]=j;
            }
        }
    }
    if(f[n][d] < 1e-8){
        std::cout<<"-1"<<"\n";
        return;
    }

    std::vector<int> res;
         
    for(int i=n,j=d;i>=1;i--){
        if(use[i][j]) res.pb(a[i]);
        j=la[i][j];
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
