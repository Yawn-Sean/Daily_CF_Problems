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
    i64 n;
    std::cin>>n;

    auto check=[&](int k)->bool{
        i64 v=n+k;
        if(v%3) return 0;
        i64 sum=1ll*k*(k+1)/2;
        if(sum*3<=v) return 1;
        return 0;

    };

    int res=0;
    for(int i=1;i<=10'000'000;i++){
        if(check(i)) res++;
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
