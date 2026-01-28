/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#define int long long

void solve(){
    int x,y,dx,dy,k;
    std::cin>>x>>y>>dx>>dy>>k;
    int l=std::abs(x-dx),r=std::abs(y-dy);
    if(l>r) std::swap(l,r);
    if(l>=r/k){
        std::cout<<l+r<<"\n";
        return;
    }else{
        int t=(r%k==0 ? r/k-1 : r/k)-l;
        i64 res=l+r+(t+1)/2*2;
        std::cout<<res<<"\n";
    }

}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
