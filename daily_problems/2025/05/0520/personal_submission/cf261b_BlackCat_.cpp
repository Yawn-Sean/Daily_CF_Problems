#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using d64=double;
using ld64=long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    i64 tot=0;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        tot+=a[i];
    }
    int p;
    std::cin>>p;
    if(tot<=p){
        std::cout<<n<<endl;
        return;
    }
    std::vector<ld64> f(n+1);
    f[0]=1;
    for(int i=1; i<=n; i++){
        f[i]=i*f[i-1];
    }
    ld64 ans=0;
    for(int i=0;i<n;i++){
        std::vector dp(n+1,std::vector<ld64>(p+1,0));
        dp[0][0]=1;

        for(int j=0; j<n; j++){
            if(i!=j){
                for(int x=n; x>0; x--){
                    for(int y=p; y>=a[j]; y--){
                        dp[x][y]+=dp[x-1][y-a[j]];
                    }
                }
            }
        }

        for(int j=0; j<n; j++){
            for(int v=0; v<=p; v++){
                if(v+a[i]>p){
                    ans+=f[j]*f[n-1-j]*dp[j][v]*j;
                }
            }
        }
    }
    std::cout<<std::fixed<<std::setprecision(10)<<ans/f[n]<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
