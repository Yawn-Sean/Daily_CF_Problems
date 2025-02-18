/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

void solve(){
    int n;
    std::cin>>n;
    int l=1,r=1e18;

    auto check=[&](int x){
        int res=0;
        for(int i=2;x/i/i/i>0;i++){
            res+=x/i/i/i;
        }
        return res;
    };

    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)>=n) r=mid;
        else l=mid+1;
    }
    std::cout<<(check(r)==n ? r : -1);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
