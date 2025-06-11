/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

std::mt19937 rd(time(0));

namespace std {
    template<>
    struct hash<std::array<int,2>> {
        size_t operator()(const std::array<int,2>& s) const {
            return hash<int>()(s[0]) ^ hash<int>()(s[1]);
        }
    };
}


void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,2>> q(m);
    for(auto &[x,y]:q) std::cin>>x>>y,x--,y--;
    std::vector<int> fac;
    for(int i=1;i*i<=n;i++){
        if(n%i) continue;
        int l=i,r=n/i;
        fac.pb(l);
        if(l!=r) fac.pb(r); 
    }

    std::unordered_set<std::array<int,2>> st;
    st.reserve(1000+rd()%25);
    for(auto t:q) st.insert(t);

    auto check=[&](int c)->bool{
        for(auto [x,y]:q){
            std::array<int,2> k={(x+c)%n,(y+c)%n};
            if(st.count(k)) continue;
            std::swap(k[0],k[1]);
            if(st.count(k)) continue;
            return 0;
        }
        return 1;
    };

    bool flag=0;
    for(auto x:fac){
        if(x==n) continue;
        if(check(x)) flag=1;
        if(flag) break;
    }
    std::cout<<(flag ? "Yes" : "No")<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
