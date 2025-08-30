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
    int n,k;
    std::cin>>n>>k;
    std::vector<std::vector<i64>> g(n+2,std::vector<i64> (n+2));
    std::vector<i64> sum(n+2),rd(n+2);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x;
            std::cin>>x;
            g[i][j]=x;
            if(x!=-1){
                rd[i]++;
                rd[j]++;
                sum[i]+=x;
                sum[j]+=x;
            }
        }
    }

    auto C=[&](int n,int m){
        if(n<m) return 0ll;
        i64 res=1;
        for(int i=n;i>=1;i--){
            if(i<=n) res*=i;
            if(i<=m) res/=i;
            if(i<=n-m) res/=i;
        }
        return res;
    };

    i64 res=0,cnt=0;
    for(int i=1;i<=n;i++){
        i64 x=C(rd[i],k);
        cnt+=x;
        res+=1ll*sum[i]*x*k/rd[i];
    }
    std::cout<<res/cnt<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
