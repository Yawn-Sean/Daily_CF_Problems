/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

using i128=__int128;

void solve(){
    int a,b;
    std::cin>>a>>b;
    int c=a*b;
    int l=1,r=1e6;

    auto check=[&](int x){
        return (i128)x*x*x<=c;
    };

    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    if(1ll*l*l*l==c and a%l==0 and b%l==0) std::cout<<"Yes"<<"\n";
    else std::cout<<"No"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
