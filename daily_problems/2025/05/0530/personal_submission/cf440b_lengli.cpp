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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    i64 sum=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        sum+=a[i];
    }
    std::queue<std::array<int,2>> z,f;

    sum/=n;

    for(int i=1;i<=n;i++){
        if(a[i]==sum) continue;
        if(a[i]<sum) z.push({i,sum-a[i]});
        if(a[i]>sum) f.push({i,a[i]-sum});
    }

    i64 res=0;
    while(z.size()){
        auto [l,t]=z.front();
        z.pop();
        while(t){
            auto [r,x]=f.front();
            if(x<=t){
                f.pop();
                t-=x;
                res+=1ll*std::abs(r-l)*x;
            }else{
                f.front()[1]-=t;
                res+=1ll*std::abs(r-l)*t;
                t=0;
            }
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
