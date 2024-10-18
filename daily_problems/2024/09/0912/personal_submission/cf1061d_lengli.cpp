/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define i128 __int128
#define int long long

void solve(){
    int n,x,y;
    std::cin>>n>>x>>y;
    std::vector<std::array<int,2>> a(n);
    for(auto &[l,r]:a) std::cin>>l>>r;
    sort(all(a));
    std::vector<i128> f(n+2,1e26);
    std::multiset<int> q;
    f[1]=x+(a[0][1]-a[0][0])*y;
    q.insert(a[0][1]);

    auto find=[&](int x){
        auto it=q.lower_bound(x);
        it=prev(it);
        if(it==q.end() or (*it)>=x) return -1ll;
        return (*it);
    };

    for(int i=2;i<=n;i++){
        auto [l,r]=a[i-1];
        auto idx=find(l);
        f[i]=std::min(f[i],f[i-1]+x+(r-l)*y);
        if(idx!=-1){
            q.erase(q.find(idx));
            f[i]=std::min(f[i],f[i-1]+(r-idx)*y);
        }
        q.insert(r);
    }
    int res=f[n]%1000000007;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
