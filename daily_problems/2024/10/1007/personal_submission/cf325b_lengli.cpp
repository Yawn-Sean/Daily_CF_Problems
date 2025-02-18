/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i128 __int128

void solve(){
    long long n;
    std::cin>>n;

    std::vector<long long> res;

    for(long long sum=0,j=0;sum<=n;sum+=(1ll<<j),j++){
        i128 l=1,r=n;
        while(l<r){
            i128 mid=(l+r)/2;
            i128 v=(i128)mid*sum+(mid-1)*(i128)mid/2;
            if(v>=n) r=mid;
            else l=mid+1;
        }
        i128 v=(i128)r*sum+(r-1)*(i128)r/2;
        if(v==n and r&1) res.pb(r<<j);
        
    }
    if(res.empty()) std::cout<<"-1"<<"\n";
    else{
        res.erase(unique(all(res)),res.end());
        for(auto x:res) std::cout<<x<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
