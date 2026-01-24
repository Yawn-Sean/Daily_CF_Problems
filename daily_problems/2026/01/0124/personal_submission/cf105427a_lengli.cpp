/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=2e9;

void solve(){
    int n,k;
    std::cin>>n>>k;
    if(n<=k){
        std::cout<<0<<"\n";
        return;
    }
    i64 len=k+1,cnt=1,ed=1;
    std::vector<std::array<i64,2>> q;

    i64 res=0;

    while(len<=inf){
        q.pb({len,cnt});
        len*=k,cnt*=k;
        len++,cnt++;
        ed++;
        if(ed==k and len<=inf){
            q.pb({len,cnt});
            if(len<=n){
                res+=n-len;
                n=len;
            }
            break;
        }
    }
    while(n>=q[0][0]){
        int l=0,r=q.size()-1;
        while(l<r){
            int mid=(l+r+1)/2;
            if(q[mid][0]<=n) l=mid;
            else r=mid-1;
        }
        auto [v,c]=q[l];
        res+=(n/v)*c;
        n%=v;
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
