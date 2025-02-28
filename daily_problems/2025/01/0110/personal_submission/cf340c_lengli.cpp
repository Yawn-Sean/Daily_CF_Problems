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
    std::vector<int> a(n);
    i64 sum=0;
    for(auto &x:a) std::cin>>x,sum+=x;
    sort(all(a));

    i64 fz=sum,fm=n;
    i64 dis=0;
    i64 la=0,cnt=0;
    for(auto x:a){
        dis+=(x-la)*cnt;
        cnt++;
        la=x;
        fz+=2ll*dis;
    }
    i64 d=std::gcd(fz,fm);
    std::cout<<fz/d<<" "<<fm/d<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
