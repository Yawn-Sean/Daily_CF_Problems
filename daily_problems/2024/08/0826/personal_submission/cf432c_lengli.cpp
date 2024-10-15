/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

std::vector<int> pr;

std::vector<int> sieve(int n){
    std::vector<int> prime,st(n+1,0);
    for(int i=2;i<=n;i++){
        if(!st[i]) prime.push_back(i);
        for(int j=0;prime[j]*i<=n;j++){
            st[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    return prime;
}


void solve(){
    int n;
    std::cin>>n;
    pr=sieve(n+2);pr.pb(1000000007);
    std::vector<int> a(n+2),idx(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        idx[a[i]]=i;
    }
    std::vector<std::array<int,2>> res;
    for(int i=1;i<=n;i++){
        int t=idx[i];
        if(t==i) continue;
        int len=t-i+1;
        int k=2;
        while(len>1){
            auto it=upper_bound(all(pr),len);
            it=prev(it);
            int l=t-*(it)+1;
            int r=t;
            std::swap(a[l],a[r]);
            res.pb({l,r});
            idx[a[l]]=l,idx[a[r]]=r;
            t=idx[i];
            len=t-i+1;
        }
    }
    std::cout<<res.size()<<"\n";
    for(auto [l,r]:res) std::cout<<l<<" "<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
