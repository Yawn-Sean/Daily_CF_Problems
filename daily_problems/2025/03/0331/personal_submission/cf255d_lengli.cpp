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
    int n,x,y,c;
    std::cin>>n>>x>>y>>c;

    auto check=[&](int t){
        i64 cnt=0;
        int l=x-t,r=x+t;
        for(int i=0;i<=t;i++,l++,r--){
            if(y+i<=n) cnt+=std::min(r,n)-std::max(l,1)+1;
            if(i>0 and y-i>=1) cnt+=std::min(r,n)-std::max(l,1)+1;
        }
        return cnt>=c;
    };

    int l=0,r=100000;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    std::cout<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
