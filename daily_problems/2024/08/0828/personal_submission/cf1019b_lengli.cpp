/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    auto query=[&](int x){
        int l,r;
        std::cout<<"? "<<x<<std::endl;
        std::cin>>l;x=x+n/2;
        std::cout<<"? "<<x<<std::endl;
        std::cin>>r;
        return l-r;
    };
    auto print=[&](int x){
        std::cout<<"! "<<x<<std::endl;
        return;
    };

    if((n/2)&1){
        print(-1);
        return;
    }
    int l=1,r=n/2+1;
    auto t=query(l);
    if(!t) {
        print(l);
        return;
    }
    while(l<r){
        int mid=(l+r)>>1;
        auto k=query(mid);
        if(!k){
            print(mid);
            return;
        }
        if(t*k>0) l=mid+1;
        else r=mid;
    }
    print(l);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
