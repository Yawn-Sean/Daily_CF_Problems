/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=1e18;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> cnt(n+2);
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        if(x<=n) cnt[x]++;
    }
    int val=0;
    while(cnt[val]) val++;

    std::vector<i64> f(val+2,inf);
    f[val]=0;
    for(int i=val-1;i>=0;i--){
        for(int j=i+1;j<=val;j++){
            f[i]=std::min(f[i],f[j]+1ll*(cnt[i]-1)*j+i);
        }
    }
    std::cout<<f[0]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
