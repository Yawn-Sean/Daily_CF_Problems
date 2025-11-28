/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    i64 n,m;
    std::cin>>n>>m;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    std::sort(all(a));

    int l=0,r=10000000;
    auto check=[&](int val)->i64{
        i64 res=0;
        if(!val){
            return 1ll*n*n-1;
        }
        for(int i=0;i<n;i++){
            auto idx=lower_bound(all(a),a[i]+val);
            if(idx==a.end()) continue;
            res+=(n-(idx-a.begin()))*2;
        }
        return res;
    };
    
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)>=m) l=mid;
        else r=mid-1;
    }
    
    std::vector<i64> suf(n);
    for(int i=n-1;i>=0;i--){
        if(i==n-1) suf[i]=a[i];
        else suf[i]=suf[i+1]+a[i];
    }

    i64 res=0;
    for(int i=0;i<n;i++){
        auto idx=upper_bound(all(a),a[i]+l);
        if(idx==a.end()) continue;
        int j=(idx-a.begin());
        i64 cnt=(n-j)*2;
        m-=cnt;
        res+=suf[j]*2-cnt*a[i];
    }
    res+=1ll*l*m;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
