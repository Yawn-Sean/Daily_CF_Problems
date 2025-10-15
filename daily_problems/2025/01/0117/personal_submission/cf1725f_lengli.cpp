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
    int n;  
    std::cin>>n;
    std::vector<std::array<int,2>> seg(n);
    for(auto &[l,r]:seg) std::cin>>l>>r;
    std::vector<int> f(32,-1);

    auto cal=[&](int idx){
        std::vector<std::array<int,2>> q;
        int mod=(1<<idx);
        int cnt=0;
        for(auto [l,r]:seg){
            if(r-l+1>=mod){
                cnt++;
            }else{
                l%=mod,r%=mod;
                if(l>r) cnt++;
                q.pb({l,1});
                q.pb({r+1,-1});
            }
        }
        sort(all(q));
        int res=cnt;
        for(auto [t,v]:q){
            cnt+=v;
            res=std::max(res,cnt);
        }
        return res;
    };

    int m;
    std::cin>>m;
    while(m--){
        int x;
        std::cin>>x;
        int v=__builtin_ctz(x);
        if(f[v]==-1) f[v]=cal(v);
        std::cout<<f[v]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
